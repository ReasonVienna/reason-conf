import React from "react";

// Support SSR
const basicscroll = typeof window !== `undefined` ? require("basicscroll") : {};

export class ParallaxScroll extends React.Component {
  componentDidMount() {
    this.initScroll();
  }
  componentWillReceiveProps() {
    this.initScroll();
  }
  componentWillUnmount() {
    this.instance.update();
    this.instance.stop();
    this.instance = null;
  }
  initScroll = () => {
    const { from, to, props } = this.props;
    this.instance = basicscroll.create({
      elem: this.element,
      from,
      to,
      props
    });
    this.instance.start();
  };
  setRef = node => {
    this.element = node;
  };
  render() {
    const { children } = this.props;
    return <div ref={this.setRef}>{children}</div>;
  }
}
