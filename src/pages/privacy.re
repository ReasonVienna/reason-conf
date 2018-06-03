open Util;

let component = ReasonReact.statelessComponent("Privacy");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      (
        {j|
# Privacy Policy

## Data protection

The operators of this website and the conference take the protection of your personal data very
seriously. We treat your personal data as confidential and in accordance with the statutory data
protection regulations and this privacy policy.

If you use this website, various pieces of personal data will be collected. Personal information
is any data with which you could be personally identified. This privacy policy explains what
information we collect and what we use it for. It also explains how and for what purpose this happens.

Please note that data transmitted via the internet (e.g. via email communication) may be subject
to security breaches. Complete protection of your data from third-party access is not possible.

## Notice concerning the party responsible for this website

The party responsible for processing data on this website is:

Nikolaus Graf

Johann Knoll Gasse 9, 1210 Vienna, Austria

[nik@reason-conf.com](mailto:nik@reason-conf.com)

The responsible party is the natural or legal person who jointly with others decides on the
purposes and means of processing personal data (names, email addresses, etc.).

## Revocation of your consent to the processing of your data

Many data processing operations are only possible with your express consent. You may revoke your
consent at any time with future effect. An informal email making this request is sufficient.
The data processed before we receive your request may still be legally processed.

## Information, blocking, deletion

As permitted by law, you have the right to be provided at any time with information free of charge
about any of your personal data that is stored as well as its origin, the recipient and the purpose
for which it has been processed. You also have the right to have this data corrected, blocked or
deleted. You can contact us at any time using the address given in our legal notice if you have
further questions on the topic of personal data.

## Third Party Services

Depending on what features and services you use we me store different data.

### Netlify

The website is hosted via the service Netlify. By visiting the website Netlify stores access logs
including the IP addresses, stored for less than 30 days.

### Tito

We use Tito to manage and process the tickets of the conference. An up to date compilation of the
personal data they collect and for how long they retain it can be found in their
[Tito Privacy Statement](https://ti.to/privacy).

### Stripe

If you purchase a ticket the payment is handled by Stripe. They store the cardholder name,
email address, unique customer identifier, order ID, bank account details, payment card details,
card expiration date, CVC code, date/time/amount of transaction, merchant name/ID and location.
For further details please see the [Stripe Privacy Statement](https://stripe.com/at/privacy/).

### Mailchimp

If you would like to receive our newsletter, we require a valid email address as well as information
that allows us to verify that you are the owner of the specified email address and that you agree to
receive this newsletter. No additional data is collected or is only collected on a voluntary basis.
We only use this data to send the requested information and do not pass it on to third parties.

We will, therefore, process any data you enter onto the contact form only with your consent.
You can revoke consent to the storage of your data and email address as well as their use for
sending the newsletter at any time, e.g. through the "unsubscribe" link in the newsletter.
The data processed before we receive your request may still be legally processed.

The data provided when registering for the newsletter will be used to distribute the newsletter
until you cancel your subscription when said data will be deleted. Data we have stored for other
purposes (e.g. email addresses for tickets) remain unaffected.

For further details please see the [Mailchimp Privacy Statement](https://mailchimp.com/legal/privacy/).

### Google Drive

Google Drive is used to store and edit our internal documents. Some of these documents contain names,
email adresses, payment information, company information and profile pictures collected when a ticket
is purchased.

### Sirportly

To manage incoming requests via email to hi@reason-conf.com as well as social media correspandance
we use the service Sirportly.

### Yandex

All emails going to an address with the URL reason-conf.com are stored and retained in Yandex's email service.

## Questions and Feedback

We try to keep our privacy policy transparent and easy to understand. In case you have any
questions or do not understand parts of it, please let us know if we can improve it further or if
you have any other questions: [hi@reason-conf.com](hi@reason-conf.com).

## Changes

We reserve the right to update or modify this Privacy Policy from time to time without prior notice.
Please review this document especially before you provide any information. This Privacy Policy was
last updated on the date indicated below. Your continued use of the Services after any changes or
revisions to this Privacy Policy shall indicate your agreement with the terms of such revised
Privacy Policy.

The last update to our Privacy Statement was posted on June 3rd, 2018.
|j}
        |> md
      )
    </div>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
