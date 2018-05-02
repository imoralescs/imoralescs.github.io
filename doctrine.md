# Doctrine

## ORM implementas Data Mapper and Unit of Work design patterns.

Data mapper is a layer designed to synchronize data stored in database with their related object of the domian layer. In the Doctrine terminology, a Data Mapper is called an Entity Manager. Entities are plain old PHP objects of the domain layer.

## Using Doctrine's Entity Manager

The principle of an ORM is to manage data stored in a relational database through an object-oriented API.  Each entity class is mapped to the related database table. Properties of the entity class are mapped to the table's columns.

Doctrine comes with the following files to map entities to table:

Annotation in comment block that embed directly in the entities.
XML configuration files.
YAML configuration files.
Plain PHP files.

## Entities and Mapping Information
