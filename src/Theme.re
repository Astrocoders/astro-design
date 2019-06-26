module Colors = {
  let primary = "00B45C";
  let primaryHover = "219653";
  let primaryActive = "187740";

  let secondary = "262A41";
  let secondaryHover = "464C6F";
  let secondaryActive = "1D2033";

  let text = "262A41";
  let textSecondary = "828282";
  let textWhite = "fff";
  
  let border = "C4C4C4";
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
  let base2 = base * 2;
  let base3 = base * 3;
  let base4 = base * 4;
};

module Helpers = {
  open Css;
  let fullCenter = [
      alignItems(center),
      justifyContent(center),
    ];
  let centerBlock = [
      marginLeft(auto),
      marginRight(auto),
    ];
};