open Util;

module Job = Data.Job;

[@bs.module] external style : Js.t({..}) = "./jobs.module.scss";

let component = ReasonReact.statelessComponent("Jobs");

let renderLocation = (ad: Job.jobAd) =>
  Job.(
    switch ad.location {
    | OnSite({city, country}) => <span> ({j|$city, $country|j} |> s) </span>
    | RemoteOnly => <span> ("Remote" |> s) </span>
    | RemoteAndOnSite({city, country}) =>
      <span> ({j|$city, $country (remote possible)|j} |> s) </span>
    }
  );

let renderJobAds = (key: string, ads: array(Job.jobAd)) =>
  Job.(
    <ul key>
      (
        Array.map(
          ad =>
            <li key=(key ++ "_" ++ ad.desc)>
              <a href=ad.href target="_blank"> (ad.desc |> s) </a>
              (renderLocation(ad))
            </li>,
          ads
        )
        |> ate
      )
    </ul>
  );

let renderJob = (i: string, {tier, company, jobAds}: Job.t) => {
  let className =
    switch tier {
    | Gold => style##gold
    | Catering => style##catering
    | LocalSupport => style##localSupport
    };
  <div key=(i ++ "_" ++ company.href) className>
    <a href=company.href> <img src=company.logo /> </a>
    (company.descMd |> md)
    (renderJobAds(company.href, jobAds))
  </div>;
};

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> ("Jobs" |> s) </h1>
      <main>
        (
          Array.mapi(
            (i, job) => renderJob(string_of_int(i), job),
            Data.Job.data
          )
          |> ate
        )
      </main>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
