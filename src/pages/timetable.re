open Util;

open Data;

let component = ReasonReact.statelessComponent("Timetable");

let miscRow = (misc: Schedule.misc) =>
  ReasonReact.arrayToElement([|
    <dt> (misc.timeslot |> s) </dt>,
    <dd> (misc.description |> s) </dd>
  |]);

/*
 A Break and a Misc type are structurally the same (for now).
 For semantic reasons, we still keep a different function
 name, in case we need to write a different render impl
 */
let breakRow = miscRow;

let talkRow = ({speaker, timeslot}: Schedule.lecture) =>
  ReasonReact.arrayToElement([|
    <dt> (timeslot |> s) </dt>,
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

let openEndRow = ({timeslot, description}: Schedule.openEnd) =>
  ReasonReact.arrayToElement([|
    <dt> (timeslot |> s) </dt>,
    <dd> (description |> s) </dd>
  |]);

let createRow = (slot: Data.Schedule.t) =>
  switch slot {
  | Break(v) => breakRow(v)
  | Misc(v) => miscRow(v)
  | Talk(v) => talkRow(v)
  | OpenEnd(v) => openEndRow(v)
  };

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (s("Timetable")) </h1>
      <dl>
        (
          Data.Schedule.schedule
          |> Array.map(createRow)
          |> ReasonReact.arrayToElement
        )
      </dl>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
