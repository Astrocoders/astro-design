module Styles = {
  open Css;

  let wrapper = style([padding(px(Theme.Spacing.base))]);
  let header =
    style([
      display(flexBox),
      alignItems(center),
      marginBottom(px(Theme.Spacing.baseHalf)),
    ]);
  let title = style([flexGrow(1.0)]);
  let close = style([fontSize(Css.rem(1.4))]);
};

[@react.component]
let make = (~method, ~displayName, ~opener, ~content, ~className="") =>
  <Modal
    opener
    content={(~close) =>
      <div className=Styles.wrapper>
        <div className=Styles.header>
          <Title
            size=Theme.FontSize.subtitle
            color=Theme.Colors.textWhite
            justify=Css.flexStart
            pBottom=0
            className=Styles.title>
            {Utils.str(
               switch (method) {
               | `insert => "Insert"
               | `update => "Update"
               },
             )}
            {Utils.str(" " ++ displayName)}
          </Title>
          <Button
            type_=`transparent
            rounded=true
            text=`textSecondary
            size=40
            onClick=close
            className=Styles.close>
            <ReactIcons.FiX />
          </Button>
        </div>
        {content(~close)}
      </div>
    }
    className
  />;