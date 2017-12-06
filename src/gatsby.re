module Link = {
  [@bs.module] external gatsbyLink : ReasonReact.reactClass = "gatsby-link";
  let make = (~destination: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=gatsbyLink,
      ~props={"to": destination},
      children
    );
};
