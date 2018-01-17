[@bs.module] external style : Js.t({..}) = "./footer.module.scss";

open Util;

open Data;

module Link = Gatsby.Link;

let component = ReasonReact.statelessComponent("Footer");

let organizerWithPic = ({imgUrl, name, href}: Data.organizerData) =>
  <a href className=style##creator key=name>
    <img src=imgUrl alt={j|Photo of $(name)|j} className=style##userpic />
    (name |> s)
  </a>;

let make = _children => {
  ...component,
  render: _self =>
    <footer className=style##root>
      <div className="container_centered grid grid-6col">
        <Navigation pathName="/" navigationLocation=Footer />
        <nav className=style##additional>
          <ul>
            <li> <Link to_="/coc/"> ("Code of Conduct" |> s) </Link> </li>
            <li>
              <a href="https://www.example.com"> ("Contact Us" |> s) </a>
            </li>
            <li> <Link to_="/imprint/"> ("Imprint" |> s) </Link> </li>
          </ul>
        </nav>
        <nav className=style##social>
          <ul>
            <li>
              <a href="https://twitter.com/reasonconf"> ("Twitter" |> s) </a>
            </li>
            <li>
              <a href="https://www.facebook.com"> ("Facebook" |> s) </a>
            </li>
            <li> <a href="https://www.github.com"> ("Github" |> s) </a> </li>
          </ul>
        </nav>
        <section className=style##copyright>
          <p className=style##about>
            (
              "Reason Conf is the not-for-profit conference organized by React Vienna organizers:"
              |> s
            )
            (
              switch Data.organizers {
              | [] => ReasonReact.nullElement
              | [o3, ...rest] =>
                <span>
                  (
                    /* Lists are only tail-spreadable, so we consider
                       the first element to be the last to be rendered */
                    Array.of_list(rest)
                    |> Array.map(organizerWithPic)
                    |> ReasonReact.arrayToElement
                  )
                  (" & " |> s)
                  (organizerWithPic(o3))
                </span>
              }
            )
          </p>
          <p> ({j|© Atrium, 2018|j} |> s) </p>
        </section>
      </div>
    </footer>
};
