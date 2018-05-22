open Gatsby;

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
      let (url, network) =
        switch (target) {
        | Twitter => ("https://twitter.com/" ++ link, "twitter")
        | Github => ("https://github.com/" ++ link, "github")
        | Website => ("https://twitter.com/", "sharethis")
        };
      <SocialIcon className=style##item network url color="#9eb3bd" />;
    },
};
