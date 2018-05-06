import React from "react";
import Papa from "papaparse";
import Dropzone from "react-dropzone";
import Logo from "../assets/logo.svg";
import styles from "./badges.module.scss";
import { isUndefined, flatten, chunk } from "lodash";

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

const convertData = (tickets, passwords) =>
  tickets
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
    .concat(Array(emptyOrgBadges).fill(getEmptyData("Volunteer")))
    .map((ticket, idx) => ({
      ...ticket,
      ...passwords[idx]
    }));

const Badge = ({ ticket }) => (
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
          <dd>{ticket.username}</dd>
        </dl>
        <dl>
          <dt>Pass.</dt>
          <dd>{ticket.password}</dd>
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
          <Badge ticket={ticket} key={"front-" + idx} />
        ))}
      </section>
      <section className={"sheet " + styles.page}>
        {reverse.map((ticket, idx) => (
          <Badge ticket={ticket} key={"back-" + idx} />
        ))}
      </section>
    </div>
  );
};

const readFileContents = file => {
  return new Promise((resolve, reject) => {
    const reader = new FileReader();
    reader.onload = async () => {
      resolve(reader.result);
    };
    reader.onabort = () => reject("file reading was aborted");
    reader.onerror = () => reject("file reading has failed");
    reader.readAsText(file, "utf-8");
  });
};

class Badges extends React.Component {
  state = {
    tickets: [],
    passwords: []
  };

  handleTicketsDrop = async acceptedFiles => {
    const csv = acceptedFiles[0];
    const content = await readFileContents(csv);
    const { data: tickets } = await Papa.parse(content, { header: true });
    this.setState({
      tickets
    });
  };

  handlePasswordsDrop = async acceptedFiles => {
    const csv = acceptedFiles[0];
    const content = await readFileContents(csv);
    const { data: passwords } = Papa.parse(content, { header: true });
    this.setState({
      passwords
    });
  };

  renderBadges(tickets, passwords) {
    const all = convertData(tickets, passwords);
    console.log(all);
    const pages = chunk(all, 4); // 4 badges per page
    return (
      <div className={styles.grid}>
        {pages.map((tickets, idx) => <SplitPage tickets={tickets} key={idx} />)}
      </div>
    );
  }

  render() {
    const { tickets, passwords } = this.state;
    return (
      <section>
        {(tickets.length === 0 || passwords.length === 0) && (
          <div className="container container_centered">
            <h2>ReasonConf Badges Generator</h2>
            <Dropzone
              name="tickets"
              multiple={false}
              disablePreview
              onDrop={this.handleTicketsDrop}
              className={styles.dropzone}
              activeClassName={styles.dropzoneHover}
            >
              {tickets.length === 0 ? (
                <p>Drop ti.to CSV file here...</p>
              ) : (
                <p>Found {tickets.length} tickets!</p>
              )}
            </Dropzone>
            <Dropzone
              name="passwords"
              multiple={false}
              disablePreview
              onDrop={this.handlePasswordsDrop}
              className={styles.dropzone}
              activeClassName={styles.dropzoneHover}
            >
              {passwords.length === 0 ? (
                <p>Drop passwords CSV file here...</p>
              ) : (
                <p>Found {passwords.length} passwords!</p>
              )}
            </Dropzone>
          </div>
        )}
        {tickets.length > 0 &&
          passwords.length > 0 &&
          this.renderBadges(tickets, passwords)}
      </section>
    );
  }
}

export default Badges;
