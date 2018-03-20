open Util;

let component = ReasonReact.statelessComponent("Sponsors");

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> (s("For Sponsors")) </h1>
      <main className="leadText">
        (
          {js|
ReasonConf is the _world's first_ conference for
[ReasonML](https://reasonml.github.io), a new language on top of OCaml
designed to build highly efficient and type-safe React applications.
|js}
          |> md
        )
      </main>
      <main>
        (
          {js|
Although ReasonML is considered early tech, the conference has gained
quite some attention and support from JavaScript community around the
world:

- The [announcement
  tweet](https://twitter.com/reasonconf/status/954084342086717441)
  received **143,581** impressions, **400** likes, and attracted
  **361** followers
- We get support by leading Reason contributors as speakers and mentors
- We invited guests from the OCaml industry, such as Facebook, Bloomberg, JaneStreet & OCaml Labs
- Our Early Bird Tickets were **sold out in just two days**

ReasonConf is a **not-for-profit** conference. [The goal of the
event](/about/) is to bring the global community together. Around half
of the tickets are provided to our international communities and
notable contributors to the Reason ecosystem.
          |js}
          |> md
        )
      </main>
      <section className="grid--6col grid grid_6cols">
        <section className="grid--3col">
          (
            {js|
## ReasonConf Facts

- **Three day event** with practical workshops and a single track conference
- We expect **180 attendees**, including speakers and volunteers
- Speakers include **leading members and visionaries** of the ReasonML, JavaScript, and OCaml communities
- **International audience** with a strong focus on web-development with React
- Part of [**Diversity Tickets**](https://diversitytickets.org) by Travis Foundation
          |js}
            |> md
          )
        </section>
        <section className="grid--3col">
          (
            {js|
## 5 Reasons to Sponsor

1. High brand exposure to a highly skilled and self-motivated crowd of
   React, JavaScript & OCaml developers
1. Good networking possibilities and first level connection with the ReasonML community leaders
1. Improve the skillset of your developers and teach them new ways to improve code-quality of
   your React & JavaScript applications
1. Show off Vienna as an attractive hotspot for leading technology
1. Get a headstart in a high potential technology (while building on
   the enterprise-ready OCaml platform)
          |js}
            |> md
          )
        </section>
      </section>
      <h2> ("Sponsor Tiers" |> s) </h2>
      <main className="full sponsor-tiers">
        Data.Tier.(
          sponsorTiers
          |> Array.map(tier => <SponsorTier tier key=tier.id />)
          |> ReasonReact.arrayToElement
        )
      </main>
      <main>
        (
          {js|
If you're interested in sponsoring the event, please [contact us](/contact/). If you want to
collaborate on ideas which are not covered by our sponsor plans, please let us know!
          |js}
          |> md
        )
      </main>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
