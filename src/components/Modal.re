module Styles = {
  open Css;

  let wrapper =
    style([
      height(vh(100.0)),
      width(vw(100.0)),
      overflowY(scroll),
      position(fixed),
      top(px(0)),
      left(px(0)),
      backgroundColor(rgba(0, 0, 0, 0.5)),
    ]);

  let box =
    style([
      width(px(640)),
      boxSizing(borderBox),
      borderRadius(px(Theme.Border.default)),
      margin2(~v=px(Theme.Spacing.base4), ~h=auto),
      backgroundColor(hex(Theme.Colors.primary)),
    ]);

  let header =
    style([
      display(flexBox),
      alignItems(center),
      marginBottom(px(Theme.Spacing.base)),
    ]);
};

[@react.component]
let make = (~opener, ~content, ~className="") => {
  let (isOpen, setIsOpen) = React.useState(() => false);
  let container = Js.Option.getExn(ReactDOMRe._getElementById("modal-root"));
  let modal = () =>
    <div className=Styles.wrapper>
      <div className=Css.(merge([Styles.box, className]))>
        {content(~close=_ => setIsOpen(_ => false))}
      </div>
    </div>;

  <>
    {opener(~open_=_ => setIsOpen(_ => true))}
    {isOpen ? ReactDOMRe.createPortal(modal(), container) : React.null}
  </>;
};