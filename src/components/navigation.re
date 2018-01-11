module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./navigation.module.scss";

let component = ReasonReact.statelessComponent("Header");

let s = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    <nav className=style##navigation>
      <ul className=style##header>
        <li> <Link to_="/schedule/"> (s("Schedule")) </Link> </li>
        <li> <Link to_="/speakers/"> (s("Speakers")) </Link> </li>
        <li> <Link to_="/sponsors/"> (s("Sponsors")) </Link> </li>
        <li> <Link to_="/about/"> (s("About")) </Link> </li>
        <li> <Link to_="/blog/"> (s("Blog")) </Link> </li>
        <li> <Button text="Buy a ticket" /> </li>
      </ul>
    </nav>
};
