module PopoverTest = {
  module Styles = {
    open Css;

    let wrapper = style([display(flexBox), justifyContent(center)]);
    let logoutItem = style([color(hex(Theme.Colors.error))]);
  };

  [@react.component]
  let make = () => {
    let (isOpen, setIsOpen) = React.useState(() => false);

    <div className=Styles.wrapper>
      <Popover
        isOpen
        content={_ =>
          <div>
            <PopoverMenuItem onClick={_ => ()}>
              {Utils.str("Profile")}
            </PopoverMenuItem>
            <PopoverMenuItem onClick={_ => ()}>
              {Utils.str("Users")}
            </PopoverMenuItem>
            <PopoverMenuItem onClick={_ => ()} className=Styles.logoutItem>
              {Utils.str("Logout")}
            </PopoverMenuItem>
          </div>
        }
        onClickOutside={_ => setIsOpen(_ => false)}>
        <Button onClick={_ => setIsOpen(_ => !isOpen)}>
          {Utils.str("Toggle Popover")}
        </Button>
      </Popover>
    </div>;
  };
};

module ArrowPopoverTest = {
  module Styles = {
    open Css;

    let wrapper = style([display(flexBox), justifyContent(center)]);
    let container = style([marginTop(px(Theme.Spacing.baseHalf))]);
    let logoutItem = style([color(hex(Theme.Colors.error))]);
  };

  [@react.component]
  let make = () => {
    let (isOpen, setIsOpen) = React.useState(() => false);

    <div className=Styles.wrapper>
      <ArrowPopover
        isOpen
        content={_ =>
          <div>
            <PopoverMenuItem onClick={_ => ()}>
              {Utils.str("Profile")}
            </PopoverMenuItem>
            <PopoverMenuItem onClick={_ => ()}>
              {Utils.str("Users")}
            </PopoverMenuItem>
            <PopoverMenuItem onClick={_ => ()} className=Styles.logoutItem>
              {Utils.str("Logout")}
            </PopoverMenuItem>
          </div>
        }
        onClickOutside={_ => setIsOpen(_ => false)}
        containerClassName=Styles.container>
        <Button onClick={_ => setIsOpen(_ => !isOpen)}>
          {Utils.str("Toggle Arrow Popover")}
        </Button>
      </ArrowPopover>
    </div>;
  };
};

Storybook.(
  storiesOf("Popover", module_)
  |> add("default", () => <PopoverTest />)
  |> add("Arrow Popover", () => <ArrowPopoverTest />)
);
