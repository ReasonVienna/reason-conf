"use strict";

var ReasonReact = require("reason-react/src/ReasonReact.js");
var ViennaGuideSection = require("../../components/viennaGuideSection.js");

var component = ReasonReact.statelessComponent("Coffee");

var title = "Good Coffee Places";

var content =
  '\n### <a href="https://www.kaffemik.at" target="_blank">kaffemik</a>\n3rd wave coffeshop\n\n###  <a href="http://www.kaffeefabrik.at" target="_blank">kaffeefabrik</a>\nNear the Technical University where the conference takes place\n\n### <a href="http://cafejelinek.steman.at" target="_blank">Cafe Jelinek</a>\nVery special Altwiener coffee house in the 6th District close to ImpactHub.\nAuthentic old style, proper Wiener Melange and handmade cakes and other small Viennese dishes.\n\n### <a href="http://cafesperl.at" target="_blank">Cafe Sperl</a>\nAltwiener coffee house since 1880. Also very authentic Viennese flair and very well conserved\nstyle of the early 19 hundreds. Check for the visiting time, it is usually well visited on weekends\nand holidays.\n';

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
