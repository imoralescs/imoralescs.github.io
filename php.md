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
