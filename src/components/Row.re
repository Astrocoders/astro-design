module Styles = {
  open Css;
  let row = (~horizontalAlign, ~verticalAlign, ~columnOnMobile) =>
    style([
      alignItems(verticalAlign),
      display(flexBox),
      flexDirection(row),
      justifyContent(horizontalAlign),
      width(pct(100.)),
      media("(max-width: 600px)", [flexDirection(columnOnMobile ? column : row)]),
    ]);
};

[@react.component]
let make = (~className="", ~horizontalAlign=`flexStart, ~verticalAlign=`flexStart, ~columnOnMobile=true, ~children) => {
  <div className=(className ++ " " ++ {Styles.row(~horizontalAlign, ~verticalAlign, ~columnOnMobile)})>
    children
  </div>;
};

let default = make;