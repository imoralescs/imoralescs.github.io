# Amazon Web Service (AWS) 

Preparation:

1. Log in or sign up for a new AWS account.
2. Navigate to the Identity & Access Management (IAM) service and create a new Group called `serverless-group`. On the left sidebar of the Identity & Access Management (IAM) area, click on **Groups** and them **Create New Group**. Add the name `serverless-group`, and then click **Next Step** and on Attach Policy we are going to attach to this group **AdministratorAccess** checking his checkbox them click **Next Step**, review all the details of the group and click **Create Group**.
3. Navigate to the Identity & Access Management (IAM) service and create a new User called `serverless-admin`. On the left sidebar of the Identity & Access Management (IAM) area, click on **Users** and them **Add user**. Add the name `serverless-group`, then check on the checkbox **Programmatic access** to allow development and click **Next: Permissions**. On set permissions area check the group `serverless-group` and click **Next: Review**. After review all details, click **Create user**.
4. After create the user, AWS provide you a table with the **user**, **access key id** and **secret access key**. Copy all items and saved on a secure document for future used.

## Serverless

### AWS API Gateway

Is a service that enable developer to create or define endpoint & HTTP method to directly access to some AWS services.

**Create API**

1. Navigate to the API Gateway service. If you don't have any previous API you go ahead and click **Get Started** otherwise click **APIs** on the left sidebar of the section and then click the button **Create API**.
2. Will see 4 ways to create a API:

* *New API*
* *Clone from existing API* - You can used other existing API.
* *Import from Swagger* - Allow us to import a Swagger definition file.
* *Example API*

3. Select **New API** add name `firstAPI`, add description and click on **Create API**.
4. To add resource to you API, by selection you API on the left sidebar, click on dropdown **Actions -> Create Resource**. Add a name for this resource, on this case `first-api-test` and click **Create Resource**.
5. To add a request to you resource, by selecting the resource clicking on the dropdown **Actions -> Create Method** And we can decide what HTTP method we want to used. On this case pick **GET**. On the configuration of this particular method we have:

* *Integration type:*

  * **Lambda Function** - refer to any lambda function we create.
  * **HTTP** - refer to foward to another http request.
  * **AWS Service** - refer to another service provide by AWS. 
  * **Mock** - refer to mock up you own response.

6. Select **Mock** and click on **Save** button.
7. For send through API dummie data, by selecting **GET** method click on **Integration Response**, and on **Body Mapping Templates**, click on **application/json** type:

```json
{
  "message": "This is working!"
}
```

8. Click on save and we need to deploy this API, click on dropdown **Actions -> Deploy API**. We need to create or select **Stage**, if the case you need to create one, type the name of `dev` and click on **Deploy** button.
9. On the left sidebar select your API and on **Stages** section, will provide you the URL to test your API.

```
https://vtjoat3drl.execute-api.us-east-1.amazonaws.com/dev/first-api-test
```

**Options on the left sidebar**

* *APIs* - Lists of all API we create on AWS.
* *Usage Plans* 
* *API Keys* - Allow us to share our API with other developer and provider a key for used.
* *Custom Domain Names* - Allow us to choose at own domain name for API.
* *Client Certificates*
* *Setting* - Allow us manage permission and roles of the API.

**Options on API**

* *Resources*
* *Stages* - Are deploy snapshot for ship to the web.
* *Authorizes* - Allow us to add authentication to the API.
* *Model* - Allow us to models our API data with Schema.
* *Binary Support*
* *Dashboard* - Give analitics data from the API.

**Request-Response Cycle**

Basically show us a flow of the data between client(User App) and endpoint. They have **TEST** ability for testing purpose.

* *Method Request* - Handler incoming request.
* *Integration Request* - Mapping incoming data or tranform incoming data into the shape to used that data.
* *Integration Response* - Allow us to extract data or response back to the client.
* *Method Response* - Allow us to configurated the shape the form of the response data.

**Cross Origin Resource Sharing (CORS)**

Is a security model to not allow to access resource on the server from another server.

**Exercise Compare-Yourself App:**

1. Navigate to the API Gateway service. If you don't have any previous API you go ahead and click **Get Started** otherwise click **APIs** on the left sidebar of the section and then click the button **Create API**.
2. Add the name `compare-yourself` and add the resource `compare-yourself` and check on **Enable API Gateway CORS**. This automatically add to resource **OPTIONS** method.
3. Add another method **POST** by clicking on dropdown **Actions -> Create Method** by selecting our previous resource.
4. On **POST** method setup **Integration type** with **Lambda Function** and select **Lambda Region**.

### AWS Lambda

AWS Lambda allows you to run your own code in response to events in a serverless enviroment. Lambda is a Function-as-a-Service (FaaS) platform provided by Amazon Web Services (AWS). Lambda is tightly integrated into the AWS ecosystem and allows developers to build microservices that easily interact with other AWS services. For example, we can create a Lambda function that is executed every time a user signs up through the AWS Cognito service or we can trigger a Lambda function after a file is uploaded to S3. Combining Lambda with the API Gateway, we can build microservices that can be accessed from outside the AWS ecosystem.

Function-as-a-Service or serverless platforms are gaining traction because they allow developers to build applications without focusing on infrastructure.

**Create Lambda Function**

1. Navigate to the Lambda service.
2. If you don't have any previous Lambda function you go ahead and click **Get Started Now** otherwise click on **Create a Lambda function**.
3. On Select bluprint, Amazon Web Service will offer you a list of functions code template with some dummi code. On this case we are going to select as runtime **Node.js 4.3** and **Blank Function**.
4. Now we need to configure triggres, Amazon Web Service give us many triggers options but for this case we are going to leave this empty and click **Next**.
5. On configuration of the function we can strat we adding the name of the function. `firstLambda`, add description and runtime. Then we can see the Lambda code:

```javascript
exports.handler = (event, context, callback) => {
  callback(null, 'Hello from Lambda');
};
```

* **event** - This variable is used by Lambda to pass in event data to the handler (like an HTTP request).
* **context** - The context variable is used to pass in runtime information for the Lambda function, like how much time is remaining before the function will be terminated.
* **callback** - By using it, you can explicitly return data to the caller (like an HTTP response).

6. Moving to Lambda function handler and role, click on dropdown **Role** and click on **Create a custom role**. Create a new (IAM) Role, with `lambda_basic_execution` and click **Allow**.
7. Then click on dropdown **Advanced settings**, we can add memory on this section, remember if you add more memory and as more memory more higher payment, so for this case we can leave as default `128`. **Timeout** allow us to set a time spend of the function and quit no metter if the function finish or not. On this case we can choose `10 sec`. Now we can click **Next**.
8. Review all details of your Lambda and click **Create function**.
9. After successfully creation you can test your function by clicking on the **Test** button on the upper area. After test you will see:

```
"Hello from Lambda"
```

**Lambda function handler add role**

* *Handler* - This part define the entry point to the Lambda funcion. Example if the change `index.handler` to `index.fn`, this name must be the same on the function code:

```javascript
exports.fn = (event, context, callback) => {
  callback(null, 'Hello from Lambda');
};
```

* *Role* - Allow us to add permission.

### Exercise Compare-Yourself App

1. Navigate to the Lambda service.
2. If you don't have any previous Lambda function you go ahead and click **Get Started Now** otherwise click on **Create a Lambda function**.
3. On Select bluprint, Amazon Web Service will offer you a list of functions code template with some dummi code. On this case we are going to select as runtime **Node.js 4.3** and **Blank Function**.
4. Now we need to configure triggres, Amazon Web Service give us many triggers options but for this case we are going to leave this empty and click **Next**.
5. On configuration of the function we can strat we adding the name of the function `cy-store-data`, add description `Store user comparison data` and runtime. Then we can see the Lambda code:

```javascript
exports.handler = (event, context, callback) => {
  callback(null, 'Hi, I\'m Lambda');
};
```

6. Moving to Lambda function handler and role, click on dropdown **Role** and click on **Create a custom role**. Create a new (IAM) Role, with `lambda_basic_execution` and click **Allow**.
7. Then click on dropdown **Advanced settings**, we can add memory on this section, remember if you add more memory and as more memory more higher payment, so for this case we can leave as default `128`. **Timeout** allow us to set a time spend of the function and quit no metter if the function finish or not. On this case we can choose `10 sec`. Now we can click **Next**.
8. Review all details of your Lambda and click **Create function**.
9. After successfully creation you can test your function by clicking on the **Test** button on the upper area. After test you will see:

```
"Hello from Lambda"
```

**Connect Lambda to API Gateway**

1. Navigate to the API Gateways service.
2. Select API to connect function, on this case select our previous API `compare-youself` and select ours **POST** method. On **Integration type** select **Lambda Function**, select region and type the name of the function on **Lambda Function**. Then click **Save**.
3. For test, click on **Test** and we are not going to pass request body on this case, just click on **Test**. And we receive back our response.

**Accessing the API from the Web**

1. By selecting our API, click on dropdown **Actions -> Deploy API**. We need to create or select **Stage**, if the case you need to create one, type the name of `dev` and click on **Deploy** button.
2. On the left sidebar select your API and on **Stages** section, will provide you the URL to test your API.
3. On JSFiddle we are going to test our API:

```
var xhr = new XMLHttpRequest();
xhr.open('POST', 'https://2e7inih0x8.execute-api.us-east-1.amazonaws.com/dev/compare-yourself');
xhr.onreadystatechange = function(event) {
  console.log(event.target.response);
}
xhr.send();
```

4. In case we receive this error:

```
XMLHttpRequest cannot load https://2e7inih0x8.execute-api.us-east-1.amazonaws.com/dev/compare-yourself. No 'Access-Control-Allow-Origin' header is present on the requested resource. Origin 'https://fiddle.jshell.net' is therefore not allowed access.
```

5. We need to fix the header request. By clicking **POST** method on resource and click under **Integration Response**, on **Header Mappings** we need to set our missing header.
6. To set our missing header click under **Method Response**, then click dropdown on **200**, add a new header `Access-Control-Allow-Origin` on **Response header** and back to **Integration Response** add `'*'` on **Mapping value** of the **Header Mappings**.
7. Now we need to re-deploy. And try again.

**Understanding "event" argument on Lambda function code**

First we add `event` argument on `callback` as argument of function. 

```javascript
exports.handler = (event, context, callback) => {
  callback(null, event);
};
```

On test your lambda function API on **POST** method of API, we include on **Request body** :

```json
{
  "name":"Jack Doe",
  "age":"28"
}
```

And  click on test, we recive response back:

```json
{
  "name": "Jack Doe",
  "age": "28"
}
```

**Using Lambda Proxy Integration (Compare-Yourself App)**

With the Lambda proxy integration, API Gateway can pass the entire request object into Lambda function. Proxy integration allow us to map the entire client request to the event parameter of the backend Lambda function, As an interpretation of this "a function that collects request information (HTTP method, query string, path, source IP etc) of this Gateway without permission and passes it to Lambda".

1. To configurated one of endpoint to used proxy integration, On the **POST** method on API resource, click on **Integration Request**. Then check the checkbox **Use Lambda Proxy integration**
2. Now let change ours Lambda function with:

```
exports.handler = (event, context, callback) => {
  callback(null, {headers: {'Control-Access-Allow-Origin': '*'}});
};
```

3. Now let return to ours API **POST** method and test with.

```json
{
  "name": "John",
  "age": 28
}
```

4. Now we allow to pass the complete request into Lambda function.

**Body Mapping Templates**

On `Integration Request` and `Integration Response` we have **Body Mapping Templates** are used to transform an incoming payload into a different format. API Gateway allows you to define input mapping templates, for mapping the incoming request from a client to a server format, and output mapping templates, for mapping the outgoing response from the server to a client format. The mappings are defined using the Velocity Template Language combined with JSONPath expressions. 

* Let try to add this to excercise: 

1. On the **POST** method on API resource, click on **Integration Request**. Then uncheck the checkbox **Use Lambda Proxy integration**.
2. On the same method, click on **Integration Request** then on Body Mapping Templates we check the radion button on **When there are no templates defined (recommended)** then click on **Add mapping template** and we define the *Content-Type* to *application/json*. Important, this name is not random, *application/json* means that incoming request with **Content-Type** of  *application/json* will be handled by this template.
3. Now we right on template section:

```
{
  "age" : $input.json('$.personData.age')
}
```

`$input` - Variable provided by AWS, gives you access to your request data(body, params,...)
`json('$')` - Extracts complete request body.

3. On the Lambda code:

```
exports.fn = (event, context, callback) => {
  console.log(event);
  const age = event.age;
  callback(null, age * 2);
};
```

4. Then we create a **Test** with:

```
{
  "personData" : {
    "name" : "Max",
    "age" : 28
  }
}
```

5. On response we receive:

```
56
```

* Let Mapping the response: 

1. On the **POST** method on API resource, click on **Integration Response**. Then click on dropdown menu and then click on dropdown **Body Mapping Templates**.
2. Click on `application/json` and then we can see the section to add our templates.

```
{
  "your-age" : $input.json('$')
}
```

3. Then we create a **Test** with:

```
{
  "personData" : {
    "name" : "Max",
    "age" : 28
  }
}
```

4. On response we receive:

```
{
  "your-age": 56
}
```

**Models**

A model defines the structure of the incoming payload using JSON Schema. The model is an optional, but not required, piece of API Gateway. By providing a model, you make it easier to define the upcoming mapping template that actually does the transformation between the client and server.

Let create models for our exercise app:

1. On left sidebar section under our API, we have the options **Models**, click on option **Models** and then on button **Create**.
2. Type the name of the models, on this case `CompareData` and add content type `application/json`, description is optional.
3. Now we include our **Schema**:

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

4. Now let go back to our resource method **POST**, click on **Method Request** and click on dropdown **Request Body**.
5. We add content type `application/json` and select our model name, on this case `CompareData`.
6. After add our model, on the same section click the dropdown **Settings** and select on **Request Validator**: `Validate body`
7. Let test our **POST** method with:

```
{
    "age": 28,
    "height": 72,
}
```

8. On response we receive:

```
{
  "message": "Invalid request body"
}
```

9. To successfully request we need to add all parameters:

```
{
    "age": 28,
    "height": 72,
    "income": 2500
}
```

10. On response we receive:

```
{
  "your-age": 0
}
```

**JSON Schemas**

Models are defined using JSON schema.

**Models and Mappings**

After create our models, now is more simple to Mapping ours parameters.

1. On the **POST** method on API resource, click on **Integration Response**. Then click on dropdown menu and then click on dropdown **Body Mapping Templates**.
2. On **Generate template** we can select our models.
3. And on **Method Request** on the mapping section we can select our models.

**Adding DELETE method to API**

1. Navigate to the API Gateway service. On ours `compare-yourself`API adn then resource, clicking on dropdown **Actions -> Create Method** and select **DELETE**.
2. Create a new Lambda function `cy-delete-data` for **DELETE** with following code:

```
```

3. On **DELETE** method setup **Integration type** with **Lambda Function** and select **Lambda Region**. 
4. Now trying some test.

**Path Parameters**

Is how to map method request parameters to the corresponding integration request parameters for an API Gateway API.

1. Navigate to the API Gateway service. On ours `compare-yourself`API and then resource, by selecting our resource, we are going to create a child resource.
2. Clicking on dropdown **Actions -> Create Resource**, then on resource name will named `type` and the resource path will be on curly brance `{type}`. After this check on **Enable API Gateway CORS** and click on **Create Resource**.
3. Now on this new variable resource we create a new **GET** method. **Actions -> Create Method**.
4. Now let create our Lambda function to this new method:

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
    callback(null, 'Hello from Lambda');
  }
};
```

5. Now to passing data from API to Lambda (extract value from url) we need to go on **Integration Request** and setup a tamplate on **Body Mapping Templates**. Check `When there are no templates define`, add on **Content-Type** the following value `application/json` and on template editor the following code:

```
{
  "type" : "$input.params('type')"
}
```

6. After save, we are trying to test this API, on the test section will see our field input to add value. Let try `all` and as response will see `All data is here!`.

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
