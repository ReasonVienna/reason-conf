"use strict";

var ReasonReact = require("reason-react/src/ReasonReact.js");
var ViennaGuideSection = require("../../components/viennaGuideSection.js");

var component = ReasonReact.statelessComponent("Culture");

var title = "Culture";

var content =
  '\n### <a href="https://www.musikverein.at" target="_blank">Musikverein</a>\nClassical concerts in concert hall built in 1870, the Golden Hall is famous for\nthe yearly New Years Concert by the Vienna Philharmonics\n\n### <a href="http://www.nhm-wien.ac.at" target="_blank">Naturhistorisches Museum</a>\nFormer imperial natural history museum, with a vast spectrum of exhibitions\n\n### <a href="https://albertina.at" target="_blank">Albertina</a>\nVarious exhibitions of modernist art with Monet to Picasso being a permanent one\n\n### <a href="https://www.leopoldmuseum.org/" target="_blank">Leopold</a>\nmuseum featuring famous artists like Egon Schiele and Gustav Klimit\n';

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
