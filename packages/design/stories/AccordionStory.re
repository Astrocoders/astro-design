Storybook.(
  storiesOf("Accordion", module_)
  |> add("default", () =>
       <Accordion title="Lorem Ipsum">
         <Text> {Utils.str("Lorem Ipsum dolor sit amet")} </Text>
         <Button> {Utils.str("Click")} </Button>
       </Accordion>
     )
  |> add("dark", () =>
       <Accordion theme=`dark title="Lorem Ipsum">
         <Text> {Utils.str("Lorem Ipsum dolor sit amet")} </Text>
         <Button> {Utils.str("Click")} </Button>
       </Accordion>
     )
);
