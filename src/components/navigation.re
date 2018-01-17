module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./navigation.module.scss";

let component = ReasonReact.statelessComponent("Header");

let s = ReasonReact.stringToElement;

let activeClassName = style##link_active;

let make = (~pathName, _children) => {
  ...component,
  render: _self => {
    let isHomePage = pathName == "/";
    let rootClassName = isHomePage ? style##root_home : style##root;
    <nav className=rootClassName>
      <Link to_="/" className=style##link_home>
        <img src=Assets.logo alt="Home" className=style##logo />
      </Link>
      <ul className=style##list>
        <li className=style##listItem>
          <Link to_="/schedule/" className=style##link activeClassName>
            (s("Schedule"))
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/speakers/" className=style##link activeClassName>
            (s("Speakers"))
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/sponsors/" className=style##link activeClassName>
            (s("Sponsors"))
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/about/" className=style##link activeClassName>
            (s("About"))
          </Link>
        </li>
        <li className=style##listItem>
          <Link to_="/blog/" className=style##link activeClassName>
            (s("Blog"))
          </Link>
        </li>
        <li>
          <a href="#tickets" className=style##ticketsButton>
            (s("Buy a ticket"))
          </a>
        </li>
      </ul>
    </nav>;
  }
};
