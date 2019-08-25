module Styles = {
  open Css;
  let blockquoteWrapper = (~theme) =>
    style([
      color(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.textWhite
          | `light => Theme.Colors.text
          },
        ),
      ),
      backgroundColor(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.secondaryLighter
          | `light => Theme.Colors.backgroundContrast
          },
        ),
      ),
      borderRadius(px(3)),
      padding(px(Theme.Spacing.base)),
    ]);
};

[@react.component]
let make = (~theme=`light, ~children) =>
  <blockquote className={Styles.blockquoteWrapper(~theme)}>
    children
  </blockquote>;
