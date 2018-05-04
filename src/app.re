let str = ReasonReact.string;

type route = 
  | About
  | Blog
  | Article
  | NotFound;


type state = {route};

type action = 
  | ChangeRoute(route);

let reducer = (action,_state) => 
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({route:route})
  };

module Link = {
  
  let component = ReasonReact.statelessComponent("Link");

  let handleClick = (href, event) =>
    if (! ReactEventRe.Mouse.defaultPrevented(event)) {
      ReactEventRe.Mouse.preventDefault(event);
      ReasonReact.Router.push(href)
    };

  let make = (~href, children) => {
    ...component,
    render: (_self) => ReasonReact.createDomElement("a", ~props={"href": href, "onClick": handleClick(href)}, children)
  };

};

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | [] => About
  | ["about"] => About
  | ["acticle"] => Article
  | ["blog"] => Blog
  | _ => NotFound
  };

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {
    route: About
  },
  subscriptions: (self) => [
    Sub(
      () => ReasonReact.Router.watchUrl((url) => self.send(ChangeRoute(url |> mapUrlToRoute))),
      ReasonReact.Router.unwatchUrl
    )
  ],
  render: (self) =>
    <div>
     <ul>
      <li><Link href="about"> {str("About")}</Link></li>
      <li><Link href="blog"> {str("Blog")}</Link></li>
      <li><Link href="acticle"> {str("Acticle")}</Link></li>
      </ul>
      <div>
        (
          switch self.state.route {
          | About => <About name="This is about Page" />
          | Blog => <Blog name="This is blog Page" />
          | Article => <Article name="This is article Page" />
          | NotFound => <NotFound name="404 error Page" />
          }
        )
      </div>
    </div>
}
