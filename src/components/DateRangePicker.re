type state = {date: array(Js.Date.t)};

type action =
  | UpdateDate(array(Js.Date.t));

[@react.component]
let make = () => {
  let (state, send) =
    ReactUpdate.useReducer({ 
        date: [|
          Js.Date.make(),
          Js.Date.make()
        |]
      }, (action, state) =>
      switch (action) {
      | UpdateDate(newDate) => Update(state)
      }
    );
   <DatePicker
      value={state.date}
      onChange={_ => send(UpdateDate(state.date))}
   />;
};