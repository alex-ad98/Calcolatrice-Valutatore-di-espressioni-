#include <string>
#include "token.h"

Token::Token(char op) {
    operation = op;
    value = 0;
}

Token::Token(double val) {
    operation = '\0';
    value = val;
}

int check_operation(char c) {
    const std::string valid = "+-*/()";
    for (int i = 0; i < valid.size(); i++) {
        if (c == valid[i]) return true;
    }
    return false;
}
