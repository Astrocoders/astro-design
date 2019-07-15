Storybook.(
  storiesOf("Input", module_)
  |> add("default", () => <Input name="example" label="Example" />)
  |> add("Dark", () => <Input name="example" label="Example" theme=`dark />)
  |> add("Color", () =>
       <Input
         name="example"
         type_="color"
         label="Example"
         value={"#" ++ Theme.Colors.warn}
       />
     )
  |> add("Error", () =>
       <Input name="example" label="Example" error="Field is required" />
     )
  |> add("Disabled", () =>
       <Input name="example" label="Example" disabled=true />
     )
);
