type route =
  | Home
  | GettingStarted
  | Components;

let routeFromPath = (url: ReasonReactRouter.url) =>
  switch (url.path) {
  | [] => Home
  | ["getting-started"] => GettingStarted
  | ["components"] => Components
  };
let routeToPath = (route: route) =>
  switch (route) {
  | Home => "/"
  | GettingStarted => "/getting-started"
  | Components => "/components"
  };
