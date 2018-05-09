open Util;

module Link = Gatsby.Link;

let component = ReasonReact.statelessComponent("ViennaGuideSection");

let make = (~title, ~content, ~backTo="attendees#exploring-vienna", _children) => {
  ...component,
  render: _self =>
    <section>
      <h1 id="top"> (title |> s) </h1>
      <p className="leadText">
        <Link to_=backTo> ("Go back" |> s) </Link>
        (" to the overview" |> s)
      </p>
      <main> (content |> md) </main>
    </section>,
};
