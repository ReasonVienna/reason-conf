[@bs.module] external agentLogo : string = "./assets/partners/agent-conf.svg";

[@bs.module]
external reactAmsterdamLogo : string = "./assets/partners/react-amsterdam.svg";

[@bs.module]
external reactFinlandLogo : string = "./assets/partners/react-finland.svg";

[@bs.module]
external reactViennaLogo : string = "./assets/partners/React-Vienna.svg";

[@bs.module]
external reasonviennaLogo : string = "./assets/partners/reasonvienna.svg";

[@bs.module]
external scriptConfLogo : string = "./assets/partners/script-conf.svg";

[@bs.module]
external impactHubLogo : string = "./assets/partners/impacthub-logo.png";

[@bs.module]
external accentureLogo : string = "./assets/partners/accenture-logo.svg";

[@bs.module]
external janeStreetLogo : string = "./assets/partners/janestreet-logo.svg";

[@bs.module] external tuCCLogo : string = "./assets/partners/tucc-logo.svg";

type sponsorT = {
  name: string,
  logoUrl: string,
  href: string,
  tier: Data.Tier.tier
};

let sponsors = [|
  {
    name: "Accenture",
    logoUrl: accentureLogo,
    href: "https://www.accenture.com",
    tier: Gold
  },
  {
    name: "JaneStreet",
    logoUrl: janeStreetLogo,
    href: "https://www.janestreet.com",
    tier: Catering
  }
|];

let partners = [|
  {
    name: "TU Career Center",
    logoUrl: tuCCLogo,
    href: "https://www.tucareer.com/",
    tier: Partner
  },
  {
    name: "Impact Hub",
    logoUrl: impactHubLogo,
    href: "https://vienna.impacthub.net",
    tier: Partner
  },
  {
    name: "Agent Conf",
    logoUrl: agentLogo,
    href: "https://www.agent.sh/",
    tier: Partner
  },
  {
    name: "React Amsterdam",
    logoUrl: reactAmsterdamLogo,
    href: "https://react.amsterdam",
    tier: Partner
  },
  {
    name: "React Finland",
    logoUrl: reactFinlandLogo,
    href: "https://react-finland.fi",
    tier: Partner
  },
  {
    name: "React Vienna",
    logoUrl: reactViennaLogo,
    href: "https://www.meetup.com/ReactVienna/",
    tier: Partner
  },
  {
    name: "ReasonVienna",
    logoUrl: reasonviennaLogo,
    href: "https://www.meetup.com/Reason-Vienna/",
    tier: Partner
  },
  {
    name: "Script Conf",
    logoUrl: scriptConfLogo,
    href: "https://scriptconf.org",
    tier: Partner
  }
|];
