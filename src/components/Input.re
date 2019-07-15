module Styles = {
  open Css;

  let specifics = (~type_) => {
    let rules =
      switch (type_) {
      | "color" => [
          width(px(40)),
          padding(px(0)),
          selector("::-webkit-color-swatch", [borderStyle(none)]),
        ]
      | _ => []
      };

    style(rules);
  };
};

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
      className={Css.merge([
        Theme.Bases.input(~theme),
        Styles.specifics(~type_),
        className,
      ])}
    />
    <InputError error />
  </InputWrapper>;
