type item = {
  title: string,
  completed: bool,
};

type state = {items: list(item)};

let component = ReasonReact.reducerComponent("TodoApp");

let str = ReasonReact.string;

let make = children => {
  ...component,
  initialState: () => {
    items: [
      {title: "Learn Reason", completed: false},
      {title: "Learn Reason React", completed: false},
    ],
  },
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: ({state: {items}}) => {
    let numItems = List.length(items);
    <div className="app">
      <div className="title"> {str("What to do")} </div>
      <div className="items"> {str("Nothing")} </div>
      <div className="footer">
        {str(string_of_int(numItems) ++ (numItems > 1 ? " items" : " item"))}
      </div>
    </div>;
  },
};
