[@react.component]
let make =
    (
      ~result: ReasonApolloHooks.Query.variant('a),
      ~refetch,
      ~renderLoader=() => <Helper> <Spinner /> </Helper>,
      ~children,
      (),
    ) =>
  switch (result) {
  | NoData =>
    <Oopsie error={Oopsie.convertError({"message": "Nenhum dado"})} refetch />
  | Error(error) => <Oopsie error={Oopsie.convertError(error)} refetch />
  | Loading => renderLoader()
  | Data(data) => children(data)
  };
