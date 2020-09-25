let toString = React.string;

[@decco]
type text = {text: string};
[@decco]
type titleType = array(text);

[@react.component]
let make = (~title) => {
  switch (title: option(Js.Json.t)) {
  | None => ReasonReact.null
  | Some(title) =>
    let result = titleType_decode(title);
    let text =
      switch (result) {
      | Ok(title) => title[0].text
      | Error(msg) => msg.message
      };
    <h1> {text |> toString} </h1>;
  };
};