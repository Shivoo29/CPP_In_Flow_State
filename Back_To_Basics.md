# Cpp_In_Flow_State-Back to Basics

Now we will start the boring and basic but **important** C++ tutorials, so without wasting my time.

## Statements

computer program --> sequence of instruction that tell the computer what to do.

A **Statement** is a type of instruction that causes the program to perform some action.

- by far the most common type of instruction in a C++ program.
- because they are the smallest independent unit of computation in the C++ language
- they act much like sentence do in natural language.
- if you seee a line that ends in a semicolon, it's probably a statement.
 > There are many different kinds of statements in C++:
 >- Declaration statement
 >- jump statement
 >- Expression statements
 >- Compound statements
 >- Selection statements(conditionals)
 >- Iteration statements(loops)
 >- Try blocks

## Functions and the `main` function
Statements are typically groupped into units called **functions**
- A **function is a collection of statements that get executed sequentially(in order, top to bottom).

>### Rule
>In every C++ program there must be a fuction named **main**(all lower case letters).

- When the program is run, the statements inside of `main` are executed in sequential order.
- Program typically terminates when after the last statement inside main function has been executed

> ### Nomenclature
>When discussing functions, it’s fairly common shorthand to append a pair of parenthesis to the end of the function’s name. For example, if you see the term main() or doSomething(), this is shorthand for functions named main or doSomething respectively. This helps differentiate functions from other things with names (such as variables) without having to write the word “function” each time.

## Characters and text
- A **character** is a written symbol or mark, such as a letter, digit, punctiation mark, or mathematical symbol.
- A sequence of it is called a **text**.


## Dissecting Hello world!

Now that you have a brief understanding of what statements and functions are, let’s return to our “Hello world” program and take a high-level look at what each line does in more detail.
```cpp
#include <iostream>

int main()
{
   std::cout << "Hello world!";
   return 0;
}
```
- Line 1 is a special type of line called a preprocessor directive. This `#include` preprocessor directive indicates that we would like to use the contents of the `iostream` library, which is the part of the C++ standard library that allows us to read and write text from/to the console. We need this line in order to use `std::cout` on line 5. Excluding this line would result in a compile error on line 5, as the compiler wouldn’t otherwise know what `std::cout` is.

- Line 2 is blank, and is ignored by the compiler. This line exists only to help make the program more readable to humans (by separating the `#include` preprocessor directive and the subsequent parts of the program).

- Line 3 tells the compiler that we’re going to write (define) a function whose name (identifier) is `main`. As you learned above, every C++ program must have a `main` function or it will fail to link. This function will produce a value whose type is `int` (an integer).

- Lines 4 and 7 tell the compiler which lines are part of the main function. Everything between the opening curly brace on line 4 and the closing curly brace on line 7 is considered part of the `main` function. This is called the function body.

- Line 5 is the first statement within function `main`, and is the first statement that will execute when we run our program. `std::cout` (which stands for “character output”) and the << operator allow us to display information on the console. In this case, we’re displaying the text `Hello world!`. This statement creates the visible output of the program.

- Line 6 is a return statement. When an executable program finishes running, the program sends a value back to the operating system in order to indicate whether it ran successfully or not. This particular return statement returns the integer value `0` to the operating system, which means “everything went okay!”. This is the last statement in the program that executes.

All of the programs we write will follow this general template, or a variation on it.


## Syntax and syntax errors
The Set of rules that describe how specific words (and punctuation) can be arranges to form valid sentence in a language is called **syntax**


If your program does something that deviated from the syntax of the language, the compiler will halt compilation and issue a **_syntax error**.


## Comments
- A **Comment** is a programmer-readable note that is inserted directly into the source code of the program. Comments are ignored by the compiler and are for the programmer's use only.

## Single-Line Comment
- the `//` symbol begins a C++ single-line comment. which tells the compiler to ignore everything from `//` sybmol to the end of the line.
```cpp
std::cout << "Hello, world"; // Everything from here to the end of the line is ignored by the compiler.
```

## Multi-Line Comment
- the `/*` and `*/` pait of Symbols denotes a C-style multi-line comment.Everything in between the symbol is ignored.

```cpp
/* This is a multi-line comment.
   This line will be ignored.
   So will this one. */
```

## Introduction to objects and variables

### Data And Values
- In Computing, **data** is any info that can be moved, processed, or stored by computer

- In Programming, a single piece of data is called a **value**
eg. Numbers --> a=2,456,4,7,3
characters --> "a" itself
text

- Vlaues that are placed directly into the source code are called **Literals**

```cpp
#include <iostream> // for std::cout

int main()
{
   std::cout << 5; // print the literal number `5`
   std::cout << -6.7; // print the literal number `-6.7`
   std::cout << "H"; // print the literal charcter `H`
   std::cout << "Hello"; // print the literal text `Hello`

   retrun 0;
}
```

### Object and Variables
- An **Object** represents a region of storage(typically RAM or a CPU register) that can hold value
- Also have associated properties

> How the Compiler and Operating system work to assign memory to objects is beyond the socpe of this Discussion. But the key point here is that rather then say "go get the value stored in mailbox number 97823", we can just say,"go get the value stored by this object" and let the compiler figure out where and how to retrieve the value. This means we can focus on using objects to store and retrieve values, and not have to worry about where in the memory those objects are actually being placed.

- Although objects in C++ can be unnamed (anonymous), more often we name our objects using an identifier. An object with a name is called a **variable**.


### Defininf a vatiable

```cpp
int main()
{
   int z;
   int a,w;
   return 0;
}
```

### Variable assignment
```Cpp
int w;
w=0;
```
- `=` is *assignment operator* used to assign a value to a variable

```cpp
#include <iostream>

int main()
{
	int width; // define a variable named width
	width = 5; // copy assignment of value 5 into variable width

	std::cout << width; // prints 5

	width = 7; // change value stored in variable width to 7

	std::cout << width; // prints 7

	return 0;
}
```

### Variable Initilization
- The process of specifing an initial value for an object is called **initiallization**
- The syntax used to initialize an object is called an **initializer**..

```cpp
#include <iostream>
int main(){
   int width { 4 };
   std::cout<< width;
   return 0;
}
```

### Different form of initilization
```cpp
int a;         // default-initialization (no initializer)

// Traditional initialization forms:
int b = 5;     // copy-initialization (initial value after equals sign)
int c ( 6 );   // direct-initialization (initial value in parenthesis)

// Modern initialization forms (preferred):
int d { 7 };   // direct-list-initialization (initial value in braces)
int e {};      // value-initialization (empty braces)
```
- **Default-initilization**: when no initializwe is provided
- **Copy-initilization**: when initial value is provided after an equals sign
- **Direct-initilization**: when an initial value is provided inside parenthesis

#### List-initialization

```cpp
int width { 5 };    // direct-list-initialization of initial value 5 into variable width (preferred)
int height = { 6 }; // copy-list-initialization of initial value 6 into variable height (rarely used)
```
- List initilization disallows narrowing conversion

```cpp
int main()
{
   // An integer can only hold non-fractional values.
   // Initializing an int with fractional value 4.5 requires the compiler to convert 4.5 to a value an int can hold
   // such conversation is a narrowing conversation, since the fractional part of the value will be lost
   int a{ 3.4 };//commpiler error
   int b= 4.2;
   int c(3.4);
   return 0;
}
```
> [[maybe_unused]] attribute is used when we create a variable in our program which we are not using so that compiler does not thorow any exception.

## Introduction to iostream: cout, cin, and endl

- iostream is the **input/output library**, we'll use the functionality in this library to get input from the keyboard and output data to the console.

### cout
- allows us to send data to the console to be printed as text
*cout stands for character out*

```cpp
#include <iostream>
int main(){
   std::cout << "Hello, world";
   return 0;
}
```
- `<<` **insertion operator** used to send the text helloworld! to the console to be printed.

### endl
used to end the line.

**`std::cout` is buffered**, Output is typically not send to the console immediately. Instead, the requested output "Gets in line", and is stored in a region of memory set aside to collect such requests(called a **buffer**). Periodically, the buffer is **flushed**, meaning all of the data collected in the buffer is transferred to its destination

**`std::endl` vs `\n`**
`std::endl` is often inefficient, as it actually does 2 jobs: it outputs a newline(moving the cursor to the next lint of the console), and it flushed the buffer( which is slow). If we output multiple line of text ending with `std::endl`, we will get multiple flushes which is slow and prpbably unnecessary.

when outputting text to the console, we typically don't need to explicitly fluch the duffer ourselves. C++'s output system is desfined to self-flush periodically, and it's both simpler and more efficient to let it flush itself.

to output a newline without flushing the output buffer, we use `\n`, which is a special symbol that the compiler interprets as a newline character. `\n` moves the cursor to the next line of the console wothout causing a flush, so it will typically perform better




### cin
character input reads from keyboard, typically used with extraction operator `>>` to put the input data in a variable

this also takes input in buffer

## Operators
- **unary** operators act on one operand like `-` --> `-4`
- **Binary** operators act on 2 operands like `+` --> `2+3`
- **Ternary** operators act on 3 operands
- **Nullary** operators act on 0 operands

## Functions
 