open Util;

open Data;

let component = ReasonReact.statelessComponent("Sponsors");

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> (s("Sponsors")) </h1>
      <h2> ("Why sponsoring" |> s) </h2>
      <main>
        <p>
          (
            {js|
                    This conference aims to demonstrate that ReasonML is able
                    to be more than a niche language in the space of frontend
                    languages.  Attendees should feel motivated to introduce
                    Reason & OCaml in their professional context and also feel
                    comfortable with the currently existing tools. For that,
                    this event will provide a well balanced schedule with
                    practical & theoretical content.
                  |js}
            |> s
          )
        </p>
      </main>
      <h2> ("Sponsor Tiers" |> s) </h2>
      <main className="full sponsor-tiers">
        (
          Data.sponsorTiers
          |> Array.map((tier: Data.tierData) =>
               <SponsorTier tier key=tier.name />
             )
          |> ReasonReact.arrayToElement
        )
      </main>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
