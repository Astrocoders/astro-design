open AstrocodersDesign;

[@react.component]
let make = (~theme) =>
  <SystemLayout
    theme
    menu=
      <>
        <MenuItem
          theme
          icon={<ReactIcons.FiHome color="inherit" />}
          text="Home"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(Home))
          }
        />
        <MenuItem
          theme
          isActive=true
          icon={<ReactIcons.FiFlag color="inherit" />}
          text="Getting Started"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(GettingStarted))
          }
        />
        <SubmenuItem theme text="Installation" link="#" />
        <SubmenuItem theme text="Patterns" link="#" />
        <SubmenuItem theme text="Colors" link="#" />
        <SubmenuItem theme text="Positioning" link="#" />
        <Separator />
        <MenuItem
          theme
          icon={<ReactIcons.FiBox color="inherit" />}
          text="Components"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(Components))
          }
        />
      </>
    content=
      <>
        <Title size=Theme.FontSize.title color="inherit">
          {Utils.str("Introduction")}
        </Title>
        <Text color="inherit">
          {Utils.str(
             "In order to deliver fast our apps and bring consistency across all our projects and products, we designed a clean, simple and lightweight design system.",
           )}
        </Text>
        <Separator size=Theme.Spacing.base2 />
        <Title size=Theme.FontSize.subtitle color="inherit">
          {Utils.str("What we use")}
        </Title>
        <Text color="inherit">
          {Utils.str(
             "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec magna nisi, convallis vel consectetur sit amet, sagittis vitae diam. Vestibulum eget pretium elit, sit amet venenatis ante. In sit amet magna vel turpis hendrerit auctor quis quis magna. Pellentesque odio turpis, mollis at elit non, interdum congue elit.",
           )}
        </Text>
        <Separator size=Theme.Spacing.base2 />
        <Title size=Theme.FontSize.subtitle color="inherit">
          {Utils.str("Installation")}
        </Title>
        <Blockquote theme>
          <Text color="inherit">
            {Utils.str("yarn install")}
            <br />
            {Utils.str("yarn bs:watch")}
            <br />
            {Utils.str("# in another tab")}
            <br />
            {Utils.str("yarn storybook:start")}
          </Text>
        </Blockquote>
      </>
  />;
