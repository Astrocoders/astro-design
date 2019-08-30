module Styles = {
  open Css;

  let menuItem = (~isActive, ~theme) =>
    style([
      alignItems(center),
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
      cursor(`pointer),
      display(flexBox),
      hover([color(hex(Theme.Colors.primary))]),
    ]);
};

[@react.component]
let make = (~icon, ~text, ~onClick, ~isActive=false, ~theme) =>
  <div onClick className={Styles.menuItem(~isActive, ~theme)}>
    icon
    <Separator size=10 horizontal=true />
    <span> {Utils.str(text)} </span>
  </div>;
