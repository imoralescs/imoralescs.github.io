# React Static Type Check (Flow)

In programming Type is a classification of information. Example number, string, boolean. Programming language used types class to classificate his own data and know how to manage or threat data on the execution time or on runtime. They are language with static type and other with dynamically type. 

The core difference is that statically-typed languages perform type checking at compile time, while dynamically-typed languages perform type checking at runtime.

### Type-checking

This mean for example in Java if you define a boolean as:

```
boolean result = 123;
```

This has the correct type, because the boolean annotation matches the value given to result, as opposed to an inter or anything else. if you tried to declare:

```
boolean result = 123;
```

This would fail before run.

Type-checking verifies and enforces that the type of a construct (constant, boolean, number, variable, array, object) matches an invariant that you’ve specified. You might, for example, specify that “this function always returns a string.” When the program runs, you can safely assume that it will return a string.

Let see a case we Javascript where we are not using type-checking and we are using the wrong type on the process:

```
const length = 12;
const num = length(54); -> TypeError: length is not a function
```

We can get this error after time execution because Javascript is a dynamically-type language. In a statically-typed language, type errors occur during the compilation step, that is, at compile time. In dynamically-typed languages, the errors occur only once the program is executed. That is, at runtime.

This means that a program written in a dynamically-typed language can compile even if it contains type errors that would otherwise prevent the script from running properly. On the other hand, if a program written in a statically-typed language contains type errors, it will fail to compile until the errors have been fixed.
