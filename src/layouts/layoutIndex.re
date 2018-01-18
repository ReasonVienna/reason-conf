[%%raw "require('normalize.css')"];

[%%raw "require('./index.scss')"];

open Util;

module Helmet = Gatsby.Helmet;

let component = ReasonReact.statelessComponent("TemplateWrapper");

let metaData = [|
  {"name": "description", "content": "Reason Conf"},
  {
    "name": "keywords",
    "content": "Reason, ReasonML, Conference, ReasonML, Conf, Vienna, Austria"
  }
|];

let make = (~location, children) => {
  ...component,
  render: _self => {
    let isHomepage = location##pathname == "/";
    let isThanksPage = location##pathname == "/thanks/";
    <article className="page">
      <Helmet title="ReasonConf 2018" meta=metaData>
        <script src="https://js.tito.io/v1" async=Js.true_ />
        <link
          rel="stylesheet"
          _type="text/css"
          href="https://css.tito.io/v1.1"
        />
      </Helmet>
      (
        if (isHomepage) {
          <main> (children()) </main>;
        } else {
          <div className="container container_centered grid grid-col6">
            <Navigation pathName=location##pathname />
            <main> (children()) </main>
          </div>;
        }
      )
      (
        componentOrNull(
          ! isThanksPage,
          <section className="subscribe">
            <div className="container_centered grid grid-6col">
              <h2> ("Subscribe to Newsletter" |> s) </h2>
              <SubscribeForm />
            </div>
          </section>
        )
      )
      <Footer />
    </article>;
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~location=jsProps##location, jsProps##children)
  );
