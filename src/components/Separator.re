
open AstroDesign;

module Styles = {
  open Css;

  let separator = (~size, ~horizontal) =>
    style([
      marginBottom(horizontal ? px(0) : px(size)),
      width(horizontal ? px(size*2) : pct(100.)),
    ]);

};

[@react.component]
let make = (~size=Theme.Spacing.base, ~horizontal=false) => {
  <div className=(Styles.separator(~size, ~horizontal)) />
};
