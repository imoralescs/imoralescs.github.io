
## Install Angular CLI Global

```
npm install -g @angular/cli
```

## Create a new project

```
ng new node-angular-mongo --routing --style=scss
```

### Flag

They are usefull for pre config some file in Angular for us. In this case we used `--routing` and `--style=scss`

## Setup Express Server 

First we need to be on the main root directory of the project. Then by command line type:

```
npm install --save express body-parser
```

Second on the root directory we need to create a new file called `server.js` and add the following code:

```
const express = require('express')
const bodyParser = require('body-parser')
const path = require('path')
const http = require('http')
const app = express()

// Parsers
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: false }))

// Serve static files
app.use(express.static(path.join(__dirname, 'dist')))

// Set our api routes
// app.use('/api', api)

// Return other routes to Angular index file
app.get('*', (req, res) => {
    res.sendFile(path.join(__dirname, 'dist/index.html'))
})

// Set port
const port = process.env.PORT || '3000'
app.set('port', port)

// Create the HTTP Server
const server = http.createServer(app)

server.listen(port, () => console.log(`Running on localhost:${port}`))
```

### Build ours distribution directory

```
ng build
```

Note: We need to update ours project `angular.json` file to avoid the build create a new sub directory project inside on the `dist` directory. We need to update the following value `outputPath` after this when you build, all your files will be in `dist` directory 

### Run ours node server

```
node server.js
```

## Creating Restful API

First we need to include mongoose to our project.

```
npm install --save mongoose
```

Then second we need to create ours `server` directory in our root directory. Inside on that directory we create another directory called `routes`, then inside of `routes` directory, we need to create a file called `api.js`. Now add the following code:

```
const express = require('express')
const router = express.Router()
const mongoose = require('mongoose')
const post = require('../models/post')

const db = "mongodb://imoralescs:123456abc@ds123196.mlab.com:23196/node-angular"

mongoose.Promise = global.Promise
mongoose.connect(db, function(err) {
    if(err) {
        console.log('Connection error')
    }
})

router.get('/posts', function(req, res) {
    console.log('Requesting posts')

    post
        .find({})
        .exec(function(err, posts) {
            if(err) {
                console.log('Error getting the posts')
            }
            else {
                res.json(posts)
                console.log(posts)
            }
        })

})

module.exports = router
```

### Adding Model directory

On the same `server` directory create a new directory called `models`, then inside create a new file called `post.js` for create post mongo schema. then add the following code to `post.js`

```
const mongoose = require('mongoose')
const Schema = mongoose.Schema

const postSchema = new Schema({
    title: String,
    url: String,
    description: String
})

module.exports = mongoose.model('post', postSchema)
```

After create ours post schema, and added to our `routes.js` file, We need to add ours api file to ours main `server.js` file on the root, at the end we need to have the following code:

```
const express = require('express')
const bodyParser = require('body-parser')
const path = require('path')
const http = require('http')
const app = express()
const api = require('./server/routes/api')

// Parsers
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: false }))

// Serve static files
app.use(express.static(path.join(__dirname, 'dist')))

// Set our api routes
app.use('/api', api)

// Return other routes to Angular index file
app.get('*', (req, res) => {
    res.sendFile(path.join(__dirname, 'dist/index.html'))
})

// Set port
const port = process.env.PORT || '3000'
app.set('port', port)

// Create the HTTP Server
const server = http.createServer(app)

server.listen(port, () => console.log(`Running on localhost:${port}`))
```

For testing ours api, we need to try the url:

```
http://localhost:3000/api/posts
```
