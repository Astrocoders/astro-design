module Styles = {
  open Css;

  let tr =
    style([
      hover([backgroundColor(hex(Theme.Colors.backgroundContrastHover))]),
    ]);
};

[@react.component]
let make = (~children, ~className="", ~onClick=_ => ()) =>
  <tr className={Css.merge([Styles.tr, className])} onClick> children </tr>;
