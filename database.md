
## What is a Database

Ordered collection of data. 

## DBMS 

Is a software that is designed to model data and provide interaction with a user. Data is normally stored in one or more files, usually stored in tables, tables contain rows and columns. Some DBMS are MySQL, PostgreSQL, Oracle, MariaDB, etc.

Example of table inside of a database:

```
 id | first_name | last_name | email
---------------------------------------------------
 1  | Brad       | Traversy  | brad@something.com
 2  | John       | Doe       | john@something.com
 3  | Steve      | Hill      | steve@something.com
```
Table Name: Users
Columns/Fields: id, first_name, last_name, email
Rows/Records: 3 Users

## SQL (Structured Query Language) 

Is a special purpose programming language that allows developers to interact with the data in a database. Is based on relational algebra and tuple relational calculus. Data definition and data manipulation language. Perform CRUD(Create, Read, Update, Delete).

## MySQL 

Is a popular open source relational database, that is powerful, reliable and scalable. MySQL can be integrated into web applications written in multiple languages. MySQL uses a client/ server model with 3 general program categories.

 1. Server - mysqlId is the program that manages the databases and tables. It is the only program that touches the actual database.
 2. Clients - A client is a program that you can use to communicate with the MySQL server. There are many to choose from in both GUI & command-line format.
 3. Utilities - Usually used for special purposes. An example is mysqlId_safe which starts up and monitors the server.

## Storage Engine

A storage engine is what MySQL uses to store, handle and retrieve data from a database table. They are 10 storage engines in MySQL but all of them may not be available in certain situations. The most popular are MyISAM and InnoDB. MyISAM was the default storage engine until MySQL was released. Now InnoDB is the default.

## Data Types

MySQL offers many data types but places those data types into 3 categories. 

 * Unsigned - An Unsigned data type can not be negative but has twice as large a renge that positive intergers.
 * Signed - data type can have negative values.
 * TINYINT, SMALLINT, MEDIUMINT, INT and BIGINT all have signed and unsigned versions.

### Numeric

 * INT - Normal sized integer. Width up to 11 digits.
 * TINYINT - Very small integer. 0 - 255 and a width up to 4 digits. Synonym for BOOLEAN.
 * SMALLINT - Width of 5 digits.
 * MEDIUMINT - Width of 9 digits.
 * BIGINT - Up to 20 digits.
 * FLOAT - Floating point number. Can define length and number of decimals.
 * DOUBLE - Double precision floating point number.
 * DECIMAL - Unpacked floating point number.

### String 

 * CHAR - A fixed length string 1 - 255 chars in length. Not required to specify a length, default to 1.
 * VARCHAR - Variable length between 1 - 255 chars. Must have a defined length.
 * BLOB or TEXT - Max length of 65535 characters. BLOBS can store large binary data like images, but I would suggest NOT storing images in a database.
 * TINYBLOB or TINYTEXT - Max length of 255.
 * MEDIUMBLOB or MEDIUMTEXT - Max length of 16777245.
 * LONGBLOB or LONGTEXT - Max length up to 4294967295.
 * ENUM - An enumeration which is basically a list. use to create a list of items for which a value must be selected.

### Date and Time

 * DATE - A date value in YYY-MM-DD format. September 10th, 1981 would be stored as 1981-09-10
 * DATETIME - A date and time combination in YYY-MM-DD HH:MM:SS format.
 * TIMESTAMP - A timestamps between midnight.
 * TIME - Stores the time in HH:MM:SS format.
 * YEAR - Stores a year in 2-digit or 4-digit format.

## Relational Model Rules

Each column value must be a single value only. All values for a given column must be of the same data type. Each column name must be unique. The order of columns is insignificant. No two rows in a relation can be identical. The order of the rows is insignificant.

Students Table
```
 student_id | first_name | last_name | sex
---------------------------------------------------
 200800101  | Brad       | Traversy  | M
 200800102  | John       | Doe       | M
 200800103  | Steve      | Hill      | M
 200800104  | Alice      | Baker     | F
```

Courses Table
```
 course_id | course_title               | credits
-------------------------------------------------
 M101      | Mathematics                | 4.5
 P101      | Philosophy                 | 4.5
 M207      | Intro. to Programming      | 3.0
 P321      | Life, Universe, Everything | 3.0
 M321      | Database Design            | 3.0
```

Enrollments Table
```
 student_id | course_number | term | year
------------------------------------------
 200800101  | P101          | 1    | 2017
 200800102  | M101          | 1    | 2017
 200800103  | M342          | 1    | 2017
 200800104  | P321          | 1    | 2017
```

## Functional Dependencies

A functional dependency describes a relationship between columns with a single relation. A column is dependent on another if one value can be used to determine the value of another. 

Example: first_name is functionally dependent on id because id can be used to uniquely determine the value of first_name

## Database Normalization

Normalization is the process of organizing the fields and tables of a relational database to minimize redundancy and dependency. This can involve dividing large tables into smaller tables and defining relationships between them. The objective is to isolate data so that actions in a field can be made in one table and then propagated through the rest of the needed tables using properly defined relationships.

### First Normal Form (1NF)

 * No repeating or duplicate fields.
 * Each row should contain only one value.
 * Each row/record should be unique and identified by a primary key.

Example:
Customers Table (Wrong)
```
 id  | name           | membership
----------------------------------
 01  | John Doe       | silver
 01  | John Doe       | gold
 02  | Steve Hill     | gold
```

Customers Table (Right)
```
 id  | name           
------------------
 01  | John Doe       
 02  | Steve Hill     
```

Memberships Table (Right)
```
 id  | customer_id | membership           
-------------------------------
 01  | 01          | silver  
 02  | 01          | gold
 03  | 02          | gold
```

### Second Normal Form (2NF)

 * Should be in 1NF
 * All non-key fields depend on all components of the primary key.
 * No partial dependencies.

Example:
Customers Table (Wrong)
```
 id  | name           | membership_id | membership
--------------------------------------------------
 01  | John Doe       | 02            | silver
 02  | Steve Hill     | 01            | gold
```

Customers Table (Right)
```
 id  | name           
------------------
 01  | John Doe       
 02  | Steve Hill     
```

Memberships Table (Right)
```
 id  | customer_id | membership           
-------------------------------
 01  | 01          | silver  
 02  | 01          | gold
 03  | 02          | gold
```

### Third Normal Form (3NF)

 * Should be in 2NF
 * Every non-prime attribute of table must depend on primary key.

Example:
Customers Table (Wrong)
```
 id  | name  | street   | city     | zip
-------------------------------------------
 01  | John  | 2 Main   | Amesbury | 01913 
 02  | Steve | 4 School | Merrimac | 01860 
```

Customers Table (Right)
```
 id  | name  | zip
---------------------
 01  | John  | 01913 
 02  | Steve | 01860 
```

Address Table (Right)
```
 zip   | street   | city     
-----------------------------
 01913 | 2 Main   | Amesbury  
 01860 | 4 School | Merrimac  
```

## Design Process

### Step One : Define your purpose

The first step is to define the purpose of yout database and the applications that will use it. Our purpose is on this case is pretty simple. We want to create a database for an application/website that will example:

 * Sell products which can be categorized.
 * Create customer accounts.
 * Allow customer to create reviews for products.
 * Provide a basic content management system for static pages.

### Step Two : Determine your tables

Once we figure out our purpose and what kinds of task we need to do, we can divide our information up into tables. You should follow a naming convention in your table structure.

Going by the defining process, we know we need the following tables

 * product_categories
 * products
 * customers
 * reviews
 * page_categories
 * pages

### Step Three : Determine your fields

Your tables need fields. First decide which information you want to save, then decide which table it should be placed in. As an example, our "**products**" table will have an **ID**, **name**, **description**, **price**, **category** and an **image**. We can also add more along the way.

This step also includes "choosing data types".

### Step Four : Determine your relationships

We need to look at our table data and figure out which tables can relate to another. A good example is in our "**revies**" table, we have a "**customer**" field. This field will relate to the "**id**" field in the "**customers**" table.

### Step Five : Create a diagram

Now that you have your data structure figured out, tranfer it from a messy notepad file to a neat diagram or some other physical representation of the schema using software like **MySQL Workbench** or **Dia Diagram Editor**

### Step Six : Refine if needed

### Full Example Schema
```
PRODUCTS
-id (INT(11), auto_increment, primary_key)
-name (VARCHAR(100))
-description (TEXT)
-price (VARCHAR(20))
-category (INT(11), foreign_key to products_categories id)
-image (VARCHAR(100))

PRODUCTS_CATEGORIES
-id (INT(11), auto_increment, primary_key)
-name (VARCHAR(100))
-description (TEXT)
-image (VARCHAR(100))

CUSTOMERS
-id (INT(11), auto_increment, primary_key)
-first_name (VARCHAR(100))
-last_name (VARCHAR(100))
-email (VARCHAR(100))
-password (VARCHAR(100))
-avatar (VARCHAR(100))
-join_date (TIMESTAMP, DEFAULT - current_date)

CUSTOMER_ADDRESSES
-id (INT(11), auto_increment, primary_key)
-customer (INT(11), foreign_key to customers id)
-address (VARCHAR(100))
-address2 (VARCHAR(100))
-city (VARCHAR(100))
-state (VARCHAR(100))
-zipcode (VARCHAR(100))

REVIEWS
-id (INT(11), auto_increment, primary_key)
-title (VARCHAR(100))
-body (TEXT)
-rating INT(2)
-customer (INT(11), foreign_key to customers id)
-product (INT(11), foreign_key to products id)
-review_date (TIMESTAMP, DEFAULT - current_date)

PAGES
-id (INT(11), auto_increment, primary_key)
-title(VARCHAR(100))
-body (TEXT)
-category (INT(11), foreign_key to products id)
-create_date (TIMESTAMP, DEFAULT - current_date)

PAGE_CATEGORIES
-id (INT(11), auto_increment, primary_key)
-name (VARCHAR(100))
-description (TEXT)
-image (VARCHAR(100))
```

## Used SQLFiddle

 * Step 1 : Choose database and build your schema
Example:

```SQL
create table employee 
(
  emp_id BIGINT NOT NULL, 
  emp_name VARCHAR(50) NOT NULL, 
  dept_id BIGINT NULL
);

insert into employee values (1, 'John', 1);
insert into employee values (2, 'Danna', 2);
insert into employee values (3, 'Bob', 3);
insert into employee values (4, 'Peter', 1);
insert into employee values (5, 'Lynda', 2);
insert into employee values (6, 'Steve', 2);
insert into employee values (7, 'Steph', 2);
insert into employee values (8, 'Nick', null);

create table department (dept_id bigint null, dept_name varchar(50) not null);

insert into department values (1, 'IT');
insert into department values (2, 'Finance');
insert into department values (3, 'Operations');
insert into department values (null, 'No Department');
```

 * Step 2 : Enter SQL script and run

```SQL
SELECT a.emp_name, b.dept_name FROM employee a INNER JOIN department b ON a.dept_id = b.dept_id;
```

 * Step 3 : Output example:

```
| emp_name |  dept_name |
|----------|------------|
|     John |         IT |
|    Danna |    Finance |
|      Bob | Operations |
|    Peter |         IT |
|    Lynda |    Finance |
|    Steve |    Finance |
|    Steph |    Finance |
```

## MYSQL on Ubuntu

### Install

```
sudo apt-get update
sudo apt-get install mysql-server
```

Then add password, after finish install we can access to our local mysql sever cli by:

```
mysql -u root -p
```
### Show Database

```sql
SHOW DATABASES;
```

### Create Database

```
CREATE DATABASE <name>;
```

Example:

```sql
CREATE DATABASE my_app_db;
```

Then we can verify if the database it was create by using show database command.

### Delete Database

```
DROP DATABASE <name>;
```

Example:

```sql
CREATE DATABASE testing_db;
DROP DATABASE testing_db;
```

Then we can verify ours database.

### How use Database

Tell mysql which database we want to be working.

```
USE <database name>;
```

Example:

```sql
USE my_app_db;
```

## SQL

### Create Table

```sql
CREATE TABLE tablename
(
  column_name data_type,
  column_name data_type
);
```

Example:

```sql
CREATE TABLE person
(
  name VARCHAR(100),
  age INT
);
```

### Show Table

```sql
SHOW TABLES;
```

Result:

```
| TABLE_NAME |
|------------|
|     person |
```

### Show Columns

```
SHOW COLUMNS FROM <tablename>;
```

or

```
DESC <tablename>
```

Example:

```sql
SHOW COLUMNS FROM person;
```

or

```sql
DESC person;
```

Result:

```
| COLUMN_NAME |  COLUMN_TYPE | IS_NULLABLE | COLUMN_KEY | COLUMN_DEFAULT | EXTRA |
|-------------|--------------|-------------|------------|----------------|-------|
|        name | varchar(100) |         YES |            |         (null) |       |
|         age |      int(11) |         YES |            |         (null) |       |
```

### Delete Table

```
DROP TABLE <tablename>;
```

### Insert Data to Table

Adding data to your tables. Important to know, the order of statment matters.

```
INSERT INTO <tablename> (column_name, column_name)
VALUES ('column_value', 'column_value');
```

Example: Creating Schema

```sql
CREATE TABLE person
(
  name VARCHAR(100),
  age INT
);

INSERT INTO person (name, age)
VALUES ('Steve Palm', 18);

INSERT INTO person (name, age)
VALUES ('Victoria Holm', 20);
```


Example: View

```sql
SELECT * FROM person;
```

Result:

```
|          name | age |
|---------------|-----|
|    Steve Palm |  18 |
| Victoria Holm |  20 |
```

### Multiple Insert Data to Table

```
INSERT INTO <tablename> (column_name, column_name)
VALUES 
('column_value', 'column_value'),
('column_value', 'column_value');
```

Example: Creating Schema

```sql
CREATE TABLE person
(
  name VARCHAR(100),
  age INT
);

INSERT INTO person (name, age)
VALUES 
('Steve Palm', 18), 
('Victoria Holm', 20);
```


Example: View

```sql
SELECT * FROM person;
```

Result:

```
|          name | age |
|---------------|-----|
|    Steve Palm |  18 |
| Victoria Holm |  20 |
```

### NULL on SQL

On MySQL Null means the value is unknown or the value is not be specify, this not mean 0. To used null in columns we need to permit to used, on the definition of creation of the table columns. To require avoid using null, we need to specify on the creation of the table. Example:

```sql
CREATE TABLE person
(
  name VARCHAR(100) NOT NULL,
  age INT NOT NULL
);
```

### Default Value

To set default values.

```sql
CREATE TABLE person
(
  name VARCHAR(100) DEFAULT 'unnamed',
  age INT DEFAULT 18
);
```

### Primary Key

Primary keys serve as unique identifiers for the records in a table, while foreign keys are used to link related tables together. When designing a set of database tables, it is important to specify which fields will be used for primary and foreign keys to clarify both in-table structure and inter-table relationships.

You can specify a primary key for the table with the PRIMARY KEY constraint. In a well-designed database schema, a primary key serves as an unchanging, unique identifier for each record. If a key is declared as primary, this usually implies that the values in it will rarely be modified.

The PRIMARY KEY constraint can best be thought of as a combination of the NOT NULL and UNIQUE constraints because it requires values in the specified field to be neither NULL nor repeated in any other row.

Example: Creating Schema

```sql
CREATE TABLE person
(
  person_id INT NOT NULL,
  name VARCHAR(100),
  age INT,
  PRIMARY KEY(person_id)
);

INSERT INTO person (person_id, name, age)
VALUES 
(1, 'Steve Palm', 18), 
(2, 'Victoria Holm', 20);
```


Example: View

```sql
SELECT * FROM person;
```

Result:

```
| person_id |          name | age |
|-----------|---------------|-----|
|         1 |    Steve Palm |  18 |
|         2 | Victoria Holm |  20 |
```

## SQL CRUD (Create Read Update Delete)

```sql
CREATE TABLE person
(
  person_id INT NOT NULL AUTO_INCREMENT,
  name VARCHAR(100),
  last VARCHAR(100),
  age INT,
  PRIMARY KEY(person_id)
);

INSERT INTO person (name, last, age)
VALUES 
('Steve', 'Palm', 18), 
('Victoria', 'Holm', 20),
('Michael', 'Sheyl', 14), 
('Bruce', 'Londor', 22),
('Joe', 'Ray', 17), 
('Matt', 'Delvin', 20);
```

### Read (SELECT Clause)

Select expression mean, what columns do you want?

Example 1:

```sql
SELECT  
*       /* <-- Give me all columns */
FROM    
person; /* <-- Columns */ 
```

Result:

```
+-----------+----------+--------+------+
| person_id | name     | last   | age  |
+-----------+----------+--------+------+
|         1 | Steve    | Palm   |   18 |
|         2 | Victoria | Holm   |   20 |
|         3 | Michael  | Sheyl  |   14 |
|         4 | Bruce    | Londor |   22 |
|         5 | Joe      | Ray    |   17 |
|         6 | Matt     | Delvin |   20 |
+-----------+----------+--------+------+
```

Example 2:

```sql
SELECT name FROM person;
```

Result:

```
+----------+
| name     |
+----------+
| Steve    |
| Victoria |
| Michael  |
| Bruce    |
| Joe      |
| Matt     |
+----------+
```

Example 3:

```sql
SELECT name, age FROM person;
```

Result:

```
+----------+------+
| name     | age  |
+----------+------+
| Steve    |   18 |
| Victoria |   20 |
| Michael  |   14 |
| Bruce    |   22 |
| Joe      |   17 |
| Matt     |   20 |
+----------+------+
```

### WHERE Clause

We use WHERE all the time to update or delete values.

Example 1:

```sql
SELECT * FROM person WHERE age=20;
```

Result:

```
+-----------+----------+--------+------+
| person_id | name     | last   | age  |
+-----------+----------+--------+------+
|         2 | Victoria | Holm   |   20 |
|         6 | Matt     | Delvin |   20 |
+-----------+----------+--------+------+
```

Example 2:

```sql
SELECT * FROM person WHERE name='Bruce';
```

Result:

```
+-----------+-------+--------+------+
| person_id | name  | last   | age  |
+-----------+-------+--------+------+
|         4 | Bruce | Londor |   22 |
+-----------+-------+--------+------+
```

### Aliases

We can specify how our data should be display back yo us. Useful on large table with JOIN clause.

Example 1:

```sql
SELECT person_id AS id, name FROM person;
```

Result:

```
+----+----------+
| id | name     |
+----+----------+
|  1 | Steve    |
|  2 | Victoria |
|  3 | Michael  |
|  4 | Bruce    |
|  5 | Joe      |
|  6 | Matt     |
+----+----------+
```

Example 2:

```sql
SELECT person_id AS "id of person", name FROM person;
```

Result:

```
+--------------+----------+
| id of person | name     |
+--------------+----------+
|            1 | Steve    |
|            2 | Victoria |
|            3 | Michael  |
|            4 | Bruce    |
|            5 | Joe      |
|            6 | Matt     |
+--------------+----------+
```

### Update

Good practice is try to SELECT value before you UPDATE.

Example 1:

```sql
UPDATE person
SET name='Peter'
WHERE person_id=3;
```

View:

```sql
SELECT * FROM person;
```

Result:

```
+-----------+----------+--------+------+
| person_id | name     | last   | age  |
+-----------+----------+--------+------+
|         1 | Steve    | Palm   |   18 |
|         2 | Victoria | Holm   |   20 |
|         3 | Peter    | Sheyl  |   14 |
|         4 | Bruce    | Londor |   22 |
|         5 | Joe      | Ray    |   17 |
|         6 | Matt     | Delvin |   20 |
+-----------+----------+--------+------+
```

Example 2:

```sql
UPDATE person
SET name='Peter'
WHERE person_id=3;
```

View:

```sql
SELECT * FROM person;
```

Result:

```
+-----------+----------+--------+------+
| person_id | name     | last   | age  |
+-----------+----------+--------+------+
|         1 | Steve    | Palm   |   14 |
|         2 | Victoria | Holm   |   20 |
|         3 | Peter    | Sheyl  |   14 |
|         4 | Bruce    | Londor |   22 |
|         5 | Joe      | Ray    |   17 |
|         6 | Matt     | Delvin |   20 |
+-----------+----------+--------+------+

```

### Delete

```sql
DELETE FROM person WHERE name='Peter';
```

View:

```sql
SELECT * FROM person;
```

Result:

```
+-----------+----------+--------+------+
| person_id | name     | last   | age  |
+-----------+----------+--------+------+
|         1 | Steve    | Palm   |   14 |
|         2 | Victoria | Holm   |   20 |
|         4 | Bruce    | Londor |   22 |
|         5 | Joe      | Ray    |   17 |
|         6 | Matt     | Delvin |   20 |
+-----------+----------+--------+------+
```
