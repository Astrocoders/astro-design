type type_ = [ | `success | `warn | `error | `info];

module Styles = {
  open Css;

  let getBackgroundColor = (~type_) =>
    switch (type_) {
    | `success => Theme.Colors.success
    | `warn => Theme.Colors.warn
    | `error => Theme.Colors.error
    | `info => Theme.Colors.info
    };

  let wrapper = (~type_) =>
    style([
      borderRadius(px(4)),
      display(flexBox),
      marginBottom(rem(1.)),
      overflow(hidden),
      color(hex(Theme.Colors.textWhite)),
      backgroundColor(hex(getBackgroundColor(~type_))),
      width(`percent(100.)),
    ]);

  let icon =
    style([
      flexShrink(0),
      padding2(~v=rem(0.), ~h=rem(1.25)),
      fontSize(rem(2.)),
      display(flexBox),
      justifyContent(center),
      alignItems(center),
    ]);

  let message =
    style([
      padding2(~h=px(0), ~v=px(Theme.Spacing.baseHalf)),
      flexGrow(1.),
      paddingLeft(px(Theme.Spacing.baseHalf / 2)),
    ]);

  let title = style([fontSize(rem(0.9)), marginBottom(px(2))]);

  let text = style([fontSize(rem(0.8))]);
};

let getIcon = (~type_) =>
  switch (type_) {
  | `success => <ReactIcons.FiCheck />
  | `warn => <ReactIcons.FiAlertTriangle />
  | `error => <ReactIcons.FiXCircle />
  | `info => <ReactIcons.FiInfo />
  };

[@react.component]
let make = (~className="", ~type_, ~title, ~children) => {
  <div className={Css.merge([Styles.wrapper(~type_), className])}>
    <div className=Styles.icon> {getIcon(~type_)} </div>
    <div className=Styles.message>
      <h4 className=Styles.title> {Utils.str(title)} </h4>
      <div className=Styles.text> children </div>
    </div>
  </div>;
};
