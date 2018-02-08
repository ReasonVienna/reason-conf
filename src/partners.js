"use strict";

var AgentConfSvg = require("./assets/partners/agent-conf.svg");
var ScriptConfSvg = require("./assets/partners/script-conf.svg");
var ReactViennaSvg = require("./assets/partners/React-Vienna.svg");
var ReasonviennaSvg = require("./assets/partners/reasonvienna.svg");
var ReactFinlandSvg = require("./assets/partners/react-finland.svg");
var ReactAmsterdamSvg = require("./assets/partners/react-amsterdam.svg");

var partners = /* array */ [
  /* record */ [
    /* name */ "Agent Conf",
    /* logoUrl */ AgentConfSvg,
    /* href */ "https://www.agent.sh/"
  ],
  /* record */ [
    /* name */ "React Amsterdam",
    /* logoUrl */ ReactAmsterdamSvg,
    /* href */ "https://react.amsterdam"
  ],
  /* record */ [
    /* name */ "React Finland",
    /* logoUrl */ ReactFinlandSvg,
    /* href */ "https://react-finland.fi"
  ],
  /* record */ [
    /* name */ "React Vienna",
    /* logoUrl */ ReactViennaSvg,
    /* href */ "https://www.meetup.com/ReactVienna/"
  ],
  /* record */ [
    /* name */ "ReasonVienna",
    /* logoUrl */ ReasonviennaSvg,
    /* href */ "https://www.meetup.com/ReasonVienna/"
  ],
  /* record */ [
    /* name */ "Script Conf",
    /* logoUrl */ ScriptConfSvg,
    /* href */ "https://scriptconf.org"
  ]
];

exports.partners = partners;
/* partners Not a pure module */
