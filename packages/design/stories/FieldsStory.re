Storybook.(
  storiesOf("Fields/Input", module_)
  |> add("default", () => <Input name="example" label="Example" />)
  |> add("Dark", () => <Input name="example" label="Example" theme=`dark />)
  |> add("With Mask", () => {
       let (value, setValue) = React.useState(_ => "");
       <WithMaskedField
         mask=`cpf onChangeText={text => setValue(_ => text)} value>
         ...{(~value, ~onChangeText, ~maxLength as _) =>
           <Input
             name="example"
             value
             onChange={event => {
               event->ReactEvent.Synthetic.persist;
               onChangeText(ReactEvent.Form.target(event)##value);
             }}
             label="Example"
             theme=`dark
           />
         }
       </WithMaskedField>;
     })
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

Storybook.(
  storiesOf("Fields/Select", module_)
  |> add("default", () =>
       <Select
         name="example"
         label="Example"
         options=[|
           {value: "1", label: "Option 1"},
           {value: "2", label: "Option 2"},
           {value: "3", label: "Option 3"},
         |]
       />
     )
  |> add("Error", () =>
       <Select name="example" label="Example" error="Field is required" />
     )
  |> add("Disabled", () =>
       <Select name="example" label="Example" disabled=true />
     )
);

Storybook.(
  storiesOf("Fields/Checkbox", module_)
  |> add("default", () => <Checkbox name="example" label="Example" />)
  |> add("Disabled", () =>
       <Checkbox name="example" label="Example" disabled=true />
     )
);

Storybook.(
  storiesOf("Fields/Radio", module_)
  |> add("default", () => <Radio name="example" label="Example" />)
  |> add("Disabled", () =>
       <Radio name="example" label="Example" disabled=true />
     )
);

Storybook.(
  storiesOf("Fields/TextArea", module_)
  |> add("default", () => <TextArea name="example" label="Example" />)
  |> add("Error", () =>
       <TextArea name="example" label="Example" error="Field is required" />
     )
  |> add("Disabled", () =>
       <TextArea name="example" label="Example" disabled=true />
     )
);
