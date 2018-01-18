let component = ReasonReact.statelessComponent("Tickets");

let s = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    <section className="tickets">
      <div className="container_centered">
        <h1> ("Tickets" |> s) </h1>
        <Tickets event="reason-conf/reason-conf-2018" />
      </div>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
