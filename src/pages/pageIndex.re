open Util;

let component = ReasonReact.statelessComponent("Home");

module Link = Gatsby.Link;

module Tickets = Tito.Tickets;

let speakerColumn = (i, speaker) =>
  <SpeakerCard speaker key=(string_of_int(i)) />;

let make = _children => {
  ...component,
  render: _self =>
    <article>
      <header className="teaser">
        <Navigation />
        <section className="container_centered grid grid-6col">
          <h1 className="teaser--logo">
            <img
              src=Assets.logo
              alt="Reason Conf Logo"
              className="teaser--image"
            />
          </h1>
          <aside className="teaser--dates">
            <time dateTime="2018-05-11/2018-05-13" className="teaser--date">
              (
                ste(
                  {j|11–13
                       May
                      2018|j}
                )
              )
            </time>
            <p className="teaser--location"> (ste("Vienna, Austria")) </p>
          </aside>
          <main className="teaser--main">
            <h2 className="teaser--tagline">
              (
                {j|World’s first Reason conference for web-developers & OCaml enthusiasts|j}
                |> s
              )
            </h2>
            <p className="teaser--text">
              (

                  "Reason is the next big thing and it is time to bring the community together. Come and learn about the language and get inspired for innovation.\n"
                  |> s
              )
            
          </main>
          <nav>
            <a className="teaser--button" href="#tickets">
              ("Buy Tickets" |> s)
            </a>
          </nav>
        </section>
      </header>
      <section className="offering">
        <div className="container_centered grid grid-6col">
          <h2 className="offering--heading">
            ("Get productive with Reason in 3 days" |> s)
          </h2>
          <p className="offering--text">
            (
              "We want to motivate you to introduce Reason & OCaml in your production environment and make you feel  comfortable with the existing tools. For that, the conference will be focused on practice rather than theory. Enjoy 3 days of workshop / hackathon style conference with the leading speakers from around the world.\n"
              |> s
            )
          </p>
          <dl className="timeline">
            <dt className="timeline--date">
              <time dateTime="2018-05-11">
                ("11" |> s)
                <sup> ("th" |> s) </sup>
                (" May, Friday" |> s)
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> ("Get started" |> s) </h3>
              <p>
                (
                  "Full day workshop to get every attendee into the language & platform."
                  |> s
                )
              </p>
            </dd>
            <dt className="timeline--date">
              <time dateTime="2018-05-12">
                ("12" |> s)
                <sup> ("th" |> s) </sup>
                (" May, Saturday" |> s)
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> ("Get inspired" |> s) </h3>
              <p>
                (
                  "Great speakers & trainers of the Reason community with special guests of the Reason & ReasonReact project team will inspire attendees about more advanced topics.\n"
                  |> s
                )
              </p>
            </dd>
            <dt className="timeline--date">
              <time dateTime="2018-05-13">
                ("13" |> s)
                <sup> ("th" |> s) </sup>
                (" May, Sunday" |> s)
              </time>
            </dt>
            <dd className="timeline--content">
              <h3> ("Get productive" |> s) </h3>
              <p>
                (
                  "Attendees apply their learnings in a hackathon, working on a project they are interested in, aided by our mentors, speakers and volunteers."
                  |> s
                )
              </p>
            </dd>
          </dl>
        </div>
      </section>
      <section className="speakers">
        <div className="container_centered">
          <h2> ("Speakers" |> s) </h2>
          <ul className="speaker-list">
            (
              Data.speakers
              |> Array.mapi(speakerColumn)
              |> ReasonReact.arrayToElement
            )
          </ul>
        </div>
      </section>
      <section className="sponsors">
        <div className="container_centered">
          <h2> ("Sponsors" |> s) </h2>
          <p> ({j|Reason Conf is looking for amazing sponsors …|j} |> s) </p>
        </div>
      </section>
      <section className="tickets">
        <div className="container--centered">
          <h2 id="tickets"> ("Tickets" |> s) </h2>
          <Tickets event="reason-conf/reason-conf-2018" />
        </div>
      </section>
    </article>
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));
