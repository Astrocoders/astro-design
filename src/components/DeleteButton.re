[@react.component]
let make = (~className="", ~onClick=_ => ()) =>
  <Button rounded=true type_=`transparent title="Delete" onClick className>
    <ReactIcons.FiTrash2 />
  </Button>;
