[@bs.module] external style : Js.t({..}) = "./footer.module.scss";

open Util;

open Data;

module Link = Gatsby.Link;

module SocialIcons = Gatsby.SocialIcons;

module SocialIcon = Gatsby.SocialIcon;

let component = ReasonReact.statelessComponent("Footer");

let socialUrls = [|
  "https://twitter.com/reasonconf",
  "https://www.facebook.com/ReasonConf-1334078980027448/",
  "https://www.github.com/reasonvienna"
|];

let organizerWithPic = ({imgUrl, name, href}: Data.organizerData) =>
  <a href className=style##creator key=name>
    <img src=imgUrl alt={j|Photo of $(name)|j} className=style##userpic />
    (name |> s)
  </a>;

let make = _children => {
  ...component,
  render: _self =>
    <footer className=style##root>
      <div className="container_centered grid">
        <Navigation pathName="/" navigationLocation=Footer />
        <nav className=style##social>
          <SocialIcons
            urls=socialUrls
            color="#8eaeb6"
            className=style##socialIcon
          />
        </nav>
        <nav className=style##additional>
          <ul>
            <li> <Link to_="/coc/"> ("Code of Conduct" |> s) </Link> </li>
            <li>
              <a
                href="https://docs.google.com/forms/d/e/1FAIpQLSefBd8jbN99Mb5zrk7UePo3GQXgMI0nPSQlMnQ3WQPJtuaIEA/viewform?usp=sf_link"
                target="_blank">
                ("Apply for a talk" |> s)
              </a>
            </li>
            <li> <a href="/contact/"> ("Contact Us" |> s) </a> </li>
            <li> <Link to_="/imprint/"> ("Imprint" |> s) </Link> </li>
          </ul>
        </nav>
        <section className=style##copyright>
          <p className=style##about>
            ("Reason Conf 2018 is a " |> s)
            <a href="/about"> ("not-for-profit conference " |> s) </a>
            ("made by developers for developers." |> s)
          </p>
          <p />
          <p> ({j|© ReasonConf, 2018|j} |> s) </p>
        </section>
      </div>
    </footer>
};
