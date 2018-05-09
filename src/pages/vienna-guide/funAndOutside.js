"use strict";

var ReasonReact = require("reason-react/src/ReasonReact.js");
var ViennaGuideSection = require("../../components/viennaGuideSection.js");

var component = ReasonReact.statelessComponent("FunAndOutside");

var title = "Fun & Outside";

var content =
  '\n### <a href="http://www.prater.at" target="_blank">Prater</a>\nAuge park, good for running, cycling, picknicking\none part has, the Wurstelprater, is an entertainment park with free entry\nit has roller coasters, water rides and other more or less fun things on a pay-by-ride basis\n\n### <a href="https://www.mqw.at" target="_blank">Museumsquartier</a>\nThe old imperial stables, now a place to hang out and chill with a choice of some bars and\nrestaurants. The artistic center of the hip 7th district.\n\n### <a href="https://de.wikipedia.org/wiki/Jubiläumswarte" target="_blank">Jubiläumswarte</a>\nA look-out on the hills east to the city, with a great view over all of Vienna\n\n### <a href="https://www.schoenbrunn.at" target="_blank">Schönbrunn Palace & Park</a>\nImperial castle with a huge park\n\n### <a href="https://www.zoovienna.at" target="_blank">Schönbrunn Imperial Zoo</a>\nNext to the imperial castle, the oldest zoo in the world, opened 1752\nnow has a heavy focus on science and species conservation\n';

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
