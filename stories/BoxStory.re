Storybook.(
  storiesOf("Box", module_)
  |> add("Success", () =>
       <Box type_=`success title="Title"> {Utils.str("Lorem ipsum")} </Box>
     )
  |> add("Info", () =>
       <Box type_=`info title="Title"> {Utils.str("Lorem ipsum")} </Box>
     )
  |> add("Error", () =>
       <Box type_=`error title="Title"> {Utils.str("Lorem ipsum")} </Box>
     )
  |> add("Warn", () =>
       <Box type_=`warn title="Title"> {Utils.str("Lorem ipsum")} </Box>
     )
);
