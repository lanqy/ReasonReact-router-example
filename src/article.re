let component = ReasonReact.statelessComponent("Article");

let make = (~name, _children) => {
  ...component,
  render: (_self) => <div> {ReasonReact.string(name)} </div>
};