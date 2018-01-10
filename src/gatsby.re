module Link = {
  [@bs.module "gatsby-link"] external gatsbyLink : ReasonReact.reactClass = "default";
  let make = (~to_: string, children) =>
    ReasonReact.wrapJsForReason(~reactClass=gatsbyLink, ~props={"to": to_}, children);
};
