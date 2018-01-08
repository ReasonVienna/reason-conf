import 'normalize.css';
import React from 'react';
import Link from 'gatsby-link';
import Helmet from 'react-helmet';
import './index.css';

const TemplateWrapper = ({ children }) => (
  <div>
    <Helmet
      title="ReasonConf 2018"
      meta={[
        { name: 'description', content: 'Sample' },
        { name: 'keywords', content: 'sample, something' }
      ]}
    />
    {children()}
  </div>
);

export default TemplateWrapper;
