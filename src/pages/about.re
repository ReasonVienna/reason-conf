let component = ReasonReact.statelessComponent("About");

let s = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self => <h1> (s("About")) </h1>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
