let str = React.string;

module Styles = {
  open Css;
  let wrapper =
    style([
      display(flexBox),
      flexDirection(column),
      maxWidth(px(1200)),
      marginLeft(auto),
      marginRight(auto),
      paddingRight(vw(5.)),
      paddingLeft(vw(5.)),
      width(pct(100.)),
      media("(max-width: 600px)", 
        [
          paddingLeft(vw(2.)),
          paddingRight(vw(2.)),
        ]),
    ]);
};

[@react.component]
let make = (~className="", ~children) => {
  <div className=(className ++ " " ++ Styles.wrapper)>
    children
  </div>;
};

let default = make;