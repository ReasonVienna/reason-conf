open Util;

open Data;

let component = ReasonReact.statelessComponent("Schedule");

let miscRow = (misc: Schedule.misc) =>
  <tr>
    <td> (misc.timeslot |> s) </td>
    <td> (misc.description |> s) </td>
  </tr>;

/*
 A Break and a Misc type are structurally the same (for now).
 For semantic reasons, we still keep a different function
 name, in case we need to write a different render impl
 */
let breakRow = miscRow;

let talkRow = ({speaker, timeslot}: Schedule.lecture) =>
  <tr>
    <td> (timeslot |> s) </td>
    <td>
      <div>
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
      </div>
    </td>
  </tr>;

let createRow = (slot: Data.Schedule.t) =>
  switch slot {
  | Break(v) => breakRow(v)
  | Misc(v) => miscRow(v)
  | Talk(v) => talkRow(v)
  | LightningTalks(v) =>
    /* TODO: Render lightning talks properly*/
    miscRow({timeslot: v.timeslot, description: "Lightning Talks"})
  };

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (s("Timetable")) </h1>
      <table>
        <tbody>
          (
            Data.Schedule.schedule
            |> Array.map(createRow)
            |> ReasonReact.arrayToElement
          )
        </tbody>
      </table>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
