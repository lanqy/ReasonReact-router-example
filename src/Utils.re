/* require css file for side effect only */
[@bs.val] external requireCSS : string => unit = "require";

/* require an asset (eg. an image) and return exported string value (image URI) */
[@bs.val] external requireAssetURI : string => string = "require";

let str = ReasonReact.string;

[@bs.send] [@bs.return nullable]
external getAttribute : (Js.t('a), string) => option(string) =
  "getAttribute";

let dangerousHtml: string => Js.t('a) = html => {"__html": html};

let distanceFromBottom: unit => int =
  () => {
    let bodyClientHeight = [%raw "document.body.clientHeight"];
    let windowScrollY = [%raw "window.scrollY"];
    let windowInnerHeight = [%raw "window.innerHeight"];
    bodyClientHeight - (windowScrollY + windowInnerHeight);
  };

[@bs.module]
external registerServiceWorker : unit => unit = "src/registerServiceWorker";
