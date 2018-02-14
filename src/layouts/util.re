[@bs.module] external marked : (string, Js.t({..})) => string = "marked";

let componentOrNull = (condition, component) =>
  if (condition) {component} else {ReasonReact.nullElement};

let s = ReasonReact.stringToElement;

let md = markdownString => {
  let res =
    marked(
      markdownString,
      {"gfm": Js.true_, "smartLists": Js.true_, "smartypants": Js.true_}
    );
  let props = ReactDOMRe.props(~dangerouslySetInnerHTML={"__html": res}, ());
  ReactDOMRe.createElement("div", ~props, [||]);
};
