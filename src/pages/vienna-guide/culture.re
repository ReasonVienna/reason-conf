let component = ReasonReact.statelessComponent("Culture");

let title = "Culture";

let content = {j|
### <a href="https://www.musikverein.at" target="_blank">Musikverein</a>
Classical concerts in concert hall built in 1870, the Golden Hall is famous for
the yearly New Years Concert by the Vienna Philharmonics

### <a href="http://www.nhm-wien.ac.at" target="_blank">Naturhistorisches Museum</a>
Former imperial natural history museum, with a vast spectrum of exhibitions

### <a href="https://albertina.at" target="_blank">Albertina</a>
Various exhibitions of modernist art with Monet to Picasso being a permanent one

### <a href="https://www.leopoldmuseum.org/" target="_blank">Leopold</a>
museum featuring famous artists like Egon Schiele and Gustav Klimit
|j};

let make = _children => {
  ...component,
  render: _self => <ViennaGuideSection title content />,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
