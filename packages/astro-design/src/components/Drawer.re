[@bs.val] [@bs.scope "performance"] external now: unit => float = "now";
[@bs.val]
external addEventListener: (string, unit => unit) => unit = "addEventListener";
[@bs.val]
external removeEventListener: (string, unit => unit) => unit =
  "removeEventListener";

type touches = {
  first: option((float, float)),
  last: option((float, float)),
};

type state = {
  isOpen: bool,
  touches,
};

type action =
  | ToggleMenu(bool)
  | TouchStart(float)
  | TouchMove(float)
  | TouchEnd;

module Styles = {
  open Css;
  let drawer = (~isOpen) =>
    style([
      after([
        contentRule(""),
        unsafe(
          "transition",
          isOpen
            ? "opacity 450ms cubic-bezier(0.23, 1, 0.32, 1)"
            : "opacity 450ms cubic-bezier(0.23, 1, 0.32, 1), transform 0ms cubic-bezier(0.23, 1, 0.32, 1) 450ms",
        ),
        backgroundColor(rgba(0, 0, 0, 0.33)),
        position(fixed),
        bottom(px(0)),
        top(px(0)),
        right(px(0)),
        left(px(0)),
        opacity(isOpen ? 1. : 0.),
        transform(translateX(isOpen ? pct(0.) : pct(-100.))),
      ]),
    ]);

  let navbar = (~theme) =>
    style([
      alignItems(center),
      backgroundColor(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.secondary
          | `light => Theme.Colors.backgroundContrast
          },
        ),
      ),
      color(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.textWhite
          | `light => Theme.Colors.text
          },
        ),
      ),
      boxSizing(borderBox),
      display(`flex),
      justifyContent(`spaceBetween),
      flexDirection(`row),
      padding(px(20)),
      width(`percent(100.)),
      media("(min-width: 600px)", [display(`none)]),
    ]);

  let sidebar = (~theme, ~isOpen) =>
    style([
      backgroundColor(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.secondary
          | `light => Theme.Colors.backgroundContrast
          },
        ),
      ),
      color(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.textWhite
          | `light => Theme.Colors.secondary
          },
        ),
      ),
      height(vh(100.)),
      media(
        "(max-width: 600px)",
        [
          position(absolute),
          width(pct(85.)),
          top(px(0)),
          transform(translateX(isOpen ? pct(0.) : pct(-100.))),
        ],
      ),
      unsafe("transition", "transform 450ms cubic-bezier(0.23, 1, 0.32, 1)"),
      zIndex(2),
    ]);
  let backButton =
    style([
      marginRight(px(10)),
      media("(min-width: 600px)", [display(`none)]),
    ]);
};

[@react.component]
let make = (~theme, ~title, ~auxTitle="", ~className="", ~children) => {
  let navRef = React.useRef(Js.Nullable.null);
  let width =
    switch (Js.Nullable.toOption(React.Ref.current(navRef))) {
    | None => 0.0
    | Some(nav) => ReactDOMRe.domElementToObj(nav)##clientWidth
    };
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | ToggleMenu(isOpen) => {...state, isOpen}
        | TouchStart(clientX) =>
          if (state.isOpen) {
            {
              ...state,
              touches: {
                first: Some((clientX, now())),
                last: None,
              },
            };
          } else {
            state;
          }
        | TouchMove(clientX) =>
          if (state.isOpen) {
            {
              ...state,
              touches: {
                ...state.touches,
                last: Some((clientX, now())),
              },
            };
          } else {
            state;
          }
        | TouchEnd =>
          if (state.isOpen) {
            let (x, t) =
              Belt.Option.getWithDefault(state.touches.first, (0.0, 0.0));
            let (x', t') =
              Belt.Option.getWithDefault(state.touches.last, (0.0, 0.0));
            let velocity = (x' -. x) /. (t' -. t);
            let state = {
              ...state,
              touches: {
                first: None,
                last: None,
              },
            };
            if (velocity < (-0.3) || x' < width /. 2.0) {
              {...state, isOpen: false};
            } else {
              state;
            };
          } else {
            state;
          }
        },
      {
        isOpen: false,
        touches: {
          first: None,
          last: None,
        },
      },
    );

  React.useEffect(() => {
    let handler = () => dispatch(ToggleMenu(false));
    addEventListener("popstate", handler);
    Some(() => removeEventListener("popstate", handler));
  });

  <div
    className={Styles.drawer(~isOpen=state.isOpen)}
    onClick={_event =>
      if (state.isOpen) {
        dispatch(ToggleMenu(false));
      }
    }
    onTouchStart={event =>
      dispatch(
        TouchStart(
          ReactEvent.Touch.changedTouches(event)##item(0)##clientX,
        ),
      )
    }
    onTouchMove={event =>
      dispatch(
        TouchMove(ReactEvent.Touch.changedTouches(event)##item(0)##clientX),
      )
    }
    onTouchEnd={_event => dispatch(TouchEnd)}>
    <div className={Styles.navbar(~theme)}>
      <Title color="inherit" pBottom=0> {Utils.str(title)} </Title>
      <span
        onClick={event => {
          ReactEvent.Mouse.stopPropagation(event);
          dispatch(ToggleMenu(true));
        }}>
        <ReactIcons.FiMenu color="inherit" size="24" />
      </span>
    </div>
    <nav
      onClick={event => ReactEvent.Mouse.stopPropagation(event)}
      style={
        switch (state.touches) {
        | {first: Some((x, _)), last: Some((x', _))} =>
          ReactDOMRe.Style.make(
            ~transform=
              "translateX("
              ++ Js.Float.toString(x' -. x > 0.0 ? 0.0 : x' -. x)
              ++ "0px)",
            ~transition="none",
            (),
          )
        | _ => ReactDOMRe.Style.make()
        }
      }
      ref={ReactDOMRe.Ref.domRef(navRef)}>
      <div
        className={Css.merge([
          className,
          Styles.sidebar(~theme, ~isOpen=state.isOpen),
        ])}>
        <Row columnOnMobile=false verticalAlign=`center>
          <div
            onClick={_event => dispatch(ToggleMenu(false))}
            className=Styles.backButton>
            <ReactIcons.FiArrowLeft color="inherit" size="24" />
          </div>
          <Title color="inherit" pBottom=0> {Utils.str(title)} </Title>
          <Title size=Theme.FontSize.footerHeading color="inherit">
            {Utils.str(auxTitle)}
          </Title>
        </Row>
        children
      </div>
    </nav>
  </div>;
};
