[@react.component]
let default = _children => {
  <div>
    <ReasonApollo.Provider client=Client.instance>
      <Header />
    </ReasonApollo.Provider>
    <p> {React.string("HOME PAGE is here!")} </p>
  </div>;
};