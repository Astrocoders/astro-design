module Styles = {
  open Css;

  let panel = (~theme) =>
    style([
      width(`percent(100.0)),
      boxSizing(borderBox),
      padding(px(Theme.Spacing.base)),
      backgroundColor(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.secondaryLighter
          | `light => Theme.Colors.backgroundContrast
          },
        ),
      ),
    ]);
};
[@react.component]
let make = (~className="", ~theme=`light, ~children) =>
  <div className={Css.merge([Styles.panel(~theme), className])}>
    children
  </div>;
