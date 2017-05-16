# PHP 

The PHP programming language is a server-side HTML embedded scripting language.

## echo statement

When you want to display the text on a web page, then the operator `echo` is the most widely used operator in PHP. How to have use of it - after the word `echo` you want to place the text string in quotation marks:

```php
<?php echo 'Hello Worlds'; ?>
```

## HEREDOC

In order to allow people to easily write large amounts of text from within PHP, but without the need to constantly escape things, heredoc syntax was developed. He starts with <<< , followed by an arbitrary identifier can be recorded. After the disposable text should specify the same ID as in the beginning of the code:

```php

```

## Variables

Variable consists of dollar sign `$` and free ID which is assigned any value. Variable can not start with number and space. Variable name is case sensitive.

```php
$userName = "John";
```

### Interpolation

Variable interpolation is adding variables in between a string data. PHP will parse the interpolated variables and replace the variable with its value while processing the string data. The variable parsing is allowed with the string data enclosed with double quotes or with heredocs.

```php
$capital = 'Paris';

echo "The capital of France is $capital </br>"; //-> The capital of France is Paris
echo 'The capital of France is $capital </br>'; //-> The capital of France is $capital
echo "The capital of France is ${capital} </br>"; //-> The capital of France is Paris
```

### Constants

When you do not need to change the default value for a variable, it makes sense to create a constant, and then use it in any part of the script. Used to describe the constant function `define`, which is transferred to her name and a value. cCnstant name must always be enclosed in quotation marks, and its value only when it is a string.

```php
define("PI", 3.14);

echo "The mathematical constant Pi is " . PI;
```

As the name of the constant you can not use reserved words in PHP, which are described below:

### Data Types

PHP is a language dynamic typing , the variable type is determined on the basis of its values. But still you need to know what types of data exist in PHP. Listed below are all the types that can be used in PHP:

 * **Boolean:** This logic type that contains the value trueor false.
 * **Integer:** It contains integer values (for example: 4or 10or another integer).
 * **String:** It contains the value of the text of any length (example: Oleg, Kiev, Austria).
 * **Float:** Real number (example: 1.2, 3.14, 8.5498777).
 * **Object:** An object.
 * **Array:** Array.
 * **Resource:** Resource (example: file).
 * **NULL:** NULL value.

## Operators

### Mathematicals Operators 

Numeric data is processed by means of PHP operators:

 * **+:** the sum of the two numbers.
 * **-:** the difference between the numbers.
 * **/:** the quotient of two numbers.
 * **%:** remainder of the division.
 
```php
echo "2 + 2 = ", 2 + 2, "<br>";
echo "5 - 2 = ", 5 - 2, "<br>";
echo "10 * 10 = ", 10 * 10, "<br>";
echo "100 / 2 = ", 100 / 2, "<br>";
echo "10 % 2 = ", 10 % 2, "<br>";
```

### Math Functions

PHP has a huge number of mathematical functions, that is their complete list:

```php
echo "round(4.2) = ", round(4.2), "<br>"; 
```

### Assignment

The basic assignment operator is the equal sign `=`. He assigns the value of a particular variable:

```php
$fruits = 14;
```

### Increment & Decrement

There are special operators in PHP. For example, if there is a variable `$a = 0`, then to add 1 to the variable you need to write `$a++`, which means that a variable `$а` unit, if it is necessary to take away 1 is added, it must be written as follows: `$a--`.

The operator `++` called increment and `--` decrement.

```php
$a = $b = $c = $d = 2;

echo $a++, "<br>"; //-> 2
echo ++$b, "<br>"; //-> 3
echo $c--, "<br>"; //-> 2
echo --$d, "<br>"; //-> 1
```

### Priority PHP Operators

If you use multiple operators at the same time in the same expression, the need to know in what order they will be executed.

### String Operators

PHP has two string operators.

 * **First:** the concatenation operator .that combines two lines into one.
 * **Second:** concatenated assignment operator .=adds to the string as desired. 

```php
$d = "Hello";
$f = $d . " world"; 

echo $f; //-> Hello world

echo "<br/>";

$f .= " ! ! !"; 

echo $f; //-> Hello world ! ! !
```

## Conditional Statements

### IF Conditional Statement

```
if (exp) 
  statement
```

```php
$speed = 80;

if($speed > 60){
  echo "Over speed !";
}
```

### ELSE Conditional Statement

```
if (exp) 
  statement
else
  statement
```

```php
$speed = 50;

if($speed > 60) {
  echo 'Over speed !';
}
else {
  echo 'Speed within normal limits';
}
```

### ELSEIF Conditional Statement

```
if (exp) 
  statement1
elseif (exp2) 
  statement2
```

```php
$speed = 50;

if ($speed < 30) {
  echo "Speed within normal limits";
}
elseif ($speed >= 30 && $speed <= 60) {
  echo "Your speed {$speed} km/h";
}
else {
  echo "Over speed!";
}
```

### Ternary Operator

Ternary operator works almost as well as an operatorif , but when using the ternary operator, we write instead of keywords `?` and `:`.

```php
$speed = 55;

echo ($speed <= 60) ? "Speed within normal limits" : "Over speed!"; 
```

### Switch Statement

First written keyword `switch`, followed by parentheses in a written expression. 
Further, after the speech `case` to list the options values, if the value is true, then the group of statements, which are written to the operator `break`. If neither condition is not suitable, then the operator `default` (if the operator defaultdoes not record, when not carrying out any other conditions it does nothing).

```php
$speed = 55;

switch($speed)
{
  case 30 :
    echo "Your speed is 30 km/h";
    break;
  case 58 :
    echo "Your speed is 50 km/h";
    break;
  case 70 :
    echo "Over speed!";
    break;
  default :
    echo "Speed within normal limits";
    break;
}
```

## Cycles or Loops

### FOR Loop

```
for(exp1; exp2; exp3) statement
```

 * **exp1:** insert an initial value for the loop counter, a variable that counts the number of times of the loop body. 
 * **exp2:** sets the condition of repetition of the cycle. The cycle will be executed until this condition is true. 
 * **exp3:** is performed every time after caesarean section loop. Usually, it is used to change (increase or decrease) counter.

```php
for ($i = 0; $i < 10; $i++)
{
  echo "Output string. $i times <br>"; 
}
```

### WHILE Loop

```
while (exp) statement
```

WHILE loop instead of using a loop counter check condition until such time as this condition is true (TRUE). The condition is tested before executing the cycle, if it is false in the beginning, the loop will not be executed even once!  The body of the loop must be a variable that will have an impact on the condition, to prevent looping.

```php
$counter = 0;
while ($counter < 5)
{
  echo "This line will be displayed $counter times <br>"; 
  $counter++;
}
```

### DO WHILE Loop

```
do
  statement 
while (condition)
```

The main difference between DO...WHILE loop WHILE from that first performed first loop body, and then check the condition. Ie, if the condition is at once false, the loop will be executed once. 

```php
$counter = 6;

do
{
  echo "This line will be displayed $counter time"; 
  $counter++;
}

while ($counter < 5);
```

### FOREACH Loop

```
foreach (array as $value) statement 
foreach (array as $key => $value) statement
```

FOREACH cycle is presented to simplify the work with arrays (arrays will be discussed later). The arrays consist of separate elements, FOREACH loop for sorting these elements without counter. 

```php
$array = array ("Apple", "Limon", "Chery", "Oranges");

foreach ($array as $value)
{
  echo "You chose a fruit - $value <br>"; 
}
```

## Handling String Functions

## Arrays

Array is a collection of data, which are combined under a single name. The array consists of several elements that have a particular index.

Arrays are created using the assignment operator , as well as a variable. 
Names of arrays start with a `$` , followed by an arbitrary identifier, followed by square brackets: `$arr[0] = "php";`

This design creates an array and assigns it to the element at index 0 value "php", then we can refer to this element as a normal variable: `echo $arr[0]`. As a result, we see the word `?` Php .

```php
$arr[1] = "html";
$arr[2] = "css";

var_dump($arr); //-> array(2) { [1]=> string(4) "html" [2]=> string(3) "css" }
```

### Create an Array

```php
$arr = array("php", "html", "css");

var_dump($arr); //-> array(3) { [0]=> string(3) "php" [1]=> string(4) "html" [2]=> string(3) "css" }
```

### Modification Array Element

```php
$arr[0] = "PHP";
$arr[1] = "HTML";
$arr[2] = "CSS";

echo $arr[1]; //-> HTML

$arr[1] = "JAVASCRIPT";

echo $arr[1]; //-> JAVASCRIPT
```

### Removing Array Element

```php
$arr[0] = "PHP";
$arr[1] = "HTML";
$arr[2] = "CSS";

echo $arr[1]; //-> HTML

unset($arr[1]);

var_dump($arr); //-> array(2) { [0]=> string(3) "PHP" [2]=> string(3) "CSS" }
```

### Sorting Array

```php
$arr[0] = "PHP";
$arr[1] = "HTML";
$arr[2] = "CSS";

var_dump($arr); //-> array(3) { [0]=> string(3) "PHP" [1]=> string(4) "HTML" [2]=> string(3) "CSS" } 

echo '</br>';
sort($arr);

var_dump($arr); //-> array(3) { [0]=> string(3) "CSS" [1]=> string(4) "HTML" [2]=> string(3) "PHP" }
```

### Navigating Array

```php
$arr[0] = "PHP";
$arr[1] = "HTML";
$arr[2] = "CSS";

echo current($arr), "<br>"; //-> PHP
echo next($arr), "<br>"; //-> HTML
echo prev($arr), "<br>"; //-> PHP
echo end($arr), "<br>"; //-> CSS
echo reset($arr), "<br>"; //-> PHP
```

## Funtions

Function is a set of statements that identifies a specific identifier (name).

```php
function square($num)
{
  $square = $num * $num;
  echo $square;
}

square(7); //-> 49
```

### Transfer Data in PHP Function

The function can use the data that is passed to it when you call. For this purpose, use the argument list, which is a list of arguments separated by commas.

```php
function myfunc($x,$y) {
  $res = cos($x) + sin($y) + 2;
  return $res;
}

$x = 5;
$y = 7;

$z = myfunc($x,$y);

echo $z; //-> 2.940648784182
```

The operator `return` needs to function to return a value.

### Default Value PHP Function Arguments

```php
function hello($text = "Hi") {
  echo $text;
}

hello('Good Afternoon'); //-> Good Afternoon

echo "<br/>";

hello(); //-> Hi
```

## Object Oriented Programming

### Classes

The class is one of the data types. Every class definition begins with the keyword class, then the class name, a pair of braces, inside which it is possible to determine the properties and methods (to be discussed) that class. Class name can be any word on the condition that it is not included in the list of reserved word in PHP starts with a letter or underscore and followed by any number of letters, digits, or underscores. 

```php
class User
{
  public $email;
}
```

### Objects

To create an instance (object) of the class used Directive `new`.

```php
class User
{
  public $email;
}

$instance = new User();
$instance->email = "israel.morales@gmail.com";

echo $instance->email; //-> israel.morales@gmail.com
```

### Constructor / Destructors

PHP allows developers to declare constructor methods. Classes in which the declared constructor method will call this method whenever you create a new object.

```php
class Task {
  public $description;

  public function __construct($description = 'Task Title')
  {
    $this->description = $description;
  }
}

$task_01 = new Task('Learn OOP');
echo $task_01->description; //-> Learn OOP

$task_02 = new Task();
echo $task_02->description; //-> Task Title
```

Also in PHP are represented by destructors. The destructor will be called during the liberation of all references to a particular object, or at the end of the script (the order of the destructor is not guaranteed).

### Properties & Function or Methods

The variables in the class, called "properties". They are also referred to using other terms such as "attributes" or "field". They are defined by using keywords public, protected, or private, following the rules of the correct description of the variables.

```php
class Task {
  public $description = "Learn OOP";
  private $title = "OOP";
  protected $duration = "1hr";
}

$task = new Task();
echo $task->description . '</br>'; //-> Learn OOP
echo $task->title . '</br>'; //-> Fatal error: Uncaught Error: Cannot access private property
echo $task->duration . '</br>'; //-> Fatal error: Uncaught Error: Cannot access protected property
```

Functions in the class known as "method". The process of describing the method occurs as in the description of conventional functions.

```php
class Task {
  public $description = "Learn OOP";

  public function getDescription(){
    return $this->description;
  }
}

$task = new Task();
$result = $task->getDescription();

echo $result; //-> Learn OOP
```

### Properties Access Areas

The words of the public , the private , protected, determine the scope of a variable or class.

 * **public:** available to all elements of.
 * **private:** members are not accessible from the outside (outside of class).
 * **protected:** items are available only to the class and all its descendants (will be considered).

### Getters & Setters

 * Controlling the of behavior associated with getting or setting the property - this allows additional functionality (like validation) to be added more easily later.
 * Hiding the internal representation of the property while exposing a property using an alternative representation.
 * Allowing the getter/setter to be passed around as lambda expressions rather than values.
 * Getters and setters can allow different access levels - for example the get may be public, but the set could be protected.
 * Insulating your public interface from change - allowing the public interface to remain constant while the implementation changes without affecting existing consumers.
 * Providing a debugging interception point for when a property changes at runtime.
 * Improved interoperability with libraries that are designed to operate against property getter/setters - Mocking, Serialization, etc.
 * Allowing inheritors to change the semantics of how the property behaves and is exposed by overriding the getter/setter methods.
 
```php
class Person
{
  public $name;
  public $age;
  
  public function __construct($name)
  {
    $this->name = $name;
  }
  
  public function getAge()
  {
    return $this->age * 365;
  }
  
  public function setAge($age)
  {
    if($age < 18)
    {
      throw new Exception("Person is not old enough.");
    }
    
    $this->age = $age;
  }
}

$john = new Person('John Doe');
$john->setAge(30);

// without encapsulation we can overwrite value.
$john->age = 8;

var_dump($john->getAge()); //-> int(2920)
 ```
 
### Encapsulation
 
Is just changing the visibility of you properties, so we can restric access to them.
 
```php
class Person
{
  private $name;
  private $age;

  public function __construct($name)
  {
    $this->name = $name;
  }

  public function getAge()
  {
    return $this->age * 365;
  }

  public function setAge($age)
  {
    if($age < 18)
    {
      throw new Exception("Person is not old enough.");
    }

    $this->age = $age;
  }
}

$john = new Person('John Doe');
$john->setAge(30);

//$john->age = 8; // Uncaught Error: Cannot access private property

var_dump($john->getAge()); //-> int(10950)
```

### Inheritance

Inheritance is useful when you expand the class, the child class inherits all the public (public) and secure (protected) methods from the parent class. These methods will be original functionality as long as they are not overwritten.

This approach is useful for abstracting functionality. Allows for additional functionality in similar objects implement all the common functionality without the need for.

To create an inheritance from another class you want to use the operator `extends`.

```php
class Person
{
  public $name;

  public function __construct($name = 'Unknown')
  {
    $this->name = $name;
  }
}

class John extends Person {
  public function getName()
  {
    return $this->name;
  }
}

$john = new John('John Doe');
echo $john->getName(); //-> John Doe
```

### Interface

It will not add any additional functionality but it outlines a standard format to which your classes need to use. Any classes which inherit from an interface class must have at least the same methods as the interface class. The methods placed in the interface class will not have any functionality but will have just the method stubs to be used by the other classes. The methods outlined in the interface must be used by the other classes or it will throw an error.

#### Defining An Interface Class

Interface classes are defined by using the keyword interface. All the methods in the interface must be public as this is the nature of an interface.

```php
interface TaskStorageInterface
{
  public function get($id);
  public function store(Task $task);
}
```

#### Using A Defined Interface Class

You will use an interface on classes when you have classes which will do similar things but the functionality being different.

To use an interface class it's done by using the `implements` keyword.

```php
class FileTaskStorage implements TaskStorageInterface 
{
  public function get($id)
  {
    // file implementation
  }

  public function store(Task $task)
  {
    // file implementation
  }
}

class MySqlDatabaseTaskStorage implements TaskStorageInterface
{
  public function get($id)
  {
    // mysql implementation
  }

  public function store(Task $task)
  {
    // mysql implementation
  }
}
```

### Abstract

An abstract class is a type of class which we can not create an object from. An abstract class is used like an interface class except we can add functionality into the methods defined in the abstract class. To use the abstract class we will also need to use the `extends` keyword, we can only implement one abstract class where we can implement multiple interface classes.

An abstract class will have abstract methods which are defined by the abstract keyword, these methods are like the methods defined in the interface classes.

All methods in abstract classes that you want to override can not be private methods as they will need to be used outside of the class.

You will use an abstract class in a similar way you would use an interface but there is common functionality which will be used on all the classes which extend it.

```php
abstract class Service
{
  // oauth method
  abstract function getRedirectUri();
}

class FacebookService extends Service
{
  public function getRedirectUri()
  {
    return 'uri';
  }
}

class TwitterService extends Service
{
  public function getRedirectUri()
  {
    return 'uri';
  }
}

$facebook = new FacebookService;
echo $facebook->getRedirectUri(); //-> uri
```

### Traits

A Trait is simply a group of methods that you want include within another class. A Trait, like an abstract class, cannot be instantiated on it’s own.

One of the problems of PHP as a programming language is the fact that you can only have single inheritance. This means a class can only inherit from one other class.

However, a lot of the time it would be beneficial to inherit from multiple classes. For example, it might be desirable to inherit methods from a couple of different classes in order to prevent code duplication.

A Trait is kind of like a **Mixin** in that it allows you to mix Trait classes into an existing class. This means you can reduce code duplication and get the benefits whilst avoiding the problems of multiple inheritance.

```php
trait Hello
{
  public function sayHello()
  {
    return 'Hello';
  }
}

trait World
{
  public function sayWorld()
  {
    return 'Worlds';
  }
}

trait HelloWorld
{
  use Hello, World;

  public function sayHelloWorld()
  {
    return $this->sayHello() . ' ' . $this->sayWorld();
  }
}

class Greeting
{
  use HelloWorld;

  public function output()
  {
    return $this->sayHelloWorld();
  }
}

$greeting = new Greeting;
echo $greeting->output(); //-> Hello Worlds

```

### Exception

It allows you to have a more fine-grained control over code when things go wrong. This allow us to catch the fact of something is goes wrong with a block, and change the flow of you application. This is more cleaner that used if statement.

```php
class PaymentGatewayException extends Exception
{
  //
}

class GatewayPaymentFailedException extends Exception
{
  protected $message = 'Payment failed';
}

class InvalidGatewayTokenException extends Exception
{
  protected $message = 'Invalid token';
}

class PaymentGateway
{
  public function charge($token, $amount)
  {

    // Throw errors
    if(0){
      throw new InvalidGatewayTokenException;
    }

    if(1){
      throw new GatewayPaymentFailedException;

    }
  }
}

$gateway = new PaymentGateway;

// Controll flow
try {
  $gateway->charge('123', 25.00);
  echo 'Update subscription';
}
catch(PaymentGatewayException $e) {
  die($e->getMessage());
}
finally {
  die(' Finally...');
}
```

### Dependency Injection

Dependency Injection is a software design pattern that allows avoiding hard-coding dependencies and makes possible to change the dependencies both at runtime and compile time.

By using Dependency Injection we can write more maintainable, testable, and modular code. All projects have dependencies. The larger the project the more dependencies is it bound to have; now having a great number of dependencies is nothing bad by itself however how those dependencies are managed and maintained is.

Dependency Injection is not a new pattern and it has been commonly used on many languages like Java, but this pattern is somewhat new in the PHP world and it's gaining traction quickly thanks for frameworks like laravel

```php
class TwitterClient
{
  public function getTweets($handle)
  {
    return [
      'Quisque pretium',
      'Nulla condimentum ex est',
      'Duis a imperdiet nibh'
    ];
  }
}

class TwitterManager
{
  protected $client;

  public function __construct(TwitterClient $twitterclient)
  {
    $this->twitterclient = $twitterclient;
  }

  public function getTweesByUser($handle)
  {
    return $this->twitterclient->getTweets($handle);
  }
}

$twitterClient = new TwitterClient;
$twitterManager = new TwitterManager($twitterClient);

var_dump($twitterManager->getTweesByUser('israel.morales@gmail.com'));
//-> array(3) { [0]=> string(15) "Quisque pretium" [1]=> string(24) "Nulla condimentum ex est" [2]=> string(21) "Duis a imperdiet nibh" }
```

Notice we divide the code on class, this has be done because we want to maintain each class with his own responsability. **S.O.L.I.D** principle.

### Method Chaining

Method chaining is a cool and useful featured expecially for procedural sequential API. What make possible chaining is returning at every method call the called object instance.

```php
class SearchRequest
{
    protected $query;

    protected $limit;

    public function setQuery($query)
    {
      $this->query = $query;

      // Allow us chain method
      return $this;
    }

    public function setLimit($limit = 100)
    {
      $this->limit = $limit;

      return $this;
    }
}

class SearchService
{
  public function search(SearchRequest $request)
  {
    var_dump($request); 
  }
}

$service = new SearchService;
$request = new SearchRequest;

// Substitute
/*
$request->setQuery('oop');
$request->setLimit(50);
*/

$request->setQuery('oop')->setLimit(50);

$service->search($request); //-> object(SearchRequest)#2 (2) { ["query":protected]=> string(3) "oop" ["limit":protected]=> int(50) }
```
