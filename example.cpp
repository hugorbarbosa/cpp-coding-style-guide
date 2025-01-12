/**
 * @file
 * @copyright Copyright (C) 2024 Hugo Barbosa.
 */

#include "example.h"
#include <string>

namespace coding_style {
namespace some_namespace {

MyClass::MyClass(const int data)
    : data_member{data}
{
}

MyDerivedClass::MyDerivedClass(const int data)
    : MyClass(data)
    , another_data_member{data + 1}
{
}

/**
 * @brief Function example.
 *
 * @param int_par Integer parameter example.
 * @param enum_par Enum parameter example.
 */
void do_something(const int int_par, const MyEnum enum_par) noexcept
{
    // The statements here are only to verify the layout style ("if" conditions, loops, etc.).

    const auto lambda_example = []() {
        // Do something.
    };

    if (int_par < 0) {
        lambda_example();
    }
    else if (int_par == 0) {
        // Do something.
    }
    else {
        // Do something different.
    }

    for (auto i = 0; i < 10; ++i) {
        // Do something.
    }

    bool flag{false}; // A trailing comment example.
    while (!flag) {
        lambda_example(); // A very long trailing comment example, just to see how it is formatted
                          // when has multiple lines.
        flag = true;
    }

    // A very long comment, just to see how it is formatted when has multiple lines. Bla bla bla bla
    // bla.

    switch (enum_par) {
    case MyEnum::first_enumerator:
        lambda_example();
        break;
    case MyEnum::second_enumerator: {
        int local_var{0};
        lambda_example();
        ++local_var;
        break;
    }
    default:
        break;
    }
}

} // namespace some_namespace
} // namespace coding_style
