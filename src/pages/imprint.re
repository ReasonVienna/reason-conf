let component = ReasonReact.statelessComponent("Imprint");

let ste = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (ste("Imprint")) </h1>
      <h2> (ste({j|Nikolaus Graf|j})) </h2>
      <p> (ste("Johann Knoll Gasse 9, 1210 Vienna, Austria")) </p>
      <p> <a href="mailto:nik@nikgraf.com"> (ste("nik@nikgraf.com")) </a> </p>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
