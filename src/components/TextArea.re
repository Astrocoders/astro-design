module Styles = {
  open Css;

  let textarea =
    style([paddingTop(px(12)), paddingBottom(px(12)), height(px(70))]);
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
      ~error="",
      ~placeholder="",
      ~disabled=false,
    ) =>
  <InputWrapper>
    <InputLabel error> {React.string(label)} </InputLabel>
    <textarea
      name
      value
      onChange
      placeholder
      disabled
      className={Css.merge([
        Theme.Bases.input(~theme),
        Styles.textarea,
        className,
      ])}
    />
    <InputError error />
  </InputWrapper>;
