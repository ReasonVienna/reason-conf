let component = ReasonReact.statelessComponent("Schedule");

let s = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self => <h1> (s("Schedule")) </h1>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
