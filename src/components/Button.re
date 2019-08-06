module Styles = {
  open Css;

  let getBackgroundColor = (~type_) =>
    switch (type_) {
    | `secondary => (
        hex(Theme.Colors.secondary),
        hex(Theme.Colors.secondaryHover),
        hex(Theme.Colors.secondaryActive),
      )
    | `danger => (
        hex(Theme.Colors.error),
        hex(Theme.Colors.errorHover),
        hex(Theme.Colors.errorActive),
      )
    | `default => (
        hex(Theme.Colors.primary),
        hex(Theme.Colors.primaryHover),
        hex(Theme.Colors.primaryActive),
      )
    | `transparent => (transparent, rgba(0, 0, 0, 0.05), rgba(0, 0, 0, 0.1))
    };

  let getColor = (~text) =>
    switch (text) {
    | `text => hex(Theme.Colors.text)
    | `textSecondary => hex(Theme.Colors.textSecondary)
    | `default => hex(Theme.Colors.textWhite)
    };

  let button = (~type_, ~text, ~fullWidth, ~rounded, ~size) => {
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
      display(inlineFlex),
      textDecoration(none),
      color(getColor(~text)),
      backgroundColor(backgroundColor_),
      hover([backgroundColor(hoverBackgroundColor)]),
      active([backgroundColor(activeBackgroundColor)]),
      outlineWidth(px(0)),
      disabled([
        opacity(0.3),
        cursor(`text),
        hover([backgroundColor(backgroundColor_)]),
        active([backgroundColor(backgroundColor_)]),
      ]),
      ...Theme.Helpers.fullCenter,
    ];

    let rulesRounded = [
      borderRadius(`percent(Theme.Border.rounded)),
      height(px(size)),
      width(px(size)),
      boxSizing(borderBox),
      padding(px(0)),
      display(inlineFlex),
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
      ~text=`default,
      ~disabled=false,
      ~title="",
      ~rounded=false,
      ~loading=false,
      ~size=35,
      ~onClick=_ => (),
      ~className="",
      ~children,
    ) =>
  <button
    className={Css.merge([
      Styles.button(~type_, ~text, ~fullWidth, ~rounded, ~size),
      className,
    ])}
    onClick
    disabled={disabled || loading}
    title>
    {loading ? <Spinner /> : children}
  </button>;

let default = make;
