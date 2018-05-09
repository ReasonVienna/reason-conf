let component = ReasonReact.statelessComponent("Coffee");

let title = "Good Coffee Places";

let content = {j|
### <a href="https://www.kaffemik.at" target="_blank">kaffemik</a>
3rd wave coffeshop

###  <a href="http://www.kaffeefabrik.at" target="_blank">kaffeefabrik</a>
Near the Technical University where the conference takes place

### <a href="http://cafejelinek.steman.at" target="_blank">Cafe Jelinek</a>
Very special Altwiener coffee house in the 6th District close to ImpactHub.
Authentic old style, proper Wiener Melange and handmade cakes and other small Viennese dishes.

### <a href="http://cafesperl.at" target="_blank">Cafe Sperl</a>
Altwiener coffee house since 1880. Also very authentic Viennese flair and very well conserved
style of the early 19 hundreds. Check for the visiting time, it is usually well visited on weekends
and holidays.
|j};

let make = _children => {
  ...component,
  render: _self => <ViennaGuideSection title content />,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
