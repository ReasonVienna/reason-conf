open Util;

[@bs.module] external style : Js.t({..}) = "./socialLink.module.scss";

type target =
  | Twitter
  | Github
  | Website;

let component = ReasonReact.statelessComponent("SocialLink");

let make = (~target: target, ~link: option(string), _children) => {
  ...component,
  render: _self =>
    switch (link) {
    | None => ReasonReact.null
    | Some(link) =>
      let (url, iconClass) =
        switch (target) {
        | Twitter => ("https://twitter.com/" ++ link, "fab fa-twitter")
        | Github => ("https://github.com/" ++ link, "fab fa-github")
        | Website => ("https://twitter.com/", "fas fa-globe")
        };
      <div className=style##item>
        <a className=style##link href=url>
          <i className=iconClass />
          (link |> s)
        </a>
      </div>;
    },
};
