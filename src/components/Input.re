[@react.component]
let make =
    (
      ~name,
      ~label,
      ~type_="text",
      ~theme=`light,
      ~value="",
      ~className="",
      ~onChange=_ => (),
      ~error="",
      ~placeholder="",
      ~disabled=false,
    ) =>
  <InputWrapper>
    <InputLabel error> {React.string(label)} </InputLabel>
    <input
      name
      type_
      value
      onChange
      placeholder
      disabled
      className={Css.merge([Theme.Bases.input(~theme), className])}
    />
    <InputError error />
  </InputWrapper>;
