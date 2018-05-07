%raw
"require('normalize.css')";

%raw
"require('./index.scss')";

open Util;

module Helmet = Gatsby.Helmet;

let component = ReasonReact.statelessComponent("TemplateWrapper");

let title = "ReasonConf 2018";

type layoutType =
  | Home
  | Normal
  | NoLayout
  | Print;

let subscribeFormIfNeeded = hasSubscribeForm =>
  componentOrNull(
    hasSubscribeForm,
    <footer className="subscribe">
      <div className="container_centered grid grid_6cols">
        <h2> ("Subscribe to Newsletter" |> s) </h2>
        <SubscribeForm />
      </div>
    </footer>,
  );

let make = (~location, children) => {
  ...component,
  render: _self => {
    let pageType =
      switch (location##pathname) {
      | "/" => Home
      | "/speaker"
      | "/speaker/" => NoLayout
      | "/badges"
      | "/badges/" => Print
      | _ => Normal
      };
    let isThanksPage = location##pathname == "/thanks/";
    switch (pageType) {
    | NoLayout => <div> <Helmet title /> (children()) </div>
    | Print =>
      <div className="page-print">
        <Helmet title bodyAttributes={"class": "A4"}>
          <link
            rel="stylesheet"
            _type="text/css"
            href="https://cdnjs.cloudflare.com/ajax/libs/paper-css/0.3.0/paper.css"
          />
        </Helmet>
        (children())
      </div>
    | Home =>
      <div className="page">
        <Helmet title>
          <script src="https://js.tito.io/v1" async=true />
          <link
            rel="stylesheet"
            _type="text/css"
            href="https://css.tito.io/v1.1"
          />
        </Helmet>
        <main> (children()) </main>
        (subscribeFormIfNeeded(! isThanksPage))
        <Footer />
      </div>
    | Normal =>
      <div className="page">
        <Helmet title />
        <div className="container container_centered">
          <header> <Navigation pathName=location##pathname /> </header>
          <article> (children()) </article>
        </div>
        (subscribeFormIfNeeded(! isThanksPage))
        <Footer />
      </div>
    };
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~location=jsProps##location, jsProps##children)
  );
