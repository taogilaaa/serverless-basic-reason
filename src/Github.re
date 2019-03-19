[%raw "require('isomorphic-fetch')"];
[@bs.scope "JSON"] [@bs.val] external stringify: 'a => 'a = "stringify";

let usersHandler = (_event, _context, callback) => {
  Js.Promise.(
    Fetch.fetch("https://api.github.com/users")
    |> then_(Fetch.Response.json)
    |> then_(json => {
         let response = {"statusCode": 200, "body": stringify(json)};

         callback(. Js.Nullable.null, response);
       })
    |> ignore
  );

  // Prevents returning Promise and using callback at the same time
  ();
};

let userHandler = (event, _context, callback) => {
  Js.Promise.(
    Fetch.fetch(
      "https://api.github.com/users/" ++ event##pathParameters##userId,
    )
    |> then_(Fetch.Response.json)
    |> then_(json => {
         let response = {"statusCode": 200, "body": stringify(json)};

         callback(. Js.Nullable.null, response);
       })
    |> ignore
  );

  // Prevents returning Promise and using callback at the same time
  ();
};
