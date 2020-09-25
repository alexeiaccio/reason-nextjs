type payloadType = {. "uri": string };

[@bs.module "apollo-link-prismic"]
external prismicLink: (payloadType, unit) => ReasonApolloTypes.apolloLink =
  "PrismicLink";