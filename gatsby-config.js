const autoprefixer = require("autoprefixer");
module.exports = {
  siteMetadata: {
    title: `Reason Conf 2018`
  },
  plugins: [
    `gatsby-plugin-react-helmet`,
    {
      resolve: `gatsby-plugin-postcss-sass`,
      options: {
        postCssPlugins: [autoprefixer()]
      }
    }
  ]
};
