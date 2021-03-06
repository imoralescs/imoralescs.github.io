# Amazon Web Service (AWS) - EC2

### Create and Manage Nodejs Server

**Terms**

* `.bashrc`: The `.bashrc` file is a shell script which is run every time a user opens a new shell. It’s normally located in `~`, your home directory. This is where bash will try to find your settings and load them whenever the terminal is opened. BASH stands for Bourne Again Shell. There are a number of different shells including csh, zsh, dash and korn. 

* `shell`: Is an interpreter which can accept commands for a user and run them to perform operations such as navigating around a file system, running programs and interacting with devices.

* `ln`: A symbolic link, also termed a soft link, is a special kind of file that points to another file, much like a shortcut in Windows or a Macintosh alias. Unlike a hard link, a symbolic link does not contain the data in the target file.

From Elastic Compute Cloud (EC2) screen in the AWS console click on **Launch Instance**. Then on choose an Amazon Machine Image (AMI) select **Ubuntu Server**. 

On instance type pick `t2.micro` and then click on **Next: Configure Instance Details**, we are going to skip some instance property by click on **Next: Add Storage**, then **Next: Add Tags** and **Next: Configure Security Group**. 

A security group is a configuration for your server, is basically telling it which ports it should expose to which IP addresses for certain types of traffic. We going to name the group something meaningful, I chose `nodejs-group`. 

To run our app we are going to need SSH access, which by default is on port `22` and uses the TCP protocol. Amazon adds this in for us by default. There is a warning about the source being `0.0.0.0/0` which allows us to SSH from any IP address however this is fine.

Since we would like to also serve an app we need to expose a HTTP port publicly, by default this is port `80`. Click **Add Rule** and select the type as `HTTP`, the default settings for this will use TCP as the protocol and expose port `80` to all IPs. 

To launch the instance, click **Review and Launch**, then click **Launch**. 

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

**Creating a public HTTP endpoint**

Make a directory for the server and cd into it.

```
$ mkdir server
$ cd server
```

Now you are in your server directory, you need to npm init

```
$ npm init
```

This will create a `package.json` file which will be used to track any dependencies we use. All we will need to run our server is the express package. 

To install express and add it to `package.json`.

```
$ npm install express --save-dev
```

Now we just need to add some code to run the server. We will use `nano` to write the server in an `index.js` file.

```
$ nano index.js
```

```javascript
const express = require('express')
const app = express()

app.get('/', (req, res) => {
  res.send('HELLO NODEJS FROM AWS!')
})

app.listen(3000, () => console.log('Server running on port 3000'))
```

Press `ctrl+x` to exit, ensuring you save when you exit by pressing `y` followed by `enter`. Now we can use node to start the server!

```
$ node index.js
```

Once listening, this should log `Server running on port 3000`. You may have noticed however we didn’t open our instance server traffic to port `3000`, we opened it to port `80`. 

Port `80` is a privileged port and running the server there using Nodejs is unusual, generally using a router is better. If you change the `index.js` file to use `80` and then run `node index.js` you will notice you get a permission denied error.

Leave your server running and go to the **Security Groups** tab in the AWS EC2 console. Right click the **security group** on your setup Nodejs instance and click edit **inbound rules**. Click **Add Rule**. This time we are going to use a ``custom TCP`` rule on port `3000`, open to `anywhere` and **Save**.

Using a browser, visit your public DNS URL with port 3000.

**Leave Nodejs server running**

To leave the server running when we log out, we need to press `ctrl+z` to pause the process. When you press `ctrl+z` you will be presented with all jobs, in this case the only one there will be the Node.js job that was paused. 

You can see that the job number for `node index.js` is 1 (as noted by [1]+). To run that in the background, use the bg command.

```
$ bg %1
```

Then logout

```
$ exit
```

**Serving HTTP traffic on the standard port 80**

We are going to install **nginx** on the Ubuntu instance.

```
$ sudo apt-get update
$ sudo apt-get install nginx
```

After install so you should now have it running on port `80`, check by entering your public DNS URL into a browser. In case if this doesn't work, you might need to start it manually.

```
$ sudo /etc/init.d/nginx start
```

We need to configure **nginx** to route port `80` traffic to port `3000`. **nginx** has config placed in the `/etc/nginx/sites-available` folder where there is already a default config which serves the **nginx**

You can take a look at this config using `cat`.

```
$ cat /etc/nginx/sites-available/default
```

Let’s first remove the default config from `sites-enabled`, we will leave it in `sites-available` for reference.

```
$ sudo rm /etc/nginx/sites-enabled/default
```

Create a config file in `sites-available` and name it whatever you like.

```
$ sudo nano /etc/nginx/sites-available/nodejs_server
```

The following is the config we are going to use.

```
server {
  listen 80;
  server_name tutorial;
  location / {
    proxy_set_header  X-Real-IP  $remote_addr;
    proxy_set_header  Host       $http_host;
    proxy_pass        http://127.0.0.1:3000;
  }
}
```

This will forward all HTTP traffic from port `80` to port `3000`. To link the config file in `sites enabled`

```
$ sudo ln -s /etc/nginx/sites-available/nodejs_server /etc/nginx/sites-enabled/nodejs_server
```

Restart nginx for the new config to take effect.

```
$ sudo service nginx restart
```

If it is not running then you need to start it. 

```
$ node index.js
```

Once the server is running, press `ctrl+z`, then resume it as a background task.

```
$ bg %1
```

Now visit your server’s public DNS URL, using port `80`.

**Keeping the Nodejs process running with PM2**

It’s quite tedious using ctrl+z to pause a process, and then running it in the background. Also, doing it this way will not allow the Nodejs process to restart when you restart your server after an update or crash.

Before moving forward, stop your running node process

```
# Nukes all Node processes
$ killall -9 node
```

To keep these processes running we are going to use a great NPM package called PM2. Install PM2 globally.

```
$ npm i -g pm2
```

To start your server, simply use `pm2` to execute `index.js`.

```
$ pm2 start index.js
```

To make sure that your PM2 restarts when your server restarts:

```
$ pm2 startup
```

This previous statement will print out a line of code you need to run depending on the server you are using. Run the code it outputs. In my case is:

```
$ sudo env PATH=$PATH:/home/ubuntu/.nvm/versions/node/v7.10.1/bin /home/ubuntu/.nvm/versions/node/v7.10.1/lib/node_modules/pm2/bin/pm2 startup systemd -u ubuntu --hp /home/ubuntu
```

Finally, save the current running processes so they are run when PM2 restarts.

```
$ pm2 save
```

That’s it! You can log out/in to SSH, even restart your server and it will continue to run on port 80.

To list all processes use

```
$ pm2 ls
```


** Deploy code into the server **

Go to Github or your favourite source control website, login and create a new repository named what you like.

Make a new directory wherever you like to put your code projects locally

```
$ cd ~
$ mkdir nodejs-app
$ cd nodejs-app
```

Now set up your origin, make an empty commit and push it up, setting your upstream branch as master.

```
$ git init
$ git commit --allow-empty -m "First commit"
$ git remote add origin git@github.com:imoralescs/nodejs-app.git
$ git push -u origin master
```

In case of Permission denied (publickey). You need to create a new SSH key on github to upload by SSH. Simply follow those steps and you will set up your ssh key:

1. Generate a new ssh key (or skip this step if you already have a key) `ssh-keygen -t rsa -C "your@email"`

```
$ ssh-keygen -t rsa -C "imoralescs@gmail.com"
```

2. Once you have your key set in home/.ssh directory (or Users/<your user>.ssh under windows), open it and copy the content.

```
$ cd /home/israel/.ssh
$ cat  id_rsa.pub
```

3. On your GitHub profile there is an Edit Profile button. It is located on top-right corner of the webpage. Press it and you will see left Personal Settings menu.

4. Inside that menu find SSH and GPG keys option and press it. You will see an option New SSH key to add new key.

```
$ git push -u origin master
```

It’s nice to start with an empty commit.

Like we did on the server run `npm init` and then create an `index.js` file using the same code from the last.

```
$ nano index.js
```

```javascript
const express = require('express')
const app = express()

app.get('/', (req, res) => {
  res.send('HELLO NODEJS FROM AWS!')
})

app.listen(3000, () => console.log('Server running on port 3000'))
```

NPM install express

```
$ npm install express --save
```

Also, let’s add a `.gitignore` file so that we don’t check in the `node_modules` directory. `.DS_Store` files always get added to directories by OSX, they contain folder meta data. We want to ignore these too.

```
$ nano .gitignore
```

```
node_modules
.DS_Store
```

Now add all your code and push it up

```
$ git add .
$ git commit -m "Nodejs server."
$ git push
```

Now we need to pull the code into the server. We need to SSH into the server, generate a SSH private/public key pair and then add it as a deployment key in source control (i.e. Github).

```
$ ssh-keygen -t rsa
```

Show the contents of the file

```
$ cat ~/.ssh/id_rsa.pub
```

Select the key’s contents and copy it into Github. Deploy keys are added in a section called Deploy keys in the settings for your repo. 

Whenever you are logged in over SSH, you want the keys to be added so that they are used to authenticate with Github. To do this, add these lines to the top of your `~/.bashrc` file.

```
# Start the SSH agent
$ eval `ssh-agent -s`

# Add the SSH key
$ ssh-add
```

This will make sure you use the keys whenever you log on to the server. To run the code without logging out, execute the `.bashrc` file

```
$ source ~/.bashrc
```

Now we can clone the repo. Remove any previous code on the server and in the user directory, clone the repo

```
$ git clone git@github.com:imoralescs/nodejs-app.git
```

If it works, it will allow you to type “yes” to add github as a known host, then the repo will be downloaded.

**Using PM2 to deploy**

In a nice world we like to completely avoid ever using SSH. For deployment, we are going to use PM2 in order for us to do the git cloning on the server for us, with some bonus features.

Before using PM2, remove the code you just pulled in from git into your server.

```
$ rm -rf ~/server
```

While you are still in the SSH session, ensure that there are no processes still running on PM2, if there are then remove them.

```
$ pm2 ls

$ pm2 delete all
```

In your local version of the project, install PM2 globally

```
$ npm i -g pm2
```

Now we need to add a config file PM2 can read so that it knows how to deploy. PM2 configs are fully explained in the PM2 docs. The config file can be auto generated but I prefer to just create my own from scratch, avoiding any config I don’t need.

The config file should be named `ecosystem.config.js` and should look like this

```
module.exports = {
  apps: [{
    name: 'nodejs_server',
    script: './index.js'
  }],
  deploy: {
    production: {
      user: 'ubuntu',
      host: 'ec2-174-129-116-141.compute-1.amazonaws.com',
      key: '~/Documents/SSH/nodejs-server.pem',
      ref: 'origin/master',
      repo: 'git@github.com:imoralescs/nodejs-app.git',
      path: '/home/ubuntu/nodejs_server',
      'post-deploy': 'npm install && pm2 startOrRestart ecosystem.config.js'
    }
  }
}
```

You will need to add your own host in the config file.

How does PM2 use this config file? When you run pm2 deploy ..., PM2 SSHs into your server, clones your repo into the directory specified in path, then it runs the post-deploy on the server (so it starts your server using the PM2 installed globally on the server). After the deploy, you will be able to run pm2 ls on the server to see all the apps running, their names will be the same as specified in the config file.

Once the file is saved, setup the directories on the remote

```
$ pm2 deploy ecosystem.config.js production setup
```

if you run into any auth issues, look back at setting up the SSH agent to make sure you didn’t miss anything.

Once setup, commit and push your changes to Github so that when it clones it gets your `ecosystem.config.js` file, which is going to be used to start your app using PM2 on the server.

```
$ git add .
$ git commit -m "Setup PM2 deployment"
$ git push
```

Now you can run the deploy command

```
$ pm2 deploy ecosystem.config.js production
```

This should come up with an error, which will be that `npm` was not found.

The reason for this is because of some code in the `.bashrc` file of the server. This code stops the file from running if the shell is not interactive. Unlike using ssh, PM2 logs into the server in a non-interactive shell. NVM is set up in the .bashrc file so PM2 isn’t running NVM, which adds the npm executable (thus the error from PM2). Read more about interactive/non interactive shells.

SSH into your server and open up the `~/.bashrc` file. The code that excludes non-interactive sessions is near the top.

```
# If not running interactively, don't do anything
case $- in
  *i*) ;;
  *) return;;
esac
```

```
$ cat ~/.bashrc
```

All we need to do is move the NVM code above this code, so it always executes. Find the following lines and move them above the case statement

```
export NVM_DIR="/home/ubuntu/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && . "$NVM_DIR/nvm.sh"  # This loads nvm
```

```
$ nano ~/.bashrc
```

Save and exit. Back on your local terminal, try running the PM2 deploy again

```
$ pm2 deploy ecosystem.config.js production
```

It should work this time! And your server should still be running when you check in a browser.

Using a global PM2 on the server and a global PM2 on the client is a bit messy. It would be better if our code used the local version of the PM2 package. To do this, add a deploy and restart script to your `package.json`

```
...
"main": "index.js",
"scripts": {
  "restart": "pm2 startOrRestart ecosystem.config.js",
  "deploy": "pm2 deploy ecosystem.config.js production",
  "test": "echo \"Error: no test specified\" && exit 1"
},
"repository": {
...
```

Install PM2 locally and save, using `--save-dev`

```
$ npm i pm2 --save-dev
```

For those not that familiar with NPM, adding --save or --save-dev adds the package, along with a version number to `package.json`. Any packages in the `package.json` file will be installed when running npm install, which happens in the PM2 post-deploy.

Before deploying, commit all your changes and push to git. When you run npm deploy, it will now use the local version of PM2. Neat!

```
$ npm run-script deploy
```
