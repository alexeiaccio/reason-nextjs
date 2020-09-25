module GetTitle = [%graphql
  {|
  query getTitle {
    allHomes {
      edges {
        node {
          title
          body {
            ...on HomeBodyLinks {
              fields {
                link {
                  ...on Page {
                    title
                    _meta {
                      uid
                    }
                  }
                  ...on _ExternalLink {
                    url
                  }
                }
              }
            }
          }
        }
      }
    }
  }
|}
];

module GetTitleQuery = ReasonApollo.CreateQuery(GetTitle);

let styles = ReactDOMRe.Style.make(~marginRight="10px", ());
let toString = React.string;

[@react.component]
let make = _ => {
  <GetTitleQuery>
    ...{({result}) =>
      switch (result) {
      | Loading => <div> {"Loading" |> toString} </div>
      | Error(error) => <div> {error##message |> toString} </div>
      | Data(response) =>
        switch (response##allHomes##edges) {
        | None => ReasonReact.null
        | Some((data: Js.Array.t('a))) =>
          switch (data[0]) {
          | None => ReasonReact.null
          | Some(node) => {
            <div>
              <Title title=node##node##title />
              <Body body=node##node##body />
            </div>
            }
          }
        }
      }
    }
  </GetTitleQuery>;
};