[@react.component]
let make = (~color="inherit", ~className="", ~onClick=_ => ()) =>
  <Button
    rounded=true
    type_=`transparent
    text=`text
    title="Delete"
    onClick
    className
    size=28>
    <ReactIcons.FiTrash2 color />
  </Button>;
