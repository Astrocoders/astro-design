type module_;

[@bs.val] external module_: module_ = "module";

type section;

type story = unit => ReasonReact.reactElement;

[@bs.module "@storybook/react"]
external storiesOf: (string, module_) => section = "storiesOf";

[@bs.send] external add': (section, string, story) => section = "add";

let add = (title: string, story: story, section: section) =>
  add'(section, title, story);
