type date = (Js.Date.t, Js.Date.t);

[@genType]
type state('date) = {value: date};

[@bs.module "@wojtekmaj/react-daterange-picker"] [@react.component]
external make:
  (~value: date, ~onChange: state('date) => unit) => React.element =
  "default";
