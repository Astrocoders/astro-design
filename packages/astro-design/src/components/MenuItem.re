module Styles = {
  open Css;

  let menuItem = (~isActive) =>
    style([
      alignItems(center),
      color(
        isActive ? hex(Theme.Colors.primary) : hex(Theme.Colors.textWhite),
      ),
      cursor(`pointer),
      display(flexBox),
      marginBottom(px(Theme.Spacing.baseHalf)),
      hover([color(hex(Theme.Colors.primary))]),
    ]);
};

[@react.component]
let make = (~icon, ~text, ~onClick, ~isActive=false) =>
  <div onClick className={Styles.menuItem(~isActive)}>
    icon
    <Separator size=10 horizontal=true />
    <span> {Utils.str(text)} </span>
  </div>;
