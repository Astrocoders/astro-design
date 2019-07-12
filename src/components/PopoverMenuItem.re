module Styles = {
  open Css;

  let wrapper =
    style([
      backgroundColor(hex(Theme.Colors.widget)),
      color(hex(Theme.Colors.text)),
      fontSize(rem(Theme.FontSize.text)),
      padding4(
        ~top=px(Theme.Spacing.baseHalf - 5),
        ~right=px(Theme.Spacing.base2),
        ~bottom=px(Theme.Spacing.baseHalf - 5),
        ~left=px(Theme.Spacing.baseHalf),
      ),
      cursor(`pointer),
      hover([backgroundColor(hex(Theme.Colors.widgetHover))]),
      active([backgroundColor(hex(Theme.Colors.widgetActive))]),
    ]);
};

[@react.component]
let make = (~onClick, ~className="", ~children) =>
  <div className=Css.(merge([Styles.wrapper, className])) onClick>
    children
  </div>;
