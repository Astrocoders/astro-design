module Styles = {
  open Css;

  let contentBg =
    style([
      backgroundImage(url(Utils.requireAssetURI("./img/to-the-moon.svg"))),
      backgroundPosition(pct(50.), pct(110.)),
      backgroundRepeat(noRepeat),
      backgroundSize(size(pct(70.), pct(50.))),
      height(pct(100.)),
      paddingLeft(px(Theme.Spacing.base)),
      paddingRight(px(Theme.Spacing.base)),
      media(
        "(min-width: 960px)",
        [
          paddingTop(px(Theme.Spacing.base3)),
          backgroundPosition(pct(50.), pct(100.)),
        ],
      ),
    ]);
  let title = style([textAlign(center)]);
};

[@react.component]
let make = () =>
  <SystemLayout
    menu=
      <>
        <MenuItem
          icon={<ReactIcons.FiHome color="inherit" />}
          text="Home"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(Home))
          }
        />
        <MenuItem
          icon={<ReactIcons.FiFlag color="inherit" />}
          text="Getting Started"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(GettingStarted))
          }
        />
        <MenuItem
          icon={<ReactIcons.FiBox color="inherit" />}
          text="Components"
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(Components))
          }
        />
      </>
    withPadding=false
    content={
      <Col horizontalAlign=`center className=Styles.contentBg>
        <Title
          className=Styles.title
          justify=`center
          size=Theme.FontSize.title
          color=Theme.Colors.textWhite>
          {Utils.str("Outerspace components for complex apps")}
        </Title>
        <Text align=`center color=Theme.Colors.textWhite>
          {Utils.str(
             "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec magna nisi, convallis vel consectetur sit amet, sagittis vitae diam. Vestibulum eget pretium elit, sit amet venenatis ante. In sit amet magna vel turpis hendrerit auctor quis quis magna. Pellentesque odio turpis, mollis at elit non, interdum congue elit.",
           )}
        </Text>
        <Separator />
        <Button
          onClick={_ =>
            ReasonReactRouter.push(SystemRouter.routeToPath(GettingStarted))
          }>
          {Utils.str("Get Started Now!")}
        </Button>
        <Separator size=Theme.Spacing.base3 />
      </Col>
    }
  />;
