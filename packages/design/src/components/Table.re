module Styles = {
  open Css;

  let header =
    style([
      marginBottom(px(Theme.Spacing.base)),
      display(flexBox),
      alignItems(center),
    ]);
  let title = style([flexGrow(1.0)]);
  let search = style([display(flexBox), alignItems(center)]);
  let searchInput =
    style([
      padding(px(5)),
      marginLeft(px(10)),
      borderStyle(none),
      backgroundColor(transparent),
    ]);

  let panel =
    style([
      overflowX(auto),
      padding2(~v=px(Theme.Spacing.base), ~h=px(Theme.Spacing.baseHalf)),
    ]);

  let table =
    style([
      borderCollapse(`collapse),
      tableLayout(auto),
      width(`percent(100.0)),
    ]);
  let th = (~theme) =>
    style([
      textAlign(`left),
      fontSize(rem(Theme.FontSize.text)),
      padding3(~top=px(8), ~h=px(0), ~bottom=px(Theme.Spacing.baseHalf)),
      color(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.textWhite
          | `light => Theme.Colors.text
          },
        ),
      ),
      selector(":first-child", [paddingLeft(px(Theme.Spacing.baseHalf))]),
      selector(":last-child", [paddingRight(px(Theme.Spacing.baseHalf))]),
    ]);

  let pagination =
    style([
      display(flexBox),
      alignItems(center),
      justifyContent(spaceBetween),
      marginTop(px(Theme.Spacing.base)),
      fontSize(rem(0.9)),
      color(hex(Theme.Colors.textSecondary)),
      padding2(~v=px(0), ~h=px(Theme.Spacing.baseHalf)),
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
  let buttonPrevious = style([marginRight(px(Theme.Spacing.baseHalf))]);

  let tableText = (~theme) =>
    style([
      color(
        hex(
          switch (theme) {
          | `dark => Theme.Colors.textWhite
          | `light => Theme.Colors.text
          },
        ),
      ),
    ]);
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
let make =
    (
      ~headers,
      ~data,
      ~title=() => React.null,
      ~displayName,
      ~renderRow,
      ~theme=`light,
      ~loading=false,
      ~className="",
    ) => {
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

  <div className>
    <div className=Styles.header>
      <div className=Styles.title>
        <Title
          color={
            switch (theme) {
            | `dark => Theme.Colors.textWhite
            | `light => Theme.Colors.text
            }
          }
          justify=`flexStart
          size=Theme.FontSize.subtitle
          pBottom=0>
          {title()}
        </Title>
      </div>
      <div className=Styles.search>
        <ReactIcons.FiSearch />
        <input
          type_="text"
          className=Styles.searchInput
          placeholder={"Search for " ++ displayName}
        />
      </div>
    </div>
    <Panel theme className=Styles.panel>
      <table className=Styles.table>
        <thead>
          <tr>
            {Belt.Array.map(headers, header =>
               <th className={Styles.th(~theme)} key=header>
                 {Utils.str(header)}
               </th>
             )
             |> React.array}
          </tr>
        </thead>
        <tbody className={Styles.tableText(~theme)}>
          {loading
             ? helper(<Loading theme />)
             : totalCount === 0
                 ? helper(Utils.str("No entries")) : React.null}
          {Belt.Array.map(
             Belt.Array.slice(data, displayStart - 1, displayEnd),
             renderRow,
           )
           |> React.array}
        </tbody>
      </table>
      <div className=Styles.pagination>
        <div className=Styles.rows>
          <span className={Styles.tableText(~theme)}>
            {Utils.str("Rows per page:")}
          </span>
          <select
            className={Css.merge([
              Styles.tableText(~theme),
              Styles.rowsSelect,
            ])}
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
        <div
          className={Css.merge([Styles.tableText(~theme), Styles.display])}>
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
            disabled={displayStart <= 1}
            onClick={_ => dispatch(PreviousPage)}
            className=Styles.buttonPrevious>
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
    </Panel>
  </div>;
};