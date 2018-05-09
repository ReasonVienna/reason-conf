let component = ReasonReact.statelessComponent("Food");

let title = "Food";

let content = {j|

## Quick & Good

### <a href="http://www.natsu-sushi.at/japan-lokal-7" target="_blank">Natsu Sushi (7th district)</a>
Very small sushi place with a very low price and very high quality. Really good fast-food alternative and
very close to ImpactHub.

### <a href="https://goo.gl/maps/wjNM86ETcAR2" target="_blank">Berlin Döner</a>
Quick and very tasty Döner / Kebab / Falafel. Very close to ImpactHub and very long opening hours.
Quite a hip location for 7th district hipsters.

### <a href="http://www.cafeeuropa.at" target="_blank">Cafe Europa</a>
Good breakfast, lunch; in the evening a popular bar

## Austrian Flair

### <a href="https://goo.gl/maps/GFSngrv82Vk" target="_blank">Wiedner Bräu</a>
Brewery and traditional Austrian food place.

We especially recommend their sweet main dishes
like Kaiserschmarrn (scrambled pancakes).

### <a href="https://www.glacisbeisl.at/" target="_blank">Glacis Beisl</a>
Good Austrian food, nice garden, near Museumsquartier

### <a href="http://brillantengrund.com/restaurant/" target="_blank">Brilliantengrund Restaurant</a>
Very good Pinoy food, also not very far from the ImpactHub

### <a href="http://zawodsky.at" target="_blank">Zawodsky</a>
Traditonal Austrian Heurigen (wine tavern) in the middle of wine hills and a view over Vienna
(might want to take a cab there; ~25 Euro)

### <a href="http://www.weinbau-leitner.at" target="_blank">Leitner</a>
Also a nice Heurigen on a hill, but a bit easier to reach

### <a href="https://10ermarie.at" target="_blank">10er Marie</a>
A good Heurigen, but quite central and easy to reach via tram; a bit touristy

### <a href="http://stadtkrems.steman.at" target="_blank">Zur Stadt Krems</a>
Traditional Austrian food, near the ImpactHub where the workshop takes place
(closed on weekends)

## Burgers & Craft Beers (Ken Wheeler Approved)

### <a href="http://www.brickmakers.at" target="_blank">Brickmakers</a>
BBQ place with a good selection of beers, near ImpactHub

### <a href="http://www.rinderwahn.at" target="_blank">Rinderwahn</a>
Good burgers and craft beer, very close to the city center & St. Stephens Cathedral

### <a href="https://goo.gl/maps/ams1UH9P4uq">Hawidere</a>
Exceptionally good burgers & fries. Even the buns are handmade. Also they have a vast
selection of different craft beers & ciders. Make sure to make a reservation beforehand.

## Pizza

### <a href="http://www.ilmare.at" target="_blank">Il Mare</a>
Italian place with decent pizza and nice outside seating near ImpactHub

### <a href="http://www.disco-volante.at" target="_blank">Disco Volante</a>
Dispite the name, it's a very good pizza place and not a club (but the pizza oven is a huge disco ball!)

### <a href="https://goo.gl/maps/wK62y6bbZzG2" target="_blank">Mia Cucina</a>
Cute little place with a very good Pizza and a streetside guest garden.


## Others

### <a href="https://goo.gl/maps/HMckA9Rdox32" target="_blank">Swing Kitchen</a>
Exclusively Vegan Burgers and other vegan dishes. Really famous for their healthy and
great alternatives to common fast-food.

### <a href="http://www.haonoodle.at" target="_blank">Hǎo Noodle and Tea</a>
Very good Chinese restaurant on the Ring street

### <a href="http://www.7stern.net" target="_blank">Siebenstern</a>
Breakfast in the morning, lunch, and bar in the evening

### <a href="http://diehalle.at" target="_blank">Die Halle</a>
Good food in the Museumsquartier, also nice in the evening


|j};

let make = _children => {
  ...component,
  render: _self => <ViennaGuideSection title content />,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps => make(jsProps##children));
