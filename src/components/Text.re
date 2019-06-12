module Styles = {
  open Css;

  let text = (~align, ~textColor, ~textSize) =>
    style([
      color(hex(textColor)),
      fontSize(rem(textSize)),
      margin(px(0)),
      textAlign(align)
    ]);
};

[@react.component]
let make = (~className="", ~align=`left, ~color=Theme.Colors.secondary, ~size=1., ~children) =>
  <span className=(className ++ " " ++ {Styles.text(~align,~textColor=color, ~textSize=size)})> children </span>;