open Util;

open Data;

[@bs.module] external style : Js.t({..}) = "./speakerDetails.module.scss";

let component = ReasonReact.statelessComponent("SpeakerDetails");

let make = (~speaker: Data.speakerData, _children) => {
  ...component,
  render: _self =>
    <div className=style##root>
      <figure className=style##figure>
        <img src=speaker.imgUrl alt=speaker.name className=style##image />
      </figure>
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
    </div>
};
