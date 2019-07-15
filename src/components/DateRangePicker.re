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
  let (state, send) =
    ReactUpdate.useReducer({ 
        date: [|
          {
             "initDate": Js.Date.(make()),
             "endDate": Js.Date.(make())
           }
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