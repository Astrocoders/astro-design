[@react.component]
let make = (~name, ~label, ~className="", ~error="", ~disabled=false) =>
  <InputWrapper
    className=Css.(style([display(flexBox), alignItems(center)]))>
    <input
      name
      type_="radio"
      disabled
      className=Css.(merge([style([marginRight(rem(0.8))]), className]))
    />
    <InputLabel error className=Css.(style([marginBottom(px(0))]))>
      {React.string(label)}
    </InputLabel>
  </InputWrapper>;
