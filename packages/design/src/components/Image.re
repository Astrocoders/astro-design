module Styles = {
  open Css;

  let image = (~imageWidth) =>
    style([display(block), width(pct(imageWidth))]);
};

[@react.component]
let make = (~src, ~width=100., ~alt="", ~title="", ~className="") =>
  <img
    alt
    src
    className={Css.merge([Styles.image(~imageWidth=width), className])}
    title
  />;
