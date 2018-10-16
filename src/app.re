[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div className="app">
      <Header />
      <div className="title"> {ReasonReact.string("What to do")} </div>
      <div className="items"> {ReasonReact.string("Nothing")} </div>
    </div>,
};
