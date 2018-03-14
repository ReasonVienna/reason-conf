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

[@bs.module] external seanImg : string = "./assets/sean-grove.jpg";

[@bs.module] external jaredImg : string = "./assets/jared-forsyth.jpg";

[@bs.module]
external speakerPlaceholder : string = "./assets/speaker-placeholder.svg";

[@bs.module] external volunteerLogo : string = "./assets/volunteer-logo.svg";

/* List.find_opt is not supported by this BuckleScript version yet */
let find_opt = (fn, l) =>
  try (List.find(fn, l) |> (r => Some(r))) {
  | Not_found => None
  };

module Organizer = {
  type t = {
    name: string,
    imgUrl: string,
    href: string,
    twitter: string
  };
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
};

module Speaker = {
  type social = {
    twitterUser: option(string),
    githubUser: option(string),
    website: option(string)
  };
  type talk = {
    title: string,
    abstract: string
  };
  type t = {
    name: string,
    company: string,
    imgUrl: string,
    description: string,
    talk: option(talk),
    social
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
      talk:
        Some({title: {j|What's not to love about Reason?|j}, abstract: "TBA"}),
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
  let speakers: array(t) = Array.concat([headlineSpeakers, otherSpeakers]);
  let workshopLeaders: array(t) = [|
    {
      name: "Sean Grove",
      company: "onegraph.com",
      imgUrl: seanImg,
      description: "",
      talk: None,
      social: {
        githubUser: Some("sgrove"),
        twitterUser: Some("sgrove"),
        website: Some("http://www.riseos.com/")
      }
    },
    {
      name: "Jared Forsyth",
      company: "Khan Academy",
      imgUrl: jaredImg,
      description: "",
      talk: None,
      social: {
        githubUser: Some("jaredly"),
        twitterUser: Some("jaredforsyth"),
        website: Some("https://jaredforsyth.com")
      }
    }
  |];
  let createPlaceholder = name => {
    name,
    company: "?",
    imgUrl: speakerPlaceholder,
    description: "",
    talk: None,
    social: {
      githubUser: None,
      twitterUser: None,
      website: None
    }
  };
  let findSpeaker = (name: string) => {
    let result = Array.to_list(speakers) |> find_opt(s => s.name == name);
    switch result {
    | None => createPlaceholder(name)
    | Some(s) => s
    };
  };
};

module Schedule = {
  type timeslot = string;
  type lecture = {
    timeslot,
    speaker: Speaker.t
  };
  type misc = {
    timeslot,
    description: string
  };
  type t =
    | Talk(lecture)
    | Misc(misc)
    | Break(misc);
  let schedule: array(t) = [|
    Misc({timeslot: "09:00", description: "Doors open & Registration"}),
    Talk({timeslot: "10:00", speaker: Speaker.findSpeaker("Cheng Lou")}),
    Break({timeslot: "10:45", description: "30 min break"}),
    Talk({
      timeslot: "11:15",
      speaker: Speaker.findSpeaker("Cristiano Calcagno")
    }),
    Talk({timeslot: "12:00", speaker: Speaker.findSpeaker("Laura Gaetano")}),
    Break({timeslot: "13:15", description: "1.5 hour lunch break"}),
    Talk({
      timeslot: "14:00",
      speaker: Speaker.createPlaceholder("Lightning Talks")
    }),
    Break({timeslot: "15:00", description: "30 min break"}),
    Talk({timeslot: "15:30", speaker: Speaker.createPlaceholder("Talk 6")}),
    Talk({timeslot: "16:15", speaker: Speaker.createPlaceholder("Talk 7")}),
    Break({timeslot: "17:00", description: "30 min break"}),
    Talk({timeslot: "17:45", speaker: Speaker.createPlaceholder("Talk 8")}),
    Talk({timeslot: "18:30", speaker: Speaker.findSpeaker("Keira Hodgkison")}),
    Misc({timeslot: "19:15", description: "Open End / Party"})
  |];
};

module Tier = {
  type tier =
    | Gold
    | Catering
    | LocalSupport;
  type t = {
    id: string,
    name: string,
    cost: int,
    amount: int,
    description: string
  };
  let sponsorTiers: array(t) = [|
    {
      id: "main",
      name: "Gold Sponsor",
      cost: 5000,
      amount: 2,
      description: {js|
- Banner placement of your choice (stage, entrance and / or catering)
- Logo on our website in the sponsor headline
- Logo shown in every talk recording & voiceover with a message of your choice
- Tweet mention
- Job offer placement on our [job-board](/jobs)
- 3 tickets included (1050€)
- Special cooperation to realize your own ideas at the conference
  (booth, raffles, games, code-challenges, etc.)
  |js}
    },
    {
      id: "regular",
      name: "Coffee & Food",
      cost: 2500,
      amount: 4,
      description: {js|
- Banner placement at our catering
- Logo on our website
- Logo shown in every talk recording
- Tweet mention
- Job offer placement on our [job-board](/jobs)
- 2 tickets included (700€)
    |js}
    },
    {
      id: "supporter",
      name: "Local Supporter",
      cost: 1000,
      amount: 10,
      description: {js|
- Logo on the Website
- 1 sponsoring package for the ReasonVienna meetup
- Job offer placement on our [job-board](/jobs)
- 1 ticket included (350€)
    |js}
    }
  |];
};

module Job = {
  type logo = {
    src: string,
    width: string
  };
  type company = {
    logo: option(logo),
    href: string,
    descMd: string
  };
  type onsite = {
    city: string,
    country: string
  };
  type tier = Tier.tier;
  type location =
    | RemoteOnly
    | OnSite(onsite)
    | RemoteAndOnSite(onsite);
  type jobAd = {
    location,
    desc: string,
    href: string
  };
  type t = {
    tier,
    company,
    jobAds: array(jobAd)
  };
  let data: array(t) = [|
    {
      company: {
        logo: Some({src: volunteerLogo, width: "300px"}),
        descMd: {js|
### <a href="https://www.reason-conf.com" target="_blank">ReasonConf</a>

We are still looking for volunteers to help us during the conference.
As a mentor, you offer your Reason skills to help attendees during the workshop
and hackathon days (find syntax errors, fix editor problems, etc.).

Also we are looking for local volunteers to help us out with organizational
tasks, like managing our speakers during their stay in Vienna or assisting
the organizers during the conference day (giving out lanyards, assisting our
gold sponsors on site, etc.).

We are also looking for experienced Viennese locals to help us with
the Vienna tour on the last day.

By volunteering, you get free access to the conference (you can pick
certain times to have a break and enjoy the conference).

Use the links below to apply.
         |js},
        href: {j|https://www.reason-conf.com|j}
      },
      tier: LocalSupport,
      jobAds: [|
        {
          location: OnSite({city: "Vienna", country: "Austria"}),
          desc: "Mentor for Workshop & Hackathon Days",
          href: {j|mailto:hi@reason-conf.com?subject=Applying as a Mentor|j}
        },
        {
          location: OnSite({city: "Vienna", country: "Austria"}),
          desc: "Local Volunteer",
          href: {j|mailto:hi@reason-conf.com?subject=Applying as a Volunteer|j}
        }
      |]
    }
  |];
};
