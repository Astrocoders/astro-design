module Style = {
  open Css;

  let td =
    style([
      padding2(~v=rem(0.5), ~h=rem(0.0)),
      overflow(hidden),
      textOverflow(ellipsis),
      fontSize(rem(0.95)),
      color(hex(Theme.Colors.text)),
      selector(":not(:last-child)", [paddingRight(rem(1.5))]),
    ]);
};

[@react.component]
let make = (~children) => <td className=Style.td> children </td>;
