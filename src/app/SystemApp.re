[@react.component]
let make = () => {
  <div>
    {switch (RouterConfig.routeFromPath(ReasonReactRouter.useUrl())) {
     | Home => <SystemHome />
     | GettingStarted => <SystemGettingStarted />
     | _ => <SystemHome />
     }}
  </div>;
};
