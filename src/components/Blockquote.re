module Styles = {
  open Css;
  let blockquoteWrapper =
    style([
      backgroundColor(hex(Theme.Colors.secondaryLighter)),
      borderRadius(px(3)),
      padding(px(Theme.Spacing.base)),
    ]);
};

[@react.component]
let make = (~children) =>
  <blockquote className=Styles.blockquoteWrapper> children </blockquote>;
