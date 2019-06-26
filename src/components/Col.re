module Styles = {
  open Css;
  let row = (~horizontalAlign, ~verticalAlign, ~colWidth) =>
    style([
      alignItems(horizontalAlign),
      display(flexBox),
      flexDirection(column),
      justifyContent(verticalAlign),
      width(pct(colWidth)),
      media("(max-width: 600px)", [width(pct(100.))]),
    ]);
};

[@react.component]
let make = (~className="", ~horizontalAlign=`flexStart, ~verticalAlign=`flexStart, ~width=100., ~children) => {
  <div className=(className ++ " " ++ {Styles.row(~horizontalAlign, ~verticalAlign, ~colWidth=width)})>
    children
  </div>;
};

let default = make;