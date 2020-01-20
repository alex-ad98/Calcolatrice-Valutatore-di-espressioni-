#ifndef __EVALUATE_H__
#define __EVALUATE_H__

#include <vector>

struct Token;
int priority(char op);
int find_pivot(std::vector<Token>& tok, std::vector<int>& lay, int left, int right);
double evaluate(std::vector<Token>& tok, std::vector<int>& lay, int left, int right);

#endif
