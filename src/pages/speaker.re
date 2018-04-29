[@bs.module] external style : Js.t({..}) = "./speaker.module.scss";

let component = ReasonReact.statelessComponent("Speaker");

let toSpeakerDetail = (speaker: Data.Speaker.t) =>
  <div className=style##teaser key=speaker.name>
    <h1 className=style##logo>
      <img src=Assets.logo alt="ReasonConf 2018" className="teaser--image" />
    </h1>
    <section className=style##speakerCard> <SpeakerCard speaker /> </section>
  </div>;

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <main className="container_centered">
        <section className=style##speakers>
          (
            Data.Speaker.speakers
            |> Array.map(toSpeakerDetail)
            |> ReasonReact.array
          )
        </section>
      </main>
    </section>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
