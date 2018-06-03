module Link = Gatsby.Link;

open Util;

[@bs.module] external style : Js.t({..}) = "./subscribeForm.module.scss";

let component = ReasonReact.statelessComponent("SubscribeForm");

let make = _children => {
  ...component,
  render: _self =>
    ReasonReact.cloneElement(
      <form
        action="https://reason-conf.us17.list-manage.com/subscribe/post?u=2ff99718c52457a4fa5219f66&amp;id=3e392893b9"
        method="post"
        id="mc-embedded-subscribe-form"
        name="mc-embedded-subscribe-form"
        className=style##root
        target="_blank">
        <p className=style##text>
          (s("Get ReasonConf news straight to your inbox."))
        </p>
        <p className=style##smallText>
          (
            {js|We use MailChimp as newsletter tool. By subscribing you acknowledge that the information
                you provide will be transferred to MailChimp for processing in accordance with their
                [Privacy Policy](https://mailchimp.com/legal/privacy/) and [Terms](https://mailchimp.com/legal/terms/).
            |js}
            |> md
          )
        </p>
        <div className=style##formRow>
          <label htmlFor="email" className=style##label>
            ("Email" |> s)
          </label>
          <input
            _type="email"
            name="EMAIL"
            className=style##input
            id="mce-EMAIL"
            placeholder="name@domain.com"
            required=true
          />
          <div className=style##hiddenInput>
            <input
              _type="text"
              name="b_2ff99718c52457a4fa5219f66_3e392893b9"
              tabIndex=(-1)
            />
          </div>
          <Button _type="submit"> (s("Subscribe")) </Button>
        </div>
        <input _type="hidden" name="form-name" value="newsletter" />
      </form>,
      ~props={"data-netlify": true},
      [||],
    ),
};
