[@react.component]
let make = () => {
  <div>
    {switch (SystemRouter.routeFromPath(ReasonReactRouter.useUrl())) {
     | Home => <SystemHome />
     | GettingStarted => <SystemGettingStarted />
     | Components => <SystemComponents />
     | _ => <SystemHome />
     }}
  </div>;
};
