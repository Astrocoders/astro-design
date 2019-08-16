module Styles = {
  open Css;

  let link = style([textDecoration(none)]);
};

[@react.component]
let make = (~href, ~target="_blank", ~className="", ~children) => {
  <a href target className={Css.merge([className, Styles.link])}>
    children
  </a>;
};
