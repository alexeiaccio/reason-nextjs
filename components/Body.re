let toString = React.string;

// [@decco]
// type bodyType = array(body);

[@react.component]
let make = (~body) => {
  switch (body) {
  | None => ReasonReact.null
  | Some(body) =>
    let filtered1 = body
      |> Js.Array.filter(
        item =>
          switch (item |> Js.Array.isArray) {
          | true => true
          | _ => false
          }
      );
    let filtered2 = switch (filtered1[0]) {
      | Some(item) => item
        |> Js.Array.filter(x => x##fields)
      | None => [||]
    };
    let filtered3 = switch (filtered2[0]##fields) {
      | true => filtered2[0]##fields
      | _ => false
    };
    Js.log(filtered3);

    <div>
       {"Poop" |> toString} </div>;
      // {filtered
      //  |> Array.map((_, idx) =>
      //       <h1 key={idx |> Js.Int.toString}> {"text" |> toString} </h1>
      //     )
      //  |> React.array}
  };
};