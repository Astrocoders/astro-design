Storybook.(
  storiesOf("Button", module_)
  |> add("default", () => <Button> {Utils.str("Lorem ipsum")} </Button>)
  |> add("secondary", () => <Button type_=`secondary> {Utils.str("Lorem ipsum")} </Button>)
  |> add("danger", () =>
       <Button type_=`danger> {Utils.str("Lorem ipsum")} </Button>
     )
  |> add("fullWidth", () =>
       <Button fullWidth=true> {Utils.str("Lorem ipsum")} </Button>
     )
  |> add("disabled", () =>
       <Button disabled=true> {Utils.str("Lorem ipsum")} </Button>
     )
);