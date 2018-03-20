open Util;

[@bs.module] external style : Js.t({..}) = "./speakerDetails.module.scss";

module Link = Gatsby.Link;

let talkSlug = Data.Speaker.talkSlug;

let component = ReasonReact.statelessComponent("SpeakerDetails");

let make = (~speaker: Data.Speaker.t, _children) => {
  ...component,
  render: _self =>
    <section className=style##root id=(Data.Speaker.speakerAnchor(speaker))>
      <section className=style##speakerCard> <SpeakerCard speaker /> </section>
      <section className=style##description>
        <h2 className=style##name> (speaker.name |> s) </h2>
        <p className=style##company> (speaker.company |> s) </p>
        <p> (speaker.description |> s) </p>
        (
          switch speaker.talk {
          | Some(t) =>
            <p>
              ("Talk: " |> s)
              <Link to_=("/schedule/#" ++ talkSlug(t))> (t.title |> s) </Link>
            </p>
          | None => ReasonReact.nullElement
          }
        )
      </section>
    </section>
};
