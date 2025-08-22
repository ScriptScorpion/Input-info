#pragma once
#include <iostream>
std::string to_bin (unsigned char c) {
    std::string binary = "";
    while (c > 0) {
        binary = std::to_string((int)c % 2) + binary;
        c = c / 2;
    }
    return binary.empty() ? "0" : binary;
}
std::string to_bin(int n) {
    std::string binary = "";
    while (n > 0) {
        binary = std::to_string(n % 2) + binary;
        n = n / 2;
    }
    return binary.empty() ? "0" : binary;
}
void test() {
    if (to_bin('a') == "1100001") {
        std::cout << "1 Test passed! \n";
    }
    else {
        std::cout << "1 Test not passed \n\n";
        return;
    }
    if (to_bin(10) == "1010") {
        std::cout << "2 Test passed! \n\n";
    }
    else {
        std::cout << "2 Test not passed \n\n";
        return;
    }

}
