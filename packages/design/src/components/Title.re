module Styles = {
  open Css;

  let title =
      (
        ~align,
        ~justify,
        ~titleColor,
        ~titleSize,
        ~pBottom,
        ~isUppercase,
        ~weight,
      ) =>
    style([
      color(hex(titleColor)),
      fontSize(rem(titleSize)),
      fontWeight(`num(weight)),
      paddingBottom(px(pBottom)),
      textTransform(isUppercase ? uppercase : none),
      textAlign(align),
    ]);
};

[@react.component]
let make =
    (
      ~className="",
      ~align=`left,
      ~justify=`flexStart,
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
        ~align,
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
