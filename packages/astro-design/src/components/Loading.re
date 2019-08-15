open AstroDesign;

module Styles = {
  open Css;
  let text = (~theme) =>
    style([
      color(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.textWhite
          | `light => Theme.Colors.text
          },
        ),
      ),
    ]);
};

[@react.component]
let make = (~theme=`light, ~className="") =>
  <span className={Css.merge([Styles.text(~theme), className])}>
    {Utils.str("Loading...")}
  </span>;
