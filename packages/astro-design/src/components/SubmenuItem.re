module Styles = {
  open Css;

  let menuItem = (~isActive) =>
    style([
      color(
        isActive ? hex(Theme.Colors.primary) : hex(Theme.Colors.textWhite),
      ),
      textDecoration(`none),
      hover([color(hex(Theme.Colors.primary))]),
    ]);
};

[@react.component]
let make = (~text, ~link, ~isActive=false) =>
  <div
    className=Css.(
      style([display(flexBox), marginBottom(px(Theme.Spacing.baseHalf))])
    )>
    <Separator size=19 horizontal=true />
    <a className={Styles.menuItem(~isActive)} href=link>
      {Utils.str(text)}
    </a>
  </div>;
