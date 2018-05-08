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
      <h2 id="workshop-and-hackathon-venue">
        ("Workshop & Hackathon Venue" |> s)
      </h2>
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
      <h2 id="conference-venue"> ("Conference Venue" |> s) </h2>
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
      <h2 id="after-party-venue"> ("After Party Venue" |> s) </h2>
      <main>
        (
          {js|
The after party on day 2 will take place at Cafe Leopold. You can get food and drinks there and it is in walking distance to the conference venue.
      |js}
          |> md
        )
      </main>
      <section className="grid--6col grid grid_6cols">
        <section className="grid--2col">
          (
            {js|
### Address
[Museumsplatz 1, Vienna 1070](maps://?q=48.202601,16.358804)

### Nearby Subway Stations
<span class="subway subway-u2">U2</span> Museumsquartier
      |js}
            |> md
          )
        </section>
        <section className="grid--4col">
          <iframe
            src="https://www.google.com/maps/embed/v1/place?q=place_id:ChIJby9pPJAHbUcRd37S8sX_eSQ&key=AIzaSyDoRypIIXOZYLExH-dx-xpi_dhpxtCnwo0\n"
            className=style##map
          />
        </section>
      </section>
      <h2 id="sunday-dinner-venue"> ("Sunday Dinner Venue" |> s) </h2>
      <main>
        (
          {js|
After the official end of the conference we suggest to gather at a Viennese wine tavern (Heuriger). You can get food and drinks there.
      |js}
          |> md
        )
      </main>
      <section className="grid--6col grid grid_6cols">
        <section className="grid--2col">
          (
            {js|
### Address
[Mitterwurzergasse 20, 1190 Wien](maps://?q=48.252773,16.306608)
      |js}
            |> md
          )
        </section>
        <section className="grid--4col">
          <iframe
            src="https://www.google.com/maps/embed/v1/place?q=place_id:ChIJbe4fpu8IbUcR8lRIFVMXEQ4&key=AIzaSyDoRypIIXOZYLExH-dx-xpi_dhpxtCnwo0"
            className=style##map
          />
        </section>
      </section>
      <h2 id="food-and-catering"> ("Food & Catering" |> s) </h2>
      <main>
        (
          {js|
During all conference days, we will provide you with lunch, coffee and snacks.
Also to give you a better idea what to expect, here are the lunch menues for each day:

### Day 1 Menu (Workshop)

Catering is provided by bio kitchen [Issmich](https://www.issmich.at/#home).

**Morning (09:00 - 10:00)**

Coffee & Tea, Refreshments, Danish pastries (sweet & spicy), fruits

**Lunch (13:00 - 14:00)**

- Meal
  - Mediterranean citrus vegetables with Couscous
  - Indian Curry with Rice
  - Red wine goulash with Baguette
  - Maroccan chicken stew with Couscous

- Dessert
  - Apple Cake
  - Dark chocolate cake


### Day 2 Menu (Conference)

Catering is provided by our bio & vegetarian friends: [Gaumenfreundinnen](https://www.gaumenfreundinnen.com/).
Also the whole day will be supported by the great coffee makers [Kaffeemik](https://www.kaffemik.at/) to fuel everyone
with very high quality coffee.

**Morning (09:00 - 10:00)**

- Rolls with date-and-cheese spread
- Little danishes filled with apricot or plum jam

**Snacks (10:45 - 11:15)**

- Various fruits, bananas, apples, pears, strawberries
- Trail mix with nuts and dried fruits

**Lunch (12:45 - 14:15):**

- Bagels
  - ... filled with humus, basil and grilled aubergines
  - ... filled with red beets / horseradish spread and red cabbage
- Salads
  - Waldorfsalad with walnuts
  - Colorful apple / vegetable / lentils salad with dijon dressing
- Meals
  - Moroccan Tajine with chickpeas and dates
  - Spinach spaetzle with cheese sauce

**Cake Break! (16:00 - 16:30)**

- Nut-chocolate brownies
- Rhubarb streusel cake

**Evening Snacks (18:00 - 18:30)**

- Mini cinnamon buns
- Rolls with orientalic lentils spread and cucumber
- Rolls with soft goat cheese and pink pepper

### Day 3 Menu (Hackathon)

This day is more casual and we will provide basic needs, like coffee, refreshments and
some snacks. Since the schedule is very relaxed, feel free to discover the vast amount of
food places, etc. around the venue as well.

**Lunch (13:00 - 14:00)**

All kinds of Pizzas (also vegetarian and vegan)
        |js}
          |> md
        )
      </main>
    </section>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
