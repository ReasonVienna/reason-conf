module Link = Gatsby.Link;

let component = ReasonReact.statelessComponent("Thanks");

open Util;

let make = _children => {
  ...component,
  render: _self =>
    <section className="thanks grid grid-6col">
      <div className="thanks--grid">
        <h1> (s("Thank you for your interest!")) </h1>
        <p>
          (s("Your data has been submitted. We will be in contact soon."))
        </p>
        <p> <Link to_="/"> {j|← Back to home page|j} </Link> </p>
      </div>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
