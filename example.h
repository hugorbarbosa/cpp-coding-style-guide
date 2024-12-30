/**
 * @file
 * @copyright Copyright (C) 2024 Hugo Barbosa. All rights reserved.
 */

#ifndef CODING_STYLE_EXAMPLE_H
#define CODING_STYLE_EXAMPLE_H

namespace coding_style {
namespace some_namespace {

/**
 * @brief Class example.
 */
class MyClass {
public:
    /**
     * @brief Constructor.
     *
     * @param data Data value.
     */
    MyClass(const int data) noexcept;

private:
    /// Data member example.
    int data_;
};

/**
 * @brief Derived class example.
 */
class MyDerivedClass : public MyClass {
public:
    /**
     * @brief Constructor.
     *
     * @param data Data value.
     */
    MyDerivedClass(const int data) noexcept;

private:
    /// Another data member example.
    int another_data_;
};

/**
 * @brief Struct example.
 */
struct MyStruct {
    /// Data member example.
    int integer_data;
    /// Data member example.
    double double_data;
};

/**
 * @brief Enum example.
 */
enum class MyEnum {
    /// Enumerator example.
    first_enumerator,
    /// Enumerator example.
    second_enumerator
};

} // namespace some_namespace
} // namespace coding_style

#endif // CODING_STYLE_EXAMPLE_H
