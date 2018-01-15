[@bs.module] external style : Js.t({..}) = "./speakerCard.module.scss";

open Util;

let component = ReasonReact.statelessComponent("SpeakerCard");

let make = (~speaker: Data.speakerData, _children) => {
  ...component,
  render: _self =>
    <figure className=style##root>
      <img src=speaker.imgUrl alt=speaker.name />
      <figcaption>
        <h3 className=style##name> (speaker.name |> s) </h3>
        <p className=style##company> (speaker.company |> s) </p>
      </figcaption>
    </figure>
};
