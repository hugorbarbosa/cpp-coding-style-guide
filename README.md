# C++ Coding Style Guide

This project mentions some C++ coding styles that are often used on C++ projects, and contains my C++ coding style guide.

## Table of contents

// TODO: Update.

- [Introduction](#introduction)
    - [Why a coding style guide matters](#why-a-coding-style-guide-matters)
    - [Popular C++ coding style guides](#popular-c-coding-style-guides)
    - [My C++ coding style guide](#my-c-coding-style-guide)
- [Naming conventions](#naming-conventions)
    - [Types](#types)
    - [Variables](#variables)
    - [Constants](#constants)
    - [Functions](#functions)
    - [Enumerators](#enumerators)
    - [Namespaces](#namespaces)
    - [Macros](#macros)
    - [Files and directories](#files-and-directories)
- [Comments](#comments)
- [Formatting](#formatting)
- [Header files](#header-files)
    - [Include guards](#include-guards)
    - [Using namespaces](#using-namespaces)
    - [Templates](#templates)
- [Classes and structs](#classes-and-structs)
    - [Classes vs structs](#classes-vs-structs)
    - [Declaration order](#declaration-order)
- [Type deduction](#type-deduction)
    - [`auto` usage](#auto-usage)
- [Aliases](#aliases)
    - [`using` vs `typedef`](#using-vs-typedef)
- [Tools](#tools)
- [License](#license)
- [References](#references)

## Introduction

A coding style guide is a set of conventions and best practices that standardizes how code is written and formatted. For C++, this means rules for naming conventions, indentation, code structure, commenting, and the use of language features.

### Why a coding style guide matters

C++ is a complex and powerful language with many features that can be used in different ways, which makes adhering to a coding style guide important. A consistent coding style can make C++ code easier to understand, debug, and extend. The following are some points about the importance of a coding style guide:

- **Consistency**: when everyone follows the same coding conventions, it becomes easier to collaborate on projects, as the code appears uniform regardless of the individual authors.
- **Readability**: code that adheres to a style guide is easier to read and understand. Readability is crucial because software development is a team activity, and code often needs to be maintained or extended by someone other than the original author.
- **Error reduction**: a well-thought-out style guide can help avoid common pitfalls and mistakes, such as inconsistent use of resources, inefficient memory management, or risky language features.
- **Best practices**: coding style guides often incorporate best practices for writing efficient, modern, and maintainable C++ code.

### Popular C++ coding style guides

There's no "official" coding style guide for C++, as we have with [Python][ref-python-pep8] for example. However, there are several widely-recognized C++ coding style guides used in the industry. Below are some of the most popular ones:

- **[C++ Core Guidelines][ref-cpp-core-guidelines]**: collection of guidelines written by Bjarne Stroustrup, the creator of C++, along with other C++ experts. It is a set of guidelines for using C++ well, intended to help people to use modern C++ effectively. These guidelines are focused on relatively high-level issues, such as interfaces, resource management, memory management, and concurrency.
- **[Google C++ Style Guide][ref-google-cpp-style-guide]**: comprehensive style guide used across Google's codebase. It covers various topics like naming conventions, function design, and performance optimization.
- **[LLVM Coding Standards][ref-llvm-cpp-coding-standards]**: set of conventions used by the LLVM project, focusing on consistency and the clarity of code, particularly for large projects. It includes detailed rules on indentation, function declarations, and code organization.
- **[Mozilla C++ Style Guide][ref-mozilla-cpp-style-guide]**: style guide used for code written within the Mozilla project. It includes guidelines on code organization, documentation, and how to structure complex systems.

### My C++ coding style guide

This document describes my personal C++ coding style guide, reflecting my preferences and practices. It is not meant to be exhaustive and its focus is *not* on how to use C++ effectively, for that I highly recommend exploring the [C++ Core Guidelines][ref-cpp-core-guidelines], which is an excellent resource for mastering modern C++ practices and writing clean and efficient code. Instead, it highlights some conventions I follow in my C++ projects regarding coding layout style, naming conventions, indentation, etc. There may be additional considerations or exceptions depending on the project's needs and context.

Please note that this coding style guide may not be suitable for every project and should be adapted as needed to meet specific project requirements. It just contains my preferences and conventions that I try to follow in my personal projects and in projects without any established coding standard/style.

Additionally, it is relevant to mention that a C++ coding guide may provide a set of coding rules only for a particular environment. There's no C++ coding standard for all uses and all users. The most important thing is to be **consistent** within a project, and follow the coding style guide for a given application/project, independently of personal preferences.

This is a non-closed document and may evolve and improve whenever necessary.

## Naming conventions

This section presents the conventions for naming variables, functions, etc. In some cases, more than one option is referred, in order to mention some common styles that we frequently see in different C++ projects.

However, independently of the style option chosen, as already mentioned before, be **consistent**.

**Note:** identifier names that contain double underscores `__` or that start with an underscore followed by a capital letter (e.g., `_Throws`) must be avoided. Such identifiers are reserved for the C++ implementation.

### Types

*Types* includes the following:

- Classes
- Structs
- Enums
- Type aliases
- Type template parameters

Type names should use `PascalCase`, i.e., each word should start with a capital letter and no separator (e.g. underscore) between words:

```c++
class MyClass {
    ...
};

struct MyStruct {
    ...
};

enum class MyEnum {
    ...
};

using IntegerContainer = std::vector<int>;

typedef std::vector<int> IntegerContainer;
```

Another option is using [`snake_case`][ref-style-snake-case], i.e., lowercase and with underscores to separate words, as the C++ Standard Library usually applies.

To better differentiate user-defined types from the Standard Library types, another possibility is using the upper case only on the first letter and keeping underscore (e.g., `My_type`), as mentioned in the [C++ Core Guidelines][ref-cpp-core-guidelines].

```c++
// Using snake_case.
class my_class {
    ...
};

// Using snake_case but with first letter in upper case.
class My_class {
    ...
};
```

Choose only one style and be consistent within a project.

### Variables

Variables (including function parameters) and data members of classes and structs are in `snake_case`:

```c++
int a_variable{0};

class MyClass {
    ...
private:
    int data_member;
};

struct MyStruct {
    int data_member;
};
```

When naming variables, it is also common using [`camelCase`][ref-style-camel-case], i.e., each word starts with a capital letter, except the first word, and no separator (e.g. underscore) between words:

```c++
class MyClass {
    ...
private:
    int dataMember;
};
```

Another aspect that is often seen in C++ projects in variable names are prefixes and suffixes. For class private data members, it is common using the suffix `_` or prefixes like `m_` or just `m` (only `m` more common when using `camelCase`):

```c++
class MyClass {
    ...
private:
    // Using suffix "_".
    int data_member_1_;
    // Using prefix "m_".
    int m_data_member_2;
    // Using prefix "m".
    int mDataMember3;
};
```

Choose only one style and be consistent within a project.

### Constants

Variables declared with `constexpr` or `const` should use `snake_case`:

```c++
constexpr int a_constexpr_var{42};
const int a_const_var{43};
```

In some C++ projects, it is usually used a prefix when naming constants, such as `c` or `k`:

```c++
// Using prefix `c` and snake_case.
const int c_const_var{44};
// Using prefix `k` and camelCase.
const int kConstVar{45};
```

Choose only one style and be consistent within a project.

### Functions

Function names should use `snake_case`:

```c++
void a_free_function(const int a_parameter);

class MyClass {
    ...
public:
    void a_member_function(const int a_parameter);
};
```

Another possibility is using `camelCase` or `PascalCase` when naming functions:

```c++
// Using camelCase.
void anotherFreeFunction();

class MyClass {
    ...
public:
    // Using PascalCase.
    void AnotherMemberFunction();
};
```

Choose only one style and be consistent within a project.

### Enumerators

Enumerators (for both scoped and unscoped enums) should use the same naming format used for [constants](#constants):

```c++
// When constants use snake_case.
enum class MyEnum {
    first_enumerator = 0,
    second_enumerator,
};
```

It is relevant to refer that never use `ALL_CAPS` for enumerators to avoid clashes with macros:

```c++
#define START 1
#define STOP 2

// Don't use ALL_CAPS.
enum class MyEnum {
    START,
    STOP
};
```

### Namespaces

Namespace names should use `snake_case`:

```c++
namespace project_name {
namespace nested_namespace {
...
} // namespace nested_namespace
} // namespace project_name
```

Note that the top-level namespace name should be based on the project name. In addition, care must be taken when naming namespaces to avoid collisions between different namespaces but with the same name.

### Macros

Macro names should use `ALL_CAPS`, since this is the convention for macros, and helps for readability and to distinguish macros:

```c++
#define START_CODE 1
```

However, macros are a major source of bugs, since they don't obey the usual scope and type rules. Prefer to use the Modern C++ features instead, like `constexpr` for example, if possible.

### Files and directories

Names of files and directories should be all lowercase and can include underscores (`_`) to separate words.

Examples:
- `my_class.cpp`
- `my_class.h`
- `a_directory/my_struct.h`

For files relative to tests, use a prefix correspondent to the testing level:
- Mock related to `my_class`: `mock_my_class.h`
- Unit test file related to `my_class`: `ut_my_class.cpp`
- Integration test file: `it_something.cpp`
- System test file: `st_something.cpp`

## Comments

// TODO: Complete.

- Comments
- Documentation

## Formatting

// TODO: Complete.

- Indentation
- if, switch-case, for

## Header files

### Include guards

To avoid multiple inclusion, the header files should have `#define` guards. Additionally, to avoid include guards collision, the guard must be unique. For that purpose, the format of the guard name can be something like `<PROJECT>_<FILE_NAME>_H`:

```c++
// File "foo/src/bar.h":
#ifndef FOO_BAR_H
#define FOO_BAR_H
// ... declarations ...
#endif // FOO_BAR_H
```

Some implementations offer vendor extensions like `#pragma once` as alternative to include guards. However, note that this is not standard and is not portable.

### Using namespaces

Don't write `using namespace` at global scope in a header file, because it exposes this `using namespace` in all files that include this header file:

```c++
// bad.h
#include <iostream>
using namespace std; // Don't do this.
```

### Templates

Instead of defining completely a templated class in the header file, consider to put its declaration in a `.h` file and its definition in a `.ipp` file:

```c++
// my_class.h

#include <something>

namespace project_name {

template<typename T>
class MyClass {
    ...
    void a_member_function();
};

} // namespace project_name

#include "my_class.ipp"

// my_class.ipp

namespace project_name {

template<typename T>
void MyClass<T>::a_member_function()
{
    ...
}

} // namespace project_name
```

## Classes and structs

### Classes vs structs

If any member is non-public, use `class` rather than `struct`:

```c++
struct Example {
    int x;
    int y;
private:
    int z; // Private member: "Example" should be defined as class instead.
};
```

### Declaration order

Use the following order when declaring a class:

- Types and type aliases:
    - Nested structs and classes
    - Enums
    - Aliases (`using`, `typedef`)
- Static constants
- Factory functions
- Constructors, assignment operators and destructor
- Member functions (static and non-static member functions, and friend functions)
- Data members (static and non-static)

Use the following order regarding access control (omit sections in case they are empty):
- `public`
- `protected`
- `private`

Declare the section for member functions and for data, independently if it is the same, like the following example:

```c++
class X {
public:
    void function1();

private:
    void function2();

private: // To be explicit.
    int data1;
};
```

Declare member functions and after the data members, independently of the access defined:

```c++
class X {
public:
    void function1();

private:
    void function2();

public:
    int data1;

private:
    int data2;
};
```

## Type deduction

### `auto` usage

Do not use `auto` only to avoid the inconvenience of writing an explicit type. Use `auto` only if it makes the code clearer to readers who aren't familiar with the project, or if it makes the code safer.

## Aliases

### `using` vs `typedef`

Prefer `using` in C++ code instead of `typedef`:

```c++
using Bar = Foo;
typedef Foo Bar; // But prefer `using` instead.
```

## Tools

// TODO: Complete.

- clang-format
- clang-tidy
- VS Code
- Doxygen

## License

Licensed under the [MIT license](./LICENSE).

## References

- [C++ Core Guidelines][ref-cpp-core-guidelines]
- [Bjarne Stroustrup: C++ Style and Technique FAQ][ref-cpp-bs-tech-faq]
- [Bjarne Stroustrup: PPP Style Guide][ref-cpp-bs-ppp-style]
- [Google C++ Style Guide][ref-google-cpp-style-guide]
- [LLVM Coding Standards][ref-llvm-cpp-coding-standards]
- [Mozilla C++ Style Guide][ref-mozilla-cpp-style-guide]
- [PEP (Python Enhancement Proposal) 8: Style Guide for Python Code][ref-python-pep8]
- [Snake case][ref-style-snake-case]
- [Camel case][ref-style-camel-case]

[ref-cpp-core-guidelines]: https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md "C++ Core Guidelines"
[ref-cpp-bs-tech-faq]: https://www.stroustrup.com/bs_faq2.html "Bjarne Stroustrup: C++ Style and Technique FAQ"
[ref-cpp-bs-ppp-style]: https://www.stroustrup.com/Programming/PPP-style.pdf "Bjarne Stroustrup: PPP Style Guide"
[ref-google-cpp-style-guide]: https://google.github.io/styleguide/cppguide.html "Google C++ Style Guide"
[ref-llvm-cpp-coding-standards]: https://llvm.org/docs/CodingStandards.html "LLVM Coding Standards"
[ref-mozilla-cpp-style-guide]: https://firefox-source-docs.mozilla.org/code-quality/coding-style/coding_style_cpp.html "Mozilla C++ Style Guide"
[ref-python-pep8]: https://peps.python.org/pep-0008/ "PEP (Python Enhancement Proposal) 8: Style Guide for Python Code"
[ref-style-snake-case]: https://en.wikipedia.org/wiki/Snake_case "Snake case"
[ref-style-camel-case]: https://en.wikipedia.org/wiki/Camel_case "Camel case"
