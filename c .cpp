#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

struct Patient {
    char name[50];
    int age;
    char gender[10];
    char disease[10];
};

struct Hospital {
    struct Patient patients[MAX_PATIENTS];
    int count;
};

void addPatient(struct Hospital *hospital) {
    if (hospital->count >= MAX_PATIENTS) {
        printf("Hospital is full. Cannot add more patients.\n");
        return;
    }

    struct Patient newPatient;

    printf("Enter patient name: ");
    scanf("%s", newPatient.name);

    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);

    printf("Enter patient gender: ");
    scanf("%s", newPatient.gender);
    
    printf("Enter disease: ");
    scanf("%s", newPatient.disease);

    hospital->patients[hospital->count] = newPatient;
    hospital->count++;

    printf("Patient added successfully.\n");
}

void displayPatients(struct Hospital *hospital) {
    if (hospital->count == 0) {
        printf("No patients in the hospital.\n");
        return;
    }

    printf("Patients in the hospital:\n");
    for (int i = 0; i < hospital->count; i++) {
        printf("Patient %d:\n", i+1);
        printf("Name: %s\n", hospital->patients[i].name);
        printf("Age: %d\n", hospital->patients[i].age);
        printf("Gender: %s\n", hospital->patients[i].gender);
         printf("Disease: %s\n", hospital->patients[i].disease);
        printf("-------------------------\n");
    }
}

int main() {
    struct Hospital hospital;
    hospital.count = 0;

    int choice;

    do {
        printf("Hospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(&hospital);
                break;
            case 2:
                displayPatients(&hospital);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}
