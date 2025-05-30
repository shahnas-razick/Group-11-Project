#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 50

struct Patient
{
    char NIC[13];        // National Identity Card number
    char name[50];       // Patient's full name
    int age;             // Patient's age
    char address[100];   // Patient's address
    char contact_no[15]; // Patient's contact number
};

// Function to Login user
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

// Function to display menu
void displayMenu() {

    printf("\x1b[34m  _      _____ ______ ______    _____          _____  ______ \n");
    printf(" | |    |_   _|  ____|  ____|  / ____|   /\\   |  __ \\|  ____|\n");
    printf(" | |      | | | |__  | |__    | |       /  \\  | |__) | |__   \n");
    printf(" | |      | | |  __| |  __|   | |      / /\\ \\ |  _  /|  __|  \n");
    printf(" | |____ _| |_| |    | |____  | |____ / ____ \\| | \\ \\| |____ \n");
    printf(" |______|_____|_|    |______|  \\_____/_/    \\_\\_|  \\_\\______|\x1b[0m\n");
    printf("\n\x1b[31mWelcome to Life Care - A Medical Record Management System\x1b[0m\n\n");


    printf("\n\x1b[31m=== Login ===\n");
    printf("\x1b[33m1. Admin\n");
    printf("2. Doctor\n");
    printf("3. Lab Assistant\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}


void addPatient()
{
    struct Patient patient;
    FILE *file = fopen("./data/patients.txt", "a");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter patient details:\n");
    printf("NIC (12 digits): ");
    scanf("%s", patient.NIC);

    printf("Full Name: ");
    getchar(); // Clear buffer
    fgets(patient.name, sizeof(patient.name), stdin);
    patient.name[strcspn(patient.name, "\n")] = 0; // Remove newline

    printf("Age: ");
    scanf("%d", &patient.age);

    printf("Address: ");
    getchar(); // Clear buffer
    fgets(patient.address, sizeof(patient.address), stdin);
    patient.address[strcspn(patient.address, "\n")] = 0; // Remove newline

    printf("Contact Number: ");
    scanf("%s", patient.contact_no);

    fprintf(file, "%s,%s,%d,%s,%s\n",
            patient.NIC,
            patient.name,
            patient.age,
            patient.address,
            patient.contact_no);

    fclose(file);
    printf("\nPatient added successfully!\n");
}


int main()
{
    int choice;
    char userId[MAX_LENGTH];
    char password[MAX_LENGTH];

    while (1)
    {
        system("cls"); // Clear screen
        displayMenu();
        scanf("%d", &choice);

        if (choice == 4)
        {
            printf("\nThank you for using the system.\x1b[0m\n");
            break;
        }

        if (choice >= 1 && choice <= 3)
        {
            printf("Enter User ID: ");
            scanf("%s", userId);
            printf("Enter Password: ");
            scanf("%s", password);

            if (authenticateUser(choice, userId, password))
            {
                printf("\nLogin Successful!\n");
                printf("Welcome to Medical Record System\n");
                int adminChoice;
                if (choice == 1)
                {
                    adminChoice = 0;
                    while (adminChoice != 11)
                    {
                        system("cls");
                        printf("\n=== Admin Menu ===\n");
                        printf("1. Add Patient\n");
                        printf("2. Remove Patient\n");
                        printf("3. View Patients\n");
                        printf("4. Add Doctor\n");
                        printf("5. Remove Doctor\n");
                        printf("6. View Doctors\n");
                        printf("7. Book Appointment\n");
                        printf("8. Cancel Appointment\n");
                        printf("9. View Appointments\n");
                        printf("10. Remove Medical Records\n");
                        printf("11. Logout\n");
                        printf("12. Exit\n");
                        printf("Enter your choice (1-12): ");
                        scanf("%d", &adminChoice);
                        
                        if (adminChoice == 11)
                        {
                            printf("\nLogging out...\n");
                            break;
                        }

                        switch (adminChoice)
                        {
                        case 1:
                            addPatient();
                            break;
                        case 2:
                            // removePatient();
                            break;
                        case 3:
                            // viewPatients();
                            break;
                        case 4:
                            // addDoctor();
                            break;
                        case 5:
                            // removeDoctor();
                            break;
                        case 6:
                            // viewDoctors();
                            break;
                        case 7:
                            // bookAppointment();
                            break;
                        case 8:
                            // cancelAppointment();
                            break;
                        case 9:
                            // viewAppointments();
                            break;
                        case 10:
                            // removeMedicalRecords();
                            break;
                        case 12:
                            printf("\nExiting...\n");
                            exit(0);
                        default:
                            printf("\nInvalid choice!\n");
                        }
                        printf("\nPress Enter to continue...");
                        getchar();
                        getchar();
                    }
                }
                else if (choice == 2)
                {
                    printf("\nYou are logged in as Doctor.\n");
                }
                else if (choice == 3)
                {
                    printf("\nYou are logged in as Lab Assistant.\n");
                }
            }
            else
            {
                printf("\nInvalid credentials!\n");
            }
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
        }
        else
        {
            printf("\nInvalid choice! Press Enter to continue...");
            getchar();
            getchar();
        }
    }
    return 0;
}