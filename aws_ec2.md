# Amazon Web Service (AWS) - EC2

### Create and Manage Nodejs Server

From (EC2) screen in the AWS console click on **Launch Instance**. Then on choose an Amazon Machine Image (AMI) select **Ubuntu Server**. On instance type pick `t2.micro` and then click on **Next: Configure Instance Details**, we are going to skip some instance property by click on **Next: Add Storage**, then **Next: Add Tags** and **Next: Configure Security Group**. 

A security group is a configuration for your server, is basically telling it which ports it should expose to which IP addresses for certain types of traffic. We going to name the group something meaningful, I chose `nodejs-group`. 

To run our app we are going to need SSH access, which by default is on port `22` and uses the TCP protocol. Amazon adds this in for us by default. There is a warning about the source being `0.0.0.0/0` which allows us to SSH from any IP address however this is fine.

Since we would like to also serve an app we need to expose a HTTP port publicly, by default this is port `80`. Click **Add Rule** and select the type as `HTTP`, the default settings for this will use TCP as the protocol and expose port `80` to all IPs. To launch the instance, click **Review and Launch**, then click **Launch**. 

**Key Pair**

After click **Launch** you will recive a **Select an existing key pair or create a new key** modal. 

Choose **create a new key pair**, and name the key, I named it `nodejs-server`. Click **Download Key Pair**. This should download a `.pem` file which can be used to SSH into the server. Save your `.pem` file on you project directory or some SSH directory. 

Keep this file safe because anyone can connect to your server using it, if you lose the file you will need to generate a new one. then click **Launch Instances**

**SSH into your Instance Server**

From the directory which contains the file `.pem` for you instance, Open a new terminal session and use `chmod` to set permissions so that it can be used as a key.

```
$ chmod 400 nodejs-server.pem
```

From (EC2) screen in the AWS console right clicking your Nodejs instance and selecting **connect**, we can see what the correct username to connect to the instance.

```
$ ssh -i "nodejs-server.pem" ubuntu@ec2-54-89-157-152.compute-1.amazonaws.com
```

**Installing node and system dependencies**

Once in an SSH session the first thing to do is get Nodejs. NVM (Node Version Manager) is a pretty great way to install Nodejs and allows you to easily switch versions if required. To install NVM just run this command (same as in the NVM installation instructions).

```
$ curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.32.1/install.sh | bash
```

This command pulls down a script from a remote URL and runs it. You now have NVM! But if you try to run `nvm ls` you will notice it isn’t found. 

This is because NVM adds some code to your `~/.bashrc`. This file is a special file that is run every time you log in to your instance, so to get NVM running you could logout and login again or you can just run the file manually by using the `source` command.

```
$ source ~/.bashrc
```

Now running `nvm ls`. To get the latest version, just `nvm install <latest version number>`.

```
$ nvm install 7
```

To check node is ready to go just echo the version.

```
$ node --version
```
