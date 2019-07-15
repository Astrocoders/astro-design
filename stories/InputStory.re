Storybook.(
  storiesOf("Input", module_)
  |> add("default", () => <Input name="example" label="Example" />)
  |> add("Dark", () => <Input name="example" label="Example" theme=`dark />)
  |> add("Error", () =>
       <Input name="example" label="Example" error="Field is required" />
     )
  |> add("Disabled", () =>
       <Input name="example" label="Example" disabled=true />
     )
);
