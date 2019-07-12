module ArrowContainer = {
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
      ~position: string,
      ~children: React.element,
      ~targetRect: Popover.rect,
      ~popoverRect: Popover.rect,
      ~arrowColor: string,
      ~arrowSize: int
    ) =>
    React.element =
    "ArrowContainer";

  let makeProps =
      (
        ~position: string,
        ~children: React.element,
        ~targetRect: Popover.rect,
        ~popoverRect: Popover.rect,
        ~arrowColor: string="#fff",
        ~arrowSize: int=10,
      ) =>
    makeProps(
      ~position,
      ~children,
      ~targetRect,
      ~popoverRect,
      ~arrowColor,
      ~arrowSize,
    );
};

[@react.component]
let make =
    (
      ~containerClassName: string="",
      ~isOpen: bool=false,
      ~align: string="center",
      ~padding: int=0,
      ~content:
         {
           .
           "position": string,
           "targetRect": Popover.rect,
           "popoverRect": Popover.rect,
         } =>
         React.element,
      ~position: list(string)=["bottom"],
      ~transitionDuration: string="0",
      ~onClickOutside: unit => unit=_ => (),
      ~children: React.element,
    ) =>
  <Popover
    containerClassName
    isOpen
    align
    padding
    content={props =>
      <ArrowContainer
        position={
          props##position;
        }
        targetRect={
          props##targetRect;
        }
        popoverRect={
          props##popoverRect;
        }>
        {content(props)}
      </ArrowContainer>
    }
    position
    transitionDuration
    onClickOutside>
    children
  </Popover>;
