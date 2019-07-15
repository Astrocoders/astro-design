module Styles = {
  open Css;

  let panel =
    style([
      width(`percent(100.0)),
      boxSizing(borderBox),
      padding(px(Theme.Spacing.base)),
      backgroundColor(hex(Theme.Colors.backgroundContrast)),
    ]);
};
[@react.component]
let make = (~className="", ~children) =>
  <div className={Css.merge([Styles.panel, className])}> children </div>;
