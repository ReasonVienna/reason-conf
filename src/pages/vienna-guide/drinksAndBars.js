"use strict";

var ReasonReact = require("reason-react/src/ReasonReact.js");
var ViennaGuideSection = require("../../components/viennaGuideSection.js");

var component = ReasonReact.statelessComponent("Attendees");

var title = "Drinks & Bars";

var content =
  '\n### <a href="http://www.ifdogsrunfree.com" target="_blank">If Dogs Run Free</a>\nVery good cocktail place\n\n### <a href="http://tuer7.at" target="_blank">Tuer7</a>\nAwesome cocktail place, make sure to call before you go there,\nthere are no signs on the building, you have to ring the doorbell to get in\n\n### <a href="dastorberg.at" target="_blank">Das Torberg</a>\nThis bar is dedicated to all kinds of Gin & Tonic combinations.\nHuge selection of various brands and also a very moody ambience.\n\n### <a href="singyoursong.at" target="_blank">Sing Your Song</a>\nThis is a very cool karaoke bar for those who like to sing their favorite\nsongs while having a nice drink.\n';

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
