[@bs.module] external style : {. "button": string} = "./button.module.scss";

/* let style = Assets.requireSCSS("./button.module.scss"); */
let component = ReasonReact.statelessComponent("Button");

let s = ReasonReact.stringToElement;

let make = (~text="", _children) => {
  ...component,
  render: _self => <div className=style##button> (s(text)) </div>
};
