module Styles = {
  open Css;
  let text = (~theme) => style(Theme.Helpers.color(~theme));
};

[@react.component]
let make = (~theme=`light, ~value="Loading...", ~className="") =>
  <span className={Css.merge([Styles.text(~theme), className])}>
    {Utils.str(value)}
  </span>;
