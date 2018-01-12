"use strict";

var Assets = require("./assets.js");

var speakers = /* array */ [
  /* record */ [
    /* name */ "Cheng Lou",
    /* company */ "Facebook",
    /* imgUrl */ Assets.chengLou
  ],
  /* record */ [
    /* name */ "Laura Gaetano",
    /* company */ "Travis Foundation",
    /* imgUrl */ Assets.lauraGaetano
  ],
  /* record */ [
    /* name */ "Keira Hodgkison",
    /* company */ "Culture Amp",
    /* imgUrl */ Assets.keiraHodgkison
  ],
  /* record */ [
    /* name */ "Cristiano Calcagno",
    /* company */ "Facebook",
    /* imgUrl */ Assets.cristianoCalcagno
  ]
];

exports.speakers = speakers;
/* Assets Not a pure module */
