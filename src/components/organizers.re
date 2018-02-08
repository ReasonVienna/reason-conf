open Util;

open Data;

[@bs.module] external style : Js.t({..}) = "./organizers.module.scss";

let organizerWithPic = ({imgUrl, name, href, twitter}: Data.organizerData) =>
  <figure key=name className=style##organizer>
    <img src=imgUrl className=style##photo alt={j|Photo of $(name)|j} />
    <figcaption className=style##info>
      <h3 className=style##name> (name |> s) </h3>
      <a href className=style##twitter> ("@" |> s) (twitter |> s) </a>
    </figcaption>
  </figure>;

let component = ReasonReact.statelessComponent("Organizers");

let make = (~organizers: list(organizerData), _children) => {
  ...component,
  render: _self =>
    <div className=style##root>
      (
        switch organizers {
        | [] => ReasonReact.nullElement
        | orgs =>
          Array.of_list(orgs)
          |> Array.map(organizerWithPic)
          |> ReasonReact.arrayToElement
        }
      )
    </div>
};
