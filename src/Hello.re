[@bs.scope "JSON"] [@bs.val] external stringify: 'a => 'a = "stringify";

let handler = (event, _context, callback) => {
  let message =
    switch (Js.Nullable.toOption(event##queryStringParameters)) {
    | None => "Hello from Reason!"
    | Some(params) =>
      switch (Js.Nullable.toOption(params##name)) {
      | None => "Hello from Reason!"
      | Some(name) => "Hello " ++ name
      }
    };

  let body = {"message": message, "event": event};
  let response = {"statusCode": 200, "body": stringify(body)};

  callback(. Js.Nullable.null, response);
};
