module Link = Gatsby.Link;

let component = ReasonReact.statelessComponent("Footer");

let ste = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    <footer>
      <div className="container--centered grid grid-6col">
        <section className="footer--about">
          <p>
            (
              ste(
                "ReasonConf is the not-for-profit conference\norganized by community efforts by people\nbehind React Vienna community."
              )
            )
          </p>
          <p>
            <img src=Assets.patrick width="28" height="28" />
            (ste("Patrick"))
            <img src=Assets.nik width="28" height="28" />
            (ste("Nik &"))
            <img src=Assets.andrey width="28" height="28" />
            (ste("Andrey"))
          </p>
        </section>
        <nav>
          <ul>
            <li>
              <a href="https://www.example.com">
                (ste("Subscribe to Newsletter"))
              </a>
            </li>
            <li> <Link to_="/coc/"> (ste("Code of Conduct")) </Link> </li>
            <li>
              <a href="https://www.example.com"> (ste("Contact Us")) </a>
            </li>
          </ul>
        </nav>
        <nav>
          <ul>
            <li>
              <a href="https://twitter.com/reasonconf"> (ste("Twitter")) </a>
            </li>
            <li>
              <a href="https://www.facebook.com"> (ste("Facebook")) </a>
            </li>
            <li> <a href="https://www.github.com"> (ste("Github")) </a> </li>
          </ul>
        </nav>
        <section className="copyright">
          <Link to_="/imprint/"> (ste("Imprint")) </Link>
          <p> (ste({j|© Atrium, 2018|j})) </p>
        </section>
      </div>
    </footer>
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
