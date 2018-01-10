'use strict';

var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Footer      = require("../components/footer.js");
var Gatsby      = require("../gatsby.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

require('normalize.css')
;

require('./index.scss')
;

var component = ReasonReact.statelessComponent("TemplateWrapper");

var metaData = /* array */[
  {
    name: "description",
    content: "Reason Conf"
  },
  {
    name: "keywords",
    content: "Reason, ReasonML, Conference, ReasonML, Conf, Vienna, Austria"
  }
];

var styleImport = " @import url(\'https://fonts.googleapis.com/css?family=Assistant|Hammersmith+One\'); ";

function make(children) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("article", {
                  className: "container"
                }, ReasonReact.element(/* None */0, /* None */0, Gatsby.Helmet[/* make */0](/* Some */["ReasonConf 2018"], /* Some */[metaData], /* array */[])), React.createElement("style", {
                      type: "text/css"
                    }, styleImport), React.createElement("main", undefined, Curry._1(children, /* () */0)), ReasonReact.element(/* None */0, /* None */0, Footer.make(/* array */[])));
    });
  return newrecord;
}

var $$default = ReasonReact.wrapReasonForJs(component, (function (jsProps) {
        return make(jsProps.children);
      }));

var Helmet = 0;

exports.Helmet      = Helmet;
exports.component   = component;
exports.metaData    = metaData;
exports.styleImport = styleImport;
exports.make        = make;
exports.$$default   = $$default;
exports.default     = $$default;
exports.__esModule  = true;
/*  Not a pure module */
