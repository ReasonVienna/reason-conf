[@bs.module] external marked : (string, Js.t({..})) => string = "marked";

let toHHMM = date => {
  let pad = n =>
    if (n < 10) {
      "0" ++ string_of_int(n);
    } else {
      string_of_int(n);
    };
  let hh = Js.Date.getUTCHours(date) |> int_of_float |> pad;
  let mm = Js.Date.getUTCMinutes(date) |> int_of_float |> pad;
  {j|$hh:$mm|j};
};

let componentOrNull = (condition, component) =>
  if (condition) {component} else {ReasonReact.null};

let s = ReasonReact.string;

let ate = ReasonReact.array;

let md = markdownString => {
  let res =
    marked(
      markdownString,
      {"gfm": true, "smartLists": true, "smartypants": true},
    );
  let props =
    ReactDOMRe.props(
      ~dangerouslySetInnerHTML={"__html": res},
      ~className="markdown-container",
      (),
    );
  ReactDOMRe.createElement("section", ~props, [||]);
};
