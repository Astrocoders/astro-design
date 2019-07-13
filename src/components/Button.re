module Styles = {
  open Css;

  let getBackgroundColor = (~type_) =>
    switch (type_) {
    | `secondary => (
        Theme.Colors.secondary,
        Theme.Colors.secondaryHover,
        Theme.Colors.secondaryActive,
      )
    | `danger => (
        Theme.Colors.error,
        Theme.Colors.errorHover,
        Theme.Colors.errorActive,
      )
    | `default => (
        Theme.Colors.primary,
        Theme.Colors.primaryHover,
        Theme.Colors.primaryActive,
      )
    };

  let button = (~type_, ~fullWidth, ~rounded, ~size) => {
    let (backgroundColor_, hoverBackgroundColor, activeBackgroundColor) =
      getBackgroundColor(~type_);

    let rules = [
      padding(px(Theme.Spacing.baseHalf)),
      fontSize(rem(1.0)),
      lineHeight(rem(0.9)),
      cursor(`pointer),
      fontWeight(`num(400)),
      borderRadius(px(4)),
      borderStyle(`none),
      display(flexBox),
      textDecoration(none),
      color(hex(Theme.Colors.textWhite)),
      backgroundColor(hex(backgroundColor_)),
      hover([backgroundColor(hex(hoverBackgroundColor))]),
      active([backgroundColor(hex(activeBackgroundColor))]),
      outlineWidth(px(0)),
      disabled([
        opacity(0.3),
        cursor(`text),
        hover([backgroundColor(hex(backgroundColor_))]),
        active([backgroundColor(hex(backgroundColor_))]),
      ]),
      ...Theme.Helpers.fullCenter,
    ];

    let rulesRounded = [
      borderRadius(`percent(Theme.Border.rounded)),
      height(px(size)),
      width(px(size)),
      boxSizing(borderBox),
      padding(px(0)),
      display(flexBox),
      alignItems(center),
      justifyContent(center),
    ];

    [
      rules,
      fullWidth ? [width(`percent(100.0))] : [],
      rounded ? rulesRounded : [],
    ]
    ->List.concat
    ->style;
  };
};

[@react.component]
let make =
    (
      ~type_=`default,
      ~fullWidth=false,
      ~disabled=false,
      ~title="",
      ~rounded=false,
      ~size=35,
      ~onClick=_ => (),
      ~className="",
      ~children,
    ) =>
  <button
    className={Css.merge([
      Styles.button(~type_, ~fullWidth, ~rounded, ~size),
      className,
    ])}
    onClick
    disabled
    title>
    children
  </button>;

let default = make;
