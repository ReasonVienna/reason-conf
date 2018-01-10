import "normalize.css";
import React from "react";
import Link from "gatsby-link";
import Helmet from "react-helmet";
import "./index.scss";
import Footer from "../components/footer";

const TemplateWrapper = ({ children }) => (
  <article className="container">
    <Helmet
      title="ReasonConf 2018"
      meta={[
        { name: "description", content: "Reason Conf" },
        {
          name: "keywords",
          content: "Reason, Conference, ReasonML, Conf, Vienna, Austria"
        }
      ]}
    >
      <style type="text/css">{`
        @import url('https://fonts.googleapis.com/css?family=Assistant|Hammersmith+One');
    `}</style>
      <script src="https://js.tito.io/v1" async />
    </Helmet>
    <main>{children()}</main>
    <Footer />
  </article>
);

export default TemplateWrapper;
