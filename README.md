# C++ Coding Style Guide

This project presents some C++ coding styles that are often used on C++ projects, and contains my C++ coding style guide.

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
    - [Comments usage](#comments-usage)
    - [Comment style](#comment-style)
    - [TODO comments](#todo-comments)
    - [Documentation](#documentation)
- [Formatting](#formatting)
    - [Line length](#line-length)
    - [Spaces vs tabs](#spaces-vs-tabs)
    - [Layout style](#layout-style)
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
    - [Clang-format](#clang-format)
    - [Clang-tidy](#clang-tidy)
    - [Doxygen](#doxygen)
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

- [**C++ Core Guidelines**][ref-cpp-core-guidelines]: collection of guidelines written by Bjarne Stroustrup, the creator of C++, along with other C++ experts. It is a set of guidelines for using C++ well, intended to help people to use modern C++ effectively. These guidelines are focused on relatively high-level issues, such as interfaces, resource management, memory management, and concurrency.
- [**Google C++ Style Guide**][ref-google-cpp-style-guide]: comprehensive style guide used across Google's codebase. It covers various topics like naming conventions, function design, and performance optimization.
- [**Microsoft Coding Style Guide**][ref-microsoft-cpp-style-guide]: coding style guide of Microsoft. It contains many coding style rules on code formatting and naming conventions.
- [**LLVM Coding Standards**][ref-llvm-cpp-coding-standards]: set of conventions used by the LLVM project, focusing on consistency and the clarity of code, particularly for large projects. It includes detailed rules on indentation, function declarations, and code organization.
- [**Mozilla C++ Style Guide**][ref-mozilla-cpp-style-guide]: style guide used for code written within the Mozilla project. It includes guidelines on code organization, documentation, and how to structure complex systems.

### My C++ coding style guide

This document describes my personal C++ coding style guide, reflecting my preferences and practices. It is not meant to be exhaustive and its focus is *not* on how to use C++ effectively, for that I highly recommend exploring the [C++ Core Guidelines][ref-cpp-core-guidelines], which is an excellent resource for mastering modern C++ practices and writing clean and efficient code. Instead, this guide highlights some conventions I follow in my C++ projects regarding coding layout style, naming conventions, indentation, etc.

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

Another option is using [`snake_case`][ref-style-snake-case], i.e., lowercase and with underscores to separate words, as the C++ Standard Library usually applies.

To better differentiate user-defined types from the Standard Library types, it can be used upper case only on the first letter and keeping underscore (e.g., `My_type`), as mentioned in the [C++ Core Guidelines][ref-cpp-core-guidelines].

```c++
// Using snake_case.
class my_class {
    // ...
};

// Using snake_case but with first letter in upper case.
class My_class {
    // ...
};
```

Choose only one style and be consistent within a project.

### Variables

Variables (including function parameters) and data members of classes and structs are in `snake_case`:

```c++
int a_variable{0};

class MyClass {
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
private:
    int dataMember;
};
```

An aspect that is often seen in C++ projects in variable names is the usage of prefixes and suffixes. For class private data members, it is common adding the suffix `_` or prefixes like `m_` or just `m` (`m` is more common when using `camelCase`):

```c++
class MyClass {
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
public:
    void a_member_function(const int a_parameter);
};
```

Another possibility is using `camelCase` or `PascalCase` for naming functions:

```c++
// Using camelCase.
void anotherFreeFunction();

class MyClass {
public:
    // Using PascalCase.
    void AnotherMemberFunction();
};
```

Choose only one style and be consistent within a project.

### Enumerators

Enumerators (for both scoped and unscoped enums) should use `snake_case`:

```c++
enum class MyEnum {
    first_enumerator = 0,
    second_enumerator,
};
```

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

Choose only one style and be consistent within a project.

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

Macro names should use `ALL_CAPS`, since this is the convention for macros, and helps for readability and to distinguish macros:

```c++
#define START_CODE 1
```

However, macros are a major source of bugs, since they don't obey the usual scope and type rules. Prefer to use the Modern C++ features instead, like `constexpr` for example, if possible.

### Files and directories

Names of files and directories should be all lowercase and include underscores (`_`) to separate words.

Examples:

- `my_class.cpp`
- `my_class.h`
- `a_directory/my_struct.h`

For files relative to tests, use a prefix correspondent to the testing level:

- Unit test file related to `my_class`: `ut_my_class.cpp`
- Integration test file: `it_something.cpp`
- System test file: `st_something.cpp`
- Mock related to `my_class`: `mock_my_class.h`

## Comments and documentation

### Comments usage

Comments are important to state intent more clearly to the reader. It should contain details to help understand a particular part of code, but don't comment what can be easily extracted from the code. While comments are very important, the best code is self-documenting.

### Comment style

Comment using either the `//` or `/* */` syntax, as long as consistency is maintained:

```c++
// This is a comment.
// This is a multi-line
// comment.

/* This is a comment. */
/*
 * This is a multi-line
 * comment.
 */
```

### TODO comments

A TODO comment should be used when something needs to be done or changed in the future. Examples of this can be some feature or functionality that should be changed or is missing; and a particular code that is temporary, being a short-term solution.

Its format should contain the "TODO" text, followed by the issue/bug ID, a name or other identifier that contains the problem referenced by the TODO:

```c++
void a_function()
{
    // TODO Issue-42: Avoid copies performed here.
    // ...
}
```

### Documentation

It is very useful to document the source code in a format that is understandable by a tool, allowing the verification and parsing of the documentation automatically. For that purpose, document the source code using the format supported by Doxygen (see [Tools](#tools) section).

Examples:

- For files, start with the documentation as shown in the following example:
    ```c++
    /**
     * @file
     * @copyright Copyright (C) 2024 <Author/Company>. All rights reserved.
     */
    // ...
    ```
- For classes/structs and member/free functions:
    ```c++
    /**
     * @brief Adds the provided two integers.
     *
     * @param first_integer First integer to add.
     * @param second_integer Second integer to add.
     *
     * @return Sum of the two integers.
     */
    int add_two_numbers(const int first_integer, const int second_integer);

    /**
     * @brief My class.
     */
    class MyClass {
    public:
        /**
         * @brief Sets the value of data.
         * 
         * This function verifies if the data can be updated or not.
         * 
         * @param new_value New data value.
         *
         * @return True if the data value was successfully updated, false otherwise.
         */
        bool set_data(const int new_value);
    private:
        /// Data member example.
        int data_member;
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
     * @brief Adds the provided two parameters.
     *
     * @tparam T Data type.
     * @param first First parameter to add.
     * @param second Second parameter to add.
     *
     * @return Sum of the two parameters.
     */
    template<typename T>
    T add_two_numbers(const T first, const T second);

    /**
     * @brief My class.
     *
     * @tparam T Data member type.
     */
    template<typename T>
    class MyClass {
    private:
        /// Data member example.
        T data_member;
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

Ensuring that the code always has the desired format is a very difficult and error-prone task. Thus, it is highly recommended to use a tool that automatically checks and formats the code (see [Tools](#tools) section).

### Line length

Each line of code should be at most 100 characters long. A line may exceed this maximum value only in some exceptional cases (e.g., when a literal URL is longer than that value).

### Spaces vs tabs

Use only spaces, and use 4 spaces for indentation.

Tabs should not be used in code, to ensure that the alignment and number of spaces are consistent independently of the IDE / code editor used.

Furthermore, it is recommended to configure the IDE/editor to emit spaces when pressing the tab key.

### Layout style

The Kernighan & Ritchie (K&R) style is commonly used for C and C++ code, because it preserves vertical space well, and helps to easily distinguish different language constructs, such as functions and classes.

When adding conventions for constructs not found in C, that becomes what is often called as "Stroustrup" style, being this style suggested by the [C++ Core Guidelines][ref-cpp-core-guidelines].

Example:

```c++
namespace some_namespace { // Brace in the same line for namespaces.

// The declarations inside of the namespace should not be indented.

class B : public A { // Brace in the same line for classes/structs/enums.
public: // No indentation.
    // ...
};

void some_function()
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

**Note:** use always braces as shown in the example for `if`s, `for`s, `while`s, etc., to avoid eventual bugs if more code is added later that should be executed inside of a condition/loop statement.

## Header files

### Include guards

To avoid multiple inclusion, the header files should have `#define` guards. Additionally, to avoid include guards collision, the guard must be unique. For that purpose, the format of the guard name can be something like `<PROJECT>_<FILE_NAME>_H`:

```c++
// File "foo/src/bar.h":
#ifndef FOO_BAR_H
#define FOO_BAR_H
// Declarations...
#endif // FOO_BAR_H
```

Some implementations offer vendor extensions like `#pragma once` as alternative to `#define` guards. However, note that this is not standard and is not portable.

### Using namespaces

Don't write `using namespace` at global scope in a header file, because it exposes this `using namespace` to all files that include this header file:

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
    // ...
    void a_member_function();
};

}

#include "my_class.ipp" // Header file includes the .ipp file.

// my_class.ipp

namespace project_name {

template<typename T>
void MyClass<T>::a_member_function()
{
    // ...
}

}
```

## Classes and structs

### Classes vs structs

If any member is non-public, use `class` rather than `struct`:

```c++
struct Example {
    int x;
    int y;
private:
    int z; // Private member: "Example" should be declared as class instead.
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

Declare the access for member functions and for data, independently if it is the same, like the following example:

```c++
class X {
public:
    void a_function();

private:
    void another_function();

public: // Declare access for this data member and don't place together with the public member functions.
    int data;

private:
    int another_data;
};
```

## Type deduction

### `auto` usage

Do not use `auto` only to avoid the inconvenience of writing an explicit type. Use `auto` in case if it makes the code clearer to readers or if it makes the code safer.

## Aliases

### `using` vs `typedef`

Prefer `using` in C++ code instead of `typedef`:

```c++
using Bar = Foo;
typedef Foo Bar; // But prefer `using` instead.
```

## Tools

### Clang-format

Clang-format is a tool that can be used to format C++, C, C#, Java, JavaScript, JSON, Objective-C and Protobuf code. This tool can be utilized in a variety of ways, including as a standalone tool and integrated in a IDE/editor.

Clang-format supports many options that can be found using the `--help` option:

```sh
$ clang-format --help
```

This tool allows you to directly apply a predefined code style, based on styles such as Google, Microsoft, among others. This base style can be adjusted to your needs or, if necessary, a style can be completely configured with the desired style options. All these style options permitted by clang-format can be found in [clang-format style options][ref-tool-clang-format-style-options].

To exemplify how to use clang-format, this guide uses the following:

- Code sample files ([header](./example.h) and [implementation](./example.cpp)) that contain some code that will be formatted using this tool.
- A clang-format [configuration file](./.clang-format) that includes the desired style options.

As previously mentioned, clang-format can be integrated in a IDE/editor and we will use Visual Studio Code as editor example in this guide. It is only necessary to install the [C/C++ extension][ref-vscode-cpp-extension], which allows configuring and using clang-format from this editor. Additionally, you can configure to format automatically the code when saving a file, using the [settings](./.vscode/settings.json) file available in this guide as example.

Feel free to use the code sample files to do some experiments and verify that the code is automatically formatted when you save it, keeping it always with the intended style.

Refer to the [clang-format page][ref-tool-clang-format] for more details regarding this tool. To see this tool being used in a project, consult the [C++ project template][ref-cpp-project-template] as example.

### Clang-tidy

Clang-tidy is a clang-based C++ "linter" tool, that provides an extensible framework for diagnosing and fixing typical programming errors, like interface misuse or bugs, that can be deduced via static analysis. It can be utilized as a standalone tool or integrated in a IDE/editor.

Clang-tidy supports many options that can be found using the `--help` option:

```sh
$ clang-tidy --help
```

This tool allows you to specify various check options based on groups through a name prefix, such as `cppcoreguidelines-` that performs checks related to C++ Core Guidelines. All check options permitted by clang-tidy can be found in [clang-tidy checks][ref-tool-clang-tidy-checks].

As previously mentioned, clang-tidy can be integrated in a IDE/editor. The [C/C++ extension][ref-vscode-cpp-extension] needs to be installed for configuring and using clang-tidy from this editor. Additionally, you can configure to analyze automatically the code when saving a file, using the [settings](./.vscode/settings.json) file available in this guide as example.

Refer to the [clang-tidy page][ref-tool-clang-tidy] for more details regarding this tool. To see this tool being used in a project, consult the [C++ project template][ref-cpp-project-template] as example.

### Doxygen

Doxygen is a documentation generator tool that automates the creation of documentation from source code comments, supporting C++, C, C#, Python, PHP, Java, Objective-C, Fortran, VHDL, Splice, IDL, and Lex code. The documentation can be generated in various output formats, such as HTML and PDF. Additionally, this tool is able to generate graphical representations of class hierarchies and collaboration diagrams, providing a visual overview of the relationships between classes and functions.

Doxygen supports many options that can be found using the `--help` option:

```sh
$ doxygen --help
```

This tool provides a configuration file (Doxyfile) that permits users to customize the documentation generation process. The format of the comments needs to follow the one presented in the [Documentation](#documentation) section.

Refer to the [Doxygen page][ref-tool-doxygen] for more details regarding this tool. To see this tool being used in a project, consult the [C++ project template][ref-cpp-project-template] as example.

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
- [Clang-format][ref-tool-clang-format]
- [Clang-format style options][ref-tool-clang-format-style-options]
- [Clang-tidy][ref-tool-clang-tidy]
- [Clang-tidy checks][ref-tool-clang-tidy-checks]
- [Doxygen][ref-tool-doxygen]
- [Visual Studio Code C++ extension][ref-vscode-cpp-extension]
- [C++ project template][ref-cpp-project-template]

[ref-cpp-core-guidelines]: https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md "C++ Core Guidelines"
[ref-cpp-bs-tech-faq]: https://www.stroustrup.com/bs_faq2.html "Bjarne Stroustrup: C++ Style and Technique FAQ"
[ref-cpp-bs-ppp-style]: https://www.stroustrup.com/Programming/PPP-style.pdf "Bjarne Stroustrup: PPP Style Guide"
[ref-google-cpp-style-guide]: https://google.github.io/styleguide/cppguide.html "Google C++ Style Guide"
[ref-microsoft-cpp-style-guide]: https://learn.microsoft.com/en-us/dotnet/fundamentals/code-analysis/code-style-rule-options "Microsoft Coding Style Guide"
[ref-llvm-cpp-coding-standards]: https://llvm.org/docs/CodingStandards.html "LLVM Coding Standards"
[ref-mozilla-cpp-style-guide]: https://firefox-source-docs.mozilla.org/code-quality/coding-style/coding_style_cpp.html "Mozilla C++ Style Guide"
[ref-python-pep8]: https://peps.python.org/pep-0008/ "PEP (Python Enhancement Proposal) 8: Style Guide for Python Code"
[ref-style-snake-case]: https://en.wikipedia.org/wiki/Snake_case "Snake case"
[ref-style-camel-case]: https://en.wikipedia.org/wiki/Camel_case "Camel case"
[ref-tool-clang-format]: https://clang.llvm.org/docs/ClangFormat.html "Clang-format"
[ref-tool-clang-format-style-options]: https://clang.llvm.org/docs/ClangFormatStyleOptions.html "Clang-format style options"
[ref-tool-clang-tidy]: https://clang.llvm.org/extra/clang-tidy/ "Clang-tidy"
[ref-tool-clang-tidy-checks]: https://clang.llvm.org/extra/clang-tidy/checks/list.html "Clang-tidy checks"
[ref-tool-doxygen]: https://www.doxygen.nl/ "Doxygen"
[ref-vscode-cpp-extension]: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools "Visual Studio Code C++ extension"
[ref-cpp-project-template]: https://github.com/hugorbarbosa/cpp-project-template "C++ project template"
