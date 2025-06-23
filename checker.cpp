#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>
#include "include/json.hpp"  // <-- Do NOT use angle brackets

using json = nlohmann::json;

int main() {
    ::std::string password;
    ::std::getline(::std::cin, password);

    int hasDigit = 0, hasUpper = 0, hasSpecial = 0;
    const int minLength = 8;

    for (std::size_t i = 0; i < password.size(); ++i) {
        char c = password[i];
        if (std::isdigit(static_cast<unsigned char>(c))) hasDigit = 1;
        else if (::std::isupper(static_cast<unsigned char>(c))) hasUpper = 1;
        else if (!::isalnum(static_cast<unsigned char>(c))) hasSpecial = 1;
    }

    bool isStrong = password.length() >= minLength && hasDigit && hasUpper && hasSpecial;

    std::string summary;

    if (password.length() < minLength) {
        summary = "Password is too short.";
    } else if (!hasDigit) {
        summary = "Password should include digits.";
    } else if (!hasUpper) {
        summary = "Password should include uppercase letters.";
    } else if (!hasSpecial) {
        summary = "Password should include special characters.";
    } else {
        summary = "Your password looks strong!";
    }

    json result = {
        {"length", password.length()},
        {"hasDigit", hasDigit},
        {"hasUpper", hasUpper},
        {"hasSpecial", hasSpecial},
        {"isStrong", isStrong},
        {"summary", summary}   // <--- Included here
    };

    ::std::cout << result.dump() << ::std::endl;

    return 0;
}
