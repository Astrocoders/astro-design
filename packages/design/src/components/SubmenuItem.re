module Styles = {
  open Css;

  let menuItem = (~isActive, ~theme) =>
    style([
      color(
        isActive
          ? hex(Theme.Colors.primary)
          : hex(
              switch (theme) {
              | `dark => Theme.Colors.textWhite
              | `light => Theme.Colors.text
              },
            ),
      ),
      textDecoration(`none),
      hover([color(hex(Theme.Colors.primary))]),
    ]);
};

[@react.component]
let make = (~text, ~link, ~isActive=false, ~theme) =>
  <div
    className=Css.(
      style([display(flexBox), marginBottom(px(Theme.Spacing.baseHalf))])
    )>
    <Separator size=19 horizontal=true />
    <a className={Styles.menuItem(~isActive, ~theme)} href=link>
      {Utils.str(text)}
    </a>
  </div>;
