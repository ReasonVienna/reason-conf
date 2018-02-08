open Util;

[@bs.module] external style : Js.t({..}) = "./about.module.scss";

[@bs.module]
external reasonViennaLogo : string = "../assets/partners/reasonvienna.svg";

[@bs.module]
external reactViennaLogo : string = "../assets/partners/reactvienna-logo.svg";

let component = ReasonReact.statelessComponent("About");

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> ("About ReasonConf" |> s) </h1>
      <h2> ("Mission" |> s) </h2>
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
        <p>
          (
            {js|
              Another goal is to bring together contributors, lead developers and
              community drivers of the Reason, ReasonReact and OCaml
              platform. During the conference there will be enough time to discuss,
              innovate and synchronize on important topics on the roadmap. Besides
              formalities, this is also a great opportunity to finally meet people
              in person instead of chatting on Twitter or Discord.
            |js}
            |> s
          )
        </p>
        <p>
          (
            {js|
            To close our mission statement, attendees demonstrate that the Reason
            community is for everyone. We encourage diversity, establish a strong
            community guideline for a harassment free, more diverse environment
            and want to offer our platform to give a voice to everybody.
          |js}
            |> s
          )
        </p>
      </main>
      <h2> ("Organizers" |> s) </h2>
      <main>
        <Organizers organizers=Data.organizers />
        <p>
          (
            {js|
              We are the organizers of the ReasonVienna community,
              an offspring of ReactVienna. Both organizations are dedicated
              to support the exchange of knowledge and to raise new talents in
              the Austrian web developer community, with a strong focus on Facebook’s
              UI library ReactJS.
           |js}
            |> s
          )
        </p>
      </main>
      <aside className=style##logos>
        <a href="https://twitter.com/reasonvienna">
          <img src=reasonViennaLogo alt="Reason Vienna Logo" />
        </a>
        <a href="https://twitter.com/reactvienna">
          <img src=reactViennaLogo alt="React Vienna Logo" />
        </a>
      </aside>
      <main />
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
