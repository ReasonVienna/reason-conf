"use strict";

var $$Array = require("bs-platform/lib/js/array.js");
var NikJpg = require("./assets/nik.jpg");
var AndreyJpg = require("./assets/andrey.jpg");
var SanderJpg = require("./assets/sander.jpg");
var PatrickJpg = require("./assets/patrick.jpg");
var ChengLouJpg = require("./assets/cheng-lou.jpg");
var LauraGaetanoJpg = require("./assets/laura-gaetano.jpg");
var KeiraHodgkisonJpg = require("./assets/keira-hodgkison.jpg");
var CristianoCalcagnoJpg = require("./assets/cristiano-calcagno.jpg");

var headlineSpeakers = /* array */ [
  /* record */ [
    /* name */ "Cheng Lou",
    /* company */ "Facebook",
    /* imgUrl */ ChengLouJpg,
    /* description */ "I work on Reason and Facebook Messenger",
    /* talk : Some */ [
      /* record */ [/* title */ "This is a Test title", /* abstract */ "Foo"]
    ],
    /* social : record */ [
      /* twitterUser : Some */ ["_chenglou"],
      /* githubUser : Some */ ["chenglou"],
      /* website : None */ 0
    ]
  ],
  /* record */ [
    /* name */ "Laura Gaetano",
    /* company */ "Travis Foundation",
    /* imgUrl */ LauraGaetanoJpg,
    /* description */ "Laura is a manager at Travis Foundation and the organiser of Rails Girls Summer of Code (https://railsgirlssummerofcode.org/) — a 3-month scholarship program to support women in the Open Source community. With a background in the visual arts and a non-traditional career path, she landed in tech as a web developer somewhat by accident. Laura is passionate about making things, coaching at programming workshops, Open Source software, feminism, music and space (as in rockets).",
    /* talk : None */ 0,
    /* social : record */ [
      /* twitterUser : Some */ ["alicetragedy"],
      /* githubUser : Some */ ["alicetragedy"],
      /* website : Some */ ["http://www.alicetragedy.org/"]
    ]
  ],
  /* record */ [
    /* name */ "Keira Hodgkison",
    /* company */ "Culture Amp",
    /* imgUrl */ KeiraHodgkisonJpg,
    /* description */ "Keira is a developer at Culture Amp, the world's leading culture analytics platform. She works with React, Flow, and Rails on solutions to help customers share, and act upon company employee engagement data. Keira is an advocate for using functional programming techniques to improve the JavaScript coding and refactoring experience. When she's not writing code, she can be found under a large cat.",
    /* talk : None */ 0,
    /* social : record */ [
      /* twitterUser : Some */ ["keirasaid"],
      /* githubUser : Some */ ["keirah"],
      /* website : None */ 0
    ]
  ],
  /* record */ [
    /* name */ "Cristiano Calcagno",
    /* company */ "Facebook",
    /* imgUrl */ CristianoCalcagnoJpg,
    /* description */ "Engineer at Facebook.\nCo-creator of @fbinfer, founder of Monoidics, reformed academic.\nInto developer experience, front-end, static analysis, language design.\nEarly @reasonml adopter, co-creator of ReasonReact.",
    /* talk : None */ 0,
    /* social : record */ [
      /* twitterUser : Some */ ["ccrisccris"],
      /* githubUser : Some */ ["cristianoc"],
      /* website : None */ 0
    ]
  ]
];

var otherSpeakers = /* array */ [
  /* record */ [
    /* name */ "Sander Spies",
    /* company */ "Freelancer",
    /* imgUrl */ SanderJpg,
    /* description */ "As a developer always focusing on the reader of the code. Fell in love with React in 2013 because of the simplification it brought to state management. Regrets asking for Flux. Big fan of CSS-in-JS and currently lost in OCaml. Strongly believes in the importance of moving developers to Reason as it removes a lot of the burdens that JavaScript developers face daily. Can be blamed for several things in Reason like JSX. Reason fan since day one.",
    /* talk : Some */ [
      /* record */ [
        /* title */ "Down the WebAssembly rabbit hole",
        /* abstract */ "TBA"
      ]
    ],
    /* social : record */ [
      /* twitterUser : Some */ ["Sander_Spies"],
      /* githubUser : Some */ ["SanderSpies"],
      /* website : None */ 0
    ]
  ]
];

var speakers = $$Array.concat(
  /* :: */ [headlineSpeakers, /* :: */ [otherSpeakers, /* [] */ 0]]
);

var organizers_000 = /* record */ [
  /* name */ "Nik",
  /* imgUrl */ NikJpg,
  /* href */ "https://twitter.com/nikgraf",
  /* altText */ "Photo of Nik"
];

var organizers_001 = /* record */ [
  /* name */ "Andrey",
  /* imgUrl */ AndreyJpg,
  /* href */ "https://twitter.com/okonetchnikov",
  /* altText */ "Photo of Andrey"
];

var organizers_002 = /* record */ [
  /* name */ "Patrick",
  /* imgUrl */ PatrickJpg,
  /* href */ "https://twitter.com/ryyppy",
  /* altText */ "Photo of Patrick"
];

var organizers = /* tuple */ [organizers_000, organizers_001, organizers_002];

exports.headlineSpeakers = headlineSpeakers;
exports.otherSpeakers = otherSpeakers;
exports.speakers = speakers;
exports.organizers = organizers;
/* headlineSpeakers Not a pure module */
