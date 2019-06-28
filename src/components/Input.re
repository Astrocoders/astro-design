module Styles = {
  open Css;

  let field = (~fullWidth) =>
    style([
      paddingRight(px(fullWidth ? 0 : 10)),
      width(pct(fullWidth ? 100. : 50.))
    ]);
  let input =
    style([
      backgroundColor(hex(Theme.Colors.textWhite)),
      borderWidth(px(0)),
      borderRadius(px(Theme.Border.default)),
      color(hex(Theme.Colors.secondary)),
      display(block),
      padding(px(Theme.Spacing.baseHalf)),
      marginBottom(px(Theme.Spacing.baseHalf)),
      width(pct(100.))
    ]);

  let logoText = 
    style([
      textTransform(uppercase)
    ]);
};

[@react.component]
let make = (~className="", ~inputStyle="", ~name, ~type_="text", ~placeholder="", ~fullWidth=true, ~required=false) => {
   <div className=(className ++ " " ++ Styles.field(~fullWidth))>
    <input name type_ placeholder required className=(inputStyle ++ " " ++ Styles.input)/>
  </div>;
};

let default = make;