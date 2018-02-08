open Util;

open Data;

let component = ReasonReact.statelessComponent("Speakers");

let toSpeakerDetail = (speaker: Data.speakerData) =>
  <SpeakerDetails speaker key=speaker.name />;

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> ("Speakers" |> s) </h1>
      <main className="full">
        (
          Data.speakers
          |> Array.map(toSpeakerDetail)
          |> ReasonReact.arrayToElement
        )
      </main>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
