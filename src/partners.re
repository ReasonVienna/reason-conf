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

type partnerT = {
  name: string,
  logoUrl: string,
  href: string
};

let partners = [|
  {name: "Agent Conf", logoUrl: agentLogo, href: "https://www.agent.sh/"},
  {
    name: "React Amsterdam",
    logoUrl: reactAmsterdamLogo,
    href: "https://react.amsterdam"
  },
  {
    name: "React Finland",
    logoUrl: reactFinlandLogo,
    href: "https://react-finland.fi"
  },
  {
    name: "React Vienna",
    logoUrl: reactViennaLogo,
    href: "https://www.meetup.com/ReactVienna/"
  },
  {
    name: "ReasonVienna",
    logoUrl: reasonviennaLogo,
    href: "https://www.meetup.com/ReasonVienna/"
  },
  {
    name: "Script Conf",
    logoUrl: scriptConfLogo,
    href: "https://scriptconf.org"
  }
|];
