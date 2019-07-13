module Styles = {
  open Css;

  let wrapper = style([padding(px(Theme.Spacing.base2))]);
  let header = style([display(flexBox), alignItems(center)]);
  let button = style([fontSize(Css.rem(1.5))]);
};

[@react.component]
let make = (~title=React.null) =>
  <div className=Styles.wrapper>
    <div className=Styles.header>
      <Title size=1.0> title </Title>
      <Button className=Styles.button> <ReactIcons.FiX /> </Button>
    </div>
  </div>;
//{children({ close, setTitle })}
