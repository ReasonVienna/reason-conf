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
                "Reason Conf is the not-for-profit conference\norganized by community efforts by people\nbehind React Vienna community: "
              )
            )
            <a href="https://twitter.com/ryyppy" className="footer--creator">
              <img
                src=Assets.patrick
                alt="Photo of Patrick"
                className="footer--userpic"
              />
              (ste("Patrick"))
            </a>
            <a href="https://twitter.com/nikgraf" className="footer--creator">
              <img
                src=Assets.nik
                alt="Photo of Nik"
                className="footer--userpic"
              />
              (ste("Nik"))
            </a>
            (ste(" & "))
            <a
              href="https://twitter.com/okonetchnikov"
              className="footer--creator">
              <img
                src=Assets.andrey
                alt="Photo of Andrey"
                className="footer--userpic"
              />
              (ste("Andrey"))
            </a>
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
