type rect = {
  width: int,
  height: int,
  top: int,
  left: int,
  right: int,
  bottom: int,
};

[@bs.module "react-tiny-popover"] [@react.component]
external make:
  (
    ~containerClassName: string,
    ~isOpen: bool,
    ~align: string,
    ~padding: int,
    ~content: {
                .
                "position": string,
                "targetRect": rect,
                "popoverRect": rect,
              } =>
              React.element,
    ~position: list(string),
    ~transitionDuration: string,
    ~onClickOutside: unit => unit,
    ~children: React.element
  ) =>
  React.element =
  "default";

let makeProps =
    (
      ~containerClassName: string="",
      ~isOpen: bool=false,
      ~align: string="start",
      ~padding: int=0,
      ~content:
         {
           .
           "position": string,
           "targetRect": rect,
           "popoverRect": rect,
         } =>
         React.element,
      ~position: list(string)=["bottom"],
      ~transitionDuration: string="0",
      ~onClickOutside: unit => unit=_ => (),
      ~children: React.element,
    ) =>
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
  );
