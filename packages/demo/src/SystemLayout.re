open AstrocodersDesign;

module Styles = {
  open Css;

  let wrapper = (~theme) =>
    style([
      display(flexBox),
      flexDirection(row),
      height(vh(100.)),
      overflow(hidden),
      width(pct(100.)),
      media("(max-width: 600px)", [flexDirection(column)]),
      backgroundColor(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.secondary
          | `light => Theme.Colors.background
          },
        ),
      ),
    ]);

  let navigation =
    style([
      padding(px(Theme.Spacing.base)),
      media("(min-width: 960px)", [width(px(300))]),
    ]);

  let content = (~withPadding, ~theme) =>
    style([
      boxSizing(`borderBox),
      height(vh(100.)),
      padding(withPadding ? px(Theme.Spacing.base) : px(0)),
      overflowY(auto),
      media("(max-width: 600px)", [paddingTop(px(Theme.Spacing.base))]),
      backgroundColor(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.secondary
          | `light => Theme.Colors.background
          },
        ),
      ),
      ...Theme.Helpers.color(~theme),
    ]);

  let menu = (~theme) =>
    style([
      flexDirection(column),
      marginTop(px(Theme.Spacing.base)),
      ...Theme.Helpers.color(~theme),
    ]);
};

[@react.component]
let make = (~menu, ~content, ~theme, ~withPadding=true) =>
  <div className={Styles.wrapper(~theme)}>
    <Drawer logo={<Logo theme />} theme className=Styles.navigation>
      <div className={Styles.menu(~theme)}> menu </div>
    </Drawer>
    <Divider
      color={
        switch (theme) {
        | `dark => Theme.Colors.secondaryLighter
        | `light => Theme.Colors.border
        }
      }
      hideOnMobile=false
    />
    <Col className={Styles.content(~withPadding, ~theme)}> content </Col>
  </div>;
