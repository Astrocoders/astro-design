type route =
  | Home
  | GettingStarted;

let routeFromPath = (url: ReasonReactRouter.url) =>
  switch (url.path) {
  | [] => Home
  | ["getting-started"] => GettingStarted
  };
let routeToPath = (route: route) =>
  switch (route) {
  | Home => "/"
  | GettingStarted => "/getting-started"
  };
