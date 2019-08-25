open AstrocodersDesign;

module Styles = {
  open Css;
  let section = (~theme) => style(Theme.Helpers.color(theme));
};

[@react.component]
let make = (~title, ~usage, ~id, ~theme) => {
  <>
    <Separator size=Theme.Spacing.base2 />
    <section className={Styles.section(~theme)} id>
      <Title size=Theme.FontSize.subtitle color="inherit">
        {Utils.str(title)}
      </Title>
      <Title size=Theme.FontSize.footerHeading color="inherit">
        {Utils.str("Usage")}
      </Title>
      <Text align=`center color="inherit"> {Utils.str(usage)} </Text>
      <Separator size=Theme.Spacing.base />
      <Link
        href={
          "https://astrocoders.dev/astro-design/?path=/story/"
          ++ id
          ++ "--default"
        }>
        <Button> {Utils.str("See it Alive")} </Button>
      </Link>
    </section>
  </>;
};
