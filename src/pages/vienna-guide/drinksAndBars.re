let component = ReasonReact.statelessComponent("Attendees");

let title = "Drinks & Bars";

let content = {j|
### <a href="http://www.ifdogsrunfree.com" target="_blank">If Dogs Run Free</a>
Very good cocktail place

### <a href="http://tuer7.at" target="_blank">Tuer7</a>
Awesome cocktail place, make sure to call before you go there,
there are no signs on the building, you have to ring the doorbell to get in

### <a href="dastorberg.at" target="_blank">Das Torberg</a>
This bar is dedicated to all kinds of Gin & Tonic combinations.
Huge selection of various brands and also a very moody ambience.

### <a href="singyoursong.at" target="_blank">Sing Your Song</a>
This is a very cool karaoke bar for those who like to sing their favorite
songs while having a nice drink.
|j};

let make = _children => {
  ...component,
  render: _self => <ViennaGuideSection title content />,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
