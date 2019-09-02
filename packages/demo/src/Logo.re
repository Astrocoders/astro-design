open AstrocodersDesign;

module Styles = {
  open Css;

  let title = (~theme) => style(Theme.Helpers.color(~theme));
};

[@react.component]
let make = (~theme) => {
  <Title className={Styles.title(~theme)} pBottom=0>
    {Utils.str("Astrocoders")}
  </Title>;
};
