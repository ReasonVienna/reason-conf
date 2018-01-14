[@bs.module] external style : Js.t({..}) = "./footer.module.scss";

open Util;

open Data;

module Link = Gatsby.Link;

let component = ReasonReact.statelessComponent("Footer");

let organizerWithPic = (organizer: Data.organizerData) =>
  <a href=organizer.href className=style##creator key=organizer.name>
    <img src=organizer.imgUrl alt=organizer.altText className=style##userpic />
    (organizer.name |> s)
  </a>;

let make = _children => {
  ...component,
  render: _self =>
    <footer>
      <div className="container_centered grid grid-6col">
        <section className=style##about>
          <p>
            (
              "Reason Conf is the not-for-profit conference\norganized by community efforts by people\nbehind ReactVienna community"
              |> s
            )
          </p>
          (
            switch Data.organizers {
            | (x, y, z) =>
              <p>
                (
                  Array.map(organizerWithPic, [|x, y|])
                  |> ReasonReact.arrayToElement
                )
                (" & " |> s)
                (organizerWithPic(z))
              </p>
            }
          )
        </section>
        <nav>
          <ul>
            <li>
              <a href="https://www.example.com">
                ("Subscribe to Newsletter" |> s)
              </a>
            </li>
            <li> <Link to_="/coc/"> ("Code of Conduct" |> s) </Link> </li>
            <li>
              <a href="https://www.example.com"> ("Contact Us" |> s) </a>
            </li>
          </ul>
        </nav>
        <nav>
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
          <Link to_="/imprint/"> ("Imprint" |> s) </Link>
          <p> ({j|© Atrium, 2018|j} |> s) </p>
        </section>
      </div>
    </footer>
};
