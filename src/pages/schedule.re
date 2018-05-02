open Util;

module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./schedule.module.scss";

let talkSlug = Data.Speaker.talkSlug;

let component = ReasonReact.statelessComponent("Schedule");

let toTimeStr = (~fromTime, ~toTime) =>
  switch (toTime) {
  | Some(toTime) => toHHMM(fromTime) ++ {j| – |j} ++ toHHMM(toTime)
  | None => toHHMM(fromTime) ++ {j| – ∞|j}
  };

let toDurationStr = (~fromTime, ~toTime) => {
  let format = "YYYY-MM-DDTHH:mm:ss.SSSZ";
  switch (toTime) {
  | Some(toTime) =>
    DateFns.format(format, fromTime) ++ "/" ++ DateFns.format(format, toTime)
  | None => DateFns.format(format, fromTime)
  };
};

let miscRow = (~fromTime, ~toTime, description) =>
  ReasonReact.array([|
    <dt className=style##entryTime>
      <time dateTime=(toDurationStr(~fromTime, ~toTime))>
        (toTimeStr(~fromTime, ~toTime) |> s)
      </time>
    </dt>,
    <dd className=style##entryDescription> (description |> s) </dd>,
  |]);

/*
 A Break and a Misc type are structurally the same (for now).
 For semantic reasons, we still keep a different function
 name, in case we need to write a different render impl
 */
let breakRow = miscRow;

let talkRow = (~fromTime, ~toTime, speaker: Data.Speaker.t) =>
  ReasonReact.array([|
    <dt className=style##talkTime>
      <time dateTime=(toDurationStr(~fromTime, ~toTime))>
        (toTimeStr(~fromTime, ~toTime) |> s)
      </time>
    </dt>,
    <dd className=style##talkDescription>
      (
        switch (speaker.talk) {
        | Some(talk) =>
          let id = Data.Speaker.talkSlug(talk);
          <section className=style##talkDetails id>
            <Link to_=("/speakers/#" ++ Data.Speaker.speakerAnchor(speaker))>
              <SpeakerCard speaker compact=true />
            </Link>
            <h3 className=style##talkTitle>
              (talk.title |> s)
              (" " |> s)
              <a href=("#" ++ id) title=talk.title> ("#" |> s) </a>
            </h3>
            (talk.abstract |> md)
          </section>;
        | None => ReasonReact.null
        }
      )
    </dd>,
  |]);

let workshopRow = (~fromTime, ~toTime, speakers: list(Data.Speaker.t)) => {
  let renderSpeaker = speaker =>
    <Link to_=("/speakers/#" ++ Data.Speaker.speakerAnchor(speaker))>
      <SpeakerCard speaker compact=true />
    </Link>;
  ReasonReact.array([|
    <dt className=style##talkTime>
      <time dateTime=(toDurationStr(~fromTime, ~toTime))>
        (toTimeStr(~fromTime, ~toTime) |> s)
      </time>
    </dt>,
    <dd className=style##talkDescription>
      <section className=style##talkDetails>
        <h3 className=style##talkTitle> ("Workshop" |> s) </h3>
        (
          speakers
          |> List.map(renderSpeaker)
          |> Array.of_list
          |> ReasonReact.array
        )
      </section>
    </dd>,
  |]);
};

let openEndRow = (~fromTime, description) =>
  ReasonReact.array([|
    <dt className=style##entryTime>
      <time dateTime=(toDurationStr(~fromTime, ~toTime=None))>
        (toTimeStr(~fromTime, ~toTime=None) |> s)
      </time>
    </dt>,
    <dd className=style##entryDescription> (description |> s) </dd>,
  |]);

let createRow = ({task, fromTime, toTime}: Data.Timetable.entry) =>
  switch (task) {
  | Break(description) => breakRow(~fromTime, ~toTime, description)
  | Misc(description) => miscRow(~fromTime, ~toTime, description)
  | Talk(speaker) => talkRow(~fromTime, ~toTime, speaker)
  | Workshop(speakers) => workshopRow(~fromTime, ~toTime, speakers)
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
          (" May, Friday at ImpactHub" |> s)
        </time>
      </h2>
      <dl className=style##entries>
        (
          Data.Timetable.day1Timetable
          |> List.map(createRow)
          |> Array.of_list
          |> ReasonReact.array
        )
      </dl>
      <h2>
        <time dateTime="2018-05-12">
          ("12" |> s)
          <sup> ("th" |> s) </sup>
          (" May, Saturday at TU Wien Kuppelsaal" |> s)
        </time>
      </h2>
      <dl className=style##entries>
        (
          Data.Timetable.day2Timetable
          |> List.map(createRow)
          |> Array.of_list
          |> ReasonReact.array
        )
      </dl>
      <h2>
        <time dateTime="2018-05-13">
          ("13" |> s)
          <sup> ("th" |> s) </sup>
          (" May, Sunday at ImpactHub" |> s)
        </time>
      </h2>
      <main>
        <dl className=style##entries>
          <dt className=style##entryTime>
            <time> ("9:00 - 10:00" |> s) </time>
          </dt>
          <dd className=style##entryDescription>
            ("Doors open & forming Teams for the Hackathon" |> s)
          </dd>
          <dt className=style##talkTime>
            <time> ("10:00 - 13:00" |> s) </time>
          </dt>
          <dd className=style##talkDescription>
            (
              {js|
Choose between:

1. **Open Mic Session** – everyone can come and give a talk. Speakers can opt-in to be recorded and their talk published by our ReasonConf channel.
2. **Hackathon** – team up with others or work alone on your project of choice
3. **Vienna Tour** – explore the city center with one of our local volunteers
            |js}
              |> md
            )
          </dd>
          <dt className=style##entryTime>
            <time> ("13:00 - 14:00" |> s) </time>
          </dt>
          <dd className=style##entryDescription> ("Lunch" |> s) </dd>
          <dt className=style##talkTime>
            <time> ("14:00 - 17:30" |> s) </time>
          </dt>
          <dd className=style##talkDescription>
            (
              {js|
Choose between:

1. **Hackathon** – team up with others or work alone on your project of choice
2. **Vienna Tour** – explore the city center with one of our local volunteers
            |js}
              |> md
            )
          </dd>
          <dt className=style##entryTime>
            <time> ("18:00 - 22:00" |> s) </time>
          </dt>
          <dd className=style##entryDescription>
            ("Get together at a local wine tavern (Heuriger)" |> s)
          </dd>
        </dl>
      </main>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
