module BasicScroll = {
  type t;
  [@bs.module "basicscroll"]
  external create :
    {
      .
      "elem": Dom.element,
      "from": string,
      "to": string,
      "props": Js.t({..})
    } =>
    t =
    "";
  [@bs.send] external update : t => unit = "";
  [@bs.send] external start : t => unit = "";
  [@bs.send] external stop : t => unit = "";
};

type state = {
  instance: ref(option(BasicScroll.t)),
  scrollAreaRef: ref(option(Dom.element))
};

let component = ReasonReact.reducerComponent("ParallaxScroll");

let setScrollAreaRef = (theRef, {ReasonReact.state}) =>
  state.scrollAreaRef := Js.Nullable.to_opt(theRef);

let initScroll = (~from: string, ~to_: string, ~props: Js.t({..}), state) =>
  switch (state.instance^, state.scrollAreaRef^) {
  | (None, Some(scrollArea)) =>
    open BasicScroll;
    let newInstance =
      create({"elem": scrollArea, "from": from, "to": to_, "props": props});
    start(newInstance);
    state.instance := Some(newInstance);
  | (_, _) => ()
  };

let maybeDo = (fn, instance) =>
  switch instance^ {
  | Some(instance) => fn(instance)
  | None => ()
  };

let make = (~from: string, ~to_: string, ~props: Js.t({..}), children) => {
  ...component,
  initialState: () => {instance: ref(None), scrollAreaRef: ref(None)},
  didMount: self => {
    initScroll(~from, ~to_, ~props, self.state);
    ReasonReact.NoUpdate;
  },
  willReceiveProps: self => {
    initScroll(~from, ~to_, ~props, self.state);
    self.state;
  },
  willUnmount: self =>
    BasicScroll.(
      switch self.state.instance^ {
      | Some(instance) =>
        update(instance);
        stop(instance);
        self.state.instance := None;
      | None => ()
      }
    ),
  reducer: ((), _state) => ReasonReact.NoUpdate,
  render: self => <div ref=(self.handle(setScrollAreaRef))> children </div>
};
