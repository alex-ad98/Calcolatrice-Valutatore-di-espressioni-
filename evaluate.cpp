#include <climits>
#include <limits>
#include <iostream>
#include <vector>

#include "evaluate.h"
#include "token.h"

using namespace std;

int priority(char op) {
    switch(op) {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        case '\0':
            return 2;
        default:
            return -1;
    }
}

int find_pivot(vector<Token>& tok, vector<int>& lay, int left, int right) {
    int current_best_layer = INT_MAX;
    int current_best_priority = 3;
    int current_best_index = left;
    for (int i = right-1; i >= left; --i) {
        if (lay[i] < current_best_layer) {
            current_best_layer = lay[i];
            if(priority(tok[i].operation != -1)) current_best_priority = priority(tok[i].operation); //MODIFICA
            current_best_index = i;
        }
        else if (lay[i] == current_best_layer && (priority(tok[i].operation) != -1) < current_best_priority) { //MODIFICA
            current_best_priority = priority(tok[i].operation);
            current_best_index = i;
        }
    }

    return current_best_index;
}

double evaluate(vector<Token>& tok, vector<int>& lay, int left, int right) {
    int pivot = find_pivot(tok, lay, left, right);
    if (tok[pivot].operation == '\0') return tok[pivot].value;
    double result_left = evaluate(tok, lay, left, pivot);
    double result_right = evaluate(tok, lay, pivot+1, right);
    switch(tok[pivot].operation) {
        case '+':
            return result_left + result_right;
        case '-':
            return result_left - result_right;
        case '*':
            return result_left * result_right;
        case '/':
            return result_left / result_right;
        default:
            return numeric_limits<double>::quiet_NaN();
    }
}
