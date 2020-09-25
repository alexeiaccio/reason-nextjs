type data = { data: Js.Json.t };
let introspectionQueryResultData: data = {data: [%raw {| {} |}]};

[%raw {|
  introspectionQueryResultData[/* data */0] = require("../fragmentTypes.json")
|}];

let fragmentMatcher =
  ApolloInMemoryCache.createIntrospectionFragmentMatcher(
    ~data=introspectionQueryResultData.data,
  );

/* Create an InMemoryCache */
let inMemoryCache =
  ApolloInMemoryCache.createInMemoryCache(~fragmentMatcher, ());

/* Create an HTTP Link */
let httpLink =
  PrismicLink.prismicLink(
    {"uri": "https://accio-folio.prismic.io/graphql"},
    (),
  );

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());