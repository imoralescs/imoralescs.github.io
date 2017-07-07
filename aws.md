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


**Serverless Framework**
