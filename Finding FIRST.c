#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 20
#define MAX_TERMINALS 10

// Function prototypes
int isTerminal(char symbol);
void addToSet(char *set, char symbol);
int isInSet(char *set, char symbol);
void calculateFirstSet(char grammar[][MAX_SYMBOLS], int numRules, char nonTerminals[], int numNonTerminals, char firstSets[][MAX_TERMINALS]);

int main() {
    // Grammar: Representing productions in the form of A->AB or A->a
    char grammar[MAX_RULES][MAX_SYMBOLS] = {
        "S->AB",
        "A->a",
        "A->ε",
        "B->b",
        "C->c"
    };

    // Non-terminals in the grammar
    char nonTerminals[] = {'S', 'A', 'B', 'C'};

    int numRules = 5;  // Number of production rules
    int numNonTerminals = 4;  // Number of non-terminals

    // Array to store FIRST sets
    char firstSets[MAX_RULES][MAX_TERMINALS] = {0};

    // Compute the FIRST sets
    calculateFirstSet(grammar, numRules, nonTerminals, numNonTerminals, firstSets);

    // Print the FIRST sets
    for (int i = 0; i < numNonTerminals; i++) {
        printf("FIRST(%c) = { ", nonTerminals[i]);
        for (int j = 0; j < strlen(firstSets[i]); j++) {
            printf("%c ", firstSets[i][j]);
        }
        printf("}\n");
    }

    return 0;
}

// Function to check if a symbol is a terminal
int isTerminal(char symbol) {
    // Terminals are lowercase letters, for simplicity, we assume only lowercase as terminals
    return (symbol >= 'a' && symbol <= 'z');
}

// Add a symbol to the FIRST set if not already present
void addToSet(char *set, char symbol) {
    if (!isInSet(set, symbol)) {
        int len = strlen(set);
        set[len] = symbol;
        set[len + 1] = '\0';
    }
}

// Check if a symbol is already in the set
int isInSet(char *set, char symbol) {
    for (int i = 0; i < strlen(set); i++) {
        if (set[i] == symbol) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate FIRST sets for each non-terminal in the grammar
void calculateFirstSet(char grammar[][MAX_SYMBOLS], int numRules, char nonTerminals[], int numNonTerminals, char firstSets[][MAX_TERMINALS]) {
    // Iterate over each non-terminal
    for (int i = 0; i < numNonTerminals; i++) {
        char nonTerminal = nonTerminals[i];

        // Go through each production rule
        for (int j = 0; j < numRules; j++) {
            // Check if the rule starts with the current non-terminal
            if (grammar[j][0] == nonTerminal) {
                // Get the production part (right-hand side)
                char *production = &grammar[j][3];  // Skip "A->" part, start with the right-hand side

                // Process each symbol in the production
                for (int k = 0; k < strlen(production); k++) {
                    char symbol = production[k];

                    if (isTerminal(symbol)) {
                        // If it's a terminal, add it to the FIRST set of the non-terminal
                        addToSet(firstSets[i], symbol);
                        break;  // We only add the first terminal we encounter
                    } else {
                        // If it's a non-terminal, add its FIRST set to the current FIRST set
                        int nonTerminalIndex = -1;
                        for (int m = 0; m < numNonTerminals; m++) {
                            if (nonTerminals[m] == symbol) {
                                nonTerminalIndex = m;
                                break;
                            }
                        }

                        // If the symbol is a non-terminal, add its FIRST set
                        if (nonTerminalIndex != -1) {
                            for (int n = 0; n < strlen(firstSets[nonTerminalIndex]); n++) {
                                addToSet(firstSets[i], firstSets[nonTerminalIndex][n]);
                            }
                        }

                        // If the non-terminal can derive epsilon, continue to the next symbol
                        if (isInSet(firstSets[i], 'ε')) {
                            continue;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
}
