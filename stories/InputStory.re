Storybook.(
  storiesOf("Input", module_)
  |> add("default", () => 
    <Input name="name" placeholder="Name" required=true />)
  |> add("half", () => 
    <Input name="name" placeholder="Name" required=true fullWidth=false/>)
  |> add("email", () => 
    <Input name="email" placeholder="Email" required=true />)
  |> add("number", () => 
    <Input name="tel" placeholder="Phone" required=true />)
);