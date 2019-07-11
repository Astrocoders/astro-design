[@react.component]
let make = (~children) =>
  <div
    className=Css.(
      style([
        padding2(~v=px(60), ~h=px(0)),
        textAlign(center),
        fontSize(rem(0.95)),
      ])
    )>
    children
  </div>;
