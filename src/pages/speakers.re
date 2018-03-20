open Util;

let component = ReasonReact.statelessComponent("Speakers");

let toSpeakerDetail = (speaker: Data.Speaker.t) =>
  <SpeakerDetails speaker key=speaker.name />;

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <main className="full">
        <h1> ("Speakers" |> s) </h1>
        <section>
          (
            Data.Speaker.speakers
            |> Array.map(toSpeakerDetail)
            |> ReasonReact.arrayToElement
          )
        </section>
      </main>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
