
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

## Angular

### Data Service

Our Angular Service file will make calls to the API. To start we need to create ours service file using Angular CLI. We can accomplish this by type the following command on the main root project directory by command line.

```
ng generate service Post
```

After file been created, we need to go to ours `src/app/` directory and will are goign to see ours service file, in this case the name is `post.service.ts`. Note `.ts` mean TypeScript file.

Update the `post.service.ts` file with end result like this:

```
import { Injectable } from '@angular/core';
import { Http } from '@angular/http';
// This will allow to transform result from API to JSON data.
import { map } from 'rxjs/operators'

@Injectable({
  providedIn: 'root'
})
export class PostService {

  result:any;
  
  constructor(
    private _http: Http
  ) { }

  getPosts() {
    return this._http.get('/api/posts')
      .pipe(map(result => result.json()))
  }
}
```

Then like any service we create in Angule, must be added as providers at the `app.module.ts` file. The following code is the end result of adding file:

```
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { HttpModule } from '@angular/http'

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';

import { PostService } from './post.service';
import { NavComponent } from './nav/nav.component';
import { HomeComponent } from './home/home.component'

@NgModule({
  declarations: [
    AppComponent,
    NavComponent,
    HomeComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpModule
  ],
  providers: [
    PostService
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
```

## Creating Component

We are going to create our first component, this will be ours navigation. To create our component we need to used our Angular CLI. Type the following command in our command line:

```
ng generate component nav
```

## Adding Class connect services to components

First we need to create ours home componenent:

```
ng generate component home
```

Then we are going to create a class for handling our post data.

```
ng generate class Post
```

Then we can update the following file `post.ts`, located on `src/app/`. At the end we need to have the following code:

```
export class Post {
    _id: string
    title: string
    url: string
    description: string
}
```

Then we need to include class to ours home component file `home.component.ts` and including ours post services too.

```
import { Component, OnInit } from '@angular/core';
import { PostService } from '../post.service';
import { Post } from '../post';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss']
})
export class HomeComponent implements OnInit {

  posts: Array<Post>;

  constructor(private _postService: PostService) { }

  ngOnInit() {
    this._postService.getPosts()
      .subscribe(res => this.posts = res);
  }

}
```

Then we need to include ours component to the angular routes file `app-routing.module.ts`:

```
import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { HomeComponent } from './home/home.component';

const routes: Routes = [
  {
    path: '',
    component: HomeComponent
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
```

Then we add the following code to `home.component.html` file:

```
<div>
  <div *ngFor='let post of posts'>
    <p>{{ post.title }}</p>
  </div>
</div>
```

## Adding another component with routing

In this case we are going to create our details page for each post items. First we start creating the component by using Angular CLI.

```
ng generate component details
```

After create out component we need to setup ours Angular routing, located on `src/app`, file name `app-routing.module.ts`.

```
import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { DetailsComponent } from './details/details.component';

const routes: Routes = [
  { path: '', component: HomeComponent },
  { path: 'details/:id', component: DetailsComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
```

After updating our routing, we are going to update our home component template to route each post to his own details page.

```
<div class='home-container'>
  <div class='post' *ngFor='let post of posts'>
    <p class='post__title'>{{ post.title }}</p>
    <p class='post__description'>{{ post.description }}</p>
    <a class='post__more-info' routerLink='/details/{{post._id}}'>More Info</a>
  </div>
</div>
```

### Updating ours API

We are going to add to our server api, the new route to grab post by id. The file to update is located at `server/routes` and the file name is `api.js`.

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
    // console.log('Requesting posts')
    post
        .find({})
        .exec(function(err, posts) {
            if(err) {
                console.log('Error getting the posts')
            }
            else {
                res.json(posts)
                // console.log(posts)
            }
        })

})

router.get('/details/:id', function(req, res) {
    post
        .findById(req.params.id)
        .exec(function(err, post) {
            if(err) {
                console.log('Error getting the post')
            }
            else {
                res.json(post)
                // console.log(posts)
            }
        })

})

module.exports = router
```

Then we need to include this new API route to our Angular services, we are going to updating `post.service.ts` file, located at `src/app`.

```
import { Injectable } from '@angular/core';
import { Http } from '@angular/http';
// This will allow to transform result from API to JSON data.
import { map } from 'rxjs/operators'

@Injectable({
  providedIn: 'root'
})
export class PostService {

  result:any;
  
  constructor(
    private _http: Http
  ) { }

  getPosts() {
    return this._http.get('/api/posts')
      .pipe(map(result => result.json()))
  }

  getPost(id) {
    return this._http.get('/api/details/' + id)
      .pipe(map(result => result.json()))
  }
}
```

Now we need to include ours service to our details components, we are going to update `details.component.ts`, located at `src/app/details`.

```
import { Component, OnInit } from '@angular/core';
import { PostService } from '../post.service';
import { Post } from '../post';
import { Router, ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-details',
  templateUrl: './details.component.html',
  styleUrls: ['./details.component.scss']
})
export class DetailsComponent implements OnInit {

  post: Array<Post>

  constructor(
    private _postService: PostService,
    private router: ActivatedRoute
  ) { }

  ngOnInit() {
    this.router.params.subscribe((params) => {
      let id = params['id'];

      this._postService.getPost(id)
        .subscribe(result => this.post = result)
    })
  }

}
```

After update ours details component, we need to update out details component template file.

```
<div class='details' *ngIf='post'>
  <a class='details__back' routerLink='/'>Back</a>
  <h1 class='details__title'>{{ post.title}}</h1>
  <p class='details__description'>{{ post.description }}</p>
</div>
```

## Creating Post component section (POST METHOD)

First step is create our component.

```
ng generate component post
```

After create ours component we need to update our Angular routing.

```
import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { DetailsComponent } from './details/details.component';
import { PostComponent } from './post/post.component';

const routes: Routes = [
  { path: '', component: HomeComponent },
  { path: 'details/:id', component: DetailsComponent },
  { path: 'post', component: PostComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
```

Next we need to update our `api.js` server api

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
    // console.log('Requesting posts')
    post
        .find({})
        .exec(function(err, posts) {
            if(err) {
                console.log('Error getting the posts')
            }
            else {
                res.json(posts)
                // console.log(posts)
            }
        })

})

router.get('/details/:id', function(req, res) {
    post
        .findById(req.params.id)
        .exec(function(err, post) {
            if(err) {
                console.log('Error getting the post')
            }
            else {
                res.json(post)
                // console.log(posts)
            }
        })

})

router.post('/posts', function(req, res) {
    var newPost = new post();
    
    newPost.title = req.body.title;
    newPost.url = req.body.url;
    newPost.description = req.body.description

    newPost.save(function(err, addedPost) {
        if(err) {
            console.log('Error inserting the post');
        }
        else {
            res.json(addedPost);
        }
    })

})

module.exports = router
```

Then we need to update ours service

```
import { Injectable } from '@angular/core';
import { Http, Headers, RequestOptions } from '@angular/http';
// This will allow to transform result from API to JSON data.
import { map } from 'rxjs/operators';
import { Post } from './post'

@Injectable({
  providedIn: 'root'
})
export class PostService {

  result:any;
  
  constructor(
    private _http: Http
  ) { }

  getPosts() {
    return this._http.get('/api/posts')
      .pipe(map(result => result.json()))
  }

  getPost(id) {
    return this._http.get('/api/details/' + id)
      .pipe(map(result => result.json()))
  }

  insertPost(post: Post) {
    let headers = new Headers({ 'Content-Type': 'application/json' });
    let options = new RequestOptions({ headers: headers });

    return this._http.post('/api/posts', JSON.stringify(post), options).pipe(map(result => result.json()))
  }
}
```

Then update ours template

```
<div>
  <form [formGroup]='postForm' (ngSubmit)='addPost(postForm.value)' >
    <div>
      <label>Title
        <input type='text' name='title' [formControl]="postForm.controls['title']">
      </label>
    </div>
    <div>
      <label>Url
        <input type='url' name='url' [formControl]="postForm.controls['url']">
      </label>
    </div>
    <div>
      <label>Description
        <textarea name='description' id='description' [formControl]="postForm.controls['description']"></textarea>
      </label>
    </div>
    <input type='submit' value='Post' [disabled]='!postForm.valid'>
  </form>
</div>
```

And final step add our module to ours `app.module.ts`

```
import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { HttpModule } from '@angular/http'

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';

import { PostService } from './post.service';
import { NavComponent } from './nav/nav.component';
import { HomeComponent } from './home/home.component';
import { DetailsComponent } from './details/details.component';
import { PostComponent } from './post/post.component'

@NgModule({
  declarations: [
    AppComponent,
    NavComponent,
    HomeComponent,
    DetailsComponent,
    PostComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpModule,
    FormsModule,
    ReactiveFormsModule
  ],
  providers: [
    PostService
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
```
