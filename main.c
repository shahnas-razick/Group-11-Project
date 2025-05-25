#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 50

// login function
int authenticateUser(int userType, char* userId, char* password) {
    FILE* file = fopen("./data/users.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open users file\n");
        return 0;
    }

    char line[256];
    int storedType;
    char storedId[MAX_LENGTH], storedPass[MAX_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%[^,],%[^\n]", &storedType, storedId, storedPass);
        
        if (storedType == userType && 
            strcmp(storedId, userId) == 0 && 
            strcmp(storedPass, password) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void displayMenu() {
    printf("\n=== Medical Record System Login ===\n");
    printf("1. Admin\n");
    printf("2. Doctor\n");
    printf("3. Lab Assistant\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}
int main(){

}