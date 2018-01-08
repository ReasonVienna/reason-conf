let component = ReasonReact.statelessComponent("CodeOfConduct");

module Link = Gatsby.Link;

let ste = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <div>
        (
          ste(
            "World's first Reason conference for web-developers & OCaml enthusiasts"
          )
        )
      </div>
      <div>
        <div> (ste("11-13 May 2018")) </div>
        <div> (ste("Vienna, Austria")) </div>
      </div>
      <p>
        (
          ste(
            "We believe Reason is the next big thing and we think it is time to bring the community together, learn about the language and talk about new innovations.\n"
          )
        )
      </p>
      <h2> (ste("Get productive with Reason in 3 days")) </h2>
      <div>
        <div> (ste("Day 1")) </div>
        <h3> (ste("Get started")) </h3>
        <div>
          (
            ste(
              "Full day workshop to get every attendee into the language & platform."
            )
          )
        </div>
      </div>
      <div>
        <div> (ste("Day 2")) </div>
        <h3> (ste("Get inspired")) </h3>
        <div>
          (
            ste(
              "Great speakers & trainers of the Reason community with special guests of the Reason & ReasonReact project team will inspire attendees about more advanced topics.\n"
            )
          )
        </div>
      </div>
      <div>
        <div> (ste("Day 3")) </div>
        <h3> (ste("Get productive")) </h3>
        <div>
          (
            ste(
              "Attendees apply their learnings in a hackathon, working on a project they are interested in, aided by our mentors, speakers and volunteers."
            )
          )
        </div>
      </div>
      <h2> (ste("Speakers")) </h2>
      <h2> (ste("Sponsors")) </h2>
      <div>
        <p>
          (
            ste(
              "ReasonConf is the not-for-profit conference\norganized by community efforts by people\nbehind React Vienna community."
            )
          )
        </p>
        <div> <Link to_="/coc/"> (ste("Code of Conduct")) </Link> </div>
      </div>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
