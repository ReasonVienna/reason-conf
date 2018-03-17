open Util;

open Data;

let component = ReasonReact.statelessComponent("Timetable");

let toTimeStr = datetime => DateFns.format("HH:mm", datetime);

let miscRow = (~fromTime, ~toTime, ~duration, description) =>
  ReasonReact.arrayToElement([|
    <dt> <time dateTime=""> (toTimeStr(fromTime) |> s) </time> </dt>,
    <dd> (description |> s) </dd>
  |]);

/*
 A Break and a Misc type are structurally the same (for now).
 For semantic reasons, we still keep a different function
 name, in case we need to write a different render impl
 */
let breakRow = miscRow;

let talkRow = (~fromTime, ~toTime, ~duration, speaker: Data.Speaker.t) =>
  ReasonReact.arrayToElement([|
    <dt> <time dateTime=""> (toTimeStr(fromTime) |> s) </time> </dt>,
    <dd>
      (
        switch speaker.talk {
        | Some(talk) =>
          <section>
            <h2> (talk.title |> s) </h2>
            <p> (talk.abstract |> s) </p>
          </section>
        | None => ReasonReact.nullElement
        }
      )
      <SpeakerCard speaker />
    </dd>
  |]);

let openEndRow = (~fromTime, description) =>
  ReasonReact.arrayToElement([|
    <dt> <time dateTime=""> (toTimeStr(fromTime) |> s) </time> </dt>,
    <dd> (description |> s) </dd>
  |]);

let createRow = ({task, fromTime, toTime, duration}: Data.Timetable.entry) =>
  switch task {
  | Break(description) => breakRow(~fromTime, ~toTime, ~duration, description)
  | Misc(description) => miscRow(~fromTime, ~toTime, ~duration, description)
  | Talk(speaker) => talkRow(~fromTime, ~toTime, ~duration, speaker)
  | OpenEnd(description) => openEndRow(~fromTime, description)
  };

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (s("Timetable")) </h1>
      <dl>
        (
          Data.Timetable.day2Timetable
          |> List.map(createRow)
          |> Array.of_list
          |> ReasonReact.arrayToElement
        )
      </dl>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
