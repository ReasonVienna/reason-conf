const puppeteer = require("puppeteer");

(async () => {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();
  await page.goto("http://localhost:8000/speaker");
  const elements = await page.$$(
    ".src-pages----speaker-module---teaser---1pAxE"
  );
  const promises = elements.map(async el => {
    const clip = await el.boundingBox();
    const name = await page.evaluate(
      element => element.innerHTML,
      await el.$("h3")
    );
    console.log(`Exporting ${name}...`);
    return page.screenshot({
      path: `speaker-${name}.png`,
      clip
    });
  });
  Promise.all(promises)
    .then(async () => {
      console.log("All speakers screenshots exported!");
      await browser.close();
    })
    .catch(async err => {
      console.error(err)
      await browser.close();
    });
})();
