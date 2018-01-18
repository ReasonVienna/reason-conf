open Util;

open Data;

[@bs.module] external style : Js.t({..}) = "./speakers.module.scss";

let component = ReasonReact.statelessComponent("Speakers");

let toSpeakerDetail = (speaker: Data.speakerData) =>
  <li key=speaker.name className=style##listItem>
    <SpeakerDetails speaker />
  </li>;

let make = _children => {
  ...component,
  render: _self =>
    <div className=style##root>
      <h1> ("Speakers" |> s) </h1>
      <ul className=style##list>
        (
          Data.speakers
          |> Array.map(toSpeakerDetail)
          |> ReasonReact.arrayToElement
        )
      </ul>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
