module Styles = {
  open Css;

  let wrapper =
    style([
      backgroundColor(hex(Theme.Colors.secondary)),
      display(flexBox),
      flexDirection(row),
      height(vh(100.)),
      padding(px(Theme.Spacing.base)),
      width(pct(100.)),
      media("(max-width: 600px)", [flexDirection(column)]),
    ]);

  let navigation =
    style([
      padding(px(Theme.Spacing.base)),
      width(px(300)),
      media("(max-width: 600px)", [width(pct(100.))]),
    ]);

  let content = style([padding(px(Theme.Spacing.base))]);

  let menu =
    style([flexDirection(column), marginTop(px(Theme.Spacing.base))]);
};

[@react.component]
let make = () =>
  <div className=Styles.wrapper>
    <Col className=Styles.navigation>
      <Title color=Theme.Colors.textWhite> {Utils.str("AstroDesign")} </Title>
      <div className=Styles.menu>
        <MenuItem
          icon={<ReactIcons.FiHome color=Theme.Colors.textWhite />}
          text="Home"
          link="#"
        />
        <MenuItem
          icon={<ReactIcons.FiFlag color=Theme.Colors.textWhite />}
          text="Getting Started"
          link="/getting-started"
        />
        <MenuItem
          icon={<ReactIcons.FiBox color=Theme.Colors.textWhite />}
          text="Components"
          link="#"
        />
      </div>
    </Col>
    <Divider />
    <Col className=Styles.content>
      <Title size=Theme.FontSize.title color=Theme.Colors.textWhite>
        {Utils.str("Welcome!")}
      </Title>
    </Col>
  </div>;
