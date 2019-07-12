type value = {
  .
  "initDate": Js.Date.t,
  "endDate": Js.Date.t,
};

type state = {value: array(value)};

type action =
  | UpdateDate(array(value));

[@react.component]
let make = () => {
  let ({value}, dispatch) =
    React.useReducer(
      (action) =>
        switch (action) {
        | UpdateDate(newDates) => {value: newDates}
        },
    );
   <DatePicker
      value={self.state.value}
      onChange={_ => dispatch(UpdateDate(value))}
   />;
};