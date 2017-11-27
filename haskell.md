
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
