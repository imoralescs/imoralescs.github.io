
## What is a Database

Ordered collection of data. 

## DBMS 

is a software that is designed to model data and provide interaction with a user. Data is normally stored in one or more files, usually stored in tables, tables contain rows and columns. Some DBMS are MySQL, PostgreSQL, Oracle, MariaDB, etc.

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

 *
