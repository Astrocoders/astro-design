Storybook.(
  storiesOf("Positioning Elements", module_)
  |> add("Row", () => 
    <Row>
      <Button> {Utils.str("Click")} </Button>
      <Button type_=`secondary> {Utils.str("Wow, nice")} </Button>
    </Row>)
  |> add("Column", () =>
    <Col>
      <Button> {Utils.str("Click")} </Button>
      <Button type_=`secondary> {Utils.str("Wow, nice")} </Button>
    </Col>)
);