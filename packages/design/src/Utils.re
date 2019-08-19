/* Utils.str */
let str = React.string;

/* Utils.requireAssetURI */
[@bs.val] external requireAssetURI: string => string = "require";

/* Utils.useClickOutside */
let useClickOutside = (onClickOutside: Dom.mouseEvent => unit) => {
  open Webapi.Dom;

  let elementRef = React.useRef(Js.Nullable.null);

  let handleClickOutside = (domElement: Dom.element, e: Dom.mouseEvent, fn) => {
    let targetElement = MouseEvent.target(e) |> EventTarget.unsafeAsElement;

    !(domElement |> Element.contains(targetElement)) ? fn(e) : ();
  };

  let handleMouseDown = (e: Dom.mouseEvent) => {
    elementRef
    ->React.Ref.current
    ->Js.Nullable.toOption
    ->Belt.Option.map(refValue =>
        handleClickOutside(refValue, e, onClickOutside)
      )
    ->ignore;
  };

  React.useEffect0(() => {
    Document.addMouseDownEventListener(handleMouseDown, document);
    Some(
      () => Document.removeMouseDownEventListener(handleMouseDown, document),
    );
  });

  elementRef;
};

/* Utils.groupBy */
let groupBy = (type a, items, ~key) => {
  let cmp: (a, a) => int = Pervasives.compare;
  module Cmp = (val Belt.Id.comparable(~cmp));
  let empty = Belt.Map.make(~id=(module Cmp));
  let merge = newItem =>
    fun
    | None => Some([newItem])
    | Some(existingItems) => Some([newItem, ...existingItems]);
  Belt.Array.reduce(items, empty, (map, item) =>
    Belt.Map.update(map, key(item), merge(item))
  )
  ->(Belt.Map.map(Array.of_list))
  |> Belt.Map.toArray;
};

/* Utils.formatDate */
let formatDate = datestring => {
  let date = Js.Date.fromString(datestring);
  (date |> Js.Date.getFullYear |> Js.Float.toString)
  ++ "-"
  ++ (date |> Js.Date.getMonth |> Js.Float.toString)
  ++ "-"
  ++ (date |> Js.Date.getDate |> Js.Float.toString);
};

/* Utils.Errors */
module Errors = {
  let invalid = field => "Invalid " ++ field;
  let required = "Required field";
};
