type value = {
  .
  "initDate": Js.Date.t,
  "endDate": Js.Date.t,
};

type state = {date: array(value)};

type action =
  | UpdateDate(array(value));

[@react.component]
let make = () => {
  let ({date}, dispatch) =
    React.useReducer(
      (action) =>
        switch (action) {
        | UpdateDate(newDates) => ReasonReact.Update({date: newDates})
        },
    );
   <DatePicker
      value={self.state.value}
      onChange={_ => dispatch(UpdateDate(value))}
   />;
};