module Link = Gatsby.Link;

let component = ReasonReact.statelessComponent("Thanks");

open Util;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (s("Contact us")) </h1>
      <section className="thanks grid grid-6col">
        <div className="thanks--grid"> <ContactForm /> </div>
      </section>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
