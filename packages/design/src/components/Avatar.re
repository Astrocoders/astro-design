module Styles = {
  open Css;
  let avatar = (~size) =>
    style([width(px(size)), height(px(size)), borderRadius(pct(50.))]);
};

[@react.component]
let make = (~src, ~size=32, ()) =>
  <img src className={Styles.avatar(~size)} />;
