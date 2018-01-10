module Link = {
  [@bs.module "gatsby-link"]
  external linkClass : ReasonReact.reactClass = "default";
  let make = (~to_: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=linkClass,
      ~props={"to": to_},
      children
    );
};

module Helmet = {
  [@bs.module "react-helmet"]
  external linkClass : ReasonReact.reactClass = "default";
  type metaT =
    option(
      array(
        {
          .
          "name": string,
          "content": string
        }
      )
    );
  let make = (~title: option(string)=?, ~meta: metaT=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=linkClass,
      ~props={
        "title": Js.Nullable.from_opt(title),
        "meta": Js.Nullable.from_opt(meta)
      },
      children
    );
};
