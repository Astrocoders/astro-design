open Css;

module Colors = {
  let primary = "00B45C";
  let primaryHover = "219653";
  let primaryActive = "187740";

  let secondary = "262A41";
  let secondaryHover = "22253a";
  let secondaryActive = "1D2033";

  let secondaryLighter = "303348";

  let widget = "fff";
  let widgetHover = "f1f1f1";
  let widgetActive = "e1e1e1";
  let widgetShadow = "ccc";

  let text = "262A41";
  let textSecondary = "828282";
  let textWhite = "fff";

  let background = "f3f3f3";
  let backgroundContrast = "fafafa";

  let border = "d2d2d2";
  let link = "42a5f5";
  let default = "888995";
  let success = "00ce69";
  let error = "ef5350";
  let errorHover = "eb2f2b";
  let errorActive = "db1714";
  let info = "42a5f5";
  let warn = "ffc200";
};

module Border = {
  let default = 3;
  let big = 5;
  let rounded = 50.;
};

module FontSize = {
  let title = 2.1;
  let subtitle = 1.5;
  let footerHeading = 1.2;
  let text = 1.0;
};

module Spacing = {
  let base = 30;
  let baseHalf = base / 2;
  let base2 = base * 2;
  let base3 = base * 3;
  let base4 = base * 4;
};

module Helpers = {
  open Css;
  let fullCenter = [alignItems(center), justifyContent(center)];
  let centerBlock = [marginLeft(auto), marginRight(auto)];
};

module Bases = {
  let input = (~theme) =>
    style([
      padding2(~v=rem(0.75), ~h=rem(0.9)),
      width(`percent(100.0)),
      maxWidth(px(700)),
      boxSizing(borderBox),
      display(block),
      fontSize(rem(0.85)),
      borderRadius(px(Border.default)),
      color(
        hex(
          switch (theme) {
          | `dark => Colors.textWhite
          | `light => Colors.text
          },
        ),
      ),
      border(
        px(1),
        solid,
        hex(
          switch (theme) {
          | `dark => Colors.secondaryLighter
          | `light => Colors.border
          },
        ),
      ),
      backgroundColor(
        hex(
          switch (theme) {
          | `dark => Colors.secondaryLighter
          | `light => Colors.widget
          },
        ),
      ),
      fontFamily("inherit"),
    ]);
};

Css.(
  global(
    "*",
    [
      boxSizing(`borderBox),
      padding(px(0)),
      margin(px(0)),
      outlineWidth(px(0)),
    ],
  )
);
