let component = ReasonReact.statelessComponent("CodeOfConduct");

module Link = Gatsby.Link;

let ste = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (ste("Hi people")) </h1>
      <Link to_="/coc/"> (ste("Code of Conduct")) </Link>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
