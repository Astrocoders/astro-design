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

external convertError: 'a => {.. "message": string} = "%identity";

[@react.component]
let make = (~error=?, ~refetch) =>
  <Helper className=Styles.wrapper>
    <b className=Styles.title>
      {React.string(
         {j|Infelizmente, nosso servidor não foi capaz de completar esta operação|j},
       )}
    </b>
    <div className=Styles.description>
      {(
         switch (error) {
         | Some(error) => error##message
         | None => "Descrição do erro não fornecida"
         }
       )
       |> React.string}
    </div>
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
