module Styles = {
  open Css;

  let wrapper = style([marginTop(px(Theme.Spacing.baseHalf))]);
  let closeBtn = style([marginTop(px(Theme.Spacing.baseHalf - 5))]);
};

[@react.component]
let make = (~close) =>
  <div className=Styles.wrapper>
    <Button submit=true fullWidth=true> {Utils.str("Submit")} </Button>
    <Button
      onClick={_ => close()}
      type_=`secondary
      fullWidth=true
      className=Styles.closeBtn>
      {Utils.str("Close")}
    </Button>
  </div>;
