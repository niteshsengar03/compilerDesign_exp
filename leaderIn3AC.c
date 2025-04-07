#include <stdio.h>
#include <string.h>

// Global TAC array
char tac[100][100];

// Function to check if instruction is a jump
int isJump(int idx) {
    return strstr(tac[idx], "GOTO") || strstr(tac[idx], "goto") ||
           strstr(tac[idx], "IF") || strstr(tac[idx], "if");
}

// Extract jump target from line using sscanf
int extractTarget(int idx) {
    int num;
    if (sscanf(tac[idx], "%*[^0-9]%d", &num) == 1)
        return num - 1;
    return -1;
}

int main() {
    // Hardcoded TAC instructions
    strcpy(tac[0], "a = b + c");          // Line 1
    strcpy(tac[1], "if a < b goto 4");    // Line 2
    strcpy(tac[2], "d = a + b");          // Line 3
    strcpy(tac[3], "e = d + 1");          // Line 4
    strcpy(tac[4], "goto 7");             // Line 5
    strcpy(tac[5], "f = e + a");          // Line 6
    strcpy(tac[6],"a = b + c");           // line 7 
    strcpy(tac[7],"a = b + c");           // line 8


    int n = 8;
    int leader[100] = {0};

    // Rule 1: first line is always a leader
    leader[0] = 1;

    for (int i = 0; i < n; i++) {
        if (isJump(i)) {
            int target = extractTarget(i);
            if (target >= 0 && target < n)
                leader[target] = 1;

            if (i + 1 < n)
                leader[i + 1] = 1;
        }
    }

    // Print leader instructions
    printf("\nLeader Instructions:\n");
    for (int i = 0; i < n; i++) {
        if (leader[i])
            printf("Line %d: %s\n", i + 1, tac[i]);
    }

    return 0;
}
