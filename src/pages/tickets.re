open Util;

module Tickets = Tito.Tickets;

let component = ReasonReact.statelessComponent("Tickets");

let make = _children => {
  ...component,
  render: _self =>
    <section className="tickets">
      <h1> ("Tickets will be available soon!" |> s) </h1>
      <p>
        ("Please stay tuned until we open our ticket sales." |> s)
        <br />
        (
          "We recommend to subscribe to our newsletter so that we can notify you as soon as tickets are available."
          |> s
        )
      </p>
    </section>
  /* <Tickets event="reason-conf/reason-conf-2018" /> */
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
