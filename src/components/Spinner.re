module Styles = {
  open Css;

  let rotate =
    keyframes([
      (0, [transform(rotate(deg(0)))]),
      (100, [transform(rotate(deg(360)))]),
    ]);

  let spinner =
    style([
      animation(
        ~duration=2,
        ~timingFunction=`linear,
        ~iterationCount=`infinite,
        rotate,
      ),
    ]);
};

[@react.component]
let make = () => <ReactIcons.FiLoader className=Styles.spinner />;

let default = make;
