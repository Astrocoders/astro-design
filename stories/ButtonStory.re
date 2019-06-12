let str = React.string;

Storybook.(
  storiesOf("Button", module_)
  |> add("default", () => <Button> {str("Lorem ipsum")} </Button>)
  |> add("secondary", () => <Button type_=`secondary> {str("Lorem ipsum")} </Button>)
  |> add("danger", () =>
       <Button type_=`danger> {str("Lorem ipsum")} </Button>
     )
  |> add("fullWidth", () =>
       <Button fullWidth=true> {str("Lorem ipsum")} </Button>
     )
  |> add("disabled", () =>
       <Button disabled=true> {str("Lorem ipsum")} </Button>
     )
);