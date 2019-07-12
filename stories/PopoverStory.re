module PopoverTest1 = {
  module Styles = {
    open Css;

    let popover =
      style([
        backgroundColor(hex("fff")),
        boxShadow(
          ~x=px(1),
          ~y=px(1),
          ~blur=px(2),
          ~spread=px(1),
          hex("ccc"),
        ),
      ]);
  };

  [@react.component]
  let make = () => {
    let (isOpen, setIsOpen) = React.useState(() => false);

    <Popover
      containerClassName=Styles.popover
      isOpen
      align="start"
      padding=0
      position=["bottom"]
      onClickOutside={_ => setIsOpen(_ => false)}
      content={<div> {Utils.str("content")} </div>}
      transitionDuration=0.1>
      <Button onClick={_ => setIsOpen(_ => !isOpen)}>
        {Utils.str("Toggle Popover")}
      </Button>
    </Popover>;
  };
};

Storybook.(
  storiesOf("Popover", module_) |> add("default", () => <PopoverTest1 />)
);
