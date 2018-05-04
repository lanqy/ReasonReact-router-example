open Utils;

requireCSS("src/style.css");

registerServiceWorker();

ReactDOMRe.renderToElementWithId(<App />, "root");
ReasonReact.Router.push("");
