[@bs.new] [@bs.module "react-tiny-popover"]
external make:
  {
    .
    "containerClassName": string,
    "isOpen": bool,
    "align": string,
    "padding": int,
    "content": React.element,
    "position": list(string),
    "transitionDuration": float,
    "onClickOutside": unit => unit,
    "children": React.element,
  } =>
  React.element =
  "default";

[@bs.obj]
external makeProps:
  (
    ~containerClassName: string,
    ~isOpen: bool,
    ~align: string,
    ~padding: int,
    ~content: React.element,
    ~position: list(string),
    ~transitionDuration: float,
    ~onClickOutside: unit => unit,
    ~children: React.element,
    unit
  ) =>
  _ =
  "";

[@react.component]
let make =
    (
      ~containerClassName,
      ~isOpen,
      ~align,
      ~padding,
      ~content,
      ~position,
      ~onClickOutside,
      ~transitionDuration,
      ~children,
    ) =>
  make(
    makeProps(
      ~containerClassName,
      ~isOpen,
      ~align,
      ~padding,
      ~content,
      ~position,
      ~transitionDuration,
      ~onClickOutside,
      ~children,
      (),
    ),
  );
