let component = ReasonReact.statelessComponent("Input");

let make = (~value, ~onInputText, ~submit, _children) => {
  ...component,
  render: _self =>
    <div className="input">
      <input
        value
        placeholder="Enter Item"
        onChange={event => onInputText(ReactEvent.Form.target(event)##value)}
      />
      <button onClick={_ => submit()}> {ReasonReact.string("Add")} </button>
    </div>,
};
