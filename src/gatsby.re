module Link = {
  [@bs.module "gatsby-link"]
  external linkClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~to_: string,
        ~className: option(string)=?,
        ~activeStyle: option(Js.t({..}))=?,
        ~activeClassName: option(string)=?,
        children
      ) => {
    /*
        React is complaining if activeStyle & activeClassName are translated
        to e.g. activeClassName=undefined inside a JSX tag
     */
    let props =
      {"to": to_, "className": Js.Nullable.from_opt(className)}
      |> (
        p =>
          switch activeStyle {
          | Some(v) => Js.Obj.assign(p, {"activeStyle": v})
          | None => p
          }
      )
      |> (
        p =>
          switch activeClassName {
          | Some(v) => Js.Obj.assign(p, {"activeClassName": v})
          | None => p
          }
      );
    ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, children);
  };
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

module SocialIcons = {
  [@bs.module "react-social-icons"]
  external linkClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~urls: array(string),
        ~className: option(string)=?,
        ~color: option(string)=?,
        _children
      ) => {
    let props = {
      "urls": urls,
      "className": Js.Nullable.from_opt(className),
      "color": Js.Nullable.from_opt(color)
    };
    ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, _children);
  };
};

module SocialIcon = {
  [@bs.module "react-social-icons"]
  external linkClass : ReasonReact.reactClass = "SocialIcon";
  let make =
      (
        ~url: string,
        ~className: option(string)=?,
        ~color: option(string)=?,
        ~network: option(string)=?,
        _children
      ) => {
    let props = {
      "url": url,
      "className": Js.Nullable.from_opt(className),
      "color": Js.Nullable.from_opt(color),
      "network": Js.Nullable.from_opt(network)
    };
    ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, _children);
  };
};
