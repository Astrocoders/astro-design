open AstroDesign;

[@react.component]
let make = () =>
  <SystemLayout
    menu=
      <>
        <MenuItem
          icon={<ReactIcons.FiHome color=Theme.Colors.textWhite />}
          text="Home"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(Home))
          }
        />
        <MenuItem
          isActive=true
          icon={<ReactIcons.FiFlag color=Theme.Colors.textWhite />}
          text="Getting Started"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(GettingStarted))
          }
        />
        <SubmenuItem text="Installation" link="#" />
        <SubmenuItem text="Patterns" link="#" />
        <SubmenuItem text="Colors" link="#" />
        <SubmenuItem text="Positioning" link="#" />
        <Separator />
        <MenuItem
          icon={<ReactIcons.FiBox color=Theme.Colors.textWhite />}
          text="Components"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(Components))
          }
        />
      </>
    content=
      <>
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
        <Separator size=Theme.Spacing.base2 />
        <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
          {Utils.str("Installation")}
        </Title>
        <Blockquote>
          <Text color=Theme.Colors.textWhite>
            {Utils.str("yarn install")}
            <br />
            {Utils.str("yarn bs:watch")}
            <br />
            {Utils.str("# in another tab")}
            <br />
            {Utils.str("yarn start")}
          </Text>
        </Blockquote>
      </>
  />;
