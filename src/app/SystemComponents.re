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
        <MenuItem
          icon={<ReactIcons.FiBox color=Theme.Colors.textWhite />}
          text="Components"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(Home))
          }
        />
        <SubmenuItem text="Accordion" link="#" />
        <SubmenuItem text="Blockquote" link="#" />
        <SubmenuItem text="Buttons" link="#" />
        <SubmenuItem text="DatePicker" link="#" />
        <SubmenuItem text="Fields" link="#" />
        <SubmenuItem text="Popover" link="#" />
        <SubmenuItem text="Positioning" link="#" />
        <SubmenuItem text="Spinner" link="#" />
        <SubmenuItem text="Table" link="#" />
        <SubmenuItem text="Text" link="#" />
        <SubmenuItem text="Title" link="#" />
      </>
    content=
      <>
        <Title size=Theme.FontSize.title color=Theme.Colors.textWhite>
          {Utils.str("Components")}
        </Title>
        <Separator size=Theme.Spacing.base2 />
        <section id="accordion">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Accordion")}
          </Title>
          <Title
            size=Theme.FontSize.footerHeading color=Theme.Colors.textWhite>
            {Utils.str("Concept")}
          </Title>
          <Text align=`center color=Theme.Colors.textWhite>
            {Utils.str(
               "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
             )}
          </Text>
          <Separator />
          <Title
            size=Theme.FontSize.footerHeading color=Theme.Colors.textWhite>
            {Utils.str("Usage")}
          </Title>
          <Text align=`center color=Theme.Colors.textWhite>
            {Utils.str(
               "Frequently Asked Questions, Features Explanations, Lorem Ipsum",
             )}
          </Text>
          <Button> {Utils.str("See it Alive")} </Button>
        </section>
        <Separator size=Theme.Spacing.base2 />
        <section id="blockquote">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Blockquote")}
          </Title>
          <Title
            size=Theme.FontSize.footerHeading color=Theme.Colors.textWhite>
            {Utils.str("Concept")}
          </Title>
          <Text align=`center color=Theme.Colors.textWhite>
            {Utils.str(
               "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
             )}
          </Text>
          <Title
            size=Theme.FontSize.footerHeading color=Theme.Colors.textWhite>
            {Utils.str("Usage")}
          </Title>
          <Text align=`center color=Theme.Colors.textWhite>
            {Utils.str("Featured phrases, quotations, etc")}
          </Text>
          <Button> {Utils.str("See it Alive")} </Button>
        </section>
      </>
  />;
