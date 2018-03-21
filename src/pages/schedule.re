open Util;

module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./schedule.module.scss";

let component = ReasonReact.statelessComponent("Schedule");

let toTimeStr = (~fromTime, ~toTime) => {
  let format = "HH:mm";
  switch toTime {
  | Some(toTime) =>
    DateFns.format(format, fromTime)
    ++ {j| – |j}
    ++ DateFns.format(format, toTime)
  | None => DateFns.format(format, fromTime) ++ {j| – ∞|j}
  };
};

let toDurationStr = (~fromTime, ~toTime) => {
  let format = "YYYY-MM-DDTHH:mm:ss.SSSZ";
  switch toTime {
  | Some(toTime) =>
    DateFns.format(format, fromTime) ++ "/" ++ DateFns.format(format, toTime)
  | None => DateFns.format(format, fromTime)
  };
};

let titleAndAbstractToMdString = ({title, abstract}: Data.Speaker.talk) => {j|
## $title #

$abstract
|j};

let miscRow = (~fromTime, ~toTime, description) =>
  ReasonReact.arrayToElement([|
    <dt className=style##entryTime>
      <time dateTime=(toDurationStr(~fromTime, ~toTime))>
        (toTimeStr(~fromTime, ~toTime) |> s)
      </time>
    </dt>,
    <dd className=style##entryDescription> (description |> s) </dd>
  |]);

/*
 A Break and a Misc type are structurally the same (for now).
 For semantic reasons, we still keep a different function
 name, in case we need to write a different render impl
 */
let breakRow = miscRow;

let talkRow = (~fromTime, ~toTime, speaker: Data.Speaker.t) =>
  ReasonReact.arrayToElement([|
    <dt className=style##talkTime>
      <time dateTime=(toDurationStr(~fromTime, ~toTime))>
        (toTimeStr(~fromTime, ~toTime) |> s)
      </time>
    </dt>,
    <dd className=style##talkDescription>
      (
        switch speaker.talk {
        | Some(talk) =>
          let id = Data.Speaker.talkSlug(talk);
          <section className=style##talkDetails id>
            <Link to_=("/speakers/#" ++ Data.Speaker.speakerAnchor(speaker))>
              <SpeakerCard speaker compact=true />
            </Link>
            (titleAndAbstractToMdString(talk) |> md)
          </section>;
        | None => ReasonReact.nullElement
        }
      )
    </dd>
  |]);

let openEndRow = (~fromTime, description) =>
  ReasonReact.arrayToElement([|
    <dt className=style##entryTime>
      <time dateTime=(toDurationStr(~fromTime, ~toTime=None))>
        (toTimeStr(~fromTime, ~toTime=None) |> s)
      </time>
    </dt>,
    <dd className=style##entryDescription> (description |> s) </dd>
  |]);

let createRow = ({task, fromTime, toTime}: Data.Timetable.entry) =>
  switch task {
  | Break(description) => breakRow(~fromTime, ~toTime, description)
  | Misc(description) => miscRow(~fromTime, ~toTime, description)
  | Talk(speaker) => talkRow(~fromTime, ~toTime, speaker)
  | OpenEnd(description) => openEndRow(~fromTime, description)
  };

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> ("Schedule" |> s) </h1>
      <h2>
        <time dateTime="2018-05-11">
          ("11" |> s)
          <sup> ("th" |> s) </sup>
          (" May, Friday" |> s)
        </time>
      </h2>
      <main> ({js|
Will be announced soon.
          |js} |> md) </main>
      <h2>
        <time dateTime="2018-05-12">
          ("12" |> s)
          <sup> ("th" |> s) </sup>
          (" May, Saturday" |> s)
        </time>
      </h2>
      <dl className=style##entries>
        (
          Data.Timetable.day2Timetable
          |> List.map(createRow)
          |> Array.of_list
          |> ReasonReact.arrayToElement
        )
      </dl>
      <h2>
        <time dateTime="2018-05-13">
          ("13" |> s)
          <sup> ("th" |> s) </sup>
          (" May, Sunday" |> s)
        </time>
      </h2>
      <main> ({js|
Will be announced soon.
          |js} |> md) </main>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
