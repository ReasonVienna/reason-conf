[%%raw "require('normalize.css')"];

[%%raw "require('./index.scss')"];

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
      <Footer />
    </article>;
  }
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~location=jsProps##location, jsProps##children)
  );
