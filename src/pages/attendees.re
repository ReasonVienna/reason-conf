open Util;

[@bs.module] external style : Js.t({..}) = "./attendees.module.scss";

let component = ReasonReact.statelessComponent("Attendees");

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> ("For Attendees" |> s) </h1>
      <h2> ("Workshop Location" |> s) </h2>
      <main>
        (
          {js|
Workshop and hackathon days will take place at [Impact Hub Vienna](https://vienna.impacthub.net).

We'll provide you with tables, chairs, power outlets etc.
|js}
          |> md
        )
      </main>
      <aside>
        <iframe
          src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d2659.3678616032244!2d16.343639751551496!3d48.199529954720454!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x476d078cbc5cf79b%3A0x3e9197850789a772!2sImpact+Hub+Vienna!5e0!3m2!1sen!2sat!4v1520961144665"
          className=style##map
        />
        (
          {js|

[Lindengasse 56, 1070 Vienna](https://www.google.at/maps/place/Lindengasse+56,+1070+Wien/@48.199726,16.3435315,17z/data=!3m1!4b1!4m5!3m4!1s0x476d078cbbb85c8b:0xd4fa23aab5e92936!8m2!3d48.1997224!4d16.3457255?hl=en)
|js}
          |> md
        )
      </aside>
      <h2> ("Conference Venue" |> s) </h2>
      <main>
        (
          {js|
The conference day will take place at the beautiful Kuppelsaal at the Technical University
Vienna.
|js}
          |> md
        )
      </main>
      <aside>
        <iframe
          src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d2659.399509173125!2d16.369843464946502!3d48.198920303474864!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x476d0782e6d2964f%3A0x188304c94c34f778!2sDomed+hall+of+the+Vienna+University+of+Technology!5e0!3m2!1sen!2sat!4v1520960925818"
          className=style##map
        />
        (
          {js|

[Resselgasse, 1040 Vienna](https://www.google
.at/maps/place/Domed+hall+of+the+Vienna+University+of+Technology/@48.1989239,16.3676495,17z/data=!3m1!4b1!4m5!3m4!1s0x476d0782e6d2964f:0x188304c94c34f778!8m2!3d48.1989203!4d16.3698435?hl=en)

|js}
          |> md
        )
      </aside>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
