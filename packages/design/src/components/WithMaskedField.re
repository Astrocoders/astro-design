module VMask = {
  type vmask;
  [@bs.module] external vmask: vmask = "vanilla-masker";
  [@bs.send] external toMoney: (vmask, ~value: string) => string = "toMoney";
  [@bs.send] external toNumber: (vmask, ~value: string) => string = "toNumber";
  [@bs.send]
  external toPattern: (vmask, ~value: string, ~pattern: string) => string =
    "toPattern";
};

type masks = [
  | `cpf
  | `cnpj
  | `money
  | `raw
  | `rg
  | `cep
  | `bankSlip
  | `date
  | `phone
  | `shortPhone
  | `zipcode
];

module Params = {
  type state = {
    rawValue: string,
    maskedValue: string,
  };
};

module WithState = ReContainers.WithState.Make(Params);
let formatValue = mask =>
  switch (mask) {
  | `cpf => VMask.toPattern(~pattern="999.999.999-99")
  | `rg => VMask.toPattern(~pattern="99.999.999-S")
  | `cnpj => VMask.toPattern(~pattern="99.999.999/9999-99")
  | `date => VMask.toPattern(~pattern="99/99/9999")
  | `money => VMask.toMoney
  | `phone => VMask.toPattern(~pattern="(99) 99999-9999")
  | `shortPhone => VMask.toPattern(~pattern="99999-9999")
  | `zipcode => VMask.toPattern(~pattern="99999-999")
  | `bankSlip =>
    VMask.toPattern(
      ~pattern="99999.99999 99999.999999 99999.999999 9 99999999999999",
    )
  | `cep => VMask.toPattern(~pattern="99999-999")
  | `raw => ((_, ~value) => value)
  };
let getRawValue = mask =>
  switch (mask) {
  | `rg
  | `cpf
  | `cnpj
  | `zipcode
  | `bankSlip
  | `money => VMask.toNumber
  | _ => ((_, ~value) => value)
  };

let fromBRToMurican = value =>
  Js.String.replaceByRe(
    [%bs.re {|/^(\d{2})\/(\d{2})\/(\d{4})/|}],
    "$3/$2/$1",
    value,
  );

let fromMuricanToBR = value =>
  Js.String.replaceByRe(
    [%bs.re {|/^(\d{4})[^\d](\d{2})[^\d](\d{2})/|}],
    "$3/$2/$1",
    value,
  );

let getNewState = (mask, value) =>
  Params.{
    rawValue: value,
    maskedValue:
      /* If mask is a phone type when initialize it from international to brazilian format */
      switch (mask) {
      | `date when value != "" => fromMuricanToBR(value)
      | _ => VMask.(formatValue(mask, vmask, ~value))
      },
  };

type interface = {
  value: string,
  onChangeText: string => unit,
};

let use = (~value as initialValue, ~mask: masks, ~onChangeText) => {
  let (state, setValue) =
    React.useState(() => getNewState(mask, initialValue));

  React.useEffect0(() => {
    setValue(_ => getNewState(mask, initialValue));
    None;
  });

  let onChangeText' =
    React.useCallback(value => {
      let newState =
        Params.{
          rawValue:
            switch (mask) {
            /* If length is 10 means the date input is complete, so we can output back to the API consumer a valid formatted date */
            | `date =>
              String.length(value) == 10
                ? fromBRToMurican(value) : initialValue
            | _ => VMask.(getRawValue(mask, vmask, ~value))
            },
          maskedValue: VMask.(formatValue(mask, vmask, ~value)),
        };
      setValue(_ => newState);
      onChangeText(newState.rawValue);
    });

  {value: state.maskedValue, onChangeText: onChangeText'};
};

[@react.component]
let make = (~value, ~mask: masks, ~onChangeText, ~children) => {
  let {value, onChangeText} = use(~value, ~mask, ~onChangeText);

  children(~value, ~onChangeText, ~maxLength=150);
};
