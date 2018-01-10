let component = ReasonReact.statelessComponent("Home");

module Link = Gatsby.Link;

module Tickets = Tito.Tickets;

let ste = ReasonReact.stringToElement;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <article>
      <header className="teaser">
        <section className="teaser--wrapper container--centered">
          <h1 className="teaser--logo"> <img src=Assets.logo alt="Reason Conf Logo" /> </h1>
          <main className="teaser--main">
            <h2 className="teaser--tagline">
              (ste({j|World’s first Reason conference for web-developers & OCaml enthusiasts|j}))
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
            <p className="teaser--dates"> (ste({j|11–13 May 2018|j})) </p>
            <p className="teaser--location"> (ste("Vienna, Austria")) </p>
          </aside>
          <nav> <a className="teaser--button" href="#tickets"> (ste("Buy Tickets")) </a> </nav>
        </section>
      </header>
      <section className="offering">
        <div className="container--centered grid grid-6col">
          <h2 className="offering--heading"> (ste("Get productive with Reason in 3 days")) </h2>
          <p className="offering--text">
            (
              ste(
                "We want to motivate you to introduce Reason & OCaml in your production environment and make you feel  comfortable with the existing tools. For that, the conference will be focused on practice rather than theory. Enjoy 3 days of workshop / hackathon style conference with the leading speakers from around the world.\n"
              )
            )
          </p>
          <dl className="timeline">
            <dt className="timeline--date">
              <time dateTime="2018-05-11">
                (ste("11"))
                <sup> (ste("th")) </sup>
                (ste(" May, Friday"))
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> (ste("Get started")) </h3>
              <p>
                (ste("Full day workshop to get every attendee into the language & platform."))
              </p>
            </dd>
            <dt className="timeline--date">
              <time dateTime="2018-05-12">
                (ste("12"))
                <sup> (ste("th")) </sup>
                (ste(" May, Saturday"))
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> (ste("Get inspired")) </h3>
              <p>
                (
                  ste(
                    "Great speakers & trainers of the Reason community with special guests of the Reason & ReasonReact project team will inspire attendees about more advanced topics.\n"
                  )
                )
              </p>
            </dd>
            <dt className="timeline--date">
              <time dateTime="2018-05-13">
                (ste("13"))
                <sup> (ste("th")) </sup>
                (ste(" May, Sunday"))
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> (ste("Get productive")) </h3>
              <p>
                (
                  ste(
                    "Attendees apply their learnings in a hackathon, working on a project they are interested in, aided by our mentors, speakers and volunteers."
                  )
                )
              </p>
            </dd>
          </dl>
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
                  <h3 className="speaker--name"> (ste("Cheng Lou")) </h3>
                  <p className="speaker--company"> (ste("Facebook")) </p>
                </figcaption>
              </figure>
            </li>
            <li className="speaker-list--item">
              <figure className="speaker">
                <img src=Assets.lauraGaetano width="225" height="225" />
                <figcaption>
                  <h3 className="speaker--name"> (ste("Laura Gaetano")) </h3>
                  <p className="speaker--company"> (ste("Travis Foundation")) </p>
                </figcaption>
              </figure>
            </li>
            <li className="speaker-list--item">
              <figure className="speaker">
                <img src=Assets.keiraHodgkison width="225" height="225" />
                <figcaption>
                  <h3 className="speaker--name"> (ste("Keira Hodgkison")) </h3>
                  <p className="speaker--company"> (ste("Culture Amp")) </p>
                </figcaption>
              </figure>
            </li>
            <li className="speaker-list--item">
              <figure className="speaker">
                <img src=Assets.cristianoCalcagno width="225" height="225" />
                <figcaption>
                  <h3 className="speaker--name"> (ste("Cristiano Calcagno")) </h3>
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
          <Tickets event="reason-conf/reason-conf-2018" />
        </div>
      </section>
    </article>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
