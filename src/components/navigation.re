module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./navigation.module.scss";

open Util;

let component = ReasonReact.statelessComponent("Navigation");

type navigationLocation =
  | Header
  | Footer;

let make = (~pathName, ~navigationLocation=Header, _children) => {
  ...component,
  render: _self => {
    let isHomePage = pathName == "/";
    let rootClassName =
      switch navigationLocation {
      | Header => style##root_header
      | Footer => style##root_footer
      };
    /* We don't need active class named in the footer */
    let activeClassName =
      navigationLocation == Header ? style##link_active : "";
    <nav className=rootClassName>
      (
        componentOrNull(
          ! isHomePage,
          <Link to_="/" className=style##link_home>
            <img src=Assets.logo alt="Home" className=style##logo />
          </Link>
        )
      )
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
        <li className=style##listItemBuy>
          <a href="#tickets" className=style##ticketsButton>
            (s("Buy a ticket"))
          </a>
        </li>
      </ul>
    </nav>;
  }
};
