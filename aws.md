# AWS

AWS

## Compute Services

### Lambda

Before create a Lambda function or used Serverless Frameworks for manages your function application code and infrastructure, we need first to give it access keys for your AWS account.

Preparation:

1. Log in or sign up for a new AWS account.
2. Navigate to the Identity & Access Management (IAM) service and create a new Group called `serverless-group`. On the left sidebar of the Identity & Access Management (IAM) area, click on **Groups** and them **Create New Group**. Add the name `serverless-group`, and then click **Next Step** and on Attach Policy we are going to attach to this group **AdministratorAccess** checking his checkbox them click **Next Step**, review all the details of the group and click **Create Group**.
3. Navigate to the Identity & Access Management (IAM) service and create a new User called `serverless-admin`. On the left sidebar of the Identity & Access Management (IAM) area, click on **Users** and them **Add user**. Add the name `serverless-group`, then check on the checkbox **Programmatic access** to allow development and click **Next: Permissions**. On set permissions area check the group `serverless-group` and click **Next: Review**. After review all details, click **Create user**.
4. After create the user, AWS provide you a table with the **user**, **access key id** and **secret access key**. Copy all items and saved on a secure document for future used.

**Lambda and API Gateway**

Exercise 1: Simple "Hello from Lambda"

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

6. Moving to Lambda function handler and role, click on dropdown **Role** and click on **Create a custom role**. Create a new (IAM) Role, with `lambda_basic_execution` and click **Allow**.
7. Then click on dropdown **Advanced settings**, we can add memory on this section, remember if you add more memory and as more memory more higher payment, so for this case we can leave as default `128`. Now we can click **Next**.
8. Review all details of your Lambda and click **Create function**.
9. After successfully creation you can test your function by clicking on the **Test** button on the upper area. After test you will see:

```
"Hello from Lambda"
```
10. Now for Adding API Gateway, Navigate to the API Gateway service. If you don't have any previous API Gateway you go ahead and click **Get Started** otherwise click on **Create API**.
11. On Create new API, we check on radio selector **Example API**, then click on **Import**. Now will see our example API.
12. Click on **APIs** on the left sidebar of the API Gateway area and then click on **Create API**.
13. Add name of your API, on this case `firstAPI` and click **Create API**.
14. To configured you API click on dropdown **Action -> Create Resource**. Add a name for this resource, on this case `foo` and click **Create Resource**.
15. On selection the previous resources we can add a method, by clicking on dropdown **Action -> Create Method** and then on the dropdown under resource select `GET` and click the success icon.
16. Now we can integrate Lambda function. On this case on `GET` method setup check on **Integration type** select `Lambda Function` then on **Lambda Region** select your region and then type the name of the function you want to integrate. On this case `firstLambda`. And click **Seve**.
17. After sucessfully integration, click on **TEST** for testing purpose. Will see the return value:

```
"Hello from Lambda"
```

**Serverless Framework**

1. First install Nodejs on machine.
2. Install by terminal Serverless as global:

```
npm install -g serverless
```

3. To see options after install type on terminal:

```
serverless
```

4. To create a serverless project, create first the serverless directory project and then place your terminal on that directory. Now to create the project type on terminal:

```
serverless create --template aws-nodejs --name simple
```

or

```
sls create -t aws-nodejs -n simple
```

5. After create your serverless project, you will see the following file: 

* **serverless.yml** - Yaml file to configurated our project.
* **handler.js** - main file of the project.
