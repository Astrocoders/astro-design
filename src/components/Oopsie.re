module Styles = {
  open Css;

  let wrapper = style([color(hex(Theme.Colors.error))]);
  let title =
    style([
      display(block),
      fontSize(rem(1.)),
      marginBottom(px(Theme.Spacing.baseHalf)),
    ]);
  let description = style([marginBottom(px(Theme.Spacing.baseHalf))]);
  let retryBtn = style([fontSize(rem(1.5))]);
};

[@react.component]
let make = (~title, ~error="", ~refetch) =>
  <Helper className=Styles.wrapper>
    <b className=Styles.title> {React.string(title)} </b>
    <div className=Styles.description> {React.string(error)} </div>
    <Button
      type_=`transparent
      rounded=true
      text=`error
      size=60
      className=Styles.retryBtn
      onClick={_ => refetch(None) |> ignore}>
      <ReactIcons.FiRefreshCw />
    </Button>
  </Helper>;
