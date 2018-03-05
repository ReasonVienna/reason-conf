open Util;

module Job = Data.Job;

[@bs.module] external style : Js.t({..}) = "./jobs.module.scss";

let component = ReasonReact.statelessComponent("Jobs");

let renderJob = (job: Job.t) => {
  let className =
    switch job.tier {
    | Gold => style##gold
    | Catering => style##catering
    | LocalSupport => style##localSupport
    };
  <div key=job.desc className>
    (job.company.name |> s)
    <a href=job.href> (job.desc |> s) </a>
    (
      switch job.location {
      | OnSite({city, country}) => <span> ({j|$city, $country|j} |> s) </span>
      | RemoteOnly => <span> ("Remote" |> s) </span>
      | RemoteAndOnSite({city, country}) =>
        <span> ({j|$city, $country (remote possible)|j} |> s) </span>
      }
    )
  </div>;
};

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> ("Jobs" |> s) </h1>
      <main> (Array.map(renderJob, Data.Job.data) |> ate) </main>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
