Storybook.(
  storiesOf("Positioning Elements", module_)
  |> add("Row", () => 
    <Row>
      {React.string("Get Started")}
      {React.string("See More")}
    </Row>)
  |> add("Column", () =>
    <Col>
      {React.string("Get Started")}
      {React.string("See More")}
    </Col>)
);