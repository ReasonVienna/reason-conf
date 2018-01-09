let component = ReasonReact.statelessComponent("CodeOfConduct");

let ste = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (ste("Imprint")) </h1>
      <div>
        (
          ste(
            {j|Atrium ­- Verein zur Förderung von SoftwareentwicklerInnen|j}
          )
        )
      </div>
      <div> (ste("Siebenbrunnengasse 44, 1050 Vienna")) </div>
      <div> (ste("Austria")) </div>
      <div> (ste("nik@nikgraf.com")) </div>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
