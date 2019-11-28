let styles = ReactDOMRe.Style.make(~marginRight="10px", ());

[@react.component]
let make = _ => {
  <div>
    <Next.Link href="/">
      <a style=styles> {React.string("Home")} </a>
    </Next.Link>
    <Next.Link href="/about">
      <a style=styles> {React.string("About")} </a>
    </Next.Link>
  </div>;
};