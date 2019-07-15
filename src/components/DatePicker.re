
[@genType]
type state('date) = {value: array('date)};

[@bs.module "@wojtekmaj/react-daterange-picker"] [@react.component]
external make:
  (
    ~value: array('date),
    ~onChange: state('date) => unit,
  ) =>
  React.element =
  "default";

let makeProps =
    (
      ~value: array('date),
      ~onChange: state('date) => unit,
    ) =>
  makeProps(
    ~value,
    ~onChange,
  );
