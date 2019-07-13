module Style = {
  open Css;

  let td = (~isButton) => {
    let rules = [
      padding2(~v=rem(0.2), ~h=rem(0.0)),
      overflow(hidden),
      textOverflow(ellipsis),
      fontSize(rem(0.95)),
      color(hex(Theme.Colors.text)),
      selector(":not(:last-child)", [paddingRight(rem(1.5))]),
    ];
    let buttonRules = [width(`percent(1.0)), whiteSpace(nowrap)];

    [rules, isButton ? buttonRules : []]->List.concat->style;
  };
};

[@react.component]
let make = (~className="", ~isButton=false, ~children) =>
  <td className=Css.(merge([Style.td(~isButton), className]))>
    children
  </td>;
