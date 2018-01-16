module Tickets = {
  [@bs.module "./titowidget"]
  external titoWidget : ReasonReact.reactClass = "Widget";
  let make = (~event: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=titoWidget,
      ~props={"event": event},
      children
    );
};
