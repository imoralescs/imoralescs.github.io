# Mongo

## Install Mongo on local

## Access to my local mongo shell

By terminal type:

```
$ mongo
```

### Basics command

See all database inside my server:

```
$ show dbs
```

To define or create a new database:

```
$ use dns_name
```

To add element to new database `db.collection.save({property: "value"})`:

```
db.posts.save({title:"Suspendisse",text:"Nullam blandit orci ut tortor facilisis sollicitudin."})
```
