#include <iostream> // for printing output
#include <cstdint> // for type detection
#include <cctype> // for type detection
#include "test.hpp"

std::string char_to_word(unsigned char c) {
    switch (c) {
        case 0: return "NULL";
        case 1: return "SOH";
        case 2: return "STX";
        case 3: return "ETX";
        case 4: return "EOT";
        case 5: return "ENQ";
        case 6: return "ACK";
        case 7: return "BEL";
        case 8: return "BS";
        case 9: return "TAB";
        case 10: return "LF";
        case 11: return "VT";
        case 12: return "FF";
        case 13: return "CR";
        case 14: return "SO";
        case 15: return "SI";
        case 16: return "DLE";
        case 17: return "DC1";
        case 18: return "DC2";
        case 19: return "DC3";
        case 20: return "DC4";
        case 21: return "NAK";
        case 22: return "SYN";
        case 23: return "ETB";
        case 24: return "CAN";
        case 25: return "EM";
        case 26: return "SUB";
        case 27: return "ESC";
        case 28: return "FS";
        case 29: return "GS";
        case 30: return "RS";
        case 31: return "US";
        case 32: return "SPACE";
        case 127: return "DEL";
        default:
            if (c > 127) {
                return "EXTENDED";
            } else {
                return "CTRL_CHAR";
            }
    }
}

void report(const int arr[], const int size) {
    uint8_t num {};
    for (int i = 0; i < size; ++i) {
        num = num * 10 + arr[i];
    }
    printf("%d - Original Value \n", num);
    if (std::isprint((unsigned char)num)) {
        printf("%c - ASCII \n", (unsigned char)num);
    } else {
        std::cout << char_to_word((unsigned char)num) << " - ASCII \n";
    }
    std::cout << std::uppercase << std::hex << (int)num << " - HEX \n";
    std::cout << to_bin(num) << " - Binary \n";
    printf("\n");
}

void report(const std::string str) {
    for (unsigned char x : str) {
        printf("%c - Character \n", x);
        printf("%d - Number(ASCII) \n",(unsigned int)x);
        std::cout << to_bin(x) << " - Binary \n";
        printf("\n");
    }
}

int main() {
    test();
    std::string input {};
    short counter {};
    std::cout << "Enter value: ";
    std::cin >> input;
    int Arr[input.length()];
    for (char x : input) {
        if (std::isdigit(x)) {
            Arr[counter] = x - '0'; // converts char to int
            counter++;
        }
    }
    if (counter == input.length()) {
        // for numbers
        report(Arr, input.length());
    }
    else if (counter == 0) {
        // for strings
        report(input);
    }
    else {
        std::cerr << "Enter only 1 kind of data! \n";
        std::cerr.flush();
        return -1;
    }
    return 0;
}
