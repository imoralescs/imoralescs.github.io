
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

## Used Cloud9

 * Step 1 : Create you workspace, add name, allow to be public and select html5 template (Is a empty workspace).
 * Step 2 : On the workspace, shell type `mysql-ctl start` to install mysql on cloud9 project.
 * Step 3 : Then on the same shell type `mysql-ctl cli` to access to mysql command line.
 * Step 4 : For exit of mysql cli `exit;` or `quit;` or `\q;`
 * Step 5 : To Stop MySQL server `mysql-ctl stop`

Note: `mysql-ctl start` and `mysql-ctl cli` are command from cloud9 only.

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

## SQL Files

Is best practice and very useful save sql statement on a single file. Let elaborate a example:

 1- Create a database `CREATE DATABASE my_app_db;`
 2- Let used the database `USE my_app_db;`
 3- Create the file **book_data.sql** on root directory and add the following code:
 
```sql
CREATE TABLE books
(
 book_id INT NOT NULL AUTO_INCREMENT,
 title VARCHAR(100),
 author_fname VARCHAR(100),
 author_lname VARCHAR(100),
 released_year INT,
 stock_quantity INT,
 pages INT,
 PRIMARY KEY(book_id)
);

INSERT INTO books (title, author_fname, author_lname, released_year, stock_quantity, pages)
VALUES
('The Namesake', 'Jhumpa', 'Lahiri', 2003, 32, 291),
('Norse Mythology', 'Neil', 'Gainman', 2016, 43, 304),
('American Gods', 'Neil', 'Gainman', 2001, 12, 465),
('Interpreter of Maladies', 'Jhumpa', 'Lahiri', 1996, 97, 198),
('A Hologram for the King: A Novel', 'Dave', 'Eggers', 2012, 154, 352),
('The Circle', 'Dave', 'Eggers', 2013, 26, 504),
('The Amazing Adventures of Kavalier & Clay', 'Michael', 'Chabon', 2000, 68, 634),
('Just Kids', 'Patti', 'Smith', 2010, 55, 304),
('A Heartbreaking Work of Staggering Genius', 'Dave', 'Eggers', 2001, 104, 437),
('Coraline', 'Neil', 'Gainman', 2003, 100, 208),
('What We Talk About When We Talk About Love: Stories', 'Raymond', 'Carver', 1981, 23, 437),
("Where I'm Calling From: Selected Stories", 'Raymond', 'Carver', 1989, 12, 526),
('White Noise', 'Don', 'DeLillo', 1985, 49, 320),
('Cannery Row', 'John', 'Steinbeck', 1945, 95, 181),
('Oblivion: Stories', 'David', 'Foster Wallace', 2004, 172, 329),
('Consider the Lobster', 'David', 'Foster Wallace', 2005, 92, 343);
```

 4- To load the sql data `source path`, `source book_data.sql`
 5- To verify table and data `SHOW TABLES;` and `SELECT * FROM books;`

## SQL String Functions

### Concat (CONCAT)

Is ugly to used this to combine data.

Example 1:

```sql
SELECT author_fname, author_lname FROM books;
```

Result:

```
+--------------+----------------+
| author_fname | author_lname   |
+--------------+----------------+
| Jhumpa       | Lahiri         |
| Neil         | Gainman        |
| Neil         | Gainman        |
| Jhumpa       | Lahiri         |
| Dave         | Eggers         |
| Dave         | Eggers         |
| Michael      | Chabon         |
| Patti        | Smith          |
| Dave         | Eggers         |
| Neil         | Gainman        |
| Raymond      | Carver         |
| Raymond      | Carver         |
| Don          | DeLillo        |
| John         | Steinbeck      |
| David        | Foster Wallace |
| David        | Foster Wallace |
+--------------+----------------+
```

Instead we can used `CONCAT` function.

```sql
SELECT
 CONCAT(author_fname, ' ', author_lname)
FROM books;
```

Result:

```
+-----------------------------------------+
| CONCAT(author_fname, ' ', author_lname) |
+-----------------------------------------+
| Jhumpa Lahiri                           |
| Neil Gainman                            |
| Neil Gainman                            |
| Jhumpa Lahiri                           |
| Dave Eggers                             |
| Dave Eggers                             |
| Michael Chabon                          |
| Patti Smith                             |
| Dave Eggers                             |
| Neil Gainman                            |
| Raymond Carver                          |
| Raymond Carver                          |
| Don DeLillo                             |
| John Steinbeck                          |
| David Foster Wallace                    |
| David Foster Wallace                    |
+-----------------------------------------+
```

Example 2:

```sql
SELECT author_fname AS first, author_lname AS last, 
 CONCAT(author_fname, ' ', author_lname) AS full 
FROM books;
```

Result:

```
+---------+----------------+----------------------+
| first   | last           | full                 |
+---------+----------------+----------------------+
| Jhumpa  | Lahiri         | Jhumpa Lahiri        |
| Neil    | Gainman        | Neil Gainman         |
| Neil    | Gainman        | Neil Gainman         |
| Jhumpa  | Lahiri         | Jhumpa Lahiri        |
| Dave    | Eggers         | Dave Eggers          |
| Dave    | Eggers         | Dave Eggers          |
| Michael | Chabon         | Michael Chabon       |
| Patti   | Smith          | Patti Smith          |
| Dave    | Eggers         | Dave Eggers          |
| Neil    | Gainman        | Neil Gainman         |
| Raymond | Carver         | Raymond Carver       |
| Raymond | Carver         | Raymond Carver       |
| Don     | DeLillo        | Don DeLillo          |
| John    | Steinbeck      | John Steinbeck       |
| David   | Foster Wallace | David Foster Wallace |
| David   | Foster Wallace | David Foster Wallace |
+---------+----------------+----------------------+
```

### Concat with separator

Example 1:

```sql
SELECT CONCAT_WS(' - ', title, author_fname, author_lname) FROM books;
```

Result:

```
+------------------------------------------------------------------------+
| CONCAT_WS(' - ', title, author_fname, author_lname)                    |
+------------------------------------------------------------------------+
| The Namesake - Jhumpa - Lahiri                                         |
| Norse Mythology - Neil - Gainman                                       |
| American Gods - Neil - Gainman                                         |
| Interpreter of Maladies - Jhumpa - Lahiri                              |
| A Hologram for the King: A Novel - Dave - Eggers                       |
| The Circle - Dave - Eggers                                             |
| The Amazing Adventures of Kavalier & Clay - Michael - Chabon           |
| Just Kids - Patti - Smith                                              |
| A Heartbreaking Work of Staggering Genius - Dave - Eggers              |
| Coraline - Neil - Gainman                                              |
| What We Talk About When We Talk About Love: Stories - Raymond - Carver |
| Where I'm Calling From: Selected Stories - Raymond - Carver            |
| White Noise - Don - DeLillo                                            |
| Cannery Row - John - Steinbeck                                         |
| Oblivion: Stories - David - Foster Wallace                             |
| Consider the Lobster - David - Foster Wallace                          |
+------------------------------------------------------------------------+
```

### Work with parts of String (SUBSTRING)

Example 1:

```sql
SELECT 
 SUBSTRING(title, 1, 10) AS 'short title'  
FROM books;
```

Result:

```
+-------------+
| short title |
+-------------+
| The Namesa  |
| Norse Myth  |
| American G  |
| Interprete  |
| A Hologram  |
| The Circle  |
| The Amazin  |
| Just Kids   |
| A Heartbre  |
| Coraline    |
| What We Ta  |
| Where I'm   |
| White Nois  |
| Cannery Ro  |
| Oblivion:   |
| Consider t  |
+-------------+
```

Example 2:

```sql
SELECT 
 CONCAT(SUBSTRING(title, 1, 10), '...') 
 AS 'short title' 
FROM books;  
```

Result:

```
+---------------+
| short title   |
+---------------+
| The Namesa... |
| Norse Myth... |
| American G... |
| Interprete... |
| A Hologram... |
| The Circle... |
| The Amazin... |
| Just Kids...  |
| A Heartbre... |
| Coraline...   |
| What We Ta... |
| Where I'm ... |
| White Nois... |
| Cannery Ro... |
| Oblivion: ... |
| Consider t... |
+---------------+
```

### Replace parts of strings (REPLACE)

Example 1:

```sql
SELECT 
 REPLACE (title, 'e', '3') 
FROM books;
```

Result:

```
+-----------------------------------------------------+
| REPLACE (title, 'e', '3')                           |
+-----------------------------------------------------+
| Th3 Nam3sak3                                        |
| Nors3 Mythology                                     |
| Am3rican Gods                                       |
| Int3rpr3t3r of Maladi3s                             |
| A Hologram for th3 King: A Nov3l                    |
| Th3 Circl3                                          |
| Th3 Amazing Adv3ntur3s of Kavali3r & Clay           |
| Just Kids                                           |
| A H3artbr3aking Work of Stagg3ring G3nius           |
| Coralin3                                            |
| What W3 Talk About Wh3n W3 Talk About Lov3: Stori3s |
| Wh3r3 I'm Calling From: S3l3ct3d Stori3s            |
| Whit3 Nois3                                         |
| Cann3ry Row                                         |
| Oblivion: Stori3s                                   |
| Consid3r th3 Lobst3r                                |
+-----------------------------------------------------+
```

Example 2:

```sql
SELECT 
 SUBSTRING(
  REPLACE(title, 'e', '3'), 1, 10
 ) 
FROM books;
```

Result:

```
+--------------------------------------------+
| SUBSTRING(REPLACE(title, 'e', '3'), 1, 10) |
+--------------------------------------------+
| Th3 Nam3sa                                 |
| Nors3 Myth                                 |
| Am3rican G                                 |
| Int3rpr3t3                                 |
| A Hologram                                 |
| Th3 Circl3                                 |
| Th3 Amazin                                 |
| Just Kids                                  |
| A H3artbr3                                 |
| Coralin3                                   |
| What W3 Ta                                 |
| Wh3r3 I'm                                  |
| Whit3 Nois                                 |
| Cann3ry Ro                                 |
| Oblivion:                                  |
| Consid3r t                                 |
+--------------------------------------------+
```

### Reverse (REVERSE)

Example 1:

```sql
SELECT 
 CONCAT(
  author_fname, 
  REVERSE(author_fname)
 ) 
FROM books;
```

Result:

```
+---------------------------------------------+
| CONCAT(author_fname, REVERSE(author_fname)) |
+---------------------------------------------+
| JhumpaapmuhJ                                |
| NeillieN                                    |
| NeillieN                                    |
| JhumpaapmuhJ                                |
| DaveevaD                                    |
| DaveevaD                                    |
| MichaelleahciM                              |
| PattiittaP                                  |
| DaveevaD                                    |
| NeillieN                                    |
| RaymonddnomyaR                              |
| RaymonddnomyaR                              |
| DonnoD                                      |
| JohnnhoJ                                    |
| DaviddivaD                                  |
| DaviddivaD                                  |
+---------------------------------------------+
```

### Counts characters in String (CHAR_LENGTH)

Example 1:

```sql
SELECT 
 author_lname, 
 CHAR_LENGTH(author_lname) AS 'length' 
FROM books;
```

Result:

```
+----------------+--------+
| author_lname   | length |
+----------------+--------+
| Lahiri         |      6 |
| Gainman        |      7 |
| Gainman        |      7 |
| Lahiri         |      6 |
| Eggers         |      6 |
| Eggers         |      6 |
| Chabon         |      6 |
| Smith          |      5 |
| Eggers         |      6 |
| Gainman        |      7 |
| Carver         |      6 |
| Carver         |      6 |
| DeLillo        |      7 |
| Steinbeck      |      9 |
| Foster Wallace |     14 |
| Foster Wallace |     14 |
+----------------+--------+
```

Example 2:

```sql
SELECT 
 CONCAT(
  author_lname, 
  ' is ', 
  CHAR_LENGTH(author_lname), 
  ' characters long'
 ) AS 'character'  
FROM books;       
```

Result:

```
+--------------------------------------+
| character                            |
+--------------------------------------+
| Lahiri is 6 characters long          |
| Gainman is 7 characters long         |
| Gainman is 7 characters long         |
| Lahiri is 6 characters long          |
| Eggers is 6 characters long          |
| Eggers is 6 characters long          |
| Chabon is 6 characters long          |
| Smith is 5 characters long           |
| Eggers is 6 characters long          |
| Gainman is 7 characters long         |
| Carver is 6 characters long          |
| Carver is 6 characters long          |
| DeLillo is 7 characters long         |
| Steinbeck is 9 characters long       |
| Foster Wallace is 14 characters long |
| Foster Wallace is 14 characters long |
+--------------------------------------+
```

### Change a string case (UPPER() and LOWER())

Example 1:

```sql
SELECT 
 UPPER(title) 
FROM books;
```

Result:

```
+-----------------------------------------------------+
| UPPER(title)                                        |
+-----------------------------------------------------+
| THE NAMESAKE                                        |
| NORSE MYTHOLOGY                                     |
| AMERICAN GODS                                       |
| INTERPRETER OF MALADIES                             |
| A HOLOGRAM FOR THE KING: A NOVEL                    |
| THE CIRCLE                                          |
| THE AMAZING ADVENTURES OF KAVALIER & CLAY           |
| JUST KIDS                                           |
| A HEARTBREAKING WORK OF STAGGERING GENIUS           |
| CORALINE                                            |
| WHAT WE TALK ABOUT WHEN WE TALK ABOUT LOVE: STORIES |
| WHERE I'M CALLING FROM: SELECTED STORIES            |
| WHITE NOISE                                         |
| CANNERY ROW                                         |
| OBLIVION: STORIES                                   |
| CONSIDER THE LOBSTER                                |
+-----------------------------------------------------+
```

Example 2:

```sql
SELECT 
 LOWER(title) 
FROM books;
```

Result:

```
+-----------------------------------------------------+
| LOWER(title)                                        |
+-----------------------------------------------------+
| the namesake                                        |
| norse mythology                                     |
| american gods                                       |
| interpreter of maladies                             |
| a hologram for the king: a novel                    |
| the circle                                          |
| the amazing adventures of kavalier & clay           |
| just kids                                           |
| a heartbreaking work of staggering genius           |
| coraline                                            |
| what we talk about when we talk about love: stories |
| where i'm calling from: selected stories            |
| white noise                                         |
| cannery row                                         |
| oblivion: stories                                   |
| consider the lobster                                |
+-----------------------------------------------------+
```

## SQL Refining our selections

Add the following sql code:

```sql
INSERT 
 INTO books (title, author_fname, author_lname, released_year, stock_quantity, pages) 
 VALUES 
 ('10% Happier', 'Dan', 'Harris', 2014, 29, 256), 
 ('fake_book', 'Freida', 'Harris', 2001, 287, 428), 
 ('Lincoln In The Bardo', 'George', 'Saunders', 2017, 1000, 367);
```
### DISTINCT 

Example 1:

```sql
SELECT 
 DISTINCT author_lname 
FROM books;
```

Result:

```
+----------------+
| author_lname   |
+----------------+
| Lahiri         |
| Gainman        |
| Eggers         |
| Chabon         |
| Smith          |
| Carver         |
| DeLillo        |
| Steinbeck      |
| Foster Wallace |
| Harris         |
| Saunders       |
+----------------+
```

Example 2:

```sql
SELECT 
 DISTINCT released_year 
FROM books; 
```

Result:

```
+---------------+
| released_year |
+---------------+
|          2003 |
|          2016 |
|          2001 |
|          1996 |
|          2012 |
|          2013 |
|          2000 |
|          2010 |
|          1981 |
|          1989 |
|          1985 |
|          1945 |
|          2004 |
|          2005 |
|          2014 |
|          2017 |
+---------------+
```

### Sorting our results (ORDER BY)

Example 1:

```sql
SELECT author_lname 
FROM books 
ORDER BY author_lname;
```

Result:

```
+----------------+
| author_lname   |
+----------------+
| Carver         |
| Carver         |
| Chabon         |
| DeLillo        |
| Eggers         |
| Eggers         |
| Eggers         |
| Foster Wallace |
| Foster Wallace |
| Gainman        |
| Gainman        |
| Gainman        |
| Harris         |
| Harris         |
| Lahiri         |
| Lahiri         |
| Saunders       |
| Smith          |
| Steinbeck      |
+----------------+
```

Example 2:

```sql
SELECT released_year 
FROM books 
ORDER BY released_year;
```

Result:

```
+---------------+
| released_year |
+---------------+
|          1945 |
|          1981 |
|          1985 |
|          1989 |
|          1996 |
|          2000 |
|          2001 |
|          2001 |
|          2001 |
|          2003 |
|          2003 |
|          2004 |
|          2005 |
|          2010 |
|          2012 |
|          2013 |
|          2014 |
|          2016 |
|          2017 |
+---------------+
```

### LIMIT (LIMIT)

Example 1:

```sql
SELECT title 
FROM books 
LIMIT 3;
```

Result:

```
+-----------------+
| title           |
+-----------------+
| The Namesake    |
| Norse Mythology |
| American Gods   |
+-----------------+
```

### Better searching (LIKE)

Example 1:

```sql
SELECT title, author_fname 
FROM books 
WHERE author_fname 
LIKE '%da%';
```

Result:

```
+-------------------------------------------+--------------+
| title                                     | author_fname |
+-------------------------------------------+--------------+
| A Hologram for the King: A Novel          | Dave         |
| The Circle                                | Dave         |
| A Heartbreaking Work of Staggering Genius | Dave         |
| Oblivion: Stories                         | David        |
| Consider the Lobster                      | David        |
| 10% Happier                               | Dan          |
| fake_book                                 | Freida       |
+-------------------------------------------+--------------+
```

Example 2: 

```sql
SELECT title 
FROM books 
WHERE title 
LIKE '%the%';
```

Result:

```
+-------------------------------------------+
| title                                     |
+-------------------------------------------+
| The Namesake                              |
| A Hologram for the King: A Novel          |
| The Circle                                |
| The Amazing Adventures of Kavalier & Clay |
| Consider the Lobster                      |
| Lincoln In The Bardo                      |
+-------------------------------------------+
```

## SQL Aggregate Function

Is the way to grouping data. Group data base of another data. And them do operation on those groups.

### COUNT

Example 1:

How many books are in the database?

```sql
SELECT COUNT(*) FROM books;
```

Result:

```
+----------+
| COUNT(*) |
+----------+
|       19 |
+----------+
```

And how many authors?

```sql
SELECT COUNT(author_fname) FROM books;
```

Result:

```
+---------------------+
| COUNT(author_fname) |
+---------------------+
|                  19 |
+---------------------+
```

If we verify those author will see, we have some duplicate, so we want to know unique.


```sql
SELECT COUNT(DISTINCT author_fname) FROM books;
```

Result:

```
+------------------------------+
| COUNT(DISTINCT author_fname) |
+------------------------------+
|                           12 |
+------------------------------+
```

```sql
SELECT COUNT(DISTINCT author_lname, author_fname) FROM books;
```

Result:

```
+--------------------------------------------+
| COUNT(DISTINCT author_lname, author_fname) |
+--------------------------------------------+
|                                         12 |
+--------------------------------------------+
```

Example 2:

How many titles contain "the"?

```sql
SELECT COUNT(*) FROM books WHERE title LIKE '%the%'; 
```

Result:

```
+----------+
| COUNT(*) |
+----------+
|        6 |
+----------+
```

### GROUP BY

Summarize or aggregates identical data into single rows.

Example 1:

```sql
SELECT author_lname, 
 COUNT(*) 
FROM books 
GROUP BY author_lname;
```

Result:

```
+----------------+----------+
| author_lname   | COUNT(*) |
+----------------+----------+
| Carver         |        2 |
| Chabon         |        1 |
| DeLillo        |        1 |
| Eggers         |        3 |
| Foster Wallace |        2 |
| Gainman        |        3 |
| Harris         |        2 |
| Lahiri         |        2 |
| Saunders       |        1 |
| Smith          |        1 |
| Steinbeck      |        1 |
+----------------+----------+
```

Example 2:

```sql
SELECT released_year, 
 COUNT(*) 
FROM books 
GROUP BY released_year;
```

Result:

```
+---------------+----------+
| released_year | COUNT(*) |
+---------------+----------+
|          1945 |        1 |
|          1981 |        1 |
|          1985 |        1 |
|          1989 |        1 |
|          1996 |        1 |
|          2000 |        1 |
|          2001 |        3 |
|          2003 |        2 |
|          2004 |        1 |
|          2005 |        1 |
|          2010 |        1 |
|          2012 |        1 |
|          2013 |        1 |
|          2014 |        1 |
|          2016 |        1 |
|          2017 |        1 |
+---------------+----------+
```

### MIN and MAX

Example 1:

```sql
SELECT MIN(released_year) 
FROM books;
```

Result:

```
+--------------------+
| MIN(released_year) |
+--------------------+
|               1945 |
+--------------------+
```

Example 2:

```sql
SELECT MAX(pages), title 
FROM books;
```

Result:

```
+------------+--------------+
| MAX(pages) | title        |
+------------+--------------+
|        634 | The Namesake |
+------------+--------------+
```

### MIN and MAX with GROUP BY

Find the year each author published their first book.

Example 1:

```sql
SELECT author_fname, author_lname, 
 MIN(released_year) 
FROM books 
GROUP BY author_lname, author_fname;
```

Result:

```
+--------------+----------------+--------------------+
| author_fname | author_lname   | MIN(released_year) |
+--------------+----------------+--------------------+
| Raymond      | Carver         |               1981 |
| Michael      | Chabon         |               2000 |
| Don          | DeLillo        |               1985 |
| Dave         | Eggers         |               2001 |
| David        | Foster Wallace |               2004 |
| Neil         | Gainman        |               2001 |
| Dan          | Harris         |               2014 |
| Freida       | Harris         |               2001 |
| Jhumpa       | Lahiri         |               1996 |
| George       | Saunders       |               2017 |
| Patti        | Smith          |               2010 |
| John         | Steinbeck      |               1945 |
+--------------+----------------+--------------------+
```

### SUM

Adds thing together. 

Example 1:

Sum all pages in the entire database.

```sql
SELECT SUM(pages) 
FROM books;
```

Result:

```
+------------+
| SUM(pages) |
+------------+
|       6884 |
+------------+
```

Example 2:

Sum all pages each author has written.

```sql
SELECT author_fname, author_lname, 
 SUM(pages) 
FROM books 
GROUP BY author_lname, author_fname;
```

Result:

```
+--------------+----------------+------------+
| author_fname | author_lname   | SUM(pages) |
+--------------+----------------+------------+
| Raymond      | Carver         |        963 |
| Michael      | Chabon         |        634 |
| Don          | DeLillo        |        320 |
| Dave         | Eggers         |       1293 |
| David        | Foster Wallace |        672 |
| Neil         | Gainman        |        977 |
| Dan          | Harris         |        256 |
| Freida       | Harris         |        428 |
| Jhumpa       | Lahiri         |        489 |
| George       | Saunders       |        367 |
| Patti        | Smith          |        304 |
| John         | Steinbeck      |        181 |
+--------------+----------------+------------+
```

### AVG

Example 1:

Calculate the average stock quantity for books released in the same year.

```sql
SELECT released_year,  
AVG(stock_quantity) 
FROM books 
GROUP BY released_year; 
```

Result:

```
+---------------+---------------------+
| released_year | AVG(stock_quantity) |
+---------------+---------------------+
|          1945 |             95.0000 |
|          1981 |             23.0000 |
|          1985 |             49.0000 |
|          1989 |             12.0000 |
|          1996 |             97.0000 |
|          2000 |             68.0000 |
|          2001 |            134.3333 |
|          2003 |             66.0000 |
|          2004 |            172.0000 |
|          2005 |             92.0000 |
|          2010 |             55.0000 |
|          2012 |            154.0000 |
|          2013 |             26.0000 |
|          2014 |             29.0000 |
|          2016 |             43.0000 |
|          2017 |           1000.0000 |
+---------------+---------------------+
```

## SQL Logical Operators

### Not Equal

Select books that were not released in 2017.

```sql
SELECT title, released_year 
FROM books 
WHERE released_year = 2017; 
```

Result:

```
+----------------------+---------------+
| title                | released_year |
+----------------------+---------------+
| Lincoln In The Bardo |          2017 |
+----------------------+---------------+
```

```sql
SELECT title, released_year 
FROM books 
WHERE released_year != 2017; 
```

Result:

```
+-----------------------------------------------------+---------------+
| title                                               | released_year |
+-----------------------------------------------------+---------------+
| The Namesake                                        |          2003 |
| Norse Mythology                                     |          2016 |
| American Gods                                       |          2001 |
| Interpreter of Maladies                             |          1996 |
| A Hologram for the King: A Novel                    |          2012 |
| The Circle                                          |          2013 |
| The Amazing Adventures of Kavalier & Clay           |          2000 |
| Just Kids                                           |          2010 |
| A Heartbreaking Work of Staggering Genius           |          2001 |
| Coraline                                            |          2003 |
| What We Talk About When We Talk About Love: Stories |          1981 |
| Where I'm Calling From: Selected Stories            |          1989 |
| White Noise                                         |          1985 |
| Cannery Row                                         |          1945 |
| Oblivion: Stories                                   |          2004 |
| Consider the Lobster                                |          2005 |
| 10% Happier                                         |          2014 |
| fake_book                                           |          2001 |
+-----------------------------------------------------+---------------+
```

### Not Like

Select books with titles that don't start with 'W'.

```sql
SELECT title 
FROM books 
WHERE title LIKE 'W%';
```

Result:

```
+-----------------------------------------------------+
| title                                               |
+-----------------------------------------------------+
| What We Talk About When We Talk About Love: Stories |
| Where I'm Calling From: Selected Stories            |
| White Noise                                         |
+-----------------------------------------------------+
```

```sql
SELECT title 
FROM books 
WHERE title 
NOT LIKE 'W%';    
```

Result:

```
+-------------------------------------------+
| title                                     |
+-------------------------------------------+
| The Namesake                              |
| Norse Mythology                           |
| American Gods                             |
| Interpreter of Maladies                   |
| A Hologram for the King: A Novel          |
| The Circle                                |
| The Amazing Adventures of Kavalier & Clay |
| Just Kids                                 |
| A Heartbreaking Work of Staggering Genius |
| Coraline                                  |
| Cannery Row                               |
| Oblivion: Stories                         |
| Consider the Lobster                      |
| 10% Happier                               |
| fake_book                                 |
| Lincoln In The Bardo                      |
+-------------------------------------------+
```

### Greater Than or Equal To

Example 1:

Select books released after the year 2000.

```sql
SELECT title, released_year 
FROM books 
WHERE released_year > 2010;
```

Result:

```
+----------------------------------+---------------+
| title                            | released_year |
+----------------------------------+---------------+
| Norse Mythology                  |          2016 |
| A Hologram for the King: A Novel |          2012 |
| The Circle                       |          2013 |
| 10% Happier                      |          2014 |
| Lincoln In The Bardo             |          2017 |
+----------------------------------+---------------+
```

Example 2:

Select books released after the year 2000.

```sql
SELECT title, stock_quantity 
FROM books 
WHERE stock_quantity >= 100;
```

Result:

```
+-------------------------------------------+----------------+
| title                                     | stock_quantity |
+-------------------------------------------+----------------+
| A Hologram for the King: A Novel          |            154 |
| A Heartbreaking Work of Staggering Genius |            104 |
| Coraline                                  |            100 |
| Oblivion: Stories                         |            172 |
| fake_book                                 |            287 |
| Lincoln In The Bardo                      |           1000 |
+-------------------------------------------+----------------+
```

### Less Than or Equal To

Example 1:

```sql
SELECT title, released_year 
FROM books 
WHERE released_year < 2010  
ORDER BY released_year;  
```

Result:

```
+-----------------------------------------------------+---------------+
| title                                               | released_year |
+-----------------------------------------------------+---------------+
| Cannery Row                                         |          1945 |
| What We Talk About When We Talk About Love: Stories |          1981 |
| White Noise                                         |          1985 |
| Where I'm Calling From: Selected Stories            |          1989 |
| Interpreter of Maladies                             |          1996 |
| The Amazing Adventures of Kavalier & Clay           |          2000 |
| fake_book                                           |          2001 |
| A Heartbreaking Work of Staggering Genius           |          2001 |
| American Gods                                       |          2001 |
| Coraline                                            |          2003 |
| The Namesake                                        |          2003 |
| Oblivion: Stories                                   |          2004 |
| Consider the Lobster                                |          2005 |
+-----------------------------------------------------+---------------+
```

Example 2:

```sql
SELECT title, released_year 
FROM books 
WHERE released_year <= 2010  
ORDER BY released_year;
```

Result:

```
| title                                               | released_year |
+-----------------------------------------------------+---------------+
| Cannery Row                                         |          1945 |
| What We Talk About When We Talk About Love: Stories |          1981 |
| White Noise                                         |          1985 |
| Where I'm Calling From: Selected Stories            |          1989 |
| Interpreter of Maladies                             |          1996 |
| The Amazing Adventures of Kavalier & Clay           |          2000 |
| fake_book                                           |          2001 |
| A Heartbreaking Work of Staggering Genius           |          2001 |
| American Gods                                       |          2001 |
| Coraline                                            |          2003 |
| The Namesake                                        |          2003 |
| Oblivion: Stories                                   |          2004 |
| Consider the Lobster                                |          2005 |
| Just Kids                                           |          2010 |
+-----------------------------------------------------+---------------+
```

### Logical AND &&

Example 1:

Select books written by Dave Eggers, published after the year 2010.

Case 1:

```sql
SELECT title, author_lname, released_year 
FROM books 
WHERE author_lname = 'Eggers';
```

Result:

```
+-------------------------------------------+--------------+---------------+
| title                                     | author_lname | released_year |
+-------------------------------------------+--------------+---------------+
| A Hologram for the King: A Novel          | Eggers       |          2012 |
| The Circle                                | Eggers       |          2013 |
| A Heartbreaking Work of Staggering Genius | Eggers       |          2001 |
+-------------------------------------------+--------------+---------------+
```

Case 2:

```sql
SELECT title, author_lname, released_year 
FROM books 
WHERE released_year > 2010;
```

Result:

```
+----------------------------------+--------------+---------------+
| title                            | author_lname | released_year |
+----------------------------------+--------------+---------------+
| Norse Mythology                  | Gainman      |          2016 |
| A Hologram for the King: A Novel | Eggers       |          2012 |
| The Circle                       | Eggers       |          2013 |
| 10% Happier                      | Harris       |          2014 |
| Lincoln In The Bardo             | Saunders     |          2017 |
+----------------------------------+--------------+---------------+
```

Exercise:

```sql
SELECT title, author_lname, released_year 
FROM books 
WHERE author_lname = 'Eggers' AND released_year > 2010;
```

Result:

```
+----------------------------------+--------------+---------------+
| title                            | author_lname | released_year |
+----------------------------------+--------------+---------------+
| A Hologram for the King: A Novel | Eggers       |          2012 |
| The Circle                       | Eggers       |          2013 |
+----------------------------------+--------------+---------------+
```

### Logical OR ||

Example 1:

Select books written by Dave Eggers, published after the year 2010.

Case 1:

```sql
SELECT title, author_lname, released_year 
FROM books 
WHERE author_lname = 'Eggers';
```

Result:

```
+-------------------------------------------+--------------+---------------+
| title                                     | author_lname | released_year |
+-------------------------------------------+--------------+---------------+
| A Hologram for the King: A Novel          | Eggers       |          2012 |
| The Circle                                | Eggers       |          2013 |
| A Heartbreaking Work of Staggering Genius | Eggers       |          2001 |
+-------------------------------------------+--------------+---------------+
```

Case 2:

```sql
SELECT title, author_lname, released_year 
FROM books 
WHERE released_year > 2010;
```

Result:

```
+----------------------------------+--------------+---------------+
| title                            | author_lname | released_year |
+----------------------------------+--------------+---------------+
| Norse Mythology                  | Gainman      |          2016 |
| A Hologram for the King: A Novel | Eggers       |          2012 |
| The Circle                       | Eggers       |          2013 |
| 10% Happier                      | Harris       |          2014 |
| Lincoln In The Bardo             | Saunders     |          2017 |
+----------------------------------+--------------+---------------+
```

Exercise:

```sql
SELECT title, author_lname, released_year 
FROM books 
WHERE author_lname = 'Eggers' || released_year > 2010;
```

Result:

```
+-------------------------------------------+--------------+---------------+
| title                                     | author_lname | released_year |
+-------------------------------------------+--------------+---------------+
| Norse Mythology                           | Gainman      |          2016 |
| A Hologram for the King: A Novel          | Eggers       |          2012 |
| The Circle                                | Eggers       |          2013 |
| A Heartbreaking Work of Staggering Genius | Eggers       |          2001 |
| 10% Happier                               | Harris       |          2014 |
| Lincoln In The Bardo                      | Saunders     |          2017 |
+-------------------------------------------+--------------+---------------+
```

### Between

Example 1:

Select all books published between 2004 and 2015.

Case 1:

```sql
SELECT title, released_year 
FROM books 
WHERE released_year >= 2004 && released_year <= 2015;
```

Result:

```
+----------------------------------+---------------+
| title                            | released_year |
+----------------------------------+---------------+
| A Hologram for the King: A Novel |          2012 |
| The Circle                       |          2013 |
| Just Kids                        |          2010 |
| Oblivion: Stories                |          2004 |
| Consider the Lobster             |          2005 |
| 10% Happier                      |          2014 |
+----------------------------------+---------------+
```

Exercise:

```sql
SELECT title, released_year 
FROM books 
WHERE released_year 
BETWEEN 2004 AND 2015;
```

Result:

```
+----------------------------------+---------------+
| title                            | released_year |
+----------------------------------+---------------+
| A Hologram for the King: A Novel |          2012 |
| The Circle                       |          2013 |
| Just Kids                        |          2010 |
| Oblivion: Stories                |          2004 |
| Consider the Lobster             |          2005 |
| 10% Happier                      |          2014 |
+----------------------------------+---------------+
```

Exercise:

```sql
SELECT title, released_year 
FROM books 
WHERE released_year 
NOT BETWEEN 2004 AND 2015; 
```

Result:

```
+-----------------------------------------------------+---------------+
| title                                               | released_year |
+-----------------------------------------------------+---------------+
| The Namesake                                        |          2003 |
| Norse Mythology                                     |          2016 |
| American Gods                                       |          2001 |
| Interpreter of Maladies                             |          1996 |
| The Amazing Adventures of Kavalier & Clay           |          2000 |
| A Heartbreaking Work of Staggering Genius           |          2001 |
| Coraline                                            |          2003 |
| What We Talk About When We Talk About Love: Stories |          1981 |
| Where I'm Calling From: Selected Stories            |          1989 |
| White Noise                                         |          1985 |
| Cannery Row                                         |          1945 |
| fake_book                                           |          2001 |
| Lincoln In The Bardo                                |          2017 |
+-----------------------------------------------------+---------------+
```

### IN

Example 1:

Select all books written by... Carver or Lahiri or Smith

Case 1:

```sql
SELECT title, author_lname 
FROM books 
WHERE author_lname='Carver' OR author_lname='Lahiri' OR author_lname='Smith';
```

Result:

```
+-----------------------------------------------------+--------------+
| title                                               | author_lname |
+-----------------------------------------------------+--------------+
| The Namesake                                        | Lahiri       |
| Interpreter of Maladies                             | Lahiri       |
| Just Kids                                           | Smith        |
| What We Talk About When We Talk About Love: Stories | Carver       |
| Where I'm Calling From: Selected Stories            | Carver       |
+-----------------------------------------------------+--------------+
```

Exercise:

```sql
SELECT title, author_lname 
FROM books 
WHERE author_lname IN ('Carver', 'Lahiri', 'Smith');
```

Result:

```
+-----------------------------------------------------+--------------+
| title                                               | author_lname |
+-----------------------------------------------------+--------------+
| The Namesake                                        | Lahiri       |
| Interpreter of Maladies                             | Lahiri       |
| Just Kids                                           | Smith        |
| What We Talk About When We Talk About Love: Stories | Carver       |
| Where I'm Calling From: Selected Stories            | Carver       |
+-----------------------------------------------------+--------------+
```

### Case Statements

Example 1:

```sql
SELECT title, released_year, 
CASE 
 WHEN released_year >= 2000 THEN 'Modern Lit' 
 ELSE '20th Century Lit' 
END AS GENRE 
FROM books;
```

Result:

```
+-----------------------------------------------------+---------------+------------------+
| title                                               | released_year | GENRE            |
+-----------------------------------------------------+---------------+------------------+
| The Namesake                                        |          2003 | Modern Lit       |
| Norse Mythology                                     |          2016 | Modern Lit       |
| American Gods                                       |          2001 | Modern Lit       |
| Interpreter of Maladies                             |          1996 | 20th Century Lit |
| A Hologram for the King: A Novel                    |          2012 | Modern Lit       |
| The Circle                                          |          2013 | Modern Lit       |
| The Amazing Adventures of Kavalier & Clay           |          2000 | Modern Lit       |
| Just Kids                                           |          2010 | Modern Lit       |
| A Heartbreaking Work of Staggering Genius           |          2001 | Modern Lit       |
| Coraline                                            |          2003 | Modern Lit       |
| What We Talk About When We Talk About Love: Stories |          1981 | 20th Century Lit |
| Where I'm Calling From: Selected Stories            |          1989 | 20th Century Lit |
| White Noise                                         |          1985 | 20th Century Lit |
| Cannery Row                                         |          1945 | 20th Century Lit |
| Oblivion: Stories                                   |          2004 | Modern Lit       |
| Consider the Lobster                                |          2005 | Modern Lit       |
| 10% Happier                                         |          2014 | Modern Lit       |
| fake_book                                           |          2001 | Modern Lit       |
| Lincoln In The Bardo                                |          2017 | Modern Lit       |
+-----------------------------------------------------+---------------+------------------+
```

Example 2:

```sql
SELECT title, stock_quantity, 
CASE 
 WHEN stock_quantity BETWEEN 0 AND 50 THEN '*' 
 WHEN stock_quantity BETWEEN 51 AND 100 THEN '**' 
 ELSE '***' 
END AS STOCK 
FROM books;
```

Result:

```
+-----------------------------------------------------+----------------+-------+
| title                                               | stock_quantity | STOCK |
+-----------------------------------------------------+----------------+-------+
| The Namesake                                        |             32 | *     |
| Norse Mythology                                     |             43 | *     |
| American Gods                                       |             12 | *     |
| Interpreter of Maladies                             |             97 | **    |
| A Hologram for the King: A Novel                    |            154 | ***   |
| The Circle                                          |             26 | *     |
| The Amazing Adventures of Kavalier & Clay           |             68 | **    |
| Just Kids                                           |             55 | **    |
| A Heartbreaking Work of Staggering Genius           |            104 | ***   |
| Coraline                                            |            100 | **    |
| What We Talk About When We Talk About Love: Stories |             23 | *     |
| Where I'm Calling From: Selected Stories            |             12 | *     |
| White Noise                                         |             49 | *     |
| Cannery Row                                         |             95 | **    |
| Oblivion: Stories                                   |            172 | ***   |
| Consider the Lobster                                |             92 | **    |
| 10% Happier                                         |             29 | *     |
| fake_book                                           |            287 | ***   |
| Lincoln In The Bardo                                |           1000 | ***   |
+-----------------------------------------------------+----------------+-------+
```

## SQL One To Many Relationship

The most common relationship

### Working with Foreign Keys

For this part we are going to used the following data:

```sql
CREATE TABLE customers(
 id INT AUTO_INCREMENT PRIMARY KEY,
 first_name VARCHAR(100),
 last_name VARCHAR(100),
 email VARCHAR(100)
);

CREATE TABLE orders(
 id INT AUTO_INCREMENT PRIMARY KEY,
 order_date DATE,
 amount DECIMAL(8,2),
 customer_id INT,
 FOREIGN KEY(customer_id) REFERENCES customers(id)
);

INSERT INTO customers(first_name, last_name, email)
VALUES
('Boyd', 'George', 'george@gmail.com'),
('George', 'Michael', 'gm@gmail.com'),
('David', 'Bowie', 'david@gmail.com'),
('Blue', 'Steele', 'blue@gmail.com'),
('Bette', 'Davis', 'bette@gmail.com');

INSERT INTO orders(order_date, amount, customer_id)
VALUES
('2016/02/10', 99.99, 1),
('2017/11/11', 35.50, 1),
('2014/12/12', 800.67, 2),
('2015/01/03', 12.50, 2),
('1999/04/11', 450.25, 5);
```

If we try to insert the following data, we cannot because they have conflict with table base on id of customers.

```sql
INSERT INTO orders(order_date, amount, customer_id)
VALUES
('2016/06/06', 33.67, 98);
```

```
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`my_app_db`.`orders`, CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customers` (`id`))
```

### Cross Join

Example 1:

Case 1:

```sql
SELECT id 
FROM customers 
WHERE last_name='George';
```

Result:

```
+-----------------------------------------------------+--------------+
| title                                               | author_lname |
+-----------------------------------------------------+--------------+
| The Namesake                                        | Lahiri       |
| Interpreter of Maladies                             | Lahiri       |
| Just Kids                                           | Smith        |
| What We Talk About When We Talk About Love: Stories | Carver       |
| Where I'm Calling From: Selected Stories            | Carver       |
+-----------------------------------------------------+--------------+
```

Case 2:

```sql
SELECT * 
FROM orders 
WHERE customer_id=1;
```

Result:

```
+----+------------+--------+-------------+
| id | order_date | amount | customer_id |
+----+------------+--------+-------------+
|  1 | 2016-02-10 |  99.99 |           1 |
|  2 | 2017-11-11 |  35.50 |           1 |
+----+------------+--------+-------------+
```

Exercise:

```sql
SELECT * 
FROM orders 
WHERE customer_id = 
 (
  SELECT id 
  FROM customers 
  WHERE last_name='George'
 );
```

Result:

```
+----+------------+--------+-------------+
| id | order_date | amount | customer_id |
+----+------------+--------+-------------+
|  1 | 2016-02-10 |  99.99 |           1 |
|  2 | 2017-11-11 |  35.50 |           1 |
+----+------------+--------+-------------+
```

### Inner Join

Select all records from A and B where the join condition is met.

Example 1: Implicit Inner Join

```sql
SELECT email, order_date, amount 
FROM customers, orders 
WHERE customers.id = orders.customer_id;
```

Result:

```
+------------------+------------+--------+
| email            | order_date | amount |
+------------------+------------+--------+
| george@gmail.com | 2016-02-10 |  99.99 |
| george@gmail.com | 2017-11-11 |  35.50 |
| gm@gmail.com     | 2014-12-12 | 800.67 |
| gm@gmail.com     | 2015-01-03 |  12.50 |
| bette@gmail.com  | 1999-04-11 | 450.25 |
+------------------+------------+--------+
```

Example 2: Ixplicit Inner Join

```sql
SELECT email, order_date, amount 
FROM customers 
JOIN orders 
ON customers.id = orders.customer_id;
```

Result:

```
+------------------+------------+--------+
| email            | order_date | amount |
+------------------+------------+--------+
| george@gmail.com | 2016-02-10 |  99.99 |
| george@gmail.com | 2017-11-11 |  35.50 |
| gm@gmail.com     | 2014-12-12 | 800.67 |
| gm@gmail.com     | 2015-01-03 |  12.50 |
| bette@gmail.com  | 1999-04-11 | 450.25 |
+------------------+------------+--------+
```

### Left Join

Select everything from A, along with any matching records in B.

Example 1: 

```sql
SELECT email, order_date, amount 
FROM customers 
LEFT JOIN orders 
ON customers.id = orders.customer_id;
```

Result:

```
+------------------+------------+--------+
| email            | order_date | amount |
+------------------+------------+--------+
| george@gmail.com | 2016-02-10 |  99.99 |
| george@gmail.com | 2017-11-11 |  35.50 |
| gm@gmail.com     | 2014-12-12 | 800.67 |
| gm@gmail.com     | 2015-01-03 |  12.50 |
| david@gmail.com  | NULL       |   NULL |
| blue@gmail.com   | NULL       |   NULL |
| bette@gmail.com  | 1999-04-11 | 450.25 |
+------------------+------------+--------+
```

Example 2: 

```sql
SELECT email, order_date, amount 
FROM customers 
LEFT JOIN orders 
ON customers.id = orders.customer_id 
GROUP BY customers.id;
```

Result:

```
+------------------+------------+--------+
| email            | order_date | amount |
+------------------+------------+--------+
| george@gmail.com | 2016-02-10 |  99.99 |
| gm@gmail.com     | 2014-12-12 | 800.67 |
| david@gmail.com  | NULL       |   NULL |
| blue@gmail.com   | NULL       |   NULL |
| bette@gmail.com  | 1999-04-11 | 450.25 |
+------------------+------------+--------+
```

Example 3: 

```sql
SELECT email, order_date, IFNULL(SUM(amount), 0) AS total_spent 
FROM customers 
LEFT JOIN orders 
ON customers.id = orders.customer_id 
GROUP BY customers.id;   
```

Result:

```
+------------------+------------+-------------+
| email            | order_date | total_spent |
+------------------+------------+-------------+
| george@gmail.com | 2016-02-10 |      135.49 |
| gm@gmail.com     | 2014-12-12 |      813.17 |
| david@gmail.com  | NULL       |        0.00 |
| blue@gmail.com   | NULL       |        0.00 |
| bette@gmail.com  | 1999-04-11 |      450.25 |
+------------------+------------+-------------+
```

Example 4: 

```sql
SELECT email, order_date, IFNULL(SUM(amount), 0) AS total_spent 
FROM customers 
LEFT JOIN orders 
ON customers.id = orders.customer_id 
GROUP BY customers.id 
ORDER BY total_spent;   
```

Result:

```
+------------------+------------+-------------+
| email            | order_date | total_spent |
+------------------+------------+-------------+
| david@gmail.com  | NULL       |        0.00 |
| blue@gmail.com   | NULL       |        0.00 |
| george@gmail.com | 2016-02-10 |      135.49 |
| bette@gmail.com  | 1999-04-11 |      450.25 |
| gm@gmail.com     | 2014-12-12 |      813.17 |
+------------------+------------+-------------+
```

### Right Join

Select everything from B, along with any matching records in A.

Example 1: 

```sql
SELECT email, order_date, amount FROM customers RIGHT JOIN orders ON customers.id = orders.customer_id;
```

Result:

```
+------------------+------------+--------+
| email            | order_date | amount |
+------------------+------------+--------+
| george@gmail.com | 2016-02-10 |  99.99 |
| george@gmail.com | 2017-11-11 |  35.50 |
| gm@gmail.com     | 2014-12-12 | 800.67 |
| gm@gmail.com     | 2015-01-03 |  12.50 |
| bette@gmail.com  | 1999-04-11 | 450.25 |
+------------------+------------+--------+
```

## SQL Many To Many Relationship

We are imagine we're building a TV show reviewing application.

Reviewers
```
 id | first_name | last_name 
----------------------------
 1  | Brad       | Traversy  
 2  | John       | Doe       
```

Series
```
 id | title  | released_year | genre  
-----------------------------------------
 1  | Archer | 2009          | Animation
 2  | Fargo  | 2014          | Drama
```

Reviews
```
 id | rating | reviewer_id | series_id  
-----------------------------------------
 1  | 8.9    | 1           | 2
 2  | 9.5    | 2           | 2
```

Now let build our tables:

```sql
CREATE TABLE reviewers (
 id INT AUTO_INCREMENT PRIMARY KEY,
 first_name VARCHAR(100),
 last_name VARCHAR(100)
);

CREATE TABLE series (
 id INT AUTO_INCREMENT PRIMARY KEY,
 title VARCHAR(100),
 released_year YEAR(4),
 genre VARCHAR(100)
);

CREATE TABLE reviews (
 id INT AUTO_INCREMENT PRIMARY KEY,
 rating DECIMAL(2,1),
 series_id INT,
 reviewer_id INT,
 FOREIGN KEY(series_id) REFERENCES series(id),
 FOREIGN KEY(reviewer_id) REFERENCES reviewers(id)
);
```

Now let insert data into ours tables:

```
INSERT INTO series (title, released_year, genre)
VALUES
('Archer', 2009, 'Animation'),
('Arrested Development', 2003, 'Comedy'),
("Bob's Burgers", 2011, 'Animation'),
('BoJack Horseman', 2014, 'Animation'),
('Breaking Bad', 2008, 'Drama'),
('Curb Your Enthusiasm', 2000, 'Comedy'),
('Fargo', 2014, 'Drama'),
('Freaks and Geeks', 1999, 'Comedy'),
('General Hospital', 1963, 'Drama'),
('Halt and Catch Fire', 2014, 'Drama'),
('Malcolm In The Middle', 2000, 'Comedy'),
('Pushing Daisies', 2007, 'Comedy'),
('Seinfeld', 1989, 'Comedy'),
('Stranger Things', 2016, 'Drama');

INSERT INTO reviewers (first_name, last_name)
VALUES
('Thomas', 'Stoneman'),
('Wyatt', 'Skaggs'),
('Kimbra', 'Masters'),
('Domingo', 'Cortes'),
('Colt', 'Steele'),
('Pinkie', 'Petit'),
('Marlon', 'Crafford');

INSERT INTO reviews (series_id, reviewer_id, rating)
VALUES
(1,1,8.0),(1,2,7.5),(1,3,8.5),(1,4,7.7),(1,5,8.9),
(2,1,8.1),(2,4,6.0),(2,3,8.0),(2,6,8.4),(2,5,9.9),
(3,1,7.0),(3,6,7.5),(3,4,8.0),(3,3,7.1),(3,5,8.0),
(4,1,7.5),(4,3,7.8),(4,4,8.3),(4,2,7.6),(4,5,8.5),
(5,1,9.5),(5,3,9.0),(5,4,9.1),(5,2,9.3),(5,5,9.9),
(6,2,6.5),(6,3,7.8),(6,4,8.8),(6,2,8.4),(6,5,9.1),
(7,2,9.1),(7,5,9.7),
(8,4,8.5),(8,2,7.8),(8,6,8.8),(8,5,9.3),
(9,2,5.5),(9,3,6.8),(9,4,5.8),(9,6,4.3),(9,5,4.5),
(10,5,9.9),
(13,3,8.0),(13,4,7.2),
(14,2,8.5),(14,3,8.9),(14,4,8.9);
```

Now we can verify with the following SQL.

```sql
SELECT * FROM reviews;
```

### Join Example

Example 1:

```sql
SELECT title, rating 
FROM series 
JOIN reviews 
ON series.id = reviews.series_id;
```

Result:

```
+----------------------+--------+
| title                | rating |
+----------------------+--------+
| Archer               |    8.0 |
| Archer               |    7.5 |
| Archer               |    8.5 |
| Archer               |    7.7 |
| Archer               |    8.9 |
| Arrested Development |    8.1 |
| Arrested Development |    6.0 |
| Arrested Development |    8.0 |
| Arrested Development |    8.4 |
| Arrested Development |    9.9 |
| Bob's Burgers        |    7.0 |
| Bob's Burgers        |    7.5 |
| Bob's Burgers        |    8.0 |
| Bob's Burgers        |    7.1 |
| Bob's Burgers        |    8.0 |
| BoJack Horseman      |    7.5 |
| BoJack Horseman      |    7.8 |
| BoJack Horseman      |    8.3 |
| BoJack Horseman      |    7.6 |
| BoJack Horseman      |    8.5 |
| Breaking Bad         |    9.5 |
| Breaking Bad         |    9.0 |
| Breaking Bad         |    9.1 |
| Breaking Bad         |    9.3 |
| Breaking Bad         |    9.9 |
| Curb Your Enthusiasm |    6.5 |
| Curb Your Enthusiasm |    7.8 |
| Curb Your Enthusiasm |    8.8 |
| Curb Your Enthusiasm |    8.4 |
| Curb Your Enthusiasm |    9.1 |
| Fargo                |    9.1 |
| Fargo                |    9.7 |
| Freaks and Geeks     |    8.5 |
| Freaks and Geeks     |    7.8 |
| Freaks and Geeks     |    8.8 |
| Freaks and Geeks     |    9.3 |
| General Hospital     |    5.5 |
| General Hospital     |    6.8 |
| General Hospital     |    5.8 |
| General Hospital     |    4.3 |
| General Hospital     |    4.5 |
| Halt and Catch Fire  |    9.9 |
| Seinfeld             |    8.0 |
| Seinfeld             |    7.2 |
| Stranger Things      |    8.5 |
| Stranger Things      |    8.9 |
| Stranger Things      |    8.9 |
+----------------------+--------+
```

Example 2:

```sql
SELECT title, AVG(rating) AS avg_rating 
FROM series 
JOIN reviews 
ON series.id = reviews.series_id 
GROUP BY series.id 
ORDER BY avg_rating; 
```

Result:

```
+----------------------+------------+
| title                | avg_rating |
+----------------------+------------+
| General Hospital     |    5.38000 |
| Bob's Burgers        |    7.52000 |
| Seinfeld             |    7.60000 |
| BoJack Horseman      |    7.94000 |
| Arrested Development |    8.08000 |
| Curb Your Enthusiasm |    8.12000 |
| Archer               |    8.12000 |
| Freaks and Geeks     |    8.60000 |
| Stranger Things      |    8.76667 |
| Breaking Bad         |    9.36000 |
| Fargo                |    9.40000 |
| Halt and Catch Fire  |    9.90000 |
+----------------------+------------+
```

Example 3:

```sql
SELECT first_name, last_name, rating 
FROM reviewers 
INNER JOIN reviews 
ON reviewers.id = reviews.reviewer_id; 
```

Result:

```
+------------+-----------+--------+
| first_name | last_name | rating |
+------------+-----------+--------+
| Thomas     | Stoneman  |    8.0 |
| Thomas     | Stoneman  |    8.1 |
| Thomas     | Stoneman  |    7.0 |
| Thomas     | Stoneman  |    7.5 |
| Thomas     | Stoneman  |    9.5 |
| Wyatt      | Skaggs    |    7.5 |
| Wyatt      | Skaggs    |    7.6 |
| Wyatt      | Skaggs    |    9.3 |
| Wyatt      | Skaggs    |    6.5 |
| Wyatt      | Skaggs    |    8.4 |
| Wyatt      | Skaggs    |    9.1 |
| Wyatt      | Skaggs    |    7.8 |
| Wyatt      | Skaggs    |    5.5 |
| Wyatt      | Skaggs    |    8.5 |
| Kimbra     | Masters   |    8.5 |
| Kimbra     | Masters   |    8.0 |
| Kimbra     | Masters   |    7.1 |
| Kimbra     | Masters   |    7.8 |
| Kimbra     | Masters   |    9.0 |
| Kimbra     | Masters   |    7.8 |
| Kimbra     | Masters   |    6.8 |
| Kimbra     | Masters   |    8.0 |
| Kimbra     | Masters   |    8.9 |
| Domingo    | Cortes    |    7.7 |
| Domingo    | Cortes    |    6.0 |
| Domingo    | Cortes    |    8.0 |
| Domingo    | Cortes    |    8.3 |
| Domingo    | Cortes    |    9.1 |
| Domingo    | Cortes    |    8.8 |
| Domingo    | Cortes    |    8.5 |
| Domingo    | Cortes    |    5.8 |
| Domingo    | Cortes    |    7.2 |
| Domingo    | Cortes    |    8.9 |
| Colt       | Steele    |    8.9 |
| Colt       | Steele    |    9.9 |
| Colt       | Steele    |    8.0 |
| Colt       | Steele    |    8.5 |
| Colt       | Steele    |    9.9 |
| Colt       | Steele    |    9.1 |
| Colt       | Steele    |    9.7 |
| Colt       | Steele    |    9.3 |
| Colt       | Steele    |    4.5 |
| Colt       | Steele    |    9.9 |
| Pinkie     | Petit     |    8.4 |
| Pinkie     | Petit     |    7.5 |
| Pinkie     | Petit     |    8.8 |
| Pinkie     | Petit     |    4.3 |
+------------+-----------+--------+
```

Example 4:

```sql
SELECT title AS unreviewed_series 
FROM series 
LEFT JOIN reviews 
ON series.id = reviews.series_id 
WHERE rating IS NULL; 
```

Result:

```
+-----------------------+
| unreviewed_series     |
+-----------------------+
| Malcolm In The Middle |
| Pushing Daisies       |
+-----------------------+
```

Example 5:

```sql
SELECT genre, ROUND(AVG(rating), 2) AS avg_rating 
FROM series 
INNER JOIN reviews 
ON series.id = reviews.series_id 
GROUP BY genre; 
```

Result:

```
+-----------+------------+
| genre     | avg_rating |
+-----------+------------+
| Animation |       7.86 |
| Comedy    |       8.16 |
| Drama     |       8.04 |
+-----------+------------+
```
