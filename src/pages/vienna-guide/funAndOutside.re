let component = ReasonReact.statelessComponent("FunAndOutside");

let title = "Fun & Outside";

let content = {j|
### <a href="http://www.prater.at" target="_blank">Prater</a>
Auge park, good for running, cycling, picknicking
one part has, the Wurstelprater, is an entertainment park with free entry
it has roller coasters, water rides and other more or less fun things on a pay-by-ride basis

### <a href="https://www.mqw.at" target="_blank">Museumsquartier</a>
The old imperial stables, now a place to hang out and chill with a choice of some bars and
restaurants. The artistic center of the hip 7th district.

### <a href="https://de.wikipedia.org/wiki/Jubiläumswarte" target="_blank">Jubiläumswarte</a>
A look-out on the hills east to the city, with a great view over all of Vienna

### <a href="https://www.schoenbrunn.at" target="_blank">Schönbrunn Palace & Park</a>
Imperial castle with a huge park

### <a href="https://www.zoovienna.at" target="_blank">Schönbrunn Imperial Zoo</a>
Next to the imperial castle, the oldest zoo in the world, opened 1752
now has a heavy focus on science and species conservation
|j};

let make = _children => {
  ...component,
  render: _self => <ViennaGuideSection title content />,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
