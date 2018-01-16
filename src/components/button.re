[@bs.module] external style : Js.t({..}) = "./button.module.scss";

let component = ReasonReact.statelessComponent("Button");

let s = ReasonReact.stringToElement;

let make = (~_type, ~className, children) => {
  ...component,
  render: _self => {
    let classNames = Cn.make([style##root, Some(className) |> Cn.ifOpt]);
    ReasonReact.createDomElement(
      "button",
      ~props={"type": _type, "className": classNames},
      children
    );
  }
};
