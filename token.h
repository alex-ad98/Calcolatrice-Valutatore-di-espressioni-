#ifndef __TOKEN_H__
#define __TOKEN_H__

struct Token {
    char operation;
    double value;
    Token(char op);
    Token(double val);
};

int check_operation(char c);

#endif
