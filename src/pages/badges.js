import React from "react";
import Papa from "papaparse";
import Dropzone from "react-dropzone";
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

const convertData = data =>
  data
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

const Badge = ({ ticket, idx }) => (
  <section className={styles[ticket.type]}>
    <img src={Logo} alt="ReasonConf 2018" className={styles.logo} />
    <div className={styles.content}>
      <h2 className={styles.name}>
        <span className={styles.firstName}>{ticket.firstName}</span>{" "}
        <span className={styles.lastName}>{ticket.lastName}</span>
      </h2>
      {ticket.twitter && <h3 className={styles.twitter}>{ticket.twitter}</h3>}
      {ticket.company && <p className={styles.company}>{ticket.company}</p>}
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

// To render badges from 2 sides we need to change the order of them on pages
const SplitPage = ({ tickets }) => {
  const pairs = chunk(tickets, 2);
  const reverse = flatten(pairs.map(pair => [pair[1], pair[0]]));

  return (
    <div>
      <section className={"sheet " + styles.page}>
        {tickets.map((ticket, idx) => (
          <Badge ticket={ticket} idx={idx} key={"front-" + idx} />
        ))}
      </section>
      <section className={"sheet " + styles.page}>
        {reverse.map((ticket, idx) => (
          <Badge ticket={ticket} idx={idx} key={"back-" + idx} />
        ))}
      </section>
    </div>
  );
};

class Badges extends React.Component {
  state = {
    tickets: []
  };
  handleDrop = async acceptedFiles => {
    const csv = acceptedFiles[0];
    const reader = new FileReader();
    reader.onload = async () => {
      const fileAsBinaryString = reader.result;
      const { data } = await Papa.parse(fileAsBinaryString, { header: true });
      this.setState({
        tickets: convertData(data)
      });
    };
    reader.onabort = () => console.log("file reading was aborted");
    reader.onerror = () => console.log("file reading has failed");
    reader.readAsText(csv, "utf-8");
  };

  reset = () => {
    this.setState({
      tickets: []
    });
  };
  render() {
    const { tickets } = this.state;
    const pages = chunk(tickets, 4); // 4 badges per page
    return (
      <section>
        {tickets.length === 0 && (
          <div className="container container_centered">
            <h2>ReasonConf Badges Generator</h2>
            <Dropzone
              multiple={false}
              disablePreview
              onDrop={this.handleDrop}
              className={styles.dropzone}
              activeClassName={styles.dropzoneHover}
            >
              <p>Drop ti.to CSV file here...</p>
            </Dropzone>
          </div>
        )}
        {tickets.length > 0 && (
          <div className={styles.grid}>
            {pages.map((tickets, idx) => (
              <SplitPage tickets={tickets} key={idx} />
            ))}
          </div>
        )}
      </section>
    );
  }
}

export default Badges;
