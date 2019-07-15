module Styles = {
  open Css;

  let label = (~error) =>
    style([
      display(block),
      padding(px(0)),
      fontSize(rem(0.75)),
      marginBottom(rem(0.5)),
      cursor(`pointer),
      color(
        hex(
          String.length(error) > 0
            ? Theme.Colors.error : Theme.Colors.textSecondary,
        ),
      ),
    ]);
};

[@react.component]
let make = (~error, ~children, ~className="") =>
  <span className={Css.merge([Styles.label(~error), className])}>
    children
  </span>;
