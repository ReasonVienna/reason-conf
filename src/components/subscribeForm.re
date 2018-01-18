module Link = Gatsby.Link;

open Util;

[@bs.module] external style : Js.t({..}) = "./subscribeForm.module.scss";

let component = ReasonReact.statelessComponent("SubscribeForm");

let make = _children => {
  ...component,
  render: _self =>
    ReasonReact.cloneElement(
      <form
        name="newsletter"
        action="/thanks/"
        className=style##root
        method="post">
        <p className=style##text>
          (
            s(
              "Get Reason Conf news straight to your inbox. No spam, we promise!"
            )
          )
        </p>
        <div className=style##formRow>
          <label htmlFor="email" className=style##label>
            (s("Email: "))
          </label>
          <input
            _type="email"
            name="email"
            id="email"
            placeholder="name@domain.com"
            className=style##input
          />
          <Button _type="submit"> (s("Subscribe")) </Button>
        </div>
        <input _type="hidden" name="form-name" value="newsletter" />
      </form>,
      ~props={"data-netlify": Js.true_},
      [||]
    )
};
