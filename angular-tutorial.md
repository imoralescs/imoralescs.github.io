
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
