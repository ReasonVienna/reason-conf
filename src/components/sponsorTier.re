[@bs.module] external style : Js.t({..}) = "./sponsorTier.module.scss";

open Util;

let component = ReasonReact.statelessComponent("SponsorTier");

let make = (~tier: Data.tierData, _children) => {
  ...component,
  render: _self => {
    let className =
      switch tier.id {
      | "main" => style##main
      | "regular" => style##regular
      | "supporter" => style##supporter
      | "*" => style##root
      | "" => style##root
      };
    let href = "mailto:hi@reason-conf.com?subject=Sponsoring: " ++ tier.name;
    <a href className>
      <header className=style##header>
        <h3 className=style##name> (tier.name |> s) </h3>
        <p className=style##amount>
          (tier.amount |> string_of_int |> s)
          ({js| × |js} |> s)
          <h4 className=style##cost> (tier.cost |> string_of_int |> s) </h4>
          ({js|€|js} |> s)
        </p>
      </header>
      <section className=style##description>
        (tier.description |> md)
      </section>
    </a>;
  }
};
