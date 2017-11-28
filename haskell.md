
## Edit, Load Haskell Source Code

* **GHCi** - GHC’s interactive environment, in which Haskell expressions can be interactively evaluated and programs can be interpreted.

By computer command prompt navigate to root project directory, then run `stack ghci`.

### To load Haskell file

First let create a Haskell file `test.hs`

```
main :: IO()
main = putStrLn "Hello from Haskell!"
```

On **GHCi** type:

```
> :load test.hs
```

### To run ours `main` function

On **GHCi** type:

```
> :main
```

### To reload Haskell file

On **GHCi** type:

```
> :reload
```

## Expressions

Everything in Haskell is an expression or declaration. Expression may be values, combination of values and/or function applied to value. In almost all programming languages you can create expressions such as:

```
(b*b-4*a*c)/2*a
```

and you can assign these expressions to variables:

```
v = (b*b-4*a*c)/2*a
```

In Haskell, expressions are really all there is, there are no statements.

## Functions

### Calling a function

```
sqrt 2
```

### Using two arguments

```
max 5 7
```

### When to use parentheses

We using parentheses for grouping expression.

```
max (5 + 2) (sqrt 17)
```

### Define Functions

Function definitios share a few thing of Javascript.

```javascript
const hello = (name) => {
  return "Hello, " + name;
}
```

First, they start with the name of the function, following by the formal parameters of the function, separed only by white space. Next is an equal sign which expresses equality of the terms. Finally there is an expression that is the body of the function and can be evaluated to return value.

```
hello name = "Hello, " ++ name
```

Noted difference whay to used symbol for concatenation. On Javascript is `+` and on Haskell `++`.

When to used parentesis

### Type signature part of define function

C has types, for example:

```
int add (int x, int y) {
  return x + y;
}
```

Haskell has much more powerful types than C, Type signature example:

```
-- Type signature: That tells, what is the type of a variable we can used on the function and what kind of vules we return.
add :: Int -> Int -> Int

add x y = x + y
```

* `::` - double quote is a type declaration.
* `Int ->` - first argument is a Number.
* `Int ->` - second argument is a Number.
* `Int` - return value is a Number.

If you try to apply other kind of difference type on this function, like example a float type `2.3` you will receive a error.

### Simple conditional

```
overOrminus :: Int -> String
overOrminus x =
  if x >= 5
    then "Over of 5"
    else "Minus of 5"
```

### Recursion

Repetition or iteration is obtained by using recursion. On Haskell we dont have loops, that why we using recursion all the time.

```
power2 :: Int -> Int
power2 n =
  if n == 0
    then 1
    else 2 * (power2 (n-1))
```

```
repeatString :: String -> Int -> String
repeatString word n =
  if n == 0
    then ""
    else word ++ (repeatString word (n -1))
```

## Built-in Data Structures

### List

The most important datatype in any functional programming language is the list. A list is a linearly ordered collection of elements. All the elements of a list must be of the same type. The easiest way in which to specify a list is by enumeration: you simply write the elements of the list between square brackets and separate them with commas. 

```
let numbers = [1, 2, 3, 4, 5]
```

List on Haskell must be homogeneous(of the same kind), means all element inside must be the same type. This next example is not a valid list.

```
error = [1, "hello", 2]
```

On Haskell there are not such thing like untype list or a list of object.

**Prepend Element to the list**

Colon `:` is using for prepend element at the front of a list. Using colon to prepend element to array, always return a new list.

```
x = [1, 2, 3]
y = 0 : x
head y
-- Result: 0
tail y
-- Result: [1, 2, 3]
```

**Concatenating List**

Thank that Haskell list are hemogeneous, we can concatenate list from the same type.

```
[1,2,3] ++ [4,5]
"hello" ++ "world"
```

**Accessing Lists**

* **head (unary prefix)** - which extracts the first element of a non-empty list.

```
head [1, 2, 3, 4]
-- Result: 1
```

* **tail (unary prefix)** - which returns the tail of a non-empty list, that is to say, the list of all the elements except the first.

```
tail [1, 2, 3, 4]
-- Result: [2, 3, 4]
```

```
head (tail [1, 2, 3, 4])
-- result: 2
```

* **length (unary prefix)** - which returns the length of a list.

```
length [4, 3, 5, 8, 1]
-- result: 5
```

* **!! (binary infix)** - which extracts an element of a list.  Note that this list indexing operator treats the first element of a list as occupying position 0.

```
"time" !! 2
-- result: 'm'
-- number after !! is the value position to extract.
[1, 2, 3, 4] !! 0
-- result: 1
```

**Testing Null**

```
null []
-- result: True
null [1, 2, 3]
-- result: False
```

**Defining functions that operate on lists**

```
-- doable each number on list
doubleNumber :: Integral a => [a] -> [a]
doubleNumber nums =
  if null nums
  	then []
  	else (2 * (head nums)) : (doubleNumber (tail nums))

doubleNumber [2, 4, 6, 8]
-- result: [4, 8, 12, 16]
```

* `Integral a => [a] -> [a]` - Left part of the arrow, I think is defining the type of the `a` on this cases and the right is the actual type signature.
* Note we are using recursion to loop throug array.

Another function with list:

```
removeOddNumber :: Integral a => [a] -> [a]
removeOddNumber nums = 
  if null nums
  	then []
  	else
      if (mod (head nums) 2) == 0 -- even?
        then (head nums) : (removeOddNumber (tail nums))
        else removeOddNumber (tail nums)
        
removeOddNumber [1, 2, 3, 4, 5, 6, 7, 8, 9]
-- result: [2, 4, 6, 8]
```
