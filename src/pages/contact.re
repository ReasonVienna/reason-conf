module Link = Gatsby.Link;

let component = ReasonReact.statelessComponent("Thanks");

open Util;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (s("Contact us")) </h1>
      <section className="thanks grid grid_6cols">
        <div className="thanks--grid">
          <div>
            (s("Email: "))
            <a href="mailto:hi@reason-conf.com">
              (s("hi@reason-conf.com"))
            </a>
          </div>
          <div>
            (s("Twitter: "))
            <a href="https://www.twitter.com/reasonconf">
              (s("@ReasonConf"))
            </a>
          </div>
        </div>
      </section>
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
