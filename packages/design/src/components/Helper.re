[@react.component]
let make = (~children, ~className="") =>
  <div
    className=Css.(
      merge([
        style([
          padding2(~v=px(60), ~h=px(0)),
          textAlign(center),
          fontSize(rem(0.95)),
        ]),
        className,
      ])
    )>
    children
  </div>;
