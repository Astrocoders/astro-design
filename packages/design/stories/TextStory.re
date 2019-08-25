Storybook.(
  storiesOf("Text", module_)
  |> add("default", () =>
       <Text> {Utils.str("Lorem ipsum dolor sit amet")} </Text>
     )
);
