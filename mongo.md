# Mongo

Mongo DB is a non-relational data base. Stored only JSON.

## Install Mongo on local

## Access local or remote mongo shell

By terminal type:

```
$ mongo
```

### Basics command

See all database inside my mongo server:

```
$ show dbs
```

To define or create a new database:

```
$ use dbs_name
```

To add element to a collection `db.collection.insert({property: "value"})` or `db.collection.save({property: "value"})`:

```mongo
db.posts.insert({title:"Sundisse",text:"Nullam ut tortor facilisis sollicitudin."})
```

or 

```mongo
db.posts.save({title:"Suspendisse",text:"Nullam blandit orci ut tortor facilisis sollicitudin."})
```

To find all elements on the collection database
