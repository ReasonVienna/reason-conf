[%%raw "require('normalize.css')"];

[%%raw "require('./index.scss')"];

open Util;

module Helmet = Gatsby.Helmet;

let component = ReasonReact.statelessComponent("TemplateWrapper");

let title = "ReasonConf 2018";

let make = (~location, children) => {
  ...component,
  render: _self => {
    let isHomepage = location##pathname == "/";
    let isThanksPage = location##pathname == "/thanks/";
    <div className="page">
      <Helmet title>
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
          <div className="container container_centered">
            <header> <Navigation pathName=location##pathname /> </header>
            <article> (children()) </article>
          </div>;
        }
      )
      (
        componentOrNull(
          ! isThanksPage,
          <footer className="subscribe">
            <div className="container_centered grid grid-6col">
              <h2> ("Subscribe to Newsletter" |> s) </h2>
              <SubscribeForm />
            </div>
          </footer>
        )
      )
      <Footer />
    </div>;
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~location=jsProps##location, jsProps##children)
  );
