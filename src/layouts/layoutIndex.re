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
    <article className="container">
      <Helmet title="ReasonConf 2018" meta=metaData />
      (componentOrNull(! isHomepage, <Navigation />))
      <main> (children()) </main>
      <Footer />
    </article>;
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~location=jsProps##location, jsProps##children)
  );
