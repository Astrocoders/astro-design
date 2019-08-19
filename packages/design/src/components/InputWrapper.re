module Styles = {
  open Css;

  let wrapper =
    style([
      paddingBottom(px(Theme.Spacing.baseHalf)),
      width(`percent(100.0)),
      display(block),
    ]);
};

[@react.component]
let make = (~children, ~className="") =>
  <label className={Css.merge([Styles.wrapper, className])}>
    children
  </label>;
