[@react.component]
let make = (~className="", ~onClick=_ => ()) =>
  <Button rounded=true type_=`transparent title="Edit" onClick className>
    <ReactIcons.FiEdit />
  </Button>;
