[@genType]
type state('date) = {value: array('date)};

[@genType]
type renderDateRangePicker('date) = {
  date: 'date,
  value: array('date),
  onChange: unit => unit,
};

[@genType.import "@wojtekmaj/react-daterange-picker"]
[@bs.module "./DatePicker.gen"]
external make:
  (
    ~value: array('date),
    ~onChange: state('date) => unit,
    'a
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  ) =
  "";

let make = make;