type value = (Js.Date.t, Js.Date.t);

type state = {date: value};

type action =
  | UpdateDate(value);

[@react.component]
let make = () => {
  let (state, send) =
    ReactUpdate.useReducer(
      {date: (Js.Date.make(), Js.Date.make())}, (action, _) =>
      switch (action) {
      | UpdateDate(newDate) => Update({date: newDate})
      }
    );
  <DatePicker
    value={state.date}
    onChange={_ => send(UpdateDate(state.date))}
  />;
};
