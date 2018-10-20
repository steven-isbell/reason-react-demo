[%bs.raw {|require('./app.css')|}];

type state = {
  items: list(Todotype.item),
  inputText: string,
};

type action =
  | InputText(string)
  | Toggle(int)
  | RemoveItem(int)
  | Submit;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  let handleSubmit = state => {
    let newId: int = List.length(state.items);
    let newItem: Todotype.item = {
      id: newId,
      title: state.inputText,
      completed: false,
    };
    let newList = [newItem, ...state.items];
    ReasonReact.Update({items: newList, inputText: ""});
  };
  {
    ...component,
    initialState: () => {
      items: [{id: 0, title: "Add Some Todos", completed: false}],
      inputText: "",
    },
    reducer: action =>
      switch (action) {
      | InputText(newText) => (
          state => ReasonReact.Update({...state, inputText: newText})
        )
      | Toggle(id) => (
          state =>
            ReasonReact.Update({
              ...state,
              items:
                List.map(
                  (item: Todotype.item) =>
                    item.id == id ?
                      {...item, completed: !item.completed} : item,
                  state.items,
                ),
            })
        )
      | RemoveItem(id) => (
          state =>
            ReasonReact.Update({
              ...state,
              items:
                List.filter(
                  (item: Todotype.item) => item.id !== id,
                  state.items,
                ),
            })
        )
      | Submit => (state => handleSubmit(state))
      },
    render: ({state: {items, inputText}}) =>
      <div className="app">
        <Header />
        <div className="container"> <Todo items inputText /> </div>
      </div>,
  };
};
