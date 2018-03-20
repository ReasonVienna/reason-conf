open Util;

module Job = Data.Job;

let component = ReasonReact.statelessComponent("Jobs");

let renderLocation = (ad: Job.jobAd) =>
  Job.(
    switch ad.location {
    | OnSite({city, country}) => <span> ({j| ($city, $country)|j} |> s) </span>
    | RemoteOnly => <span> (" (Remote)" |> s) </span>
    | RemoteAndOnSite({city, country}) =>
      <span> ({j| ($city, $country or Remote)|j} |> s) </span>
    }
  );

let renderJobAds = (key: string, ads: array(Job.jobAd)) =>
  Job.(
    <ul key>
      (
        Array.map(
          ad =>
            <li key=(key ++ "_" ++ ad.desc)>
              <a href=ad.href target="_blank">
                (ad.desc |> s)
                (renderLocation(ad))
              </a>
            </li>,
          ads
        )
        |> ate
      )
    </ul>
  );

let renderJob = (i: string, {tier, company, jobAds}: Job.t) => {
  let className =
    "job "
    ++ (
      switch tier {
      | Gold => "gold"
      | Catering => "catering"
      | LocalSupport => "localSupport"
      }
    );
  <div key=(i ++ "_" ++ company.href) className>
    <a href=company.href>
      (
        switch company.logo {
        | None => ReasonReact.nullElement
        | Some({src, width}) => <img src width />
        }
      )
    </a>
    (company.descMd |> md)
    (renderJobAds(company.href, jobAds))
  </div>;
};

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> ("Jobs" |> s) </h1>
      <main className="leadText">
        (
          /*
                     {js|
                       We are cooperating with companies who are eager to invest in
                       emerging technologies. They are also looking for new talents!
                     |js}
           */
          {js|
             This job board will show-case job offers of our featured
             sponsors. If you are interested to collaborate with us, please get
             in touch!
            |js}
          |> s
        )
      </main>
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
