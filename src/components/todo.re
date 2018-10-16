type item = {
  title: string,
  completed: bool,
};

type state = {items: list(item)};

type action =
  | AddItem;

let component = ReasonReact.reducerComponent("TodoApp");

let str = ReasonReact.string;

let newItem = () => {title: "Complete a task", completed: true};

let make = children => {
  ...component,
  initialState: () => {
    items: [
      {title: "Learn Reason", completed: false},
      {title: "Learn Reason React", completed: false},
    ],
  },
  reducer: (action, {items}) =>
    switch (action) {
    | AddItem => ReasonReact.Update({items: [newItem(), ...items]})
    },
  render: ({state: {items}, send}) => {
    let numItems = List.length(items);
    <div className="app">
      <div className="title">
        {str("What to do")}
        <button onClick={_e => send(AddItem)}> {str("Add Item")} </button>
      </div>
      <div className="items"> {str("Nothing")} </div>
      <div className="footer">
        {str(string_of_int(numItems) ++ (numItems > 1 ? " items" : " item"))}
      </div>
    </div>;
  },
};
