module Styles = {
  open Css;

  let title = (~align, ~titleColor, ~titleSize, ~isUppercase, ~weight) =>
    style([
      color(hex(titleColor)),
      fontSize(rem(titleSize)),
      fontWeight(weight),
      paddingBottom(px(Theme.Spacing.base/2)),
      textTransform(isUppercase ? uppercase : none),
      textAlign(align),
      width(auto)
    ]);
};

[@react.component]
let make = (~className="", ~align=`center, ~color=Theme.Colors.secondary, ~size=Theme.FontSize.title, ~isUppercase=false, ~weight=700, ~children) =>
  <h2 className=(className ++ " " ++ {Styles.title(~align, ~titleColor=color, ~titleSize=size, ~isUppercase, ~weight)})> children </h2>;