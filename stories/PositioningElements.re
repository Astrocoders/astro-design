Storybook.(
  storiesOf("Positioning/Horizontal", module_)
  |> add("Row Wrapper", () =>
       <Row>
         <Button> {Utils.str("Click")} </Button>
         <Button type_=`secondary> {Utils.str("Wow, nice")} </Button>
       </Row>
     )
  |> add("Separator Horizontal", () =>
       <Row>
         <Button> {Utils.str("Click")} </Button>
         <Separator horizontal=true />
         <Button type_=`secondary> {Utils.str("Wow, nice")} </Button>
       </Row>
     )
  |> add("Divider Horizontal", () =>
       <Row>
         <Button> {Utils.str("Click")} </Button>
         <Divider color=Theme.Colors.secondary />
         <Button type_=`secondary> {Utils.str("Wow, nice")} </Button>
       </Row>
     )
);

Storybook.(
  storiesOf("Positioning/Vertical", module_)
  |> add("Column Wrapper", () =>
       <Col>
         <Button> {Utils.str("Click")} </Button>
         <Button type_=`secondary> {Utils.str("Wow, nice")} </Button>
       </Col>
     )
  |> add("Separator Horizontal", () =>
       <Col>
         <Button> {Utils.str("Click")} </Button>
         <Separator />
         <Button type_=`secondary> {Utils.str("Wow, nice")} </Button>
       </Col>
     )
  |> add("Divider Horizontal", () =>
       <Col>
         <Button> {Utils.str("Click")} </Button>
         <Divider color=Theme.Colors.secondary horizontal=true />
         <Button type_=`secondary> {Utils.str("Wow, nice")} </Button>
       </Col>
     )
);
