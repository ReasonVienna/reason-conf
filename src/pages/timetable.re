open Util;

module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./timetable.module.scss";

let component = ReasonReact.statelessComponent("Timetable");

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
## $title

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
          <section className=style##talkDetails>
            <Link
              to_=(
                "/speakers/#"
                ++ Js.Option.getWithDefault("", speaker.social.githubUser)
              )>
              <SpeakerCard speaker compact=true />
            </Link>
            (titleAndAbstractToMdString(talk) |> md)
          </section>
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
      <h1> (s("Timetable")) </h1>
      <h2> (s("Day 2")) </h2>
      <dl className=style##entries>
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
