let component = ReasonReact.statelessComponent("Header");

let str = ReasonReact.string;

let style =
  Css.{
    "header":
      style([
        backgroundColor(rgba(238, 35, 45, 1.0)),
        display(flexBox),
        justifyContent(spaceBetween),
        alignItems(center),
      ]),
    "title": style([color(white), fontSize(px(36)), fontWeight(500)]),
    "logo": style([width(px(200)), height(px(80)), marginLeft(px(32))]),
    "search_input_wrapper": style([marginRight(px(32))]),
    "search_input": style([marginRight(px(8))]),
  };

let make = _children => {
  ...component,
  render: _self =>
    <header className=style##header>
      <span className=style##title> {str("Reason ToDo")} </span>
      <div className=style##search_input_wrapper>
        <input className=style##search_input placeholder="search" />
        <button> {str("Search")} </button>
      </div>
    </header>,
};
