let component = ReasonReact.statelessComponent("Home");

module Link = Gatsby.Link;

let ste = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <div className="teaser">
        <div>
          <img src=Assets.logo width="507" height="132" />
          <p>
            (
              ste(
                "World's first Reason conference for web-developers & OCaml enthusiasts"
              )
            )
          </p>
          <p>
            (
              ste(
                "We believe Reason is the next big thing and we think it is time to bring the community together, learn about the language and talk about new innovations.\n"
              )
            )
          </p>
        </div>
        <div>
          <div> (ste({j|11–13 May 2018|j})) </div>
          <div> (ste("Vienna, Austria")) </div>
          <a href="#tickets"> (ste("Buy Tickets")) </a>
        </div>
      </div>
      <h2> (ste("Get productive with Reason in 3 days")) </h2>
      <div>
        <div> (ste("Day 1")) </div>
        <h3> (ste("Get started")) </h3>
        <p>
          (
            ste(
              "Full day workshop to get every attendee into the language & platform."
            )
          )
        </p>
      </div>
      <div>
        <div> (ste("Day 2")) </div>
        <h3> (ste("Get inspired")) </h3>
        <p>
          (
            ste(
              "Great speakers & trainers of the Reason community with special guests of the Reason & ReasonReact project team will inspire attendees about more advanced topics.\n"
            )
          )
        </p>
      </div>
      <div>
        <div> (ste("Day 3")) </div>
        <h3> (ste("Get productive")) </h3>
        <p>
          (
            ste(
              "Attendees apply their learnings in a hackathon, working on a project they are interested in, aided by our mentors, speakers and volunteers."
            )
          )
        </p>
      </div>
      <h2> (ste("Speakers")) </h2>
      <div>
        <img src=Assets.chengLou width="225" height="225" />
        <div> (ste("Cheng Lou")) </div>
        <div> (ste("Facebook")) </div>
        <img src=Assets.lauraGaetano width="225" height="225" />
        <div> (ste("Laura Gaetano")) </div>
        <div> (ste("Travis Foundation")) </div>
        <img src=Assets.keiraHodgkison width="225" height="225" />
        <div> (ste("Keira Hodgkison")) </div>
        <div> (ste("Culture Amp")) </div>
        <img src=Assets.cristianoCalcagno width="225" height="225" />
        <div> (ste("Cristiano Calcagno")) </div>
        <div> (ste("Facebook")) </div>
      </div>
      <h2> (ste("Sponsors")) </h2>
      <p> (ste({j|Reason Conf is looking for amazing sponsors …|j})) </p>
      <h2 id="tickets"> (ste("Tickets")) </h2>
      <p> (ste({j|Coming soon …|j})) </p>
      <div>
        <img src=Assets.patrick width="28" height="28" />
        (ste("Patrick"))
        <img src=Assets.nik width="28" height="28" />
        (ste("Nik &"))
        <img src=Assets.andrey width="28" height="28" />
        (ste("Andrey"))
        <p>
          (
            ste(
              "ReasonConf is the not-for-profit conference\norganized by community efforts by people\nbehind React Vienna community."
            )
          )
        </p>
        <div>
          <a href="https://www.example.com">
            (ste("Subscribe to Newsletter"))
          </a>
          <Link to_="/coc/"> (ste("Code of Conduct")) </Link>
          <a href="https://www.example.com"> (ste("Contact Us")) </a>
        </div>
        <div>
          <a href="https://twitter.com/reasonconf"> (ste("Twitter")) </a>
          <a href="https://www.facebook.com"> (ste("Facebook")) </a>
          <a href="https://www.github.com"> (ste("Github")) </a>
        </div>
        <div>
          <Link to_="/imprint/"> (ste("Imprint")) </Link>
          <div> (ste({j|© Atrium, 2018|j})) </div>
        </div>
      </div>
    </div>
};

let default =
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
