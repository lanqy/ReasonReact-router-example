let component = ReasonReact.statelessComponent("About");

let make = (~name, _children) => {
  ...component,
  render: (_self) => <div> {ReasonReact.string(name)} </div>
};