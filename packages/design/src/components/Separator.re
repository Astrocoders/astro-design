module Styles = {
  open Css;

  let separator = (~size, ~horizontal, ~hideOnMobile) =>
    style([
      marginBottom(horizontal ? px(0) : px(size)),
      width(horizontal ? px(size * 2) : pct(100.)),
      media("(min-width: 600px)", [display(hideOnMobile ? `none : `block)]),
    ]);
};

[@react.component]
let make = (~size=Theme.Spacing.base, ~horizontal=false, ~hideOnMobile=false) => {
  <div className={Styles.separator(~size, ~horizontal, ~hideOnMobile)} />;
};
