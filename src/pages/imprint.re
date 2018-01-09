let component = ReasonReact.statelessComponent("Imprint");

let ste = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h1> (ste("Imprint")) </h1>
      <h2>
        (ste({j|Atrium—Verein zur Förderung von SoftwareentwicklerInnen|j}))
      </h2>
      <p> (ste("Siebenbrunnengasse 44, 1050 Vienna, Austria")) </p>
      <p> <a href="mailto:nik@nikgraf.com"> (ste("nik@nikgraf.com")) </a> </p>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
