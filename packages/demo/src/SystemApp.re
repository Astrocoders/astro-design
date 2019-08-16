[@react.component]
let make = (~theme=`light) => {
  <div>
    {switch (SystemRouter.routeFromPath(ReasonReactRouter.useUrl())) {
     | Home => <SystemHome theme />
     | GettingStarted => <SystemGettingStarted theme />
     | Components => <SystemComponents theme />
     | _ => <SystemHome theme />
     }}
  </div>;
};
