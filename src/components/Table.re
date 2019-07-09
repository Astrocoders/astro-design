module Styles = {
  open Css;

  let wrapper =
    style([
      overflowX(auto),
      width(`percent(100.0)),
      boxSizing(borderBox),
      padding(px(Theme.Spacing.base)),
      backgroundColor(hex("fafafa")),
    ]);

  let table =
    style([
      borderCollapse(`collapse),
      tableLayout(auto),
      width(`percent(100.0)),
    ]);

  let th =
    style([
      textAlign(`left),
      fontSize(rem(Theme.FontSize.text)),
      padding2(~v=px(8), ~h=px(0)),
      color(hex(Theme.Colors.text)),
    ]);

  let pagination =
    style([
      display(flexBox),
      alignItems(center),
      marginTop(px(Theme.Spacing.base)),
      justifyContent(center),
      fontSize(rem(0.9)),
      color(hex(Theme.Colors.textSecondary)),
    ]);

  let buttons = style([display(flexBox), alignItems(center)]);

  let rows = style([marginRight(px(40))]);
  let rowsSelect =
    style([
      borderStyle(none),
      background(transparent),
      marginLeft(px(Theme.Spacing.baseHalf)),
    ]);

  let rowsSelectOption = style([borderStyle(none)]);

  let display = style([marginRight(px(40))]);
};

type state = {
  page: int,
  rows: int,
};

type action =
  | NextPage
  | PreviousPage
  | ChangeNumberOfRows(int);

[@react.component]
let make = (~headers, ~data, ~renderRow, ~loading=false) => {
  let ({page, rows}, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | NextPage => {...state, page: state.page + 1}
        | PreviousPage => {...state, page: state.page - 1}
        | ChangeNumberOfRows(number) => {rows: number, page: 0}
        },
      {page: 0, rows: 10},
    );

  let totalCount = Belt.Array.length(data);
  let displayStart = Js.Math.min_int(page * rows + 1, totalCount);
  let displayEnd = Js.Math.min_int((page + 1) * rows, totalCount);

  let helper = (~children) => <tr> <HelperTd> children </HelperTd> </tr>;

  let option = value =>
    <option className=Styles.rowsSelectOption value>
      {Utils.str(value)}
    </option>;

  <div className=Styles.wrapper>
    <table className=Styles.table>
      <thead>
        <tr>
          {Belt.Array.map(headers, header =>
             <th className=Styles.th key=header> {Utils.str(header)} </th>
           )
           |> React.array}
        </tr>
      </thead>
      <tbody>
        {loading
           ? helper(<Loading />)
           : totalCount === 0 ? helper(Utils.str("No entries")) : React.null}
        {Belt.Array.map(
           Belt.Array.slice(data, displayStart - 1, displayEnd),
           renderRow,
         )
         |> React.array}
      </tbody>
    </table>
    <div className=Styles.pagination>
      <div className=Styles.rows>
        <span> {Utils.str("Rows per page:")} </span>
        <select
          className=Styles.rowsSelect
          value={string_of_int(rows)}
          onChange={e =>
            dispatch(ChangeNumberOfRows(e->ReactEvent.Form.target##value))
          }>
          {option("5")}
          {option("10")}
          {option("25")}
          {option("50")}
          {option("100")}
        </select>
      </div>
      <div className=Styles.display>
        {Utils.str(
           "Showing "
           ++ string_of_int(displayStart)
           ++ "-"
           ++ string_of_int(displayEnd)
           ++ " of "
           ++ string_of_int(totalCount),
         )}
      </div>
      <div className=Styles.buttons>
        <Button
          rounded=true
          title="Previous"
          disabled={displayStart === 1}
          onClick={_ => dispatch(PreviousPage)}
          style=[Css.marginRight(Css.px(Theme.Spacing.baseHalf))]>
          <ReactIcons.FiChevronLeft />
        </Button>
        <Button
          rounded=true
          title="Next"
          disabled={displayEnd >= totalCount}
          onClick={_ => dispatch(NextPage)}>
          <ReactIcons.FiChevronRight />
        </Button>
      </div>
    </div>
  </div>;
};
