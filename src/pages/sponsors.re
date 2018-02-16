open Util;

open Data;

let component = ReasonReact.statelessComponent("Sponsors");

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> (s("For sponsors")) </h1>
      <main>
        (
          {js|
ReasonConf is a _not-for-profit_ conference [organized by community efforts](/about/).
Our goal is to provide great experience for attendees and speakers at an affordable price.

## This is why we need your help!

By sponsoring this event, you're not only getting a visibility across
best developers from around the world but also supporting the future of web-development.

We've carefully crafted our sponsor tiers in order to be able to provide maximum value for both
companies and event visitors. That being said, we're open for different ways of collaboration.
Please feel free to [contact us](/contact/) if you have additional ideas.|js}
          |> md
        )
      </main>
      <main className="full sponsor-tiers">
        (
          Data.sponsorTiers
          |> Array.map(tier => <SponsorTier tier key=tier.id />)
          |> ReasonReact.arrayToElement
        )
      </main>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
