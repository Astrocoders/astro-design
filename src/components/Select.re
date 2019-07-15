type option_ = {
  value: string,
  label: string,
};

[@react.component]
let make =
    (
      ~name,
      ~label,
      ~theme=`light,
      ~value="",
      ~className="",
      ~onChange=_ => (),
      ~options: array(option_)=[||],
      ~error="",
      ~disabled=false,
    ) =>
  <InputWrapper>
    <InputLabel error> {Utils.str(label)} </InputLabel>
    <select
      name
      disabled
      value
      className={Css.merge([Theme.Bases.input(~theme), className])}
      onChange>
      {Belt.Array.map(options, option =>
         <option key={option.value} value={option.value}>
           {Utils.str(option.label)}
         </option>
       )
       |> React.array}
    </select>
    <InputError error />
  </InputWrapper>;
