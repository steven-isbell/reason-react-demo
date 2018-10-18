let component = ReasonReact.statelessComponent("Item");

let make = (~item: Todotype.item, ~onRemove, ~onToggle, _children) => {
  ...component,
  render: _self =>
    <div className="item">
      <input
        _type="checkbox"
        checked={item.completed}
        onChange={_ => onToggle(item.id)}
      />
      <p> {ReasonReact.string(item.title)} </p>
      <button onClick={_ => onRemove(item.id)}>
        {ReasonReact.string("Remove")}
      </button>
    </div>,
};
