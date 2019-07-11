[@react.component]
let make = (~children) =>
  <td
    colSpan=100
    className=Css.(
      style([
        padding2(~v=px(60), ~h=px(0)),
        textAlign(center),
        fontSize(rem(0.95)),
      ])
    )>
    children
  </td>;
