Storybook.(
  storiesOf("Blockquote", module_)
  |> add("default", () =>
       <Blockquote> {Utils.str("Lorem ipsum dolor sit amet")} </Blockquote>
     )
  |> add("dark", () =>
       <Blockquote theme=`dark>
         {Utils.str("Lorem ipsum dolor sit amet")}
       </Blockquote>
     )
);
