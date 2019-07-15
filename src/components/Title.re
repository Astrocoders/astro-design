module Styles = {
  open Css;

  let title =
      (~justify, ~titleColor, ~titleSize, ~pBottom, ~isUppercase, ~weight) =>
    style([
      display(flexBox),
      alignItems(center),
      justifyContent(justify),
      color(hex(titleColor)),
      fontSize(rem(titleSize)),
      fontWeight(`num(weight)),
      paddingBottom(px(pBottom)),
      textTransform(isUppercase ? uppercase : none),
      width(auto),
    ]);
};

[@react.component]
let make =
    (
      ~className="",
      ~justify=`center,
      ~color=Theme.Colors.secondary,
      ~size=Theme.FontSize.title,
      ~pBottom=Theme.Spacing.baseHalf,
      ~isUppercase=false,
      ~weight=700,
      ~children,
    ) =>
  <h2
    className={Css.merge([
      Styles.title(
        ~justify,
        ~titleColor=color,
        ~pBottom,
        ~titleSize=size,
        ~isUppercase,
        ~weight,
      ),
      className,
    ])}>
    children
  </h2>;
