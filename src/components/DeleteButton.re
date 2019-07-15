[@react.component]
let make = (~className="", ~onClick=_ => ()) =>
  <Button
    rounded=true type_=`transparent title="Delete" onClick className size=28>
    <ReactIcons.FiTrash2 />
  </Button>;
