Storybook.(
  storiesOf("Status Box", module_)
  |> add("Success", () =>
       <StatusBox type_=`success title="Title">
         {Utils.str("Lorem ipsum")}
       </StatusBox>
     )
  |> add("Info", () =>
       <StatusBox type_=`info title="Title">
         {Utils.str("Lorem ipsum")}
       </StatusBox>
     )
  |> add("Error", () =>
       <StatusBox type_=`error title="Title">
         {Utils.str("Lorem ipsum")}
       </StatusBox>
     )
  |> add("Warn", () =>
       <StatusBox type_=`warn title="Title">
         {Utils.str("Lorem ipsum")}
       </StatusBox>
     )
);
