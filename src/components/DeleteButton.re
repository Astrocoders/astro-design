[@react.component]
let make = (~className="", ~onClick=_ => ()) =>
  <Button
    rounded=true
    type_=`transparent
    text=`text
    title="Delete"
    onClick
    className
    size=28>
    <ReactIcons.FiTrash2 />
  </Button>;
