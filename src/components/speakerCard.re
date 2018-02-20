[@bs.module] external style : Js.t({..}) = "./speakerCard.module.scss";

open Util;

module ParallaxScroll = Gatsby.ParallaxScroll;

let component = ReasonReact.statelessComponent("SpeakerCard");

let make = (~speaker: Data.speakerData, _children) => {
  ...component,
  render: _self =>
    <ParallaxScroll
      from="top-bottom"
      to_="bottom-top"
      props={
        "--speakers-ty": {
          "from": "100px",
          "to": "-100px"
        }
      }>
      <figure className=style##root>
        <img src=speaker.imgUrl alt=speaker.name />
        <figcaption className=style##description>
          <h3 className=style##name> (speaker.name |> s) </h3>
          <p className=style##company> (speaker.company |> s) </p>
        </figcaption>
      </figure>
    </ParallaxScroll>
};
