[@react.component]
let make =
    (
      ~result: ReasonApolloHooks.Query.variant('a),
      ~refetch: ReasonApolloHooks.Query.refetch('a),
      ~oopsieTitle,
      ~oopsieNoDataMessage,
      ~renderLoader=() => <Helper> <Spinner /> </Helper>,
      ~children,
      (),
    ) =>
  switch (result) {
  | NoData => <Oopsie title=oopsieTitle error=oopsieNoDataMessage refetch />
  | Error(error) =>
    <Oopsie
      title=oopsieTitle
      error={
        error##message;
      }
      refetch
    />
  | Loading => renderLoader()
  | Data(data) => children(data)
  };
