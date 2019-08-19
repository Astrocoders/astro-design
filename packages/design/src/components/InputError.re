module Styles = {
  open Css;

  let error =
    style([
      padding3(~top=px(5), ~h=px(0), ~bottom=px(0)),
      margin(px(0)),
      fontSize(rem(0.7)),
      color(hex(Theme.Colors.error)),
    ]);
};

let renderError = (error, className) =>
  <span className={Css.merge([Styles.error, className])}>
    {React.string(error)}
  </span>;

[@react.component]
let make = (~error, ~className="") =>
  String.length(error) > 0 ? renderError(error, className) : React.null;
