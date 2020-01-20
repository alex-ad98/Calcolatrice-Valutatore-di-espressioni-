#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <limits>
#include <iostream>
#include <vector>

#include "evaluate.h"
#include "token.h"

//#define DEBUG 1

using namespace std;

int main() {
    cout << "Inserisci espressione da valutare: " << endl;
    vector<Token> tokens;
    //cin >> ws;
    char c = cin.peek();
    while (c != '\n') {
        if (isdigit(c)) {
            double n;
            cin >> n;
            tokens.push_back(Token(n));
        }
        else {
            if (!check_operation(c)) {
                cout << "Errore di sintassi, carattere '" << c << "' non riconosciuto." << endl;
                return EXIT_FAILURE;
            }
            tokens.push_back(Token(c));
            cin.ignore(1);
        }
        //cin >> ws;
        c = cin.peek();
    }

#if DEBUG
    for (int i = 0; i < tokens.size(); i++) {
        cout << tokens[i].value << "\t" << (char)tokens[i].operation << endl; //MODIFICA
    }
#endif

    vector<int> layers;
    vector<Token> tokens_new; // without '(', ')'
    int l = 0; // current layer
    for (int i = 0; i < tokens.size(); ++i) {
        char op = tokens[i].operation;
        if(op == '\0' || op == '(') {
            l++;
        }
        else {
            l--;
        }
        if (op != '(' && op != ')') {
            tokens_new.push_back(tokens[i]);
            layers.push_back(l);
        }
    }

    double result = evaluate(tokens_new, layers, 0, tokens_new.size());
    cout << "Il risultato è " << result << endl;

#if DEBUG
    for (int i = 0; i < tokens_new.size(); i++) {
        cout << "value = " << tokens_new[i].value << "\toperation = " << tokens_new[i].operation << "\tlayer = " << layers[i] << endl;
    }
#endif

    return EXIT_SUCCESS;
}
