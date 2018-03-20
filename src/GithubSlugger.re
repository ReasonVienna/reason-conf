type t;

[@bs.new] [@bs.module] external slugger : unit => t = "github-slugger";

[@bs.send] external reset : t => unit = "";

[@bs.send] external slug : (t, string) => string = "";

let instance = slugger();

let slug = str => {
  /* we don't care about uniqueness */
  reset(instance);
  slug(instance, str);
};
