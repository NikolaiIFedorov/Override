# About C++
## Execution order
C++ executes code line by line, like you would do in a recipe. For example, if your code

`<instruction 1>`
`<instruction 2>`

it would execute them in that order of, `<instruction 1>`, `<instruction 2>`.

## Global and Local Variables
C++ also has global and local variables. I won't get in depth of what it means just now, but on the surface, if you had something like this:

```cpp
<globalParameter>

{
    <localParameter>
}
```

You can use the `globalVariable` anywhere (`{}`), but the `localVariable` is available only inside the curly braces.

## Basic Data Types

- `int` - integer numbers
- `float` - floating-point numbers; allows for decimals
- `bool` - true or false
- `char` - single characters
- `std::string` - sequences of characters. Requires `#include <string>`
- `void` - represents the absence of a data type. Used for functions that do not return a value.

## Basic Collection Data Types
- `std::vector<dataType>` - a dynamic array of values of type `<dataType>`. Requires `#include <vector>`. 
- `std::set<dataType>` - a collection of unique values of type `<dataType>`. Requires `#include <set>`.
- `std::map<keyType, valueType>` - maps keys of type `keyType` to values of type `valueType`. Requires `#include <map>`.

## Pointers
Usually, data types store just values.
Pointers store the memory address to those values with this syntax:
`<dataType>*`

Pointer methods:
 - converting value type to pointer: `&<value>`
 - accessing value from a pointer: `*<pointer>`

## Creating a Variable

```cpp
int variableDeclaration;
```

To declare a variable, specify the data type followed by the variable name.

```cpp
int variableInitialization = 5;
```

You can also initialize it by assigning a value.

Variables follow this syntax: `<dataType> <variableName> = <value>;`

### Variable Methods
 - Setting a value: `<variableName> = <value>`

Number types only:
 - Adding: `<variableName> += <valuetoAdd>` or to add just one: `<variableName>++`
 - Subtracting: `<variableName> -= <valuetoSubtract>` or to subtract just one: `<variableName>--`
 - Multiplying: `<variableName> *= <valuetoMultiply>`
 - Dividing: `<variableName> /= <valuetoDivide>`

Some data types allow specific methods for variables, that can be acsessed with this syntax:
`<variableName>.<methodName>(<parameters>)`

## Creating a Function

```cpp
int functionDeclaration();
```

To declare a function, specify the return type, followed by the function name and parentheses.

```cpp
int functionDefinitionWithParameters(int param1, float param2 = 5);
```

If the function takes parameters, declare them in the parentheses. You can give them default values, so when calling the function, you don't have to provide that parameter.

```cpp
int functionDefinition()
{
    int localVariable = 10;
    return localVariable;
}
```

To define the function, write the body in curly braces. To return a value, use `return` followed by the value.

Functions follow this syntax:

```
<returnType> <functionName>(<parameters>)
{
    <functionBody>
    <return> <value or variable>
}
```

### Function methods
Functions can be called with this syntax:
`<functionName>(<parameters>);`

## Creating a Class

```cpp
class EmptyClassName
{
};
```

To create a class, specify the name with the syntax: `class <className> {};`

```cpp
class ClassWithMethods
{
    void function();
    int variable = 2;
};
```

Classes store functions and variables. The basic syntax is:

```
class <className>
{
    <functions and variables>
};
```

Syntax for functions and variables is the same as outside the class.

```cpp
class ClassWithMethodsAndFields
{
public:
    void publicFunction();
    int publicVariable;

private:
    void privateFunction();
    int privateVariable = 2;
};
```

Classes have access specifiers that control visibility:

- `public` - accessible anywhere in the program
- `private` - accessible only within the class
- If not specified, classes will default to private

The syntax for that is:

```
class <className>
{
public:
    <public functions and variables>
private:
    <private functions and variables>
};
```

```cpp
class ClassWithMethodsAndFieldsAndConstructors
{
public:
    ClassWithMethodsAndFieldsAndConstructors(int privateVariableValue) : privateVariable(privateVariableValue) {}
    void publicFunction();
    int publicVariable;

private:
    void privateFunction();
    int privateVariable;
};
```

A class can have a constructor, a special function called when the class is initialized.

Constructors follow function syntax with some differences:
- No return type.
- No type in the declaration, just the class name.
- Can initialize member variables with: `<constructorName>(<value>) : <memberVariableName>(<value>) {}`

### Class application and Static members

```cpp
class Class{
    public:
        Class(int paramValue) : constructorValue(paramValue) {}
        int GetConstructorValue() { return constructorValue; }
    private:
        int constructorValue;
};

Class variableTypeofClass(5);
Class secondVariableTypeofClass(2);

variableTypeofClass.GetConstructorValue(); // returns the constructorValue for variableTypeofClass, which is 5.
secondVariableTypeofClass.GetConstructorValue(); // returns the constructorValue for secondVariableTypeofClass, which is 2.
```
Classes can be used as a data type, like int, char, etc.
This means that classes can have separate instances.
Each variable will store its own version of the class. `variableTypeofClass` will have its `constructorValue` at `5`, while the `secondVariableTypeofClass` will have it at `2`.

```cpp
class ClassWithStaticMembers{
    public:
        ClassWithStaticMembers(int paramValue) : constructorValue(paramValue) 
        {
            totalConstructorValue += paramValue;
        }

        int GetConstructorValue() { return constructorValue; }
        static int GetTotalConstructorValue() { return totalConstructorValue; }
    private:
        int constructorValue;
        static int totalConstructorValue;
};

ClassWithStaticMembers::GetTotalConstructorValue(); // returns totalConstructorValue.
```

Since classes have separate instances, the class members are not shared between instances.
The exception here is static members. Every class instance has access to a static member, but the static member does not belong to any instance - it belongs to the class itself.
This means you do not need an instance to use the static member. You can acsess it with this syntax:
`<className>::<staticMember>`