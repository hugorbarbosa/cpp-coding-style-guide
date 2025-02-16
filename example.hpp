/**
 * @file
 * @copyright Copyright (C) 2024 Hugo Barbosa.
 */

#ifndef CODING_STYLE_EXAMPLE_HPP
#define CODING_STYLE_EXAMPLE_HPP

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
    /// Data member.
    int data_member;
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
    /// Another data member.
    int another_data_member;
};

/**
 * @brief Struct example.
 */
struct MyStruct {
    /// Data member.
    int integer_data;
    /// Data member.
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

#endif // CODING_STYLE_EXAMPLE_HPP
