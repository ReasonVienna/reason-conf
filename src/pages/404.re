let component = ReasonReact.statelessComponent("NotFoundPage");

let ste = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  render: (_self) => <div> <h1> (ste("404 - NOT FOUND")) </h1> </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
