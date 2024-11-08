include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100

// Structure to store health data
struct HealthData {
    char name[50];
    int age;
    float height; // in meters
    float weight; // in kilograms
    float bloodPressure; // in mmHg
};

// Array to store multiple users' data
struct HealthData users[MAX_USERS];
int userCount = 0;

// Function to send alerts to doctor's device
void sendAlerts(struct HealthData data) {
    if (data.bloodPressure > 140) {
        printf("ALERT: High blood pressure detected for %s. Blood Pressure: %.2f mmHg\n", data.name, data.bloodPressure);
    } else if (data.bloodPressure < 90) {
        printf("ALERT: Low blood pressure detected for %s. Blood Pressure: %.2f mmHg\n", data.name, data.bloodPressure);
    } else {
        printf("ALERT: Medium blood pressure detected for %s. Blood Pressure: %.2f mmHg\n", data.name, data.bloodPressure);
    }
}

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Function to provide BMI-related advice
void sendBMIAdvice(float bmi, struct HealthData data) {
    printf("\nBMI for %s: %.2f\n", data.name, bmi);
    if (bmi < 18.5) {
        printf("ALERT: %s is underweight. Consider a nutritional and health check.\n", data.name);
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("INFO: %s has a normal weight. Keep maintaining a healthy lifestyle!\n", data.name);
    } else if (bmi >= 25 && bmi < 29.9) {
        printf("ALERT: %s is overweight. Consider a balanced diet and regular exercise.\n", data.name);
    } else {
        printf("ALERT: %s is obese. A medical consultation is recommended.\n", data.name);
    }
}

// Function to input health data for a user
void inputHealthData() {
    if (userCount >= MAX_USERS) {
        printf("Error: Maximum user limit reached.\n");
        return;
    }
    struct HealthData user;
    printf("Enter health data for the user:\n");
    printf("Name: ");
    scanf("%s", user.name);
    printf("Age: ");
    scanf("%d", &user.age);
    printf("Height (meters): ");
    scanf("%f", &user.height);
    printf("Weight (kilograms): ");
    scanf("%f", &user.weight);
    printf("Blood Pressure (mmHg): ");
    scanf("%f", &user.bloodPressure);

    users[userCount++] = user;
    printf("User added successfully!\n");
}

// Function to display all users' health data
void displayAllUsersData() {
    for (int i = 0; i < userCount; i++) {
        printf("\nHealth data for user %d:\n", i + 1);
        printf("Name: %s\n", users[i].name);
        printf("Age: %d\n", users[i].age);
        printf("Height: %.2f meters\n", users[i].height);
        printf("Weight: %.2f kilograms\n", users[i].weight);
        printf("Blood Pressure: %.2f mmHg\n", users[i].bloodPressure);
        sendAlerts(users[i]);
        float bmi = calculateBMI(users[i].weight, users[i].height);
        sendBMIAdvice(bmi, users[i]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nHealth Monitoring System\n");
        printf("1. Add User\n");
        printf("2. View All Users' Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                inputHealthData();
                break;
            case 2:
                displayAllUsersData();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
