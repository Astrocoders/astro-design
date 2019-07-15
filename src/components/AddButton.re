[@react.component]
let make = (~className="", ~onClick=_ => ()) =>
  <Button rounded=true title="Add" onClick className>
    <ReactIcons.FiPlus />
  </Button>;
