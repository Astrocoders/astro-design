open AstroDesign;

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
        <MenuItem
          theme
          icon={<ReactIcons.FiBox color="inherit" />}
          text="Components"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(Home))
          }
        />
        <SubmenuItem theme text="Accordion" link="#accordion" />
        <SubmenuItem theme text="Blockquote" link="#blockquore" />
        <SubmenuItem theme text="Button" link="#button" />
        <SubmenuItem theme text="DatePicker" link="#datepicker" />
        <SubmenuItem theme text="Fields" link="#fields" />
        <SubmenuItem theme text="Popover" link="#popover" />
        <SubmenuItem theme text="Positioning" link="#positioning" />
        <SubmenuItem theme text="Spinner" link="#spinner" />
        <SubmenuItem theme text="Table" link="#table" />
        <SubmenuItem theme text="Text" link="#text" />
        <SubmenuItem theme text="Title" link="#title" />
      </>
    content=
      <>
        <Title size=Theme.FontSize.title color="inherit">
          {Utils.str("Components")}
        </Title>
        <SystemComponentDescription
          theme
          id="accordion"
          title="Accordion"
          usage="Frequently Asked Questions, Bullet Points, Features Explanation, etc"
        />
        <SystemComponentDescription
          theme
          id="blockquote"
          title="Blockquote"
          usage="Featured phrases, quotations, etc"
        />
        <SystemComponentDescription
          theme
          id="button"
          title="Button"
          usage="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
        />
        <SystemComponentDescription
          theme
          id="datepicker"
          title="DatePicker"
          usage="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
        />
        <SystemComponentDescription
          theme
          id="fields"
          title="Fields (Inputs)"
          usage="Form Fields, Color Picker, etc"
        />
        <SystemComponentDescription
          theme
          id="popover"
          title="Popover"
          usage="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
        />
        <SystemComponentDescription
          theme
          id="positioning"
          title="Positioning"
          usage="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
        />
        <SystemComponentDescription
          theme
          id="spinner"
          title="Spinner"
          usage="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
        />
        <SystemComponentDescription
          theme
          id="table"
          title="Table"
          usage="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
        />
        <SystemComponentDescription
          theme
          id="text"
          title="Text"
          usage="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
        />
        <SystemComponentDescription
          theme
          id="title"
          title="Title"
          usage="Lorem ipsum dolor sit amet, consectetur adipiscing elit."
        />
      </>
  />;
