module Styles = {
  open Css;

  let panel = (~background) =>
    style([
      width(`percent(100.0)),
      boxSizing(borderBox),
      padding(px(Theme.Spacing.base)),
      backgroundColor(hex(background)),
    ]);
};
[@react.component]
let make = (~className="", ~background=Theme.Colors.backgroundContrast, ~children) =>
  <div className={Css.merge([Styles.panel(~background), className])}> children </div>;
