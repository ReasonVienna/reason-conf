const autoprefixer = require("autoprefixer");
const { withPrefix } = require("gatsby-link");

module.exports = {
  siteMetadata: {
    title: "ReasonConf 2018",
    siteUrl: "https://reason-conf.com",
    description:
      "World's first Reason conference for web-developers & OCaml enthusiasts",
    image: withPrefix("/open-graph.jpg"),
    keywords: "Reason, ReasonML, Conference, ReasonML, Conf, Vienna, Austria"
  },
  plugins: [
    "gatsby-plugin-react-helmet",
    {
      resolve: "gatsby-plugin-postcss-sass",
      options: {
        postCssPlugins: [autoprefixer()]
      }
    },
    {
      resolve: "gatsby-plugin-google-analytics",
      options: {
        trackingId: "UA-112745828-1",
        anonymize: true
      }
    }
  ]
};
