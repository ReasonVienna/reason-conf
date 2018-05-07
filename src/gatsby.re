module Link = {
  [@bs.module "gatsby-link"] external withPrefix : string => string = "";
  [@bs.module "gatsby-link"]
  external linkClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~to_: string,
        ~className: option(string)=?,
        ~activeStyle: option(Js.t({..}))=?,
        ~activeClassName: option(string)=?,
        children,
      ) => {
    /*
        React is complaining if activeStyle & activeClassName are translated
        to e.g. activeClassName=undefined inside a JSX tag
     */
    let props =
      {"to": to_, "className": Js.Nullable.fromOption(className)}
      |> (
        p =>
          switch (activeStyle) {
          | Some(v) => Js.Obj.assign(p, {"activeStyle": v})
          | None => p
          }
      )
      |> (
        p =>
          switch (activeClassName) {
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
          "content": string,
        },
      ),
    );
  let make =
      (~title: option(string)=?, ~bodyAttributes=?, ~meta: metaT=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=linkClass,
      ~props={
        "title": Js.Nullable.fromOption(title),
        "bodyAttributes": Js.Nullable.fromOption(bodyAttributes),
        "meta": Js.Nullable.fromOption(meta),
      },
      children,
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
        _children,
      ) => {
    let props = {
      "urls": urls,
      "className": Js.Nullable.fromOption(className),
      "color": Js.Nullable.fromOption(color),
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
        _children,
      ) => {
    let props = {
      "url": url,
      "className": Js.Nullable.fromOption(className),
      "color": Js.Nullable.fromOption(color),
      "network": Js.Nullable.fromOption(network),
    };
    ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, _children);
  };
};
