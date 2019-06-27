module Styles = {
  open Css;

  let text = (~align, ~textColor, ~textSize, ~textLineHeight) =>
    style([
      color(hex(textColor)),
      fontSize(rem(textSize)),
      lineHeight(pct(textLineHeight)),
      textAlign(align)
    ]);
};

[@react.component]
let make = (~className="", ~align=`left, ~lineHeight=150., ~color=Theme.Colors.secondary, ~size=Theme.FontSize.text, ~children) =>
  <span className=(className ++ " " ++ {Styles.text(~align,~textColor=color, ~textSize=size, ~textLineHeight=lineHeight)})> children </span>;