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
        <SubmenuItem text="Accordion" link="#accordion" />
        <SubmenuItem text="Blockquote" link="#blockquore" />
        <SubmenuItem text="Buttons" link="#buttons" />
        <SubmenuItem text="DatePicker" link="#datepicker" />
        <SubmenuItem text="Fields" link="#fields" />
        <SubmenuItem text="Popover" link="#popover" />
        <SubmenuItem text="Positioning" link="#positioning" />
        <SubmenuItem text="Spinner" link="#spinner" />
        <SubmenuItem text="Table" link="#table" />
        <SubmenuItem text="Text" link="#text" />
        <SubmenuItem text="Title" link="#title" />
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
        <Separator size=Theme.Spacing.base2 />
        <section id="buttons">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Buttons")}
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
        <Separator size=Theme.Spacing.base2 />
        <section id="datepicker">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Date Picker")}
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
        <Separator size=Theme.Spacing.base2 />
        <section id="fields">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Fields")}
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
        <Separator size=Theme.Spacing.base2 />
        <section id="popover">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Popover")}
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
        <Separator size=Theme.Spacing.base2 />
        <section id="positioning">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Positioning")}
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
        <Separator size=Theme.Spacing.base2 />
        <section id="spinner">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Spinner")}
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
        <Separator size=Theme.Spacing.base2 />
        <section id="table">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Table")}
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
        <Separator size=Theme.Spacing.base2 />
        <section id="text">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Text")}
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
        <Separator size=Theme.Spacing.base2 />
        <section id="title">
          <Title size=Theme.FontSize.subtitle color=Theme.Colors.textWhite>
            {Utils.str("Title")}
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
