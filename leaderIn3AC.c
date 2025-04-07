#include <stdio.h>
#include <string.h>

#define MAX 100

int isJump(const char *line) {
    return strstr(line, "GOTO") || strstr(line, "goto") || strstr(line, "IF") || strstr(line, "if");
}

// Extract target line number from jump statements like "if a < b goto 4" or "goto 6"
int extractTarget(const char *line) {
    int num;
    if (sscanf(line, "%*[^0-9]%d", &num) == 1)
        return num - 1;  // Convert to 0-based index
    return -1;
}

int main() {
    // Hardcoded TAC instructions
    char tac[MAX][MAX] = {
        "a = b + c",            // Line 1
        "if a < b goto 4",      // Line 2
        "d = a + b",            // Line 3
        "e = d + 1",            // Line 4
        "goto 6",               // Line 5
        "f = e + a"             // Line 6
    };
    int n = 6;
    int leader[MAX] = {0};

    // Rule 1: First instruction is a leader
    leader[0] = 1;

    for (int i = 0; i < n; i++) {
        if (isJump(tac[i])) {
            // Rule 2: Mark the jump target as a leader
            int target = extractTarget(tac[i]);
            if (target >= 0 && target < n)
                leader[target] = 1;

            // Rule 3: Mark the instruction following the jump as a leader
            if (i + 1 < n)
                leader[i + 1] = 1;
        }
    }

    // Print leaders
    printf("\nLeader Instructions:\n");
    for (int i = 0; i < n; i++) {
        if (leader[i])
            printf("Line %d: %s\n", i + 1, tac[i]);
    }

    return 0;
}