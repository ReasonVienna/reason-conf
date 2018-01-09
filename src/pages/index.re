let component = ReasonReact.statelessComponent("Home");

module Link = Gatsby.Link;

let ste = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    <article>
      <header className="teaser">
        <section className="teaser--wrapper container--centered">
          <main className="teaser--main">
            <h1 className="teaser--logo">
              <img src=Assets.logo alt="Reason Conf Logo" />
            </h1>
            <h2 className="teaser--tagline">
              (
                ste(
                  {j|World’s first Reason conference for web-developers & OCaml enthusiasts|j}
                )
              )
            </h2>
            <p className="teaser--text">
              (
                ste(
                  "We believe Reason is the next big thing and we think it is time to bring the community together, learn about the language and talk about new innovations.\n"
                )
              )
            </p>
          </main>
          <aside className="teaser--aside">
            <p> (ste({j|11–13 May 2018|j})) </p>
            <p> (ste("Vienna, Austria")) </p>
            <a href="#tickets"> (ste("Buy Tickets")) </a>
          </aside>
        </section>
      </header>
      <section className="timeline">
        <div className="container--centered">
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
        </div>
      </section>
      <section className="speakers">
        <div className="container--centered">
          <h2> (ste("Speakers")) </h2>
          <ul className="speaker-list">
            <li className="speaker-list--item">
              <figure className="speaker">
                <img src=Assets.chengLou width="225" height="225" />
                <figcaption>
                  <p className="speaker--name"> (ste("Cheng Lou")) </p>
                  <p className="speaker--company"> (ste("Facebook")) </p>
                </figcaption>
              </figure>
            </li>
            <li className="speaker-list--item">
              <figure className="speaker">
                <img src=Assets.lauraGaetano width="225" height="225" />
                <figcaption>
                  <p className="speaker--name"> (ste("Laura Gaetano")) </p>
                  <p className="speaker--company">
                    (ste("Travis Foundation"))
                  </p>
                </figcaption>
              </figure>
            </li>
            <li className="speaker-list--item">
              <figure className="speaker">
                <img src=Assets.keiraHodgkison width="225" height="225" />
                <figcaption>
                  <p className="speaker--name"> (ste("Keira Hodgkison")) </p>
                  <p className="speaker--company"> (ste("Culture Amp")) </p>
                </figcaption>
              </figure>
            </li>
            <li className="speaker-list--item">
              <figure className="speaker">
                <img src=Assets.cristianoCalcagno width="225" height="225" />
                <figcaption>
                  <p className="speaker--name">
                    (ste("Cristiano Calcagno"))
                  </p>
                  <p className="speaker--company"> (ste("Facebook")) </p>
                </figcaption>
              </figure>
            </li>
          </ul>
        </div>
      </section>
      <section className="sponsors">
        <div className="container--centered">
          <h2> (ste("Sponsors")) </h2>
          <p> (ste({j|Reason Conf is looking for amazing sponsors …|j})) </p>
        </div>
      </section>
      <section className="tickets">
        <div className="container--centered">
          <h2 id="tickets"> (ste("Tickets")) </h2>
          <p> (ste({j|Coming soon …|j})) </p>
        </div>
      </section>
    </article>
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
