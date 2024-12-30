/**
 * @file
 * @copyright Copyright (C) 2024 Hugo Barbosa. All rights reserved.
 */

#include "example.h"
#include <string>

namespace coding_style {
namespace some_namespace {

MyClass::MyClass(const int data)
    : data_{data}
{
}

MyDerivedClass::MyDerivedClass(const int data)
    : MyClass(data)
    , another_data_{data + 1}
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
    // The statements here are only to verify the layout style for each one of them (if, for, etc.).

    constexpr auto do_something = []() {
        // Do something.
    };

    if (int_par < 0) {
        do_something();
    }
    else if (int_par == 0) {
        do_something();
    }
    else {
        do_something();
    }

    for (auto i = 0; i < 10; ++i) {
        do_something();
    }

    bool flag{false}; // A trailing comment example.
    while (!flag) {
        do_something(); // A very long trailing comment example, just to see how it is formatted
                        // when has multiple lines.
        flag = true;
    }

    // A very long comment, just to see how it is formatted when has multiple lines. Bla bla bla bla
    // bla.

    switch (enum_par) {
    case MyEnum::first_enumerator:
        do_something();
        break;
    case MyEnum::second_enumerator: {
        int local_var{0};
        do_something();
        ++local_var;
        break;
    }
    default:
        break;
    }
}

} // namespace some_namespace
} // namespace coding_style
