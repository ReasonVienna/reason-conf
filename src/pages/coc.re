module Link = Gatsby.Link;

let component = ReasonReact.statelessComponent("CodeOfConduct");

let ste = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (ste("Code of Conduct")) </h1>
      <Link to_="/"> "[back]" </Link>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
