module Link = Gatsby.Link;

let component = ReasonReact.statelessComponent("Footer");

let ste = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <img src=Assets.patrick width="28" height="28" />
      (ste("Patrick"))
      <img src=Assets.nik width="28" height="28" />
      (ste("Nik &"))
      <img src=Assets.andrey width="28" height="28" />
      (ste("Andrey"))
      <p>
        (
          ste(
            "ReasonConf is the not-for-profit conference\norganized by community efforts by people\nbehind React Vienna community."
          )
        )
      </p>
      <div>
        <a href="https://www.example.com">
          (ste("Subscribe to Newsletter"))
        </a>
        <Link to_="/coc/"> (ste("Code of Conduct")) </Link>
        <a href="https://www.example.com"> (ste("Contact Us")) </a>
      </div>
      <div>
        <a href="https://twitter.com/reasonconf"> (ste("Twitter")) </a>
        <a href="https://www.facebook.com"> (ste("Facebook")) </a>
        <a href="https://www.github.com"> (ste("Github")) </a>
      </div>
      <div>
        <Link to_="/imprint/"> (ste("Imprint")) </Link>
        <div> (ste({j|© Atrium, 2018|j})) </div>
      </div>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
