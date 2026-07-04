# C++ Coding Style Guide

This project presents some C++ coding styles that are often used in C++ projects. Furthermore, it also contains my C++ coding style guide.

## Table of contents

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
- [Comments and documentation](#comments-and-documentation)
    - [Comment style](#comment-style)
    - [TODO comments](#todo-comments)
    - [Documentation](#documentation)
- [Formatting](#formatting)
    - [Line length](#line-length)
    - [Spaces vs tabs](#spaces-vs-tabs)
    - [Layout style](#layout-style)
- [Best practices](#best-practices)
    - [Initializer syntax](#initializer-syntax)
    - [Prefer `nullptr` to 0 and NULL](#prefer-nullptr-to-0-and-null)
    - [Scoped `enum`s](#scoped-enums)
    - [Default case in `switch` statements](#default-case-in-switch-statements)
    - [Header file extension](#header-file-extension)
    - [Include guards](#include-guards)
    - [Using namespaces](#using-namespaces)
    - [Classes vs Structs](#classes-vs-structs)
    - [Declaration order](#declaration-order)
    - [Templates declaration](#templates-declaration)
    - [`auto` usage](#auto-usage)
    - [Prefer `using` to `typedef`](#prefer-using-to-typedef)
    - [Comments usage](#comments-usage)
- [License](#license)
- [References](#references)

## Introduction

A coding style guide is a set of conventions and best practices that standardizes how code is written and formatted. For C++, this means rules for naming conventions, indentation, code structure, commenting, and the use of language features.

### Why a coding style guide matters

C++ is a complex and powerful language with many features that can be used in different ways, which makes adhering to a coding style guide important. A consistent coding style can make C++ code easier to understand, debug, and extend. The following points describe in more detail the importance of using a coding style guide:

- **Consistency**: when everyone follows the same coding conventions, it becomes easier to collaborate on projects, as the code appears uniform regardless of the individual authors.
- **Readability**: code that adheres to a style guide is easier to read and understand. Readability is crucial because software development is a team activity, and code often needs to be maintained or extended by someone other than the original author.
- **Error reduction**: a well-thought-out style guide can help avoid common pitfalls and mistakes, such as inconsistent use of resources, inefficient memory management, or risky language features.
- **Best practices**: coding style guides often incorporate best practices for writing efficient, modern, and maintainable C++ code.

### Popular C++ coding style guides

There's no "official" coding style guide for C++, as we have for [Python][ref-python-pep8], for example. However, there are several widely-recognized C++ coding style guides used in the industry. Below are some of the most popular ones:

- [**C++ Core Guidelines**][ref-cpp-core-guidelines]: collection of guidelines written by Bjarne Stroustrup, the creator of C++, along with other C++ experts. It is a set of guidelines for using C++ well, intended to help people to use modern C++ effectively. These guidelines are focused on relatively high-level issues, such as interfaces, resource management, memory management, and concurrency.
- [**Google C++ Style Guide**][ref-google-cpp-style-guide]: comprehensive style guide used across Google's codebase. It covers various topics like naming conventions, function design, and performance optimization.
- [**Microsoft Coding Style Guide**][ref-microsoft-cpp-style-guide]: coding style guide built by Microsoft. It contains many coding style rules that cover, for example, code formatting and naming conventions.
- [**LLVM Coding Standards**][ref-llvm-cpp-coding-standards]: set of conventions used by the LLVM project, focusing on consistency and the clarity of code, particularly for large projects. It includes detailed rules on indentation, function declarations, and code organization.
- [**Mozilla C++ Style Guide**][ref-mozilla-cpp-style-guide]: style guide used for code written within the Mozilla project. It includes guidelines on code organization, documentation, and how to structure complex systems.

### My C++ coding style guide

This document describes my personal C++ coding style guide, reflecting my preferences and practices. It is not meant to be exhaustive and its focus is *not* on how to use C++ effectively. Instead, this guide highlights some conventions I follow in my C++ projects regarding coding layout style, naming conventions, indentation, etc. Nevertheless, some best practices are included as well in this guide as a reference.

Please note that this coding style guide may not be suitable for every project and should be adapted as needed to meet specific project requirements. It just contains my preferences and conventions that I try to follow in my personal projects and in projects without any established coding standard/style.

Additionally, it is relevant to mention that a C++ coding guide may provide a set of coding rules only for a particular environment. There's no C++ coding standard for all uses and all users. The most important thing is to be **consistent** within a project, and follow the coding style guide for a given application/project, independently of personal preferences.

This is a non-closed document and may evolve and improve whenever necessary.

## Naming conventions

This section outlines conventions for naming variables, functions, and other entities. In some cases, multiple options are provided to introduce the reader to different styles commonly seen in C++ projects, being the first option listed for each topic the one I personally prefer. However, regardless of the style option you choose, be **consistent**.

Manually ensuring that the code always has the desired naming conventions is a very error-prone task. Therefore, it is recommended to use a tool that automatically verifies the naming conventions from the code. A tool that is commonly utilized for this purpose is clang-tidy, through the respective identifier naming check. Please refer to the [C++ development tooling][ref-cpp-development-tooling] guide to know more details about clang-tidy, and to the [C++ project template][ref-cpp-project-template] to see how this tool can be used in a project.

**Note:** identifier names that contain double underscores `__` or that start with an underscore followed by a capital letter (e.g., `_Throws`) must be avoided. Such identifiers are reserved for the C++ implementation.

### Types

*Types* include the following:

- Classes
- Structs
- Enums
- Type aliases
- Type template parameters

Type names should use `PascalCase`, i.e., each word should start with a capital letter and no separator (e.g., underscore) between words:

```c++
class MyClass {
    // ...
};

template<typename MyTemplateParameter>
class MyClassTemplate {
    // ...
};

struct MyStruct {
    // ...
};

enum class MyEnum {
    // ...
};

using IntegerContainer = std::vector<int>;
typedef std::vector<int> IntegerContainer;
```

#### Also commonly used

Another option is using [`snake_case`][ref-style-snake-case], i.e., lowercase and with underscores to separate words, as the C++ Standard Library usually applies.

Yet another possibility is to utilize upper case only in the first letter and keep the underscore to separate words (e.g., `My_type`), as mentioned in the [C++ Core Guidelines][ref-cpp-core-guidelines], to better differentiate user-defined types from Standard Library types.

```c++
// Using snake_case.
class my_class {
    // ...
};

// Using snake_case but with the first letter capitalized.
class My_class {
    // ...
};
```

Choose just one style and be consistent within a project.

### Variables

Variables (including function parameters) and data members of classes and structs are in `snake_case`. Data members of classes (but not structs) additionally have a trailing underscore, with the exception of constant class members, which should follow the format for [naming constants](#constants):

```c++
int my_variable{0};

class MyClass {
public:
    // Constant class members don't have a trailing underscore.
    static const int my_constant{42};
private:
    // Only class data members have a trailing underscore.
    int my_data_member_;
};

struct MyStruct {
    int my_data_member;
};
```

#### Also commonly used

When naming variables, it is also common using [`camelCase`][ref-style-camel-case], i.e., each word starts with a capital letter, except the first word, and no separator between words:

```c++
class MyClass {
private:
    // Using camelCase.
    int myDataMember;
};
```

Additionally, an aspect commonly seen in C++ projects is the use of prefixes and suffixes in variable names. Besides a trailing underscore, it is also common to add prefixes like `m_` or simply `m` to name class data members:

```c++
class MyClass {
private:
    // Using prefix "m_" and snake_case.
    int m_my_data_member;
    // Using prefix "m" and camelCase.
    int mMyDataMember;
};
```

Choose just one style and be consistent within a project.

### Constants

Variables declared with `constexpr` or `const` should use `snake_case`:

```c++
constexpr int my_constexpr_var{42};
const int my_const_var{43};
```

#### Also commonly used

It is also common to use `camelCase` on constants when this style is applied for variables. Similarly, some C++ projects use a prefix when naming constants, such as `c` or `k`:

```c++
// Using prefix `c` and snake_case.
const int c_my_const_var{44};
// Using prefix `k` and camelCase.
const int kMyConstVar{45};
```

Choose just one style and be consistent within a project.

### Functions

Function names should use `snake_case`:

```c++
void my_free_function(const int first_parameter);

class MyClass {
public:
    void my_member_function(const int first_parameter);
};
```

#### Also commonly used

Another possibility is using `camelCase` or `PascalCase` for naming functions:

```c++
// Using camelCase.
void myFreeFunction(const int first_parameter);

class MyClass {
public:
    // Using PascalCase.
    void MyMemberFunction(const int first_parameter);
};
```

Choose just one style and be consistent within a project.

### Enumerators

Enumerators (for both scoped and unscoped enums) should use `snake_case`:

```c++
enum class MyEnum {
    first_enumerator = 0,
    second_enumerator,
};
```

#### Also commonly used

Similarly, `camelCase` or `PascalCase` might also be used to name enumerators:

```c++
enum class MyEnum {
    // Using camelCase.
    firstEnumerator,
    secondEnumerator,
};

enum class MyEnum {
    // Using PascalCase.
    FirstEnumerator,
    SecondEnumerator,
};
```

Choose just one style and be consistent within a project.

**Note:** never use `ALL_CAPS` for enumerators to avoid clashes with macros:

```c++
#define START 1
#define STOP 2

enum class MyEnum {
    // Don't use ALL_CAPS.
    START,
    STOP
};
```

### Namespaces

Namespace names should use `snake_case`:

```c++
namespace project_name {
namespace nested_namespace {

// ...

} // namespace nested_namespace
} // namespace project_name
```

The top-level namespace name should be based on the project name. In addition, care must be taken when naming namespaces to avoid collisions between different namespaces but with the same name.

### Macros

Macro names should use `ALL_CAPS`, as this is the convention for macros and helps with readability and distinguishability:

```c++
#define START_CODE 1
```

Nevertheless, macros can be a source of bugs because they don't obey the usual scope and type rules. Prefer to use Modern C++ features instead (e.g., `constexpr`) if possible.

### Files and directories

Names of files and directories should be all lowercase and include underscores to separate words. Examples:

- `my_class.cpp`
- `my_class.hpp`
- `my_directory/my_struct.hpp`

For files relative to tests, use the following rules:

- For unit tests, use the prefix `ut_`. Example: unit test file related to `my_class` should be named as `ut_my_class.cpp`.
- For integration tests, use the prefix `it_`. Example: `it_something.cpp`.
- For system tests, use the prefix `st_`. Example: `st_something.cpp`.
- For testing doubles (mocks, fakes, stubs, etc.), use a prefix that identifies its type. Example: mock file related to `my_class` should be named as `mock_my_class.hpp`.

## Comments and documentation

### Comment style

Comment using either the `//` or `/* */` syntax, as long as consistency is maintained:

```c++
// This is a comment.

// This is a comment in
// multiple lines.

/* This is a comment. */

/*
 * This is a comment in
 * multiple lines.
 */
```

### TODO comments

A TODO comment should be used when something needs to be done or changed in the future. For example, some feature or functionality that should be implemented in the future that currently is missing, or some solution that must be changed/improved because it is now considered as a temporary solution.

Its format must contain the "TODO" text, followed by the issue/bug ID, a name or other identifier that contains the problem referenced by the TODO, as shown below:

```c++
void my_function()
{
    // TODO(Issue-42): Avoid copies.
    // ...code that performs copies...
}
```

### Documentation

It is very useful to document the source code in a format that is understandable by a tool, allowing the verification and parsing of the documentation in an automatic way. Doxygen is a tool that can be utilized for that purpose, so the source code should be documented using the format supported by this tool, as demonstrated in the examples below. Please refer to the [C++ development tooling][ref-cpp-development-tooling] guide to know more details about doxygen, and to the [C++ project template][ref-cpp-project-template] to see how this tool can be used in a project.

Examples:

- For files, start with the documentation described as follows:
    ```c++
    /**
     * @file
     * @copyright Copyright (C) 2024 <Author/Company>.
     */
    // ...code...
    ```
- For classes/structs and member/free functions:
    ```c++
    /**
     * @brief Add the provided two integers.
     *
     * @param first_integer First integer to add.
     * @param second_integer Second integer to add.
     *
     * @return Sum of the two integers.
     */
    long add_two_integers(const int first_integer, const int second_integer);

    /**
     * @brief My class.
     */
    class MyClass {
    public:
        /**
         * @brief Set the data member value.
         * 
         * This function verifies if the data can be updated or not.
         * 
         * @param new_value New data member value.
         *
         * @return True if the data member was successfully updated, false otherwise.
         */
        bool set_data(const int new_value);
    private:
        /// Data member example.
        int data_member_;
    };

    /**
     * @brief My struct.
     */
    struct MyStruct {
        /// Data member example.
        int data_member;
    };
    ```
- For templates:
    ```c++
    /**
     * @brief Log the provided data.
     *
     * @tparam T Data type.
     * @param data Data to be logged.
     */
    template<typename T>
    void log(T data);

    /**
     * @brief My class.
     *
     * @tparam T Data member type.
     */
    template<typename T>
    class MyClass {
    private:
        /// Data member example.
        T data_member_;
    };
    ```
- For enums:
    ```c++
    /**
     * @brief Possible operation results.
     */
    enum class OperationResult {
        /// Operation has succeeded.
        success,
        /// Operation has failed due to out-of-memory.
        out_of_memory,
        /// Operation has failed due to unknown reason.
        unknown
    };
    ```

## Formatting

Ensuring that the code always has the desired format is a very difficult and error-prone task. Thus, it is highly recommended to use a tool that automatically checks and formats the code. A tool that is commonly utilized for this purpose is clang-format, which allows to directly apply a predefined code style (e.g., Google, Microsoft, etc) or customize a new one with the desired style options. Please refer to the [C++ development tooling][ref-cpp-development-tooling] guide to know more details about clang-format, and to the [C++ project template][ref-cpp-project-template] to see how this tool can be used in a project.

### Line length

Each line of code should be at most 100 characters long. A line may exceed this maximum value only in some exceptional cases (e.g., when a literal URL is longer than 100 characters).

### Spaces vs tabs

Use only spaces, and use 4 spaces for indentation.

Tabs should not be used in code, to ensure that the alignment and number of spaces are consistent independently of the IDE or code editor that is utilized.

Furthermore, it is recommended to configure the IDE/editor to emit spaces when pressing the tab key.

### Layout style

The Kernighan & Ritchie (K&R) style is commonly used for C and C++ code, because it preserves vertical space well, and helps to easily distinguish different language constructs, such as functions and classes.

When adding conventions for constructs not found in C, that becomes what is often called as "Stroustrup" style, being this style suggested in the [C++ Core Guidelines][ref-cpp-core-guidelines].

Example:

```c++
namespace some_namespace { // Brace in the same line for namespaces.

// The declarations inside of the namespace should not be indented.

class B : public A { // Brace in the same line for classes/structs/enums.
public: // No indentation.
    // ...indentation of the code inside...
};

void my_function()
{ // Brace in a new line for functions.
    if (condition) { // Space between "if" and "(", and brace in the same line.
        some_function(); // Indentation of the code inside.
    }
    else if (another_condition) { // "else" is in a new line.
        other_function(a);
    }
    else {
        other_function();
    }

    // Same rules for loops.
    for (auto i = 0; i < 10; ++i) {
        some_function();
    }

    while (condition) {
        some_function();
    }

    do {
        some_function();
    } while (condition);

    switch (x) {
    case 0: // No indentation of the case label.
        // ...
        break;
    case 1:
        // ...
        break;
    default:
        // ...
        break;
    }
}

} // namespace some_namespace
```

**Note:** use always braces as shown in the example for `if`s, `for`s, `while`s, etc., to avoid eventual bugs if more code is added later that should be executed inside of the condition/loop scope.

## Best practices

The focus of this guide is *not* on the C++ best practices and how to use it effectively, for that I highly recommend exploring C++ books and other material about that topic, like the following ones, which are excellent resources for mastering modern C++ practices and writing clean and efficient code:

- [C++ Core Guidelines][ref-cpp-core-guidelines].
- *Effective Modern C++: 42 Specific Ways to Improve Your Use of C++11 and C++14* (Scott Meyers).
- *C++ Best Practices: 45ish Simple Rules with Specific Action Items for Better C++* (Jason Turner).
- *Clean Code: A Handbook of Agile Software Craftsmanship* (Robert C. Martin).
- *The C++ Programming Language* (Bjarne Stroustrup).

Nevertheless, the following sections describe some recommended best practices.

### Initializer syntax

Prefer using `{}` for initialization, because the rules for `{}` are simpler, more general, less ambiguous, and safer than for other forms of initialization.

Use `=` only when no narrowing conversions can happen, and avoid `()` initialization since it allows parsing ambiguities.

However, note that for containers, there is a tradition of using `{}` for a list of elements and `()` for sizes:

```c++
std::vector<int> v1(10);   // Vector of 10 elements with the default value 0.
std::vector<int> v2{10};   // Vector of 1 element with the value 10.
std::vector<int> v3(1, 2); // Vector of 1 element with the value 2.
std::vector<int> v4{1, 2}; // Vector of 2 elements with the values 1 and 2.
```

In addition, it is relevant to mention that the initialization of a variable declared using `auto` with a single value had surprising results until C++17. Therefore, consider using `=` for the initialization of `auto` variables before C++17, and always use `{}` from C++17 onward:

```c++
// C++14: Instead of being "int", the type may be deduced to "std::initializer_list<int>" (not clearly defined in the Standard, depends on the implementer).
// C++17: Type is deduced to "int" (clearly defined in the Standard).
auto x{42};
```

### Prefer `nullptr` to 0 and NULL

Prefer `nullptr` instead of `0` or `NULL` in C++ code. C++'s primary policy is that the literal 0 is an `int`, not a pointer, and generally speaking, the same is true for the `NULL` case. So, use always `nullptr` for pointers to be explicit about the type and for better readability.

### Scoped `enum`s

Prefer scoped `enum`s to unscoped ("plain") `enum`s because the enumerator names in an `enum class` are scoped to the `enum` itself. In contrast, the enumerator names of a "plain" (unscoped) `enum` are introduced into the enclosing scope.

Additionally, the unscoped `enum`s convert to int too readily, and might lead to bugs more easily.

### Default case in `switch` statements

Avoid `default` in `switch` statements since it might introduce bugs.

Consider this example:

```c++
enum class Result {
    success,
    out_of_memory
};

std::string_view get_result(const Result result)
{
    switch (result) {
    case Result::success:
        return "success";
    case Result::out_of_memory:
        return "out_of_memory";
    }
}
```

If all compiler warnings are enabled, it is possible to get an warning mentioning that "not all code paths return a value". It makes sense since we can call the function like `get_result(static_cast<Result>(42))`, and for this case, we face Undefined Behavior of not returning a value from the function.

We may think about adding the `default` case to fix the warning:

```c++
std::string_view get_result(const Result& result)
{
    switch (result) {
    case Result::success:
        return "success";
    case Result::out_of_memory:
        return "out_of_memory";
    default:
        return "unknown";
    }
}
```

But if a new enumerator is introduced, this function doesn't specifically handle this new case and no compiler warning is emitted, returning an wrong string for this new enumerator:

```c++
enum class Result {
    success,
    out_of_memory,
    busy // New enumerator.
};

std::string_view get_result(const Result& result)
{
    switch (result) {
    case Result::success:
        return "success";
    case Result::out_of_memory:
        return "out_of_memory";
    default: // New enumerator is wrongly handled by the default case.
        return "unknown";
    }
}
```

So, the `default` case shall be avoided in order to use the compiler to catch this needed change. The following is the recommended way for this example:

```c++
enum class Result {
    success,
    out_of_memory,
    busy
};

std::string_view get_result(const Result& result)
{
    switch (result) {
    case Result::success:
        return "success";
    case Result::out_of_memory:
        return "out_of_memory";
    // Compiler warning about unhandled enumerator is emitted now.
    /*
    case Result::busy:
        return "busy";
    */
    }

    return "unknown";
}
```

### Header file extension

Prefer using the following extensions for header files:

- `.hpp`: for headers that are C++ only. Using this extension communicates that this header should not be included by a C source file, since it contains code that is only compatible with C++.
- `.h`: for headers that are compatible with C and C++ or pure C headers. This header can be included by both a C source file and a C++ source file.

This distinction can be particularly useful when working on a project that uses both C and C++ code.

But consistency is more important, so if your project uses something different, you should follow that.

### Include guards

To avoid multiple inclusion, the header files should have `#define` guards. Moreover, to avoid include guards collision, the guard must be unique. For that purpose, the format of the guard name can be something like `<PROJECT>_<FILE_NAME>_HPP`:

```c++
// File "foo/src/dir/bar.hpp":
#ifndef FOO_BAR_HPP
#define FOO_BAR_HPP

// ...code...

#endif // FOO_BAR_HPP
```

**Note:** some implementations offer vendor extensions like `#pragma once` as alternative to `#define` guards. However, note that this is not standard and is not portable.

### Using namespaces

Don't write `using namespace` at global scope in a header file, because it exposes this `using namespace` to all files that include this header file:

```c++
// bad.hpp
#include <iostream>
using namespace std; // Don't do this.
```

### Classes vs Structs

If any member is non-public, use `class` rather than `struct`:

```c++
struct Example {
    int x;
    int y;
private:
    int z; // Private member: this struct should be declared as class instead.
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

Regarding access control, the following order should be used (omit sections in case they are empty):

- `public`
- `protected`
- `private`

### Templates declaration

To separate the declaration and definition of template classes, the usage of `.ipp` files is a recommended practice, as shown in the following example:

```c++
// my_class.hpp

namespace project_name {

template<typename T>
class MyClass {
    void my_member_function();
    // ...code...
};

}

#include "my_class.ipp" // Header file includes the .ipp file.

// my_class.ipp

namespace project_name {

template<typename T>
void MyClass<T>::my_member_function()
{
    // ...code...
}

}
```

Using a `.ipp` file has some benefits, like separation of concerns, maintainability and code clarity. But it might not be necessary in some cases, such as small or simple templates to avoid unnecessary complexity and file management overhead, and libraries intended for wide distribution to avoid issues with template instantiation.

Thus, the choice between using `.ipp` file or keeping everything in the header file depends largely on the size and complexity of the code and the project's needs. For more maintainable and scalable codebases, separating template definitions into `.ipp` files is generally a good practice.

### `auto` usage

Do not use `auto` only to avoid the inconvenience of writing an explicit type. Use `auto` in case if it makes the code clearer to readers or if it makes the code safer.

### Prefer `using` to `typedef`

Prefer `using` instead of `typedef` in C++ code:

```c++
using Bar = Foo;
typedef Foo Bar; // But prefer `using` instead.
```

### Comments usage

Comments are important to state intent more clearly to the reader. It should contain details to help understanding some code, but don't comment what can be easily extracted from the code. While comments are very important, the best code is self-documenting.

## License

Licensed under the [MIT license](./LICENSE).

## References

- [C++ Core Guidelines][ref-cpp-core-guidelines]
- [Bjarne Stroustrup: C++ Style and Technique FAQ][ref-cpp-bs-tech-faq]
- [Bjarne Stroustrup: PPP Style Guide][ref-cpp-bs-ppp-style]
- [Google C++ Style Guide][ref-google-cpp-style-guide]
- [Microsoft Coding Style Guide][ref-microsoft-cpp-style-guide]
- [LLVM Coding Standards][ref-llvm-cpp-coding-standards]
- [Mozilla C++ Style Guide][ref-mozilla-cpp-style-guide]
- [PEP (Python Enhancement Proposal) 8: Style Guide for Python Code][ref-python-pep8]
- [Snake case][ref-style-snake-case]
- [Camel case][ref-style-camel-case]
- [C++ project template][ref-cpp-project-template]
- [C++ development tooling][ref-cpp-development-tooling]

[ref-cpp-core-guidelines]: https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md "C++ Core Guidelines"
[ref-cpp-bs-tech-faq]: https://www.stroustrup.com/bs_faq2.html "Bjarne Stroustrup: C++ Style and Technique FAQ"
[ref-cpp-bs-ppp-style]: https://www.stroustrup.com/Programming/PPP-style.pdf "Bjarne Stroustrup: PPP Style Guide"
[ref-google-cpp-style-guide]: https://google.github.io/styleguide/cppguide.html "Google C++ Style Guide"
[ref-microsoft-cpp-style-guide]: https://learn.microsoft.com/en-us/dotnet/fundamentals/code-analysis/code-style-rule-options "Microsoft Coding Style Guide"
[ref-llvm-cpp-coding-standards]: https://llvm.org/docs/CodingStandards.html "LLVM Coding Standards"
[ref-mozilla-cpp-style-guide]: https://firefox-source-docs.mozilla.org/code-quality/coding-style/coding_style_cpp.html "Mozilla C++ Style Guide"
[ref-python-pep8]: https://peps.python.org/pep-0008/ "PEP 8: Style Guide for Python Code"
[ref-style-snake-case]: https://en.wikipedia.org/wiki/Snake_case "Snake case"
[ref-style-camel-case]: https://en.wikipedia.org/wiki/Camel_case "Camel case"
[ref-cpp-project-template]: https://github.com/hugorbarbosa/cpp-project-template "C++ project template"
[ref-cpp-development-tooling]: https://github.com/hugorbarbosa/cpp-learning/blob/main/topics/development_tooling/cpp_development_tooling.md "C++ development tooling"
