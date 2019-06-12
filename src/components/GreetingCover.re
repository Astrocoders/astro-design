[@react.component]
let make = (~message) =>
  <div>
    {ReasonReact.string(message)}
  </div>;
