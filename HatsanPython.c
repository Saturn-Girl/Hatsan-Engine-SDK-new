#include<stdio.h>
#include <stdbool.h>


int main() {
    printf("[INFO] HatsanPlayer initialized.\n");
    return 0;
}
// Simple c function to check variable and that is fine ; )

void Python() {
    bool IsPython = true;
    if (IsPython) {
        printf("[INFO] python is enabled.\n");
    }else{
        printf("[ERROR] python is NOT enabled.\n");
    }
}
void CheckVavlue() {
    printf("[INFO] checking value...\n");
    int value = 42;
    if (value == 42) {
        printf("[INFO] value is correct: %d\n", value);
    }else{
        printf("[ERROR] value is incorrect: %d/n",value);
    }
}

void Log() {
    printf("[INFO] logging function initialized\n");
}
