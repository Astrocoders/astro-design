module Styles = {
  open Css;

  let title =
      (~align, ~titleColor, ~titleSize, ~pBottom, ~isUppercase, ~weight) =>
    style([
      display(flexBox),
      alignItems(center),
      color(hex(titleColor)),
      fontSize(rem(titleSize)),
      fontWeight(`num(weight)),
      paddingBottom(px(pBottom)),
      textTransform(isUppercase ? uppercase : none),
      textAlign(align),
      width(auto),
    ]);
};

[@react.component]
let make =
    (
      ~className="",
      ~align=`center,
      ~color=Theme.Colors.secondary,
      ~size=Theme.FontSize.title,
      ~pBottom=Theme.Spacing.baseHalf,
      ~isUppercase=false,
      ~weight=700,
      ~children,
    ) =>
  <h2
    className={
      className
      ++ " "
      ++ Styles.title(
           ~align,
           ~titleColor=color,
           ~pBottom,
           ~titleSize=size,
           ~isUppercase,
           ~weight,
         )
    }>
    children
  </h2>;
