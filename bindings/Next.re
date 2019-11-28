module Link = {
  [@bs.module "next/link"] [@react.component]
  external make: (
    ~href: string=?,
    ~_as: string=?,
    ~prefetch: option(bool)=?,
    ~replace: option(bool)=?,
    ~shallow: option(bool)=?,
    ~passHref: option(bool)=?,
    ~children: 'b,
  ) => React.element = "default";
};

// module Head = {
//   [@bs.module "next/head"] [@react.component];
//   external make: (~children: 'b) => React.element = "default";
// };

// module Error = {
//   [@bs.module "next/error"] [@react.component];
//   external make: (~statusCode: int, ~children: 'b) =>
//     React.element = "default";
// };
