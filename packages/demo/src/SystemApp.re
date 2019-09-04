[@react.component]
let make = (~theme=`dark) => {
  <div>
    {switch (SystemRouter.routeFromPath(ReasonReactRouter.useUrl())) {
     | Home => <SystemHome theme />
     | GettingStarted => <SystemGettingStarted theme />
     | Components => <SystemComponents theme />
     }}
  </div>;
};
