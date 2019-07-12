module Styles = {
  open Css;

  let container =
    style([
      backgroundColor(hex(Theme.Colors.widget)),
      boxShadow(
        ~x=px(1),
        ~y=px(1),
        ~blur=px(2),
        ~spread=px(1),
        hex(Theme.Colors.widgetShadow),
      ),
    ]);
};

[@bs.module "react-tiny-popover"] [@react.component]
external make:
  (
    ~containerClassName: string,
    ~isOpen: bool,
    ~align: string,
    ~padding: int,
    ~content: React.element,
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
      ~content: React.element,
      ~position: list(string)=["bottom"],
      ~transitionDuration: string="0",
      ~onClickOutside: unit => unit=_ => (),
      ~children: React.element,
    ) =>
  makeProps(
    ~containerClassName={
      Css.(merge([Styles.container, containerClassName]));
    },
    ~isOpen,
    ~align,
    ~padding,
    ~content,
    ~position,
    ~transitionDuration,
    ~onClickOutside,
    ~children,
  );
