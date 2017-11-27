
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

### Function Types

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
