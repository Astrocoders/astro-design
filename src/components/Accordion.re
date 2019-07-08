module Styles = {
  open Css;
  let accordion =
    style([
      marginBottom(px(Theme.Spacing.base)),
      marginTop(px(Theme.Spacing.base)),
      userSelect(none),
      width(pct(100.)),
    ]);

  let accordionTitleWrapper =
    style([
      alignItems(center),
      cursor(`pointer),
      display(flexBox),
      justifyContent(spaceBetween),
      width(pct(100.)),
    ]);

  let accordionTitle =
    style([
      important(width(pct(100.))),
      important(paddingBottom(px(0))),
    ]);

  let accordionContent =
    style([
      marginTop(px(Theme.Spacing.baseHalf))
    ]);

};

[@react.component]
let make = (~title, ~children) => {
  <details className=Styles.accordion>
    <summary className=Styles.accordionTitleWrapper>
      <Title color=Theme.Colors.primary weight=400 size=1.4 className=Styles.accordionTitle> {Utils.str(title)} </Title>
      <img src={Utils.requireAssetURI("../img/chevronUp.svg")} alt="Expand"  />
    </summary>
    <div className=Styles.accordionContent> children </div>
  </details>;
};

let default = make;