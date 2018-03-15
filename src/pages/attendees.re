open Util;

[@bs.module] external style : Js.t({..}) = "./attendees.module.scss";

let component = ReasonReact.statelessComponent("Attendees");

let make = _children => {
  ...component,
  render: _self =>
    <section>
      <h1> ("For Attendees" |> s) </h1>
      <main className="leadText">
        (
          {js|
ReasonConf is a 3-day event and it will take place at two different
places. But don't worry, public transportation in Vienna is
great and it's easy to reach everything by the subway, tram or
bus.
|js}
          |> md
        )
      </main>
      <h2> ("Workshop Venue" |> s) </h2>
      <main>
        (
          {js|
Workshop and hackathon days will take place at [Impact Hub Vienna](https://vienna.impacthub.net).

We'll provide you with tables, chairs, power outlets etc. Please bring your laptop with you.
|js}
          |> md
        )
      </main>
      <section className="grid--6col grid grid_6cols">
        <section className="grid--2col">
          (
            {js|
### Address
[Lindengasse 56, 1070 Vienna](maps://?q=Lindengasse+56,+1070+Vienna)

### Nearby Subway Stations
<span class="subway subway-u3">U3</span> Zieglergasse,
<span class="subway subway-u3">U3</span> Neubaugasse
|js}
            |> md
          )
        </section>
        <section className="grid--4col">
          <iframe
            src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d2659.3678616032244!2d16.343639751551496!3d48.199529954720454!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x476d078cbc5cf79b%3A0x3e9197850789a772!2sImpact+Hub+Vienna!5e0!3m2!1sen!2sat!4v1520961144665"
            className=style##map
          />
        </section>
      </section>
      <h2> ("Conference Venue" |> s) </h2>
      <main>
        (
          {js|
The conference day (day 2) will take place at the beautiful Kuppelsaal at the Technical University
Vienna.
|js}
          |> md
        )
      </main>
      <section className="grid--6col grid grid_6cols">
        <section className="grid--2col">
          (
            {js|
### Address
[Resselgasse, 1040 Vienna](maps://?q=48.19892,16.369844)

### Nearby Subway Stations
<span class="subway subway-u1">U1</span> <span class="subway subway-u2">U2</span> <span class="subway subway-u4">U4</span> Karlsplatz

  |js}
            |> md
          )
        </section>
        <section className="grid--4col">
          <iframe
            src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d2659.399509173125!2d16.369843464946502!3d48.198920303474864!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x476d0782e6d2964f%3A0x188304c94c34f778!2sDomed+hall+of+the+Vienna+University+of+Technology!5e0!3m2!1sen!2sat!4v1520960925818"
            className=style##map
          />
        </section>
      </section>
    </section>
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
