module Styles = {
  open Css;

  let wrapper = style([marginBottom(px(Theme.Spacing.base))]);

  let header = (~theme, open_) => {
    let rules = [
      color(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.textWhite
          | `light => Theme.Colors.text
          },
        ),
      ),
      padding(px(Theme.Spacing.baseHalf)),
      display(flexBox),
      alignItems(center),
      cursor(`pointer),
      transition("all", ~duration=200, ~delay=0, ~timingFunction=`easeInOut),
      ...Theme.Helpers.background(~theme),
    ];

    let openRules = [
      boxShadow(
        Shadow.box(
          ~x=px(1),
          ~y=px(1),
          ~blur=px(20),
          ~spread=px(1),
          rgba(0, 0, 0, 0.08),
        ),
      ),
      backgroundColor(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.secondary
          | `light => Theme.Colors.backgroundContrast
          },
        ),
      ),
    ];

    [rules, open_ ? openRules : []]->List.concat->style;
  };

  let chevron = open_ =>
    style([
      fontSize(rem(1.3)),
      marginRight(px(Theme.Spacing.base)),
      transform(rotate(deg(open_ ? 90. : 0.))),
    ]);

  let title = style([flexGrow(1.0), fontSize(rem(1.0))]);

  let auxTitle = style([fontSize(rem(0.8)), fontWeight(bold)]);

  let body = open_ =>
    style([
      padding(px(Theme.Spacing.baseHalf)),
      display(open_ ? block : none),
    ]);
};

type state = {open_: bool};
type action =
  | Toggle;

let str = React.string;

[@react.component]
let make = (~title, ~auxTitle="", ~className="", ~theme=`light, ~children) => {
  let ({open_}, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Toggle => {open_: !state.open_}
        },
      {open_: false},
    );

  <div className=Css.(merge([Styles.wrapper, className]))>
    <div
      className={Styles.header(~theme, open_)}
      onClick={_ => dispatch(Toggle)}>
      <ReactIcons.FiChevronRight className={Styles.chevron(open_)} />
      <div className=Styles.title> {str(title)} </div>
      <div className=Styles.auxTitle> {str(auxTitle)} </div>
    </div>
    <div className={Styles.body(open_)}> children </div>
  </div>;
};
