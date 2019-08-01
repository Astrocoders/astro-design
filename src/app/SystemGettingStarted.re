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
        {Utils.str("Introduction")}
      </Title>
      <Text color=Theme.Colors.textWhite>
        {Utils.str(
           "In order to deliver fast our apps and bring consistency across all our projects and products, we designed a clean, simple and lightweight design system.",
         )}
      </Text>
      <Separator size=Theme.Spacing.base2 />
      <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
        {Utils.str("What we use")}
      </Title>
      <Text color=Theme.Colors.textWhite>
        {Utils.str(
           "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec magna nisi, convallis vel consectetur sit amet, sagittis vitae diam. Vestibulum eget pretium elit, sit amet venenatis ante. In sit amet magna vel turpis hendrerit auctor quis quis magna. Pellentesque odio turpis, mollis at elit non, interdum congue elit.",
         )}
      </Text>
    </Col>
  </div>;
