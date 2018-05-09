"use strict";

var ReasonReact = require("reason-react/src/ReasonReact.js");
var ViennaGuideSection = require("../../components/viennaGuideSection.js");

var component = ReasonReact.statelessComponent("Food");

var title = "Food";

var content =
  '\n\n## Quick & Good\n\n### <a href="http://www.natsu-sushi.at/japan-lokal-7" target="_blank">Natsu Sushi (7th district)</a>\nVery small sushi place with a very low price and very high quality. Really good fast-food alternative and\nvery close to ImpactHub.\n\n### <a href="https://goo.gl/maps/wjNM86ETcAR2" target="_blank">Berlin Döner</a>\nQuick and very tasty Döner / Kebab / Falafel. Very close to ImpactHub and very long opening hours.\nQuite a hip location for 7th district hipsters.\n\n### <a href="http://www.cafeeuropa.at" target="_blank">Cafe Europa</a>\nGood breakfast, lunch; in the evening a popular bar\n\n## Austrian Flair\n\n### <a href="https://goo.gl/maps/GFSngrv82Vk" target="_blank">Wiedner Bräu</a>\nBrewery and traditional Austrian food place.\n\nWe especially recommend their sweet main dishes\nlike Kaiserschmarrn (scrambled pancakes).\n\n### <a href="https://www.glacisbeisl.at/" target="_blank">Glacis Beisl</a>\nGood Austrian food, nice garden, near Museumsquartier\n\n### <a href="http://brillantengrund.com/restaurant/" target="_blank">Brilliantengrund Restaurant</a>\nVery good Pinoy food, also not very far from the ImpactHub\n\n### <a href="http://zawodsky.at" target="_blank">Zawodsky</a>\nTraditonal Austrian Heurigen (wine tavern) in the middle of wine hills and a view over Vienna\n(might want to take a cab there; ~25 Euro)\n\n### <a href="http://www.weinbau-leitner.at" target="_blank">Leitner</a>\nAlso a nice Heurigen on a hill, but a bit easier to reach\n\n### <a href="https://10ermarie.at" target="_blank">10er Marie</a>\nA good Heurigen, but quite central and easy to reach via tram; a bit touristy\n\n### <a href="http://stadtkrems.steman.at" target="_blank">Zur Stadt Krems</a>\nTraditional Austrian food, near the ImpactHub where the workshop takes place\n(closed on weekends)\n\n## Burgers & Craft Beers (Ken Wheeler Approved)\n\n### <a href="http://www.brickmakers.at" target="_blank">Brickmakers</a>\nBBQ place with a good selection of beers, near ImpactHub\n\n### <a href="http://www.rinderwahn.at" target="_blank">Rinderwahn</a>\nGood burgers and craft beer, very close to the city center & St. Stephens Cathedral\n\n### <a href="https://goo.gl/maps/ams1UH9P4uq">Hawidere</a>\nExceptionally good burgers & fries. Even the buns are handmade. Also they have a vast\nselection of different craft beers & ciders. Make sure to make a reservation beforehand.\n\n## Pizza\n\n### <a href="http://www.ilmare.at" target="_blank">Il Mare</a>\nItalian place with decent pizza and nice outside seating near ImpactHub\n\n### <a href="http://www.disco-volante.at" target="_blank">Disco Volante</a>\nDispite the name, it\'s a very good pizza place and not a club (but the pizza oven is a huge disco ball!)\n\n### <a href="https://goo.gl/maps/wK62y6bbZzG2" target="_blank">Mia Cucina</a>\nCute little place with a very good Pizza and a streetside guest garden.\n\n\n## Others\n\n### <a href="https://goo.gl/maps/HMckA9Rdox32" target="_blank">Swing Kitchen</a>\nExclusively Vegan Burgers and other vegan dishes. Really famous for their healthy and\ngreat alternatives to common fast-food.\n\n### <a href="http://www.haonoodle.at" target="_blank">Hǎo Noodle and Tea</a>\nVery good Chinese restaurant on the Ring street\n\n### <a href="http://www.7stern.net" target="_blank">Siebenstern</a>\nBreakfast in the morning, lunch, and bar in the evening\n\n### <a href="http://diehalle.at" target="_blank">Die Halle</a>\nGood food in the Museumsquartier, also nice in the evening\n\n\n';

function make() {
  return /* record */ [
    /* debugName */ component[/* debugName */ 0],
    /* reactClassInternal */ component[/* reactClassInternal */ 1],
    /* handedOffState */ component[/* handedOffState */ 2],
    /* willReceiveProps */ component[/* willReceiveProps */ 3],
    /* didMount */ component[/* didMount */ 4],
    /* didUpdate */ component[/* didUpdate */ 5],
    /* willUnmount */ component[/* willUnmount */ 6],
    /* willUpdate */ component[/* willUpdate */ 7],
    /* shouldUpdate */ component[/* shouldUpdate */ 8],
    /* render */ function() {
      return ReasonReact.element(
        /* None */ 0,
        /* None */ 0,
        ViennaGuideSection.make(title, content, /* None */ 0, /* array */ [])
      );
    },
    /* initialState */ component[/* initialState */ 10],
    /* retainedProps */ component[/* retainedProps */ 11],
    /* reducer */ component[/* reducer */ 12],
    /* subscriptions */ component[/* subscriptions */ 13],
    /* jsElementWrapped */ component[/* jsElementWrapped */ 14]
  ];
}

var $$default = ReasonReact.wrapReasonForJs(component, function(jsProps) {
  return make(jsProps.children);
});

exports.component = component;
exports.title = title;
exports.content = content;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* component Not a pure module */
