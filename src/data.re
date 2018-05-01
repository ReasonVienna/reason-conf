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
external vladimirKurchatkinImg : string = "./assets/vladimir-kurchatkin.jpg";

[@bs.module]
external javierChavarriImg : string = "./assets/javier-chavarri.jpg";

[@bs.module] external glennSlotteImg : string = "./assets/glenn-slotte.jpg";

[@bs.module] external lanceHarperImg : string = "./assets/lance-harper.jpg";

[@bs.module] external maximValckeImg : string = "./assets/maxim-valcke.jpg";

[@bs.module]
external romanSchieferImg : string = "./assets/roman-schiefer.jpg";

[@bs.module]
external speakerPlaceholder : string = "./assets/speaker-placeholder.svg";

[@bs.module] external volunteerLogo : string = "./assets/volunteer-logo.svg";

[@bs.module]
external accentureLogo : string = "./assets/partners/accenture-logo.svg";

[@bs.module]
external janeStreetLogo : string = "./assets/partners/janestreet-logo.svg";

[@bs.module] external g2iLogo : string = "./assets/partners/g2i-logo.svg";

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
    twitter: string,
  };
  /* First in this list should be rendered last */
  let organizers = [
    {
      name: "Patrick Stapfer",
      imgUrl: patrickImg,
      href: "https://twitter.com/ryyppy",
      twitter: "ryyppy",
    },
    {
      name: "Nik Graf",
      imgUrl: nikImg,
      href: "https://twitter.com/nikgraf",
      twitter: "nikgraf",
    },
    {
      name: "Andrey Okonetchnikov",
      imgUrl: andreyImg,
      href: "https://twitter.com/okonetchnikov",
      twitter: "okonetchnikov",
    },
  ];
};

module Speaker = {
  type social = {
    twitterUser: option(string),
    githubUser: option(string),
    website: option(string),
  };
  type talk = {
    title: string,
    abstract: string,
  };
  type t = {
    name: string,
    company: string,
    imgUrl: string,
    description: string,
    talk: option(talk),
    social,
  };
  let talkSlug = ({title}: talk) => GithubSlugger.slug(title);
  let speakerAnchor = ({social}) =>
    Js.Option.getWithDefault("tba", social.githubUser);
  let createPlaceholder = (~company="?", ~talk=?, ~name="TBA", ()) => {
    name,
    company,
    imgUrl: speakerPlaceholder,
    description: "Details will be announced reasonably soon!",
    talk,
    social: {
      githubUser: None,
      twitterUser: None,
      website: None,
    },
  };
  let chengLou = {
    name: "Cheng Lou",
    company: "Facebook",
    imgUrl: chengLouImg,
    description: {j|I work on Reason and Facebook Messenger|j},
    talk: Some({title: "Keynote", abstract: ""}),
    social: {
      githubUser: Some("chenglou"),
      twitterUser: Some("_chenglou"),
      website: None,
    },
  };
  let keiraHodgkison = {
    name: "Keira Hodgkison",
    company: "Culture Amp",
    imgUrl: keiraHodgkisonImg,
    description: {j|
Keira is a developer at Culture Amp, the world's
leading culture analytics platform. She works with React, Flow,
and Rails on solutions to help customers share, and act upon
company employee engagement data. Keira is an advocate for using
functional programming techniques to improve the JavaScript
coding and refactoring experience. When she's not writing code,
she can be found under a large cat.
       |j},
    talk:
      Some({
        title: {j|What’s not to love about Reason?|j},
        abstract: {j|
Even though Reason looks like JavaScript with a few
additional functional features and semantics, it's sometimes
easy to forget that it's a completely different language,
with different problems.

This talk looks at life on the bleeding edge, as experienced by a
not-so-functional programmer.
       |j},
      }),
    social: {
      githubUser: Some("keirah"),
      twitterUser: Some("keirasaid"),
      website: None,
    },
  };
  let cristianoCalcagno = {
    name: "Cristiano Calcagno",
    company: "Facebook",
    imgUrl: cristianoCalcagnoImg,
    description: {j|
Engineer at Facebook.
Co-creator of @fbinfer, founder of Monoidics, reformed academic.
Into developer experience, front-end, static analysis, language design.
Early @reasonml adopter, co-creator of ReasonReact.
       |j},
    talk:
      Some({
        title: "ReasonReact and local state",
        abstract: {j|
The talk introduces ReasonReact and the way it operates on the state
of React components.  This is illustrated by introducing the notion of
local state presented via a series of examples.

State is changed by means of reducers, that can operate directly on
the current component, or on distant components via remote actions.

Further examples illustrate how certain animations can be considered
instances of local state that can be easily composed.
|j},
      }),
    social: {
      githubUser: Some("cristianoc"),
      twitterUser: Some("ccrisccris"),
      website: None,
    },
  };
  let lauraGaetano = {
    name: "Laura Gaetano",
    company: "Travis Foundation",
    imgUrl: lauraGaetanoImg,
    /* TODO: CHECK BACK WITH LAURA TO UPDATE THE DESCRIPTION */
    description: {j|
Laura is a manager at Travis Foundation and the
organiser of [Rails Girls Summer of Code](https://railsgirlssummerofcode.org/) --
a 3-month scholarship
program to support women in the Open Source community. With a
background in the visual arts and a non-traditional career path,
she landed in tech as a web developer somewhat by
accident. Laura is passionate about making things, coaching at
programming workshops, Open Source software, feminism, music and
space (as in rockets).
       |j},
    talk:
      Some({
        title: "Building inclusive Open Source communities",
        abstract: {j|
Tech has a diversity problem: marginalised people are being pushed out
of the industry; their voices and experiences are erased. Open Source
is particularly bad, with too few contributors who aren’t white, male,
cisgender and able-bodied.

What if things were different? What if we could create spaces that are
welcoming, where we show empathy and compassion? What if those
qualities could reflect in our work, ultimately helping us create
better software?

In this talk, you will hear stories of first-time contributions,
successful examples in supporting and mentoring newcomers, and find
out steps you can take as an Open Source contributor or maintainer to
make your community more inclusive.
|j},
      }),
    social: {
      githubUser: Some("alicetragedy"),
      twitterUser: Some("alicetragedy"),
      website: Some("http://www.alicetragedy.org/"),
    },
  };
  let sanderSpies = {
    name: "Sander Spies",
    company: "Independent",
    imgUrl: sanderSpiesImg,
    description: {j|As a developer always focusing on the reader of
      the code. Fell in love with React in 2013 because of the
      simplification it brought to state management. Regrets asking
      for Flux. Big fan of CSS-in-JS and currently lost in
      OCaml. Strongly believes in the importance of moving developers
      to Reason as it removes a lot of the burdens that JavaScript
      developers face daily. Can be blamed for several things in
      Reason like JSX. Reason fan since day one.|j},
    talk:
      Some({
        title: {j|Down the WebAssembly rabbit hole|j},
        abstract: {j|
In this talk we go beyond syntax and look at an experimental
webassembly backend for OCaml / ReasonML.
|j},
      }),
    social: {
      githubUser: Some("SanderSpies"),
      twitterUser: Some("Sander_Spies"),
      website: None,
    },
  };
  let vladimirKurchatkin = {
    name: "Vladimir Kurchatkin",
    company: {j|Backend Developer at Lazada|j},
    description: "OCaml enthusiast, Node.js and Flow contributor",
    imgUrl: vladimirKurchatkinImg,
    talk:
      Some({
        title: {j|Building native Node.js addons in Reason|j},
        abstract: {j|
Reason community is growing rapidly, and a lot of people are
interested in leveraging it on their servers. One way to achieve this
is to use native OCaml compiler. It produces exceptionally performant
binaries, but the native ecosystem is scarce, and you will struggle
with finding solutions for very common tasks.

Another option is to use BuckleScript and compile everything to
JavaScript. You would regain access to the vast Node.js ecosystem but
would have to sacrifice performance. It seems that you have to choose
either ecosystem or performance.

In this talk, I will show how to preserve both by compiling Reason
code to native Node.js addons. I will present a toolkit that makes it
easy and fun, walk through its features and examples and talk a bit
about its internals and advanced OCaml features used.
|j},
      }),
    social: {
      githubUser: Some("vkurchatkin"),
      twitterUser: Some("vkurchatkin"),
      website: None,
    },
  };
  let javierChavarri = {
    name: {j|Javier Chávarri|j},
    company: {j|Tech Lead at Webflow|j},
    description: {j|
Javi is Tech Lead at Webflow. He also helps improving the Reason IDE tooling, in particular the OCaml language server and the VSCode extension.
Came to Reason led by the interest in finding better ways to create and maintain software. Stayed for the community (and OCaml!).
Excited about what will happen when Reason and BuckleScript keep removing boundaries between native and web.
       |j},
    imgUrl: javierChavarriImg,
    talk:
      Some({
        title: {j|State of the Reason Editor integration|j},
        abstract: {j|
We will review the current state of the IDE tooling for Reason:
- Editors (and OSs) supported
- How the different parts work (language clients and the main language server) and their repositories
- Quick review of the differences between ocamlmerlin and bsb when it comes to IDE integration.
- Finally, we will briefly look into the features that could be built next, steered by the community needs
|j},
      }),
    social: {
      githubUser: Some("jchavarri"),
      twitterUser: Some("javierwchavarri"),
      website: None,
    },
  };
  let glennSlotte = {
    name: "Glenn Slotte",
    imgUrl: glennSlotteImg,
    company: "Freelance Code Monkey",
    description: {j|
Glenn is probably one of the most mysterious figures
in the Reason community. He contributed essential bindings for the
Reason and BuckleScript ecosystem (bs-jest, bs-fetch, bs-json,...) and he
is also the creator of redex.github.io.
|j},
    talk: Some({title: "TBA", abstract: "TBA"}),
    social: {
      githubUser: Some("glennsl"),
      twitterUser: None,
      website: None,
    },
  };
  let lanceHarper = {
    name: "Lance Harper",
    imgUrl: lanceHarperImg,
    company: "Independent",
    description: {j| Growth focused engineer who loves building mobile experiences |j},
    talk:
      Some({
        title: {j|Reason coming from F#|j},
        abstract: {j|
F# has been a powerful language based on OCaml without mainstream
adoption. Let's discuss their differences.
         |j},
      }),
    social: {
      githubUser: Some("lanceharper"),
      twitterUser: None,
      website: None,
    },
  };
  let maximValcke = {
    name: "Maxim Valcke",
    imgUrl: maximValckeImg,
    company: {j|Software engineer at PieSync|j},
    description: {j|
Syncing contacts at PieSync by day, submitting PR's to Reason at
night. When not coding he likes to practise Spanish and get very tired
doing this thing called triathlon, sometimes simultaneously.
       |j},
    talk:
      Some({
        title: {j|Practical Interpretation of Code Formatting|j},
        abstract: {j|
Today every major language has some kind of library that helps a
developer formatting his or her code. Tools like Prettier, Gofmt and
Refmt are setting new standards and have a deep impact on our day to
day programming.

But what does it actually mean to format code?  Does it mean pressing
a magical button to align your code? Is it more than the automatic
insertion of trailing commas your colleague always seems to forget?
Why are we even doing it? How is it going to impact us as programmers
to get better?

"Code formatting" is an opaque ocean, we’ve done a really poor job
at explaining what code formatting actually means in today’s
world. The recent hype around code formatting tools defaults us into
thinking that we can’t live without them anymore. We need to stop and
ask why we’re using these tools. Is it really the best course of
action?

Based on my experience contributing to Reason over the past 1.5 years,
this lightning talk will be a short, critical deep dive in the past,
present & future of our beloved Reason formatter Refmt.
|j},
      }),
    social: {
      githubUser: Some("iwankaramazow"),
      twitterUser: Some("_iwan_refmt"),
      website: None,
    },
  };
  let seanGrove = {
    name: "Sean Grove",
    company: "Co-founder of onegraph.com",
    imgUrl: seanImg,
    description: {j|
Sean's been hacking on devtools, debuggers, unikernels, scrapers,
graphical tools, and apartment designers in ClojureScript, ReasonML,
and Rust for years, alongside giving talks on various kinds of tech,
all while shipping business products that handle millions in
revenue. It's mostly been luck though, he continues to spend late nights staring at the computer perplexed about how anything he writes works.
|j},
    talk:
      Some({
        title: {j|Having your cake and eating it too — GraphQL in Reason|j},
        abstract: {j|
Traditionally, soundly typed-language are warm and cozy in their own
world, but as soon as they have to deal with the outside world (say,
talking to a REST API), the pain quickly sets in: trying to keep a
type definition in sync with a moving external service, manual
conversion back and forth, and lots of boilerplate.

Well no more! Proper GraphQL support in ReasonML libraries means that
we can have full-stack safety, knowing that if our programs compile,
the server can satisfy our requirements! And on top of that, we get
all the other GraphQL goodies, like tooling, in-editor auto-complete,
and fantastic compile-time optimizations, for free!

But what about the server-side, you ask? There are so many places
things can go wrong when trying to maintain the promises you give to
your GraphQL clients, I hear you cry out.

Dry your eyes, friend, for ocaml-graphql-server is here to guide you
to the happy full-stack GraphQL+Reason world you've been dreaming of,
where whole classes of errors are eliminated.

As in any good talk however, we'll also take a look at some of the
painful points of this approach, and how ReasonML might make some
tasks more difficult, so that you can leave with a confident
understanding of whether this new frontier is one you want to
brave any time soon.
|j},
      }),
    social: {
      githubUser: Some("sgrove"),
      twitterUser: Some("sgrove"),
      website: Some("http://www.riseos.com/"),
    },
  };
  let jaredForsyth = {
    name: "Jared Forsyth",
    company: "Khan Academy",
    imgUrl: jaredImg,
    description: {j|
Jared is one of the hosts of the ReasonTown podcast, and
contributes to Reason core. He works at Khan Academy doing
mobile and web development, using React and React Native
alongside native Java and Swift. He loves type systems and
learning new languages, and is deeply invested in improving the
experience of programming for everyone.
|j},
    talk:
      Some({
        title: {j|Why We’re Afraid of Change|j},
        abstract: {j|
Would you rather have a community like npm, where there are hundreds
of thousands of packages, but very few feel stable, or one like opam,
with only a few thousand packages and a much more rigorous vetting
system? How do language and community decisions affect the pull
between security and freedom, safety and agility? Can we design a
system that gives us both?

Come learn about how tools, language features, and community
structures all impact the "feel" of a developer community, and what
tricks Reason could borrow from other communities to ensure that we
can have freedom to publish without fearing change.
|j},
      }),
    social: {
      githubUser: Some("jaredly"),
      twitterUser: Some("jaredforsyth"),
      website: Some("https://jaredforsyth.com"),
    },
  };
  let romanSchiefer = {
    name: "Roman Schiefer",
    company: "Accenture",
    imgUrl: romanSchieferImg,
    description: {j|
Roman, based in Vienna, is Technology Architect inside Accenture’s
Emerging Technologies domain. Together with his domain he brings new
technologies to large scale enterprises all around the world. Roman’s
focus lies on Web- and Cloud-Native-Technologies as well as other
Software-Innovation topics. He is currently managing a Reason
implementation for a large client.
       |j},
    talk:
      Some({
        title: "Using Reason in traditional Enterprises",
        abstract: {j|
Bringing new technologies to large-scale enterprises is a challenge in
which we are involved quite often. In this talk we will reflect on our
current experience with Reason based on a real implementation.
       |j},
      }),
    social: {
      githubUser: Some("RSchiefer"),
      twitterUser: Some("RSchiefer"),
      website: None,
    },
  };
  let tbaSpeaker =
    createPlaceholder(
      ~talk={title: "A small enterprise case-study", abstract: "TBA"},
      ~company="Accenture",
      (),
    );
  let headlineSpeakers = [|
    chengLou,
    keiraHodgkison,
    cristianoCalcagno,
    lauraGaetano,
  |];
  let otherSpeakers = [|
    sanderSpies,
    vladimirKurchatkin,
    javierChavarri,
    romanSchiefer,
    lanceHarper,
    maximValcke,
    seanGrove,
    jaredForsyth,
  |];
  let speakers: array(t) = Array.concat([headlineSpeakers, otherSpeakers]);
};

module Timetable = {
  type task =
    | Talk(Speaker.t)
    | Misc(string)
    | Break(string)
    | Workshop(list(Speaker.t))
    | OpenEnd(string);
  type step = {
    task,
    duration: option(int),
  };
  type entry = {
    task,
    fromTime: Js.Date.t,
    toTime: option(Js.Date.t),
    duration: option(int),
  };
  let addDuration = (time, duration) =>
    switch (duration) {
    | Some(d) => DateFns.addMinutes(float_of_int(d), time)
    | None => time
    };
  let day1StartEntry = {
    let day2Start = Js.Date.fromString("2018-05-11T11:00:00.000+02:00");
    let duration = Some(60);
    let fromTime = day2Start;
    let toTime = Some(addDuration(day2Start, duration));
    {
      task: Misc("Doors open, Registration & Editor Setup"),
      fromTime,
      toTime,
      duration,
    };
  };
  let day2StartEntry = {
    let day2Start = Js.Date.fromString("2018-05-12T11:00:00.000+02:00");
    let duration = Some(60);
    let fromTime = day2Start;
    let toTime = Some(addDuration(day2Start, duration));
    {task: Misc("Doors open & Registration"), fromTime, toTime, duration};
  };
  let day1Steps = [
    {
      task: Workshop([Speaker.seanGrove, Speaker.jaredForsyth]),
      duration: Some(180),
    },
    {task: Break("Lunch"), duration: Some(60)},
    {
      task: Workshop([Speaker.seanGrove, Speaker.jaredForsyth]),
      duration: Some(240),
    },
    {task: OpenEnd("Open End"), duration: None},
  ];
  let day2Steps = [
    {task: Talk(Speaker.chengLou), duration: Some(45)},
    {task: Break("Coffee break"), duration: Some(30)},
    {task: Talk(Speaker.cristianoCalcagno), duration: Some(45)},
    {task: Talk(Speaker.lauraGaetano), duration: Some(45)},
    {task: Break("Lunch"), duration: Some(90)},
    {task: Talk(Speaker.sanderSpies), duration: Some(45)},
    {task: Talk(Speaker.javierChavarri), duration: Some(15)},
    {task: Talk(Speaker.romanSchiefer), duration: Some(15)},
    {task: Talk(Speaker.lanceHarper), duration: Some(15)},
    {task: Talk(Speaker.maximValcke), duration: Some(15)},
    {task: Break("Coffee  break"), duration: Some(30)},
    {task: Talk(Speaker.seanGrove), duration: Some(45)},
    {task: Talk(Speaker.vladimirKurchatkin), duration: Some(45)},
    {task: Break("Coffee  break"), duration: Some(30)},
    {task: Talk(Speaker.jaredForsyth), duration: Some(45)},
    {task: Talk(Speaker.keiraHodgkison), duration: Some(45)},
    {task: OpenEnd("Open End / Party"), duration: None},
  ];
  let calcStep = (pre: entry, step: step) : entry => {
    let fromTime = addDuration(pre.fromTime, pre.duration);
    let toTime =
      switch (step.duration) {
      | None => None
      | Some(_) => Some(addDuration(fromTime, step.duration))
      };
    {task: step.task, duration: step.duration, fromTime, toTime};
  };
  let rec calcTimetable = (pre: entry, steps: list(step)) : list(entry) =>
    switch (steps) {
    | [s, ...rest] =>
      let next = calcStep(pre, s);
      [next, ...calcTimetable(next, rest)];
    | [] => []
    };
  /* This is just for debugging a table,.. also a good inspiration
     on how to interpret table data */
  let logTimetable = (table: list(entry)) : unit =>
    List.iter(
      (r: entry) => {
        let task =
          switch (r.task) {
          | Talk(speaker) => speaker.name
          | Misc(msg) => msg
          | Break(msg) => msg
          | Workshop(speakers) =>
            speakers
            |> List.map((speaker: Speaker.t) => speaker.name)
            |> String.concat(" ")
          | OpenEnd(msg) => msg
          };
        let fromTime = DateFns.format("DD.MM, HH:mm", r.fromTime);
        let duration =
          switch (r.duration) {
          | Some(d) => {j| ($d min)|j}
          | None => ""
          };
        let timeRange =
          switch (r.toTime) {
          | Some(time) =>
            let toTime = DateFns.format("HH:mm", time);
            {j|$fromTime - $toTime$duration|j};
          | None => fromTime
          };
        Js.log3(task, " ", timeRange);
      },
      table,
    );
  let day1Timetable = [
    day1StartEntry,
    ...calcTimetable(day2StartEntry, day1Steps),
  ];
  let day2Timetable = [
    day2StartEntry,
    ...calcTimetable(day2StartEntry, day2Steps),
  ];
};

module Tier = {
  type tier =
    | Gold
    | Catering
    | LocalSupport
    | Partner;
  type t = {
    id: string,
    name: string,
    cost: int,
    amount: int,
    description: string,
  };
  let sponsorTiers: array(t) = [|
    {
      id: "main",
      name: "Gold Sponsor",
      cost: 5000,
      amount: 1,
      description: {js|
- Banner placement of your choice (stage, entrance and / or catering)
- Logo on our website in the sponsor headline
- Logo shown in every talk recording & voiceover with a message of your choice
- Tweet mention
- Job offer placement on our job-board
- 3 tickets included (1050€)
- Special cooperation to realize your own ideas at the conference
  (booth, raffles, games, code-challenges, etc.)
  |js},
    },
    {
      id: "regular",
      name: "Coffee & Food",
      cost: 2500,
      amount: 3,
      description: {js|
- Banner placement at our catering
- Logo on our website
- Logo shown in every talk recording
- Tweet mention
- Job offer placement on our job-board
- 2 tickets included (700€)
    |js},
    },
    {
      id: "supporter",
      name: "Local Supporter",
      cost: 1000,
      amount: 10,
      description: {js|
- Logo on the Website
- 1 sponsoring package for the ReasonVienna meetup
- Job offer placement on our job-board
- 1 ticket included (350€)
    |js},
    },
  |];
};

module Job = {
  type logo = {
    src: string,
    width: string,
  };
  type company = {
    logo: option(logo),
    href: string,
    descMd: string,
  };
  type tier = Tier.tier;
  type location =
    | Nothing
    | RemoteOnly
    | OnSite(string)
    | RemoteAndOnSite(string);
  type jobAd = {
    location,
    desc: string,
    href: string,
  };
  type t = {
    tier,
    company,
    jobAds: array(jobAd),
  };
  let data: array(t) = [|
    {
      company: {
        logo: Some({src: accentureLogo, width: "300px"}),
        descMd: {js|
Accenture is a leading global professional services company, providing
a broad range of services and solutions in strategy, consulting,
digital, technology and operations.

Combining unmatched experience and specialized skills across more than
40 industries and all business functions – underpinned by the world’s
largest delivery network – Accenture works at the intersection of
business and technology to help clients improve their performance and
create sustainable value for their stakeholders.

With approximately 442,000 people serving clients in more than 120
countries, Accenture drives innovation to improve the way the world
works and lives.

Visit us at <a href="https://www.accenture.com" target="_blank">www.accenture.com</a>
         |js},
        href: {j|https://www.accenture.com/|j},
      },
      tier: Gold,
      jobAds: [|
        {
          location: OnSite("Vienna, Austria"),
          desc: "Consultant / Emerging Technology Innovation",
          href: {j|https://www.accenture.com/at-de/careers/jobdetails?id=00574672_de&title=Beraterin+%2f+Berater+im+Bereich+Emerging+Technology+Innovation&keyword=HJ_TEC|J_TEC|HJ_JAV|J_JAV|Technologieberaterin|Technologieberater|J_TECARCH|j},
        },
      |],
    },
    {
      company: {
        logo: Some({src: janeStreetLogo, width: "300px"}),
        descMd: {js|
Jane Street is a quantitative trading firm and the largest industrial
user of OCaml, a functional programming language with a sophisticated
type system.

The company has more more than 250 developers writing
OCaml to build reliable, high-performance software at massive scale,
including critical systems that trade $13 billion in global equities
every day.

Jane Street developers help define the next generation of
the OCaml compiler and actively maintain nearly 100 open source
projects. The company has offices in New York, London, Hong Kong, and
Amsterdam.
         |js},
        href: {j|https://www.janestreet.com/|j},
      },
      tier: Catering,
      jobAds: [|
        {
          location: OnSite("NYC, London, Hong Kong"),
          desc: "Software Developer - Functional Programming",
          href:
            Gatsby.Link.withPrefix(
              {j|jobs/janestreet_software_developer.pdf|j},
            ),
        },
        {
          location: Nothing,
          desc: "Other open positions",
          href: {j|https://www.janestreet.com/open-positions/|j},
        },
      |],
    },
    {
      company: {
        logo: Some({src: g2iLogo, width: "80px"}),
        descMd: {js|
G2i offers USA, European, and South American based web and mobile
developers that can become part of your team at reasonable rates.

Our devs are experienced with React, React Native, GraphQL, Node.js,
and Android/iOS.|js},
        href: {j|http://g2i.co/|j},
      },
      tier: LocalSupport,
      jobAds: [|
        {
          location: OnSite("San Francisco"),
          desc: "Senior React Engineer",
          href: {j|https://jobs.lever.co/g2i/d62d9cf2-67d4-42d4-a034-584acd5d277f|j},
        },
        {
          location: RemoteOnly,
          desc: "React/Redux + Node/Rails Full Stack Developer",
          href: {j|https://jobs.lever.co/g2i/f6588986-eda0-4192-aa5c-9949ff509fa0|j},
        },
        {
          location: RemoteOnly,
          desc: "React Native Engineer",
          href: {j|https://jobs.lever.co/g2i/58bf69ab-f263-4750-9023-9b88bee37159|j},
        },
        {
          location: RemoteOnly,
          desc: "Remote Node Engineer",
          href: {j|https://jobs.lever.co/g2i/90988547-6a17-438c-acee-99d27fc94dd9|j},
        },
      |],
    },
  |];
};
