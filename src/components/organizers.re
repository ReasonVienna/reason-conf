open Util;

open Data;

let organizerWithPic = ({imgUrl, name, href}: Data.organizerData) =>
  <a href key=name>
    <img src=imgUrl alt={j|Photo of $(name)|j} />
    (name |> s)
  </a>;

let component = ReasonReact.statelessComponent("Organizers");

let make = (~organizers: list(organizerData), ~className: string, _children) => {
  ...component,
  render: _self =>
    <div className>
      (
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
      )
    </div>
};
