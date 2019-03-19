# serverless-basic-reason

## Getting started

This repo contains simple usage of `AWS Lambda` with `serverless` and `reason` with `bucklescript` to `nodejs`, initialized by running `bsb -init my-new-project -theme basic-reason` then adding the needed `serverless` config files.

**Clone the repository**

**Install dependencies**

```sh
yarn install # or npm install
```

## Build

```sh
yarn build # or npm run build
```

**Run Offline + Watch**

```sh
yarn serve   # or npm run serve
```

## Testing

Run `yarn serve` then navigate to [http://localhost:3000](http://localhost:3000), the list of available endpoints should be listed there

**REST API**

We can do a `GET` request to 
 * `/hello` -> Hello test API
  ```json
  {
    "message": "Hello from Reason!",
    "event": {
      ...
    }
  }
  ```

 * `/users` -> Github `users` api
  ```json
    [
      {
        "login": "mojombo",
        "id": 1,
        "node_id": "MDQ6VXNlcjE=",
        ...
      }
    ]
  ```

 * `/users/{userId}` -> Github `user` by `username`
 ```json
  {
    "login": "taogilaaa",
    "id": 11565866,
    "node_id": "MDQ6VXNlcjExNTY1ODY2",
    ...
  }
 ```

The server returns the following response:


## Editor
If you use `vscode`, Press `Windows + Shift + B` it will build automatically

**Deployment:**

We can deploy the existing solution by using [Serverless](https://serverless.com) then run

```sh
# Setup serverless aws account configuration
serverless config credentials --provider aws --key YOUR_AWS_ACCESS_KEY_ID --secret YOUR_AWS_SECRET_ACCESS_KEY

yarn deploy # or npm run deploy
```
