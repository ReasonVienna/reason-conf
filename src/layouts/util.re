let componentOrNull = (condition, component) =>
  if (condition) {component} else {ReasonReact.nullElement};

let s = ReasonReact.stringToElement;
