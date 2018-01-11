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

let styleImport =
  ReasonReact.stringToElement(
    {js| @import url('https://fonts.googleapis.com/css?family=Assistant|Hammersmith+One'); |js}
  );

let make = children => {
  ...component,
  render: _self =>
    <article className="container">
      <Helmet title="ReasonConf 2018" meta=metaData />
      <style _type="text/css"> styleImport </style>
      <Navigation />
      <main> (children()) </main>
      <Footer />
    </article>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
