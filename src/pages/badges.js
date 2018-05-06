import React from "react";
import Papa from "papaparse";
import Logo from "../assets/logo.svg";
import styles from "./badges.module.scss";
import { isUndefined, flatten, chunk } from "lodash";
import wlan from "raw!../../data/wifi-tu.csv";
import raw from "raw!../../data/attendees.csv";

const { data } = Papa.parse(raw, { header: true });
const { data: passwords } = Papa.parse(wlan, { header: true });

const emptyBadges = 10;
const emptyOrgBadges = 5;

const getEmptyData = type => ({
  firstName: null,
  lastName: null,
  company: null,
  type,
  twitter: null
});

const getType = type => {
  switch (type) {
    case "Organizer": {
      return "Organizer";
    }
    case "Volunteer": {
      return "Volunteer";
    }
    default:
      return "Attendee";
  }
};

const allBadges = data
  // .splice(0, 5)
  .reduce((res, i) => {
    if (!i["Void Status"]) {
      return res.concat({
        firstName: i["Ticket First Name"],
        lastName: i["Ticket Last Name"],
        company:
          i["Ticket Company Name"] &&
          (!i["Ticket Full Name"].includes(i["Ticket Company Name"]) &&
            !i["Ticket Company Name"].includes(i["Ticket Full Name"]))
            ? i["Ticket Company Name"]
            : null, // Remove company if it's same as the name
        type: getType(i["Ticket"]),
        twitter: i["Tags"] ? `@${i["Tags"]}` : null
      });
    }
  }, [])
  .concat(Array(emptyBadges).fill(getEmptyData("Attendee")))
  .concat(Array(emptyOrgBadges).fill(getEmptyData("Volunteer")));
console.log(allBadges);
const pages = chunk(allBadges, 4);

const Badge = (person, idx) => {
  return (
    <section className={styles[person.type]}>
      <img src={Logo} alt="ReasonConf 2018" className={styles.logo} />
      <div className={styles.content}>
        <h2 className={styles.name}>
          <span className={styles.firstName}>{person.firstName}</span>{" "}
          <span className={styles.lastName}>{person.lastName}</span>
        </h2>
        {person.twitter && <h3 className={styles.twitter}>{person.twitter}</h3>}
        {person.company && <p className={styles.company}>{person.company}</p>}
      </div>
      <section className={styles.footer}>
        <div className={styles.footerLeft}>
          <h4>ImpactHub</h4>
          <dl>
            <dt>WLAN</dt>
            <dd>ImpactHubVienna</dd>
          </dl>
          <dl>
            <dt>Pass.</dt>
            <dd>WeLoveImpact</dd>
          </dl>
        </div>
        <div className={styles.footerRight}>
          <h4>TU Wien</h4>
          <dl>
            <dt>WLAN</dt>
            <dd>tunetguest</dd>
          </dl>
          <dl>
            <dt>User.</dt>
            <dd>{passwords[idx].username}</dd>
          </dl>
          <dl>
            <dt>Pass.</dt>
            <dd>{passwords[idx].password}</dd>
          </dl>
        </div>
      </section>
    </section>
  );
};

// To render badges from 2 sides we need to change the order of them on pages
const SplitPage = attendees => {
  const pairs = chunk(attendees, 2);
  const reverse = flatten(pairs.map(pair => [pair[1], pair[0]]));

  return (
    <div>
      <section className={"sheet " + styles.page}>
        {attendees.map(Badge)}
      </section>
      <section className={"sheet " + styles.page}>{reverse.map(Badge)}</section>
    </div>
  );
};

const Badges = () => {
  return <div className={styles.grid}>{pages.map(SplitPage)}</div>;
};

export default Badges;
