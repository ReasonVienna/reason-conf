open Util;

let component = ReasonReact.statelessComponent("Speakers");

let speakerRow = (i: int, speaker) =>
  <div> <SpeakerCard speaker key=(string_of_int(i)) /> </div>;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> ("Speakers" |> s) </h1>
      (Data.speakers |> Array.mapi(speakerRow) |> ReasonReact.arrayToElement)
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
