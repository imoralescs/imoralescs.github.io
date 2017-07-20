# Amazon Web Service (AWS) - Serverless

## Preparation

### Creating Groups

From Identity & Access Management (IAM) screen in the AWS console click on **Groups** on the left sidebar. Then click **Create New Group** and add the name of the group `serverless-group`. Then click **Next Step** and on **Attach Policy** we are going to attach to this group `AdministratorAccess` by selecting it and finish this section by click on **Next Step**, reviews all details and click on **Create Group**.

### Creating Users

From Identity & Access Management (IAM) screen in the AWS console click on **Users** on the left sidebar. Then click **Add user** and add the name `serverless-admin`. Select **Programmatic access** to allow development and click on **Next: Permission**. From on set permissions area select the group `serverless-group` adn click on **Next: Review**. After review all details we can proceed by click on **Create user**.

### Access Key & Secret Key

After create the user, AWS will provide you a table with the **user**, **access key id** and **secret access key**. Copy all items and saved on a secure document for future used.

## AWS API Gateway

Is a service that enable developer to create or define endpoint & HTTP method to directly access to some AWS services.

### Create API

From API Gateway service screen in the AWS console click on **Get Started** to create a new API or otherwise if you already have some API, click **Create API** on the left sidebar.

Will see 4 ways to create our API:

1. **New API**
2. **Clone from existing API** - You can used other existing API.
3. **Import from Swagger** - Allow us to import a Swagger definition file.
4. **Example API**

On this initial example we are going to select create a new API, click on **New API** and add the name of `firstAPI`. We can add some description and click on **Create API**.

### Add Resource to API

From API Gateway service screen in the AWS console by selecting our API on the left sidebar, we click on **Actions -> Create Resource**. This allow us to create our resource to the same API we selecting. Add to resource a name and url path name, on this case will be `first-api-test`, and click on **Create Resource**.

### Add Method to API Resource

From API Gateway service screen in the AWS console by our desire resource to add method or by selecting our resource to add method, click on **Actions -> Create Method** and we can pick what kind of HTTP method we want to include to it resource selecting. On this case we are going to select **GET**.

On the setup of this method, we have:

* **Lambda Function** - refer to any lambda function we create.
* **HTTP** - refer to foward to another http request.
* **AWS Service** - refer to another service provide by AWS. 
* **Mock** - refer to mock up you own response.

On this case we are going to select **Mock** and click on **Save**. To testing purpose we are going to send through our API some dummies data. By selecting our new previous method we are going to click on **Integration Response**, expand on **Body Mapping Templates**, click on **application/json** and add the following JSON code:

```json
{
  "message": "This is working!"
}
```

Once added click on **Save** and we need to deploy this API to used or testing.

### Deploy API

From API Gateway service screen in the AWS console by selecting our API we desire to deploy on the left sidebar, click on **Actions -> Deploy API**. We need to create or select **Stage** we want to deploy. If is the case that we need to create a new one, type the name of the stage, on this case will be `dev` adn click on **Deploy**. 

From API Gateway service screen in the AWS console by selecting our API on the left sidebar, on the **Stages** section, AWS will provide you the URL to test your API.

```
https://vtjoat3drl.execute-api.us-east-1.amazonaws.com/dev/first-api-test
```

### Options on the left sidebar on API Gateway service screen

* **APIs** - Lists of all API we create on AWS.
* **Usage Plans**
* **API Keys** - Allow us to share our API with other developer and provider a key for used.
* **Custom Domain Names** - Allow us to choose at own domain name for API.
* **Client Certificates**
* **Setting** - Allow us manage permission and roles of the API.

### Options on each API

* **Resources**
* **Stages** - Are deploy snapshot for ship to the web.
* **Authorizes** - Allow us to add authentication to the API.
* **Model** - Allow us to models our API data with Schema.
* **Binary Support**
* **Dashboard** - Give analitics data from the API.

### API Request-Response Cycle

Basically show us a flow of the data between client(User App) and endpoint. They have **TEST** ability for testing purpose.

* **Method Request** - Handler incoming request.
* **Integration Request** - Mapping incoming data or tranform incoming data into the shape to used that data.
* **Integration Response** - Allow us to extract data or response back to the client.
* **Method Response** - Allow us to configurated the shape the form of the response data.

### Cross Origin Resource Sharing (CORS)

Is a security model to not allow to access resource on the server from another server.

## AWS Lambda

AWS Lambda allows you to run your own code in response to events in a serverless enviroment. Lambda is a Function-as-a-Service (FaaS) platform provided by Amazon Web Services (AWS). Lambda is tightly integrated into the AWS ecosystem and allows developers to build microservices that easily interact with other AWS services. For example, we can create a Lambda function that is executed every time a user signs up through the AWS Cognito service or we can trigger a Lambda function after a file is uploaded to S3. Combining Lambda with the API Gateway, we can build microservices that can be accessed from outside the AWS ecosystem.

Function-as-a-Service or serverless platforms are gaining traction because they allow developers to build applications without focusing on infrastructure.

### Create Lambda Function

From Lambda service screen in the AWS console, if you don't have any previous Lambda function you can go ahead and click **Get Started Now** otherwise click on **Create a Lambda function**. AWS will provide you a selections of blueprint as templates with some dummie code. On this case we are going to select as runtime `Node.js 4.3` and `Blank Function`. After selection of template AWS will ask for triggers option to ours function. We have many options to trigger a Lambda function but for this case, we can leave this option `empty` and click **Next**.

Following previous step we need now to configurate our function, we start with name on this case `firstLambda`, description and runtime. Then we can edit the Lambda code:

```javascript
exports.handler = (event, context, callback) => {
  callback(null, 'Hello from Lambda');
};
```

On code we have:

* **event** - This variable is used by Lambda to pass in event data to the handler (like an HTTP request).
* **context** - The context variable is used to pass in runtime information for the Lambda function, like how much time is remaining before the function will be terminated.
* **callback** - By using it, you can explicitly return data to the caller (like an HTTP response).

Once edit the Lambda code we moving to function handler and role, click on **Role** adn then click on **Create a custom role**. Create a new (IAM) Role, with `lambda_basic_execution` and click on **Allow**. After allow permission we can add some advance properties by click on **Advance settings**. On memory we can add more memory to our function, but as more memory you add more higher payment will be. On this case we are going to set memory to `128`, then timeout allow us to set the time of ou function will spend on execution and quit no metter if the function accomplish or not. On this case we are going to set this to `10 sec`. To finish click on **Next**.

Now we can reviews all details of our Lambda function and click on **Create function**. After successfully creation we can test our function by clicking on the **Test** on upper area. Will see the response of:

```
"Hello from Lambda"
```

### Lambda function handler add role

* **Handler** - This part define the entry point to the Lambda funcion. Example if the change `index.handler` to `index.fn`, this name must be the same on the function code:

```javascript
exports.fn = (event, context, callback) => {
  callback(null, 'Hello from Lambda');
};
```

* **Role** - Allow us to add permission.

## Exercise Compare-Yourself App

### Setting API

From API Gateway service screen in the AWS console, click **APIs** on the left sidebar and then click on **Create API**. Add the name `compare-yourself`, add a new resource with the name `compare-yourself` and select **Enable API Gateway CORS**.

Once enable API gateway CORS AWS automatically add to resource **OPTIONS** method. Now when your API's resources receive requests from a domain other than the API's own domain, you must enable cross-origin resource sharing (CORS) for selected methods on the resource. 

Now again, once enable CORS, we add another method **POST** by click on **Actions -> Create Method** and on method setup we set on **Integration type** to `Lambda Function`, add a dummies Lambda function, this case we can used `firstLambda` and select our **Lambda Region**.

### Setting Our First Lambda Function for POST data

From Lambda service screen in the AWS console, create our application post Lambda function. By selecting **Blank Function** and runtime **Node.js 4.3**. Set trigger to empty, add the name of this function to `cy-store-data` and description to `Store user comparison data`.

On our Lambda code will are going to write:

```javascript
exports.handler = (event, context, callback) => {
  callback(null, 'Store Data');
};
```

Once create our Lambda function we can test ours function and following to the next step.

### Connect Lambda to API Gateway

From API Gateway service screen in the AWS console, by selecting ours API and resource `compare-youself`, selecting **POST** method. Click on **Integration Request** and on **Integration type** select `Lambda Function`. Select region and type the name of the Lambda function associate to this HTTP method, then save.

Now let test our API by API Gateway service screen in the AWS console. We are going to pass request body on this case and we will receive response back.

### Accessing API from the Web

To access our API from external used, we need to deploy our API first. After deploy ours API we can trying using our API on JSFiddler:


```
var xhr = new XMLHttpRequest();
xhr.open('POST', 'https://2e7inih0x8.execute-api.us-east-1.amazonaws.com/dev/compare-yourself');
xhr.onreadystatechange = function(event) {
  console.log(event.target.response);
}
xhr.send();
```

In case we receive this error:

```
XMLHttpRequest cannot load https://2e7inih0x8.execute-api.us-east-1.amazonaws.com/dev/compare-yourself. No 'Access-Control-Allow-Origin' header is present on the requested resource. Origin 'https://fiddle.jshell.net' is therefore not allowed access.
```

To solve this problem, we need to fix our API header request. From API Gateway service screen in the AWS console, by selecting our API resource method **POST** click on **Integration Response** and expand **Header Mappings** we need to set our missing header.

To set our missing header, return to method cycle and click on **Method Response**, then expand **200**, add a new header `Access-Control-Allow-Origin`. Once add new header return to method cycle and click on **Integration Response** expand **Header Mapping** and on **Response header**, add `'*'` on **Mapping value** of the **Header Mappings**. Once finish previous step re-deploy and we can trying again.

### Understanding `event` argument on Lambda function code

On our POST Lambda function we add `event` argument on `callback` as argument of function. 

```javascript
exports.handler = (event, context, callback) => {
  callback(null, event);
};
```

Then test your lambda function API on **POST** method of API, we include on **Request body** :

```json
{
  "name":"Jack Doe",
  "age":"28"
}
```

And click on test, we recive response back:

```json
{
  "name": "Jack Doe",
  "age": "28"
}
```

**Using Lambda Proxy Integration**

With the Lambda proxy integration, API Gateway can pass the entire request object into Lambda function. Proxy integration allow us to map the entire client request to the event parameter of the backend Lambda function, As an interpretation of this "a function that collects request information (HTTP method, query string, path, source IP etc) of this Gateway without permission and passes it to Lambda".

To configurated one of our endpoint or method to used proxy integration, by selecting our **POST** method on API resource, click on **Integration Request**. Then select **Use Lambda Proxy integration**. Once finish the previous step, edit our POST Lambda function with:

```
exports.handler = (event, context, callback) => {
  callback(null, {headers: {'Control-Access-Allow-Origin': '*'}});
};
```

Now let return to ours API **POST** method and test with:

```json
{
  "name": "John",
  "age": 28
}
```

Now we allow to pass the complete request into Lambda function.

### Body Mapping Templates

On `Integration Request` and `Integration Response` we have **Body Mapping Templates** are used to transform an incoming payload into a different format. API Gateway allows you to define input mapping templates, for mapping the incoming request from a client to a server format, and output mapping templates, for mapping the outgoing response from the server to a client format. The mappings are defined using the Velocity Template Language combined with JSONPath expressions. 

From API Gateway service screen in the AWS console, by selecting our API `compare-youself`, resource and method **POST**, click on **Integration Request** and uncheck **Use Lambda Proxy integration**.

On the same method, click on **Integration Request** then expand **Body Mapping Templates** we select on **When there are no templates defined (recommended)** then click on **Add mapping template** and we define the **Content-Type** to `application/json`. Important, this name is not random, `application/json` means that incoming request with **Content-Type** of  `application/json` will be handled by this template. 

On edit template section we write:

```json
{
  "age" : $input.json('$.personData.age')
}
```

* `$input` - Variable provided by AWS, gives you access to your request data(body, params,...)
* `json('$')` - Extracts complete request body.

Then edit our POST Lambda function with:

```
exports.fn = (event, context, callback) => {
  console.log(event);
  const age = event.age;
  callback(null, age * 2);
};
```

Then we create a **Test** with:

```
{
  "personData" : {
    "name" : "Max",
    "age" : 28
  }
}
```

On response we receive:

```
56
```

**Let Mapping the response** 

From API Gateway service screen in the AWS console, by selecting our API `compare-youself`, resource and method **POST**, click on **Integration Response**. Then expand on **Body Mapping Templates** and click on **application/json** and then we can see the section to add our templates:

```
{
  "your-age" : "$input.json('$')"
}
```

Then we create a **Test** with:

```
{
  "personData" : {
    "name" : "Max",
    "age" : 28
  }
}
```

On response we receive:

```
{
  "your-age": 56
}
```

### Models

A model defines the structure of the incoming payload using JSON Schema. The model is an optional, but not required, piece of API Gateway. By providing a model, you make it easier to define the upcoming mapping template that actually does the transformation between the client and server.

Let create models for our exercise API. From API Gateway service screen in the AWS console, on left sidebar section under our API, we have the options **Models**, click on **Models** and then click on **Create**. Type the name of the models, on this case `CompareData` and add content type `application/json`, description is optional. Once finish of create model, we include our **Schema**:

```
{
  "$schema": "http://json-schema.org/draft-04/schema#",
  "title": "CompareData",
  "type": "object",
  "properties": {
    "age": {"type": "integer"},
    "height": {"type": "integer"},
    "income": {"type": "integer"}
  },
  "required": ["age", "height", "income"]
}
```

Now let go back to our resource method **POST**, click on **Method Request** and expand **Request Body**. Then we add content type `application/json` and select our model name, on this case `CompareData`. Once add our model, on the same section click expand **Settings** and select on **Request Validator**: `Validate body`. Let test our **POST** method with:

```
{
    "age": 28,
    "height": 72,
}
```

On response we receive:

```
{
  "message": "Invalid request body"
}
```

To successfully request we need to add all parameters:

```
{
    "age": 28,
    "height": 72,
    "income": 2500
}
```

On response we receive:

```
{
  "your-age": 0
}
```

### JSON Schemas

Models are defined using JSON schema.

**Models and Mappings**

After create our models, now is more simple to Mapping ours parameters.

From API Gateway service screen in the AWS console, by selecting our API `compare-youself`, resource and method **POST**, click on **Integration Response**. Then expand **Body Mapping Templates**. On **Generate template** we can select our models. And on **Method Request** on the mapping section we can select our models.

### Adding DELETE method to API

From API Gateway service screen in the AWS console, click **APIs** on the left sidebar by selecting our `compare-yourself` API let add a new method **DELETE**, click on **Actions -> Create Method** and select **DELETE**. 

Create a new Lambda function `cy-delete-data` for our **DELETE** method with following code:

```javascript
exports.handler = (event, context, callback) => {
  callback(null, 'Deleted!');
};
```

Once create our Lambda function for our method **DELETE**, we need to setup on **Integration type** with **Lambda Function** and select **Lambda Region**. after integration we can trying some test.

### Path Parameters

Path parameters is how to map method request parameters to the corresponding integration request parameters for an API Gateway.

From API Gateway service screen in the AWS console, by selecting our API `compare-youself`, then selecting our resource `compare-youself`, we are going to create a child resource, by clicking on **Actions -> Create Resource**, then on resource name will apply the name to `type` and the resource path will be on curly brance `{type}`. After this check on **Enable API Gateway CORS** and click on **Create Resource**.

By selecting this new variable resource we are going create a new **GET** method, click **Actions -> Create Method**. Now let create our new Lambda function `cy-get-data` to attach to this new method:

```
exports.handler = (event, context, callback) => {
  const type = event.type;
  
  if(type === 'all') {
    callback(null, 'All the data');
  }
  else if(type === 'single') {
    callback(null, 'Just my data');
  }
  else {
    callback(null, 'Hello from get Lambda');
  }
};
```

Now return to API Gateway service screen in the AWS console and add new get Lambda function to **GET** method. 

To passing data from API to our Lambda get function (we need to extract value from url) we need to click on **Integration Request** and expand **Body Mapping Templates**. Then select `When there are no templates define`, click on **add mapping template** and add on **Content-Type** the following value `application/json` and on template editor the following code:

```
{
  "type" : "$input.params('type')"
}
```

Once save, we are trying to test this API, on the test section will see our field input to add value. Let try `all` and as response will see `All the data`.

### Test our API from the web

**Step 1:** Enabaling CORS

From API Gateway service screen in the AWS console, by selecting our API `compare-youself`, the select our main resource and click **Actions -> Enable CORS**. This will add all the CORS header for us. Note: Add to each resource.

**Step 2:** Deploy
**Step 3:** Test our API on Codepen or JSFiddle**

* POST

```javascript
let xhr = new XMLHttpRequest();
xhr.open('POST', 'https://d5bmzork35.execute-api.us-east-1.amazonaws.com/dev/compare-yourself');
xhr.onreadystatechange = function(event){
	console.log(event.target.response);
}
xhr.setRequestHeader('Content-Type', 'application/json');
xhr.send(JSON.stringify({age: 28, height:72, income: 2500}));
```

```
Response: "Store Data!"
```

* DELETE

```
let xhr = new XMLHttpRequest();
xhr.open('DELETE', 'https://d5bmzork35.execute-api.us-east-1.amazonaws.com/dev/compare-yourself');
xhr.onreadystatechange = function(event){
	console.log(event.target.response);
}
xhr.setRequestHeader('Content-Type', 'application/json');
xhr.send();
```

```
Response: "Deleted!"
```

* GET

```
let xhr = new XMLHttpRequest();
xhr.open('GET', 'https://d5bmzork35.execute-api.us-east-1.amazonaws.com/dev/compare-yourself/single');
xhr.onreadystatechange = function(event){
	console.log(event.target.response);
}
xhr.setRequestHeader('Content-Type', 'application/json');
xhr.send();
```

```
Response: "Just my data"
```

### Serverless Framework

The Serverless framework is an open-source, MIT-licensed solution which helps with creating and managing AWS Lambda functions easier.

1. First install Nodejs on machine. Ensure that you have installed latest LTS version of Nodejs. 
2. Install by terminal Serverless as global:

```
npm install -g serverless
```

3. To see options after install type on terminal:

```
serverless
```

4. Create new project directory for our serverless service, then place your terminal on the new directory. Now to create the project type on terminal:

```
serverless create --template aws-nodejs --name simpleLambda
```

or

```
sls create -t aws-nodejs -n simpleLambda
```

5. Our previous terminal command, create a serverless project by choosing **AWS Nodejs** template and adding the name `simpleLambda`. When creating a new service is finished, we will see file structure in the project folder: 

* **serverless.yml** - a YAML file where we will define configurations for our service, such as AWS Resources (S3, DynamoDB, etc), Region, Nodejs Runtime, we want to use and also our service’s functions configurations.
* **handler.js** - Initial Javascript file , created by serverless, that is supposed to be the place where we will write our function’s logic. 

```javascript
'use strict';

module.exports.hello = (event, context, callback) => {
  const response = {
    statusCode: 200,
    body: JSON.stringify({
      message: 'Go Serverless v1.0! Your function executed successfully!',
      input: event,
    }),
  };
  
  callback(null, response);
};
```

* **.gitignore**

6. Open the **serverless.yml** file and edit these Configuration sections: `handler`. This section route to your **handler.js** file function.

```
functions:
  hello:
    handler: handler.hello
```

7. To deploy our function to AWS first we need to configurated our serverless framework on our machine with ours AWS credential.

* To setup credential on serverless, by terminal type:

```
serverless config credentials --provider aws --key xxx --secret yyy
```

* In case we already have a previous olds credentials we can remove that old credentials by following this steps on terminal:

```
cd ~
cd .aws
rm credentials
```

8. Let deploy our services to AWS:

```
serverless deploy --function simpleLambda
```

* Note: After deploy, AWS will provide the following details:

```
Service Information
service: simpleLambda
stage: dev
region: us-east-1
api keys:
  None
endpoints:
  None
functions:
  hello: simpleLambda-dev-hello
```


9. To test our service we need to invoke our function, remember our function is `hello`, not the name of the services:

```
serverless invoke -f hello
```

* Response

```json
{
  "statusCode": 200,
  "body": "{\"message\":\"Go Serverless v1.0! Your function executed successfully!\",\"input\":{}}"
}

```

10. To test our function on local and not on AWS we can type:

```
serverless invoke local -f hello
```

11. Let add method name associated to HTTP path and verbs. We need to add to our **serverless.yml** the following:

```
functions:
  hello:
    handler: handler.hello
    events:
      - http:
          path: hello
          method: get 
```

12. After deploy, AWS provide the url to test on browser.

```
Service Information
service: simpleLambda
stage: dev
region: us-east-1
api keys:
  None
endpoints:
  GET - https://jn1lnbbj9k.execute-api.us-east-1.amazonaws.com/dev/hello
functions:
  hello: simpleLambda-dev-hello
```
