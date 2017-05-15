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

```php
// if (exp) 
//   statement

$speed = 80;

if($speed > 60){
  echo "Over speed !";
}
```

### ELSE Conditional Statement

```php
// if (exp) 
//   statement
// else
//   statement

$speed = 50;

if($speed > 60) {
  echo 'Over speed !';
}
else {
  echo 'Speed within normal limits';
}
```

### ELSEIF Conditional Statement

```php
// if (exp) 
//   statement1
// elseif (exp2) 
//   statement2

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
