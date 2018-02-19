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
ReasonConf is a _not-for-profit_ conference [organized by
community efforts](/about/). Our goal is to provide a great
experience for attendees and speakers for an affordable
price.

By sponsoring this event, you're not only increasing your global
visibility across a community of highly ambitous React / JavaScript
developers, but you are also empowering the Reason community to
innovate in the OCaml / React / JavaScript ecosystem.

## Some Facts

We expect around **180 attendees**, including speakers and volunteers.
Our Early Bird Tickets (40x) were sold out **after just 2 days**.

This is the first conference for ReasonML, so we got some serious
attention from the JavaScript & React Twitter community. This was the
tweet activity of our [first
tweet](https://twitter.com/reasonconf/status/954084342086717441):
- **143,581** impressions
- **1,822** engagements
- **400** likes
- **154** retweets
- ...and attracted **361** followers

## Our Offer

We've created various sponsor tiers in order to be able to
provide the best value for both, companies and attendees.

Please feel free to [contact us](/contact/) if you want to
collaborate on ideas which are not covered by our sponsor
plans. We are open for collaboration!
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
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
