module Styles = {
  open Css;

  let tr = style([hover([backgroundColor(rgba(0, 0, 0, 0.07))])]);
};

[@react.component]
let make = (~children, ~className="", ~onClick=_ => ()) =>
  <tr className={Css.merge([Styles.tr, className])} onClick> children </tr>;
