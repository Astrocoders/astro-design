module Styles = {
  open Css;

  let title =
    style([
      display(block),
      fontSize(rem(1.)),
      marginBottom(px(Theme.Spacing.baseHalf)),
    ]);
  let description = style([marginBottom(px(Theme.Spacing.baseHalf))]);
  let retryBtn = style([fontSize(rem(1.5))]);
};

external convertError: 'a => string = "%identity";

[@react.component]
let make = (~error=?, ~refetch) =>
  <Helper>
    <b className=Styles.title>
      {React.string(
         {j|Infelizmente, nosso servidor não foi capaz de completar essa operação|j},
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
      text=`text
      size=60
      className=Styles.retryBtn
      onClick={_ => refetch(None) |> ignore}>
      <ReactIcons.FiRefreshCw />
    </Button>
  </Helper>;
