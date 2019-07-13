[@react.component]
let make = (~className="", ~onClick=_ => ()) =>
  <Button
    rounded=true type_=`transparent title="Edit" onClick className size=28>
    <ReactIcons.FiEdit />
  </Button>;
