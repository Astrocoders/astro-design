module Styles = {
  open Css;

  let wrapper =
    style([
      backgroundColor(hex(Theme.Colors.secondary)),
      display(flexBox),
      flexDirection(row),
      height(vh(100.)),
      overflow(hidden),
      width(pct(100.)),
      media("(max-width: 600px)", [flexDirection(column)]),
    ]);

  let navigation =
    style([
      padding(px(Theme.Spacing.base)),
      width(px(300)),
      media("(max-width: 600px)", [width(pct(100.))]),
    ]);

  let content = (~withPadding) =>
    style([
      boxSizing(`borderBox),
      height(vh(100.)),
      padding(withPadding ? px(Theme.Spacing.base) : px(0)),
      overflowY(auto),
      media("(max-width: 600px)", [paddingTop(px(Theme.Spacing.base))]),
    ]);

  let menu =
    style([
      flexDirection(column),
      marginTop(px(Theme.Spacing.base)),
      media("(max-width: 600px)", [display(none)]),
    ]);
};

[@react.component]
let make = (~menu, ~content, ~withPadding=true) =>
  <div className=Styles.wrapper>
    <Col className=Styles.navigation>
      <Title justify=`center color=Theme.Colors.textWhite>
        {Utils.str("AstroDesign")}
      </Title>
      <div className=Styles.menu> menu </div>
    </Col>
    <Divider />
    <Col className={Styles.content(~withPadding)}> content </Col>
  </div>;
