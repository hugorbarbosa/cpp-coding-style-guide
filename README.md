# C++ Coding Style Guide

This project mentions some C++ coding styles that are often used on C++ projects, and contains my C++ coding style guide.

## Table of contents

// TODO: Update.

- [Introduction](#introduction)
    - 
- [Coding style guide](#coding-style-guide)
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

There's no "official" coding style guide for C++, as we have for [Python][ref-python-pep8] for example. However, there are several widely-recognized C++ coding style guides used in the industry. Below are some of the most popular ones:

- **[C++ Core Guidelines][ref-cpp-core-guidelines]**: collection of guidelines written by Bjarne Stroustrup, the creator of C++, along with other C++ experts. It is a set of guidelines for using C++ well, intended to help people to use modern C++ effectively. These guidelines are focused on relatively high-level issues, such as interfaces, resource management, memory management, and concurrency.
- **[Google C++ Style Guide][ref-google-cpp-style-guide]**: comprehensive style guide used across Google's codebase. It covers various topics like naming conventions, function design, and performance optimization.
- **[LLVM Coding Standards][ref-llvm-cpp-coding-standards]**: set of conventions used by the LLVM project, focusing on consistency and the clarity of code, particularly for large projects. It includes detailed rules on indentation, function declarations, and code organization.
- **[Mozilla C++ Style Guide][ref-mozilla-cpp-style-guide]**: style guide used for code written within the Mozilla project. It includes guidelines on code organization, documentation, and how to structure complex systems.

It is relevant to mention that a C++ coding guide may provide a set of coding rules only for a particular environment. There's no C++ coding standard for all uses and all users. What is important is to be **consistent** within a project, and follow the coding style guide for a given application/project, independently of personal preferences.

## Coding style guide

The following is my personal C++ coding style guide, reflecting my preferences and practices. It is not meant to be exhaustive and its focus is *not* on how to use C++ effectively, for that I highly recommend exploring the [C++ Core Guidelines][ref-cpp-core-guidelines], which is an excellent resource for mastering modern C++ practices and writing clean and efficient code. Instead, it highlights some conventions I follow in my C++ projects regarding coding layout style, naming conventions, indentation, etc. There may be additional considerations or exceptions depending on the project's needs and context.

Please note that this coding style guide may not be suitable for every project and should be adapted as needed to meet specific project requirements. It just contains my preferences and conventions that I try to follow in my personal projects and in projects without any established coding standard/style.

This is a non-closed document and may evolve and improve whenever necessary.

// TODO: Complete and continue analysis from https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#sf-source-files.

### Classes and structs

**Use `class` rather than `struct` if any member is non-public**

If the `struct` has some member that is non-public, it should defined as `class` instead.

Example:

```c++
struct Example {
    int x;
    int y;
private:
    int z; // Private member: Example should be defined as class.
};
```

### `auto` usage

**Use **

### Header files

### Naming conventions

- Prefixes and suffixes
- Classes and structs (private and public members)
- Templates
- Aliases

#### Enumerations

**Don't use ALL_CAPS to avoid clashes with macros**

Example:
```c++
#define START 1
#define STOP 2

enum class Step { START, STOP };
```

#### Macros

**Use ALL_CAPS for macros (only)**

This is the convention for macros, and helps for readability and to distinguish macros.

Example:
```c++
#define start 1 // Wrong
#define START 1 // Good
```

**Avoid the usage of macros**

Macros are a major source of bugs, since they don't obey the usual scope and type rules. Prefer to use the Modern C++ features instead, like `constexpr` for example.

#### Files and directories

### Indentation

if, switch-case, for

## Tools

- clang-format
- clang-tidy

## License

Licensed under the [MIT license](./LICENSE).

## References

- [C++ Core Guidelines][ref-cpp-core-guidelines]
- [Bjarne Stroustrup's C++ Style and Technique FAQ][ref-cpp-bs-tech-faq]
- [Google C++ Style Guide][ref-google-cpp-style-guide]
- [LLVM Coding Standards][ref-llvm-cpp-coding-standards]
- [Mozilla C++ Style Guide][ref-mozilla-cpp-style-guide]
- [PEP (Python Enhancement Proposal) 8: Style Guide for Python Code][ref-python-pep8]

[ref-cpp-core-guidelines]: https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md "C++ Core Guidelines"
[ref-cpp-bs-tech-faq]: https://www.stroustrup.com/bs_faq2.html "Bjarne Stroustrup's C++ Style and Technique FAQ"
[ref-google-cpp-style-guide]: https://google.github.io/styleguide/cppguide.html "Google C++ Style Guide"
[ref-llvm-cpp-coding-standards]: https://llvm.org/docs/CodingStandards.html "LLVM Coding Standards"
[ref-mozilla-cpp-style-guide]: https://firefox-source-docs.mozilla.org/code-quality/coding-style/coding_style_cpp.html "Mozilla C++ Style Guide"
[ref-python-pep8]: https://peps.python.org/pep-0008/ "PEP (Python Enhancement Proposal) 8: Style Guide for Python Code"
