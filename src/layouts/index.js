import 'normalize.css';
import React from 'react';
import Link from 'gatsby-link';
import Helmet from 'react-helmet';
import './index.css';
import Footer from '../components/footer';

const TemplateWrapper = ({ children }) => (
  <div>
    <Helmet
      title="ReasonConf 2018"
      meta={[
        { name: 'description', content: 'Reason Conf' },
        {
          name: 'keywords',
          content: 'Reason, Conference, ReasonML, Conf, Vienna, Austria'
        }
      ]}
    />
    {children()}
    <Footer />
  </div>
);

export default TemplateWrapper;
