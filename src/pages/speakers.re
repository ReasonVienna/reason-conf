open Util;

open Data;

[@bs.module] external style : Js.t({..}) = "./speakers.module.scss";

let component = ReasonReact.statelessComponent("Speakers");

let toSpeakerDetail = (speaker: Data.speakerData) =>
  <div key=speaker.name> <SpeakerDetails speaker /> </div>;

let make = _children => {
  ...component,
  render: _self =>
    <div className=style##root>
      <h1> ("Speakers" |> s) </h1>
      <section className=style##speaker_rows>
        (
          Data.speakers
          |> Array.map(toSpeakerDetail)
          |> ReasonReact.arrayToElement
        )
      </section>
    </div>
};

let foo = (~test: option(string)=?, ()) =>
  switch test {
  | Some(v) => Js.log(v)
  | None => Js.log("empty")
  };

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
