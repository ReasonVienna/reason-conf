open Util;

open Data;

[@bs.module] external style : Js.t({..}) = "./organizers.module.scss";

let organizerWithPic = ({imgUrl, name, href}: Data.organizerData) =>
  <a href className=style##creator key=name>
    <img src=imgUrl alt={j|Photo of $(name)|j} className=style##userpic />
    (name |> s)
  </a>;

let component = ReasonReact.statelessComponent("Organizers");

let make = (~organizers: list(organizerData), _children) => {
  ...component,
  render: _self =>
    switch organizers {
    | [] => ReasonReact.nullElement
    | [o3, ...rest] =>
      <span>
        (
          /* Lists are only tail-spreadable, so we consider
             the first element to be the last to be rendered */
          Array.of_list(rest)
          |> Array.map(organizerWithPic)
          |> ReasonReact.arrayToElement
        )
        (" & " |> s)
        (organizerWithPic(o3))
      </span>
    }
};
