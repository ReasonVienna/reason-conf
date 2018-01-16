module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./subscribeForm.module.scss";

let component = ReasonReact.statelessComponent("SubscribeForm");

let s = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    ReasonReact.cloneElement(
      <form name="subscribe" className=style##root>
        <label htmlFor="email" className=style##label> (s("Email: ")) </label>
        <input
          _type="email"
          id="email"
          placeholder="name@domain.com"
          className=style##input
        />
        <Button _type="submit" className=style##button>
          (s("Subscribe"))
        </Button>
      </form>,
      ~props={"data-netlify": true},
      [||]
    )
};
