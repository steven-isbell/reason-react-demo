let component = ReasonReact.reducerComponent("Todo");

let make = _children => {
  ...component,
  render: ({state: {items, inputText}, send}) =>
    <div className="app">
      <div className="app-header">
        <div className="title">
          {ReasonReact.string("Reason Todo List")}
        </div>
      </div>
      <Input
        submit={_ => send(Submit)}
        value=inputText
        onInputText={text => send(InputText(text))}
      />
      <div className="list">
        {
          ReasonReact.array(
            Array.of_list(
              List.map(
                (item: Todotype.item) =>
                  <Item
                    key={string_of_int(item.id)}
                    item
                    onRemove={id => send(RemoveItem(id))}
                    onToggle={id => send(Toggle(id))}
                  />,
                items,
              ),
            ),
          )
        }
      </div>
    </div>,
};
