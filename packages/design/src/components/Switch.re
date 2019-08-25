[@bs.module "react-switch"] [@react.component]
external make:
  (
    ~checked: bool,
    ~onChange: unit => unit,
    ~disabled: bool,
    ~onColor: string,
    ~offColor: string,
    ~checkedIcon: React.element,
    ~uncheckedIcon: React.element,
    ~className: string,
    ~height: int,
    ~width: int
  ) =>
  React.element =
  "default";

let makeProps =
    (
      ~checked: bool=false,
      ~onChange: unit => unit=_ => (),
      ~disabled: bool=false,
      ~onColor: string="#00B45C",
      ~offColor: string="#888",
      ~checkedIcon: React.element=React.null,
      ~uncheckedIcon: React.element=React.null,
      ~className: string="",
      ~height: int=28,
      ~width: int=56,
    ) =>
  makeProps(
    ~checked,
    ~onChange,
    ~disabled,
    ~onColor,
    ~offColor,
    ~checkedIcon,
    ~uncheckedIcon,
    ~className,
    ~height,
    ~width,
  );
