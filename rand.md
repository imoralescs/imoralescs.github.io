#include <iostream>
#include <cstdio>

using namespace std;

//---- Function

//-- Function prototype declaration
// Some time user defined function after main() function, this make th compiler throw a error. Because the compiler is unaware of user defined function. Function prototype is a declaration of the function without its body to give compiler information about user defined function.
/*
void func();

int main()
{
    puts("This is main()");
    func();
    return 0;
}

void func() {
    puts("This is func()");
}
*/
// This is not the common way to do this, the common way to do this is a header file .h, the you define your prototype function in there.

//-- Static values inside function
// When a variable is declared as static, space for it get allocated for the lifetime of the program even if the function is called multiples time, space for the static variable is allocated only once and the value.
/*
void func() {
    static int i = 5;
    cout << "i is: " << i << endl;
    
    i = 42;
    cout << "i is: " << i << endl;
}

int main()
{
    func();
    func();
    return 0;
}
//-> i is: 5
//-> i is: 42
//-> i is: 42
//-> i is: 42
*/
// If we dont used the static reserved word, every time we call the function the value of the variable will be change or initiate to the initial value.
/*
void func() {
    int i = 5;
    cout << "i is: " << i << endl;
    
    i = 42;
    cout << "i is: " << i << endl;
}

int main()
{
    func();
    func();
    return 0;
}
//-> i is: 5
//-> i is: 42
//-> i is: 5
//-> i is: 42
*/

//-- Return

//-- Function pointer
// Why point to a function, imagine the sort function where you need to sort an array, sometime you want to order array elements in an ascending order or descending order.
// We declare a function by the following example:
/*
int foo(int);
*/
// So we can declare pointer to function on the same way as variable 
/*
int * foo(int);
*/
// But this we create a error, why? On C++ operator precedence also play role here, in this case operator () will take priority over operator *. So we would change the default precedence using () operator data-type (*pointerName)(parameters);
/*
int (*foo)(int);
*/
/*
void func() {
    puts("This is func()");
}

int main()
{
    void (*fp)() = func;

    fp();
    return 0;
}
*/
// Is important that the value of return in function and pointer will be the same.
// Example implementation 

// Example 1
/*
void add(int a, int b) {
    cout << a + b << endl;
}

void mult(int a, int b) {
    cout << a * b << endl;
}

int main()
{
    // Declare a function pointer
    void (*fptr)(int, int);

    // fptr -> add
    fptr = &add;
    fptr(12, 3);

    // fptr -> mult
    fptr = &mult;
    fptr(5, 4);

    return 0;
}
*/

// We can alse create arrays of function pointer

// Example 2
/*
void add(int a, int b) {
    cout << a + b << endl;
}

void mult(int a, int b) {
    cout << a * b << endl;
}

int main()
{
    void (*fptr[2])(int, int);

    fptr[0] = add;
    fptr[1] = mult;

    fptr[0](12, 3);
    fptr[1](5, 4);

    return 0;
}
*/
//-> 15
//-> 20

// Example 3



// Example 4
/*
const char *prompt();
int jump(const char *);

void fa() { puts("This is fa()"); }
void fb() { puts("This is fb()"); }
void fc() { puts("This is fc()"); }
void fd() { puts("This is fd()"); }
void fe() { puts("This is fe()"); }

void (*fptr[])() = { fa, fb, fc, fd, fe, nullptr};

int main() {
    while(jump(prompt()));
    
    puts("\nDone");
    
    return 0;
}

const char *prompt() {
    puts("Choose an option:");
    puts("1. Function fa()");
    puts("2. Function fb()");
    puts("3. Function fc()");
    puts("4. Function fd()");
    puts("5. Function fe()");
    puts("Q. Quit");
    puts(">> ");

    fflush(stdout);
    const int buffsz = 16;
    static char response[buffsz];
    fgets(response, buffsz, stdin);

    return response;
}

int jump(const char * rs) {
    char code = rs[0];
    if(code == 'q' || code == 'Q') {
        return 0;
    }

    int func_length = 0;
    while(fptr[func_length] != NULL) {
        func_length++;
    }

    // Convert ASCII numeral to int
    int i = (int) code - '0';

    // List is zero-based
    i--;

    if(i < 0 || i >= func_length) {
        puts("Invalid choice");
    }
    else {
        fptr[i]();
        return 1;
    }
}
*/
// To execute this code we used C++11 Standard c++11 mode
// g++ -std=c++11 main.cpp -o main

//-- Function overload

/*
void print(int i) {
    cout << "Here is int: " << i << endl;
}

void print(double f) {
    cout << "Here is float: " << f << endl;
}

void print(const char *c) {
    cout << "Here is char*: " << c << endl;
}

int main() {
    print(10);
    print(10.10);
    print("ten");
    return 0;
}
//-> Here is int: 10
//-> Here is float: 10.1
//-> Here is char*: ten
*/

//-- Variadic arguments
// Allows a function to accept any number of arguments. Indicated by the parameter of the form ... which must appear last in the parameter-list of a function declaration.
// First argument is int count of remaining args

//-- Recursive

//---- Preprocessor
/*
For C/C++ preprocessor, preprocessing occurs before a program is compiled.  A complete process involved during the preprocessing, compiling and linking can be read in C/C++ - Compile, link and running programs.

Some possible actions are:

    Inclusion of other files in the file being compiled.
    Definition of symbolic constants and macros.
    Conditional compilation of program code or code segment.
    Conditional execution of preprocessor directives.

All preprocessor directives begin with #, and only white space characters may appear before a preprocessor directive on a line.
*/

//-- Macros 
// Macros are a text processing feature. What happens once you build your program is that all occurrences of macros are “expanded” and replaced by the macro definitions. Macros are piece of code in a program which is given some name. Whenever this name is encountered by the compiler the compiler replaces the name with the actual piece of code. The ‘#define’ directive is used to define a macro. Let us now understand macro definition with the help of a program. Simple text replacement.
/*
#define ONE 1
#define HELLO_STRING "Hello, World!"
#define SUM(x, y) (x + y)

int main()
{
    int a = 5;
    int b = 10;
    int sum = SUM(a, b);

    puts(HELLO_STRING);
    
    cout << "Sum of 5 + 10 is: " << sum << endl;
    return 0;
}
//-> Hello, World!
//-> Sum of 5 + 10 is: 15
*/
//-- Include
/*
File Inclusion: This type of preprocessor directive tells the compiler to include a file in the source code program. There are two types of files which can be included by the user in the program:

Header File or Standard files: These files contains definition of pre-defined functions like printf(), scanf() etc. These files must be included for working with these functions. Different function are declared in different header files. For example standard I/O funuctions are in ‘iostream’ file whereas functions which perform string operations are in ‘string’ file.

Syntax:
#include< file_name >

where file_name is the name of file to be included. The ‘<‘ and ‘>’ brackets tells the compiler to look for the file in standard directory.

user defined files: When a program becomes very large, it is good practice to divide it into smaller files and include whenever needed. These types of files are user defined files. These files can be included as:

#include"filename"
*/

//-- Conditional
/*
Conditional Compilation: Conditional Compilation directives are type of directives which helps to compile a specific portion of the program or to skip compilation of some specific part of the program based on some conditions. This can be done with the help of two preprocessing commands ‘ifdef‘ and ‘endif‘.
*/

#define FOO

#ifdef FOO 

#define NUMBER 47

#else 

#define NUMBER 2

#endif

int main() {
    cout << "Number is: " << NUMBER << endl;
    return 0;
}


https://www.tenouk.com/Module10.html
https://simplesnippets.tech/preprocessor-directives-macros-in-cpp/
