Storybook.(
  storiesOf("Title", module_)
  |> add("default", () => <Title> {Utils.str("Lorem ipsum")} </Title>)
  |> add("uppercase", () => <Title isUppercase=true> {Utils.str("Lorem ipsum")} </Title>)
);