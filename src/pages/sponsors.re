open Util;

let component = ReasonReact.statelessComponent("Sponsors");

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> (s("For sponsors")) </h1>
      <main>
        (
          {js|
ReasonConf is the **world's first** conference for [ReasonML](https://reasonml.github.io), a new language meant to replace JavaScript in developing ambitious web applications.
Despite the fact that ReasonML is young, the conference has gained attention and support from JavaScript community around the world:

- The [announcement tweet](https://twitter.com/reasonconf/status/954084342086717441) received **143,581** impressions, **400** likes, and attracted **361** followers
- All Early Bird Tickets were **sold out in two days**
- The conference attracted multiple core members of ReasonML community as speakers and attendees

## ReasonConf Facts

- **World’s first conference** about ReasonML
- **Three day event** with practical workshops and a single track conference
- **200 attendees**, including speakers and volunteers
- Speakers include **leading members and visionaries** of the ReasonML, JavaScript, and OCaml communities
- **International audience** with a strong focus on web-development
- Part of [**Diversity Tickets**](https://diversitytickets.org) by Travis Foundation

ReasonConf is a **not-for-profit** conference. [The goal of the event](/about/) is to bring the global community together. We are giving away half of the tickets to the international communities and notable members who work on the language.

## 5 Reasons to Sponsor
1. Connect with leading JavaScript, ReasonML and OCaml  developers and community drivers
1. Support a growing, vibrant, and diverse ReasonML community
1. Discover the leading edge of web-development and align your company with it
1. Improve the skillset of your developers
1. Attract new talent to your company

## Sponsor Tiers
          |js}
          |> md
        )
      </main>
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
