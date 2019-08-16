module Styles = {
  open Css;

  let divider = (~color, ~size, ~horizontal, ~hideOnMobile) =>
    style([
      borderColor(hex(color)),
      borderStyle(`solid),
      borderWidth(px(size)),
      borderBottomWidth(horizontal ? px(0) : px(size)),
      borderLeftWidth(horizontal ? px(size) : px(0)),
      marginLeft(horizontal ? px(0) : px(Theme.Spacing.baseHalf)),
      marginRight(horizontal ? px(0) : px(Theme.Spacing.baseHalf)),
      marginBottom(horizontal ? px(Theme.Spacing.baseHalf) : px(0)),
      marginTop(horizontal ? px(Theme.Spacing.baseHalf) : px(0)),
      width(horizontal ? pct(100.) : px(1)),
      media("(min-width: 600px)", [display(hideOnMobile ? `none : `block)]),
    ]);
};

[@react.component]
let make =
    (
      ~color=Theme.Colors.secondaryLighter,
      ~size=1,
      ~horizontal=false,
      ~hideOnMobile=false,
    ) => {
  <div
    className={Styles.divider(~color, ~size, ~horizontal, ~hideOnMobile)}
  />;
};
