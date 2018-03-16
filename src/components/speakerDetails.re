open Util;

[@bs.module] external style : Js.t({..}) = "./speakerDetails.module.scss";

let component = ReasonReact.statelessComponent("SpeakerDetails");

let make = (~speaker: Data.Speaker.t, _children) => {
  ...component,
  render: _self =>
    <section
      className=style##root
      id=(Js.Option.getWithDefault("", speaker.social.githubUser))>
      <section className=style##speakerCard> <SpeakerCard speaker /> </section>
      <section className=style##description>
        <h2 className=style##name> (speaker.name |> s) </h2>
        <p className=style##company> (speaker.company |> s) </p>
        <p> (speaker.description |> s) </p>
        (
          switch speaker.talk {
          | Some(t) => <p> ("Talk: " |> s) <a href=""> (t.title |> s) </a> </p>
          | None => ReasonReact.nullElement
          }
        )
      </section>
    </section>
};
