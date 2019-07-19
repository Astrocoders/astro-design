module Styles = {
  open Css;

  let title =
    style([
      fontWeight(bold),
      marginBottom(px(Theme.Spacing.baseHalf)),
      display(flexBox),
      alignItems(center),
    ]);
};
[@react.component]
let make = (~className="", ~children) =>
  <div className={Css.merge([Styles.title, className])}> children </div>;
