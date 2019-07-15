module Styles = {
  open Css;

  let field =
    style([
      alignItems(center),
      display(flexBox)
    ]);

  let input =
    style([
      borderWidth(px(0)),
      background(none),
      cursor(`pointer),
      height(px(24)),
      width(px(20)),
      unsafe("-webkit-appearance", "none")
    ]);

  let label =
    style([
      paddingLeft(px(Theme.Spacing.baseHalf))
    ]);
};

[@react.component]
let make = (~className="", ~label="") => {
   <div className=(className ++ " " ++ Styles.field)>
    <input type_="color" name="color-picker" className=Styles.input value=Theme.Colors.primary />
    <label htmlFor="color-picker" className=Styles.label>{Utils.str(label)}</label>
  </div>;
};

let default = make;