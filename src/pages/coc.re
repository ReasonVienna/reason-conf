let component = ReasonReact.statelessComponent("CodeOfConduct");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (ReasonReact.stringToElement("Code of Conduct")) </h1>
      <Gatsby.Link destination="/">
        (ReasonReact.stringToElement("Go back to the homepage"))
      </Gatsby.Link>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
