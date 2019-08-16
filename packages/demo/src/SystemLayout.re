open AstroDesign;

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
      media("(min-width: 960px)", [width(px(300))]),
    ]);

  let content = (~withPadding) =>
    style([
      boxSizing(`borderBox),
      height(vh(100.)),
      padding(withPadding ? px(Theme.Spacing.base) : px(0)),
      overflowY(auto),
      media("(max-width: 600px)", [paddingTop(px(Theme.Spacing.base))]),
    ]);

  let menu = (~theme) =>
    style([
      flexDirection(column),
      marginTop(px(Theme.Spacing.base)),
      ...Theme.Helpers.color(theme),
    ]);
};

[@react.component]
let make = (~menu, ~content, ~theme, ~withPadding=true) =>
  <div className=Styles.wrapper>
    <Drawer title="AstroDesign" theme className=Styles.navigation>
      <div className={Styles.menu(~theme)}> menu </div>
    </Drawer>
    <Divider hideOnMobile=false />
    <Col className={Styles.content(~withPadding)}> content </Col>
  </div>;
