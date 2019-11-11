Storybook.(
  storiesOf("Avatar", module_)
  |> add("default", () =>
       <Avatar src="https://avatars3.githubusercontent.com/u/1283200?s=460" />
     )
  |> add("large", () =>
       <Avatar
         size=64
         src="https://avatars3.githubusercontent.com/u/1283200?s=460"
       />
     )
);
