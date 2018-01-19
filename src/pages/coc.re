let component = ReasonReact.statelessComponent("CodeOfConduct");

let ste = ReasonReact.stringToElement;
let ate = ReasonReact.arrayToElement;

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (ste("Conference Code of Conduct")) </h1>
      <p>
        (
          ste(
            "All attendees, speakers, sponsors and volunteers at our conference are required to agree with the following code of conduct. Organisers will enforce this code throughout the event. We expect cooperation from all participants to help ensure a safe environment for everybody."
          )
        )
      </p>
      <h2> (ste("Need Help?")) </h2>
      <p> (ste("You have our contact details in the emails we’ve sent.")) </p>
      <h2> (ste("The Quick Version")) </h2>
      <p>
        (
          ate([|
            (ste("Our conference is dedicated to providing a harassment-free conference experience for everyone, regardless of gender, gender identity and expression, age, sexual orientation, disability, physical appearance, body size, race, ethnicity, religion (or lack thereof), or technology choices. We do not tolerate harassment of conference participants in any form. Sexual language and imagery is not appropriate for any conference venue, including talks, workshops, parties, Twitter and other online media. Conference participants violating these rules may be sanctioned or expelled from the conference ")),
            <em>(ste("without a refund"))</em>,
            (ste(" at the discretion of the conference organisers.")),
          |])
        )
      </p>
      <h2> (ste("The Less Quick Version")) </h2>
      <p>
        (
          ste(
            "Harassment includes offensive verbal comments related to gender, gender identity and expression, age, sexual orientation, disability, physical appearance, body size, race, ethnicity, religion, technology choices, sexual images in public spaces, deliberate intimidation, stalking, following, harassing photography or recording, sustained disruption of talks or other events, inappropriate physical contact, and unwelcome sexual attention."
          )
        )
      </p>
      <p>
        (
          ste(
            "Participants asked to stop any harassing behavior are expected to comply immediately."
          )
        )
      </p>
      <p>
        (
          ste(
            "Sponsors are also subject to the anti-harassment policy. In particular, sponsors should not use sexualised images, activities, or other material. Booth staff (including volunteers) should not use sexualised clothing/uniforms/costumes, or otherwise create a sexualised environment."
          )
        )
      </p>
      <p>
        (
          ste(
            "If a participant engages in harassing behavior, the conference organisers may take any action they deem appropriate, including warning the offender or expulsion from the conference with no refund."
          )
        )
      </p>
      <p>
        (
          ste(
            "If you are being harassed, notice that someone else is being harassed, or have any other concerns, please contact a member of conference staff immediately. Conference staff can be identified as they’ll be wearing branded clothing and/or badges."
          )
        )
      </p>
      <p>
        (
          ste(
            "Conference staff will be happy to help participants contact hotel/venue security or local law enforcement, provide escorts, or otherwise assist those experiencing harassment to feel safe for the duration of the conference. We value your attendance."
          )
        )
      </p>
      <p>
        (
          ste(
            "We expect participants to follow these rules at conference and workshop venues and conference-related social events."
          )
        )
      </p>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
