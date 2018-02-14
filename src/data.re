[@bs.module] external chengLouImg : string = "./assets/cheng-lou.jpg";

[@bs.module] external lauraGaetanoImg : string = "./assets/laura-gaetano.jpg";

[@bs.module]
external cristianoCalcagnoImg : string = "./assets/cristiano-calcagno.jpg";

[@bs.module]
external keiraHodgkisonImg : string = "./assets/keira-hodgkison.jpg";

[@bs.module] external sanderSpiesImg : string = "./assets/sander.jpg";

[@bs.module] external nikImg : string = "./assets/nik.jpg";

[@bs.module] external patrickImg : string = "./assets/patrick.jpg";

[@bs.module] external andreyImg : string = "./assets/andrey.jpg";

type organizerData = {
  name: string,
  imgUrl: string,
  href: string,
  twitter: string
};

type social = {
  twitterUser: option(string),
  githubUser: option(string),
  website: option(string)
};

type talk = {
  title: string,
  abstract: string
};

type speakerData = {
  name: string,
  company: string,
  imgUrl: string,
  description: string,
  talk: option(talk),
  social
};

module Schedule = {
  type timeslot = string;
  type lecture = {
    timeslot,
    speaker: option(speakerData)
  };
  type misc = {
    timeslot,
    description: string
  };
  type t =
    | Talk(lecture)
    | Misc(misc)
    | Break(misc);
};

let headlineSpeakers = [|
  {
    name: "Cheng Lou",
    company: "Facebook",
    imgUrl: chengLouImg,
    description: {j|I work on Reason and Facebook Messenger|j},
    talk: None,
    social: {
      githubUser: Some("chenglou"),
      twitterUser: Some("_chenglou"),
      website: None
    }
  },
  {
    name: "Keira Hodgkison",
    company: "Culture Amp",
    imgUrl: keiraHodgkisonImg,
    /* TODO: CHECK BACK WITH KEIRA TO UPDATE THE DESCRIPTION */
    description: {j|Keira is a developer at Culture Amp, the world's leading culture analytics platform. She works with React, Flow, and Rails on solutions to help customers share, and act upon company employee engagement data. Keira is an advocate for using functional programming techniques to improve the JavaScript coding and refactoring experience. When she's not writing code, she can be found under a large cat.|j},
    talk: None,
    social: {
      githubUser: Some("keirah"),
      twitterUser: Some("keirasaid"),
      website: None
    }
  },
  {
    name: "Cristiano Calcagno",
    company: "Facebook",
    imgUrl: cristianoCalcagnoImg,
    description: {j|Engineer at Facebook.\nCo-creator of @fbinfer, founder of Monoidics, reformed academic.\nInto developer experience, front-end, static analysis, language design.\nEarly @reasonml adopter, co-creator of ReasonReact.|j},
    talk: None,
    social: {
      githubUser: Some("cristianoc"),
      twitterUser: Some("ccrisccris"),
      website: None
    }
  },
  {
    name: "Laura Gaetano",
    company: "Travis Foundation",
    imgUrl: lauraGaetanoImg,
    /* TODO: CHECK BACK WITH LAURA TO UPDATE THE DESCRIPTION */
    description: {j|Laura is a manager at Travis Foundation and the organiser of Rails Girls Summer of Code (https://railsgirlssummerofcode.org/) — a 3-month scholarship program to support women in the Open Source community. With a background in the visual arts and a non-traditional career path, she landed in tech as a web developer somewhat by accident. Laura is passionate about making things, coaching at programming workshops, Open Source software, feminism, music and space (as in rockets).|j},
    talk: None,
    social: {
      githubUser: Some("alicetragedy"),
      twitterUser: Some("alicetragedy"),
      website: Some("http://www.alicetragedy.org/")
    }
  }
|];

let otherSpeakers = [|
  {
    name: "Sander Spies",
    company: "Freelancer",
    imgUrl: sanderSpiesImg,
    description: "As a developer always focusing on the reader of the code. Fell in love with React in 2013 because of the simplification it brought to state management. Regrets asking for Flux. Big fan of CSS-in-JS and currently lost in OCaml. Strongly believes in the importance of moving developers to Reason as it removes a lot of the burdens that JavaScript developers face daily. Can be blamed for several things in Reason like JSX. Reason fan since day one.",
    talk: Some({title: "Down the WebAssembly rabbit hole", abstract: "TBA"}),
    social: {
      githubUser: Some("SanderSpies"),
      twitterUser: Some("Sander_Spies"),
      website: None
    }
  }
|];

let speakers: array(speakerData) =
  Array.concat([headlineSpeakers, otherSpeakers]);

/* First in this list should be rendered last */
let organizers = [
  {
    name: "Patrick Stapfer",
    imgUrl: patrickImg,
    href: "https://twitter.com/ryyppy",
    twitter: "ryyppy"
  },
  {
    name: "Nik Graf",
    imgUrl: nikImg,
    href: "https://twitter.com/nikgraf",
    twitter: "nikgraf"
  },
  {
    name: "Andrey Okonetchnikov",
    imgUrl: andreyImg,
    href: "https://twitter.com/okonetchnikov",
    twitter: "okonetchnikov"
  }
];

/* List.find_opt is not supported by this BuckleScript version yet */
let find_opt = (fn, l) =>
  try (List.find(fn, l) |> (r => Some(r))) {
  | Not_found => None
  };

let findSpeaker = (name: string) =>
  Array.to_list(speakers) |> find_opt(s => s.name == name);

let schedule: array(Schedule.t) = [|
  Misc({timeslot: "09:00", description: "Doors open & Registration"}),
  Talk({timeslot: "10:00", speaker: findSpeaker("Cheng Lou")}),
  Break({timeslot: "10:45", description: "30 min break"}),
  Misc({timeslot: "11:15", description: "Talk 2"}),
  Break({timeslot: "12:00", description: "15 min break"}),
  Talk({timeslot: "12:15", speaker: findSpeaker("Laura Gaetano")}),
  Break({timeslot: "13:00", description: "2 hour lunch break"}),
  Misc({timeslot: "15:00", description: "Talk 4"}),
  Break({timeslot: "15:45", description: "30 min break"}),
  Talk({timeslot: "16:15", speaker: findSpeaker("Sander Spies")}),
  Break({timeslot: "17:00", description: "15 min break"}),
  Misc({timeslot: "17:15", description: "Talk 6"}),
  Break({timeslot: "18:00", description: "1.5 hour break"}),
  Misc({timeslot: "19:30", description: "Talk 7"}),
  Misc({timeslot: "20:30", description: "Open End / Party"})
|];

type tierData = {
  id: string,
  name: string,
  cost: int,
  amount: int,
  description: string
};

let sponsorTiers = [|
  {
    id: "main",
    name: "Main Sponsor",
    cost: 10000,
    amount: 1,
    description: {js|
- Banner next to the stage and entrance
- Headline your logo on the website
- Mention in every talk recording including voice over
- Tweet mention
- 5 tickets included
- Special cooperation with ideas on the Event
  |js}
  },
  {
    id: "regular",
    name: "Coffee & Food",
    cost: 2500,
    amount: 4,
    description: {js|
- Banner next to catering
- Logo on the Website
- Logo shown in every talk recording
- Tweet mention
- 2 tickets included
    |js}
  },
  {
    id: "supporter",
    name: "Local Supporter",
    cost: 500,
    amount: 10,
    description: {js|
- Logo on the Website
- 1 tickets included
    |js}
  }
|];
