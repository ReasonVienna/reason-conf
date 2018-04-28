module Link = Gatsby.Link;

open Util;

[@bs.module] external style : Js.t({..}) = "./contactForm.module.scss";

let component = ReasonReact.statelessComponent("ContactForm");

let make = _children => {
  ...component,
  render: _self =>
    ReasonReact.cloneElement(
      <form
        name="contact" action="/thanks/" className=style##root method="post">
        <div className=style##formRow>
          <label htmlFor="name" className=style##label> ("Name" |> s) </label>
          <input
            _type="text"
            name="name"
            id="name"
            placeholder="John Appleseed"
            className=style##input
            required=true
          />
        </div>
        <div className=style##formRow>
          <label htmlFor="email" className=style##label>
            ("Email" |> s)
          </label>
          <input
            _type="email"
            name="email"
            id="email"
            placeholder="name@domain.com"
            className=style##input
            required=true
          />
        </div>
        <div className=style##formRow>
          <label htmlFor="message" className=style##label>
            ("Message" |> s)
          </label>
          <textarea
            id="message"
            name="message"
            className=style##textarea
            required=true
          />
        </div>
        <Button _type="submit" className=style##submit>
          (s("Submit"))
        </Button>
        <input _type="hidden" name="form-name" value="contact" />
      </form>,
      ~props={"data-netlify": true},
      [||],
    ),
};
