Storybook.(
  storiesOf("Color Picker", module_)
  |> add("default", () => 
    <ColorPicker />)
  |> add("with label", () => 
    <ColorPicker label="Lorem Ipsum" />)
);