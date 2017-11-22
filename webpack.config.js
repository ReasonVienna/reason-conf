const path = require('path');

module.exports = {
  entry: './lib/js/src/index.js',
  output: {
    path: path.join(__dirname, "public"),
    filename: 'app.js',
  },
};
