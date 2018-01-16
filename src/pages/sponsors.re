let component = ReasonReact.statelessComponent("Sponsors");

let s = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self => <h1> (s("Sponsors")) </h1>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
