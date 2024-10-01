#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int gcd(int a, int b);
void processCarpools();
void processTemperatures();
void processEmployeeTimeCards();

// Main function
int main() {
    int choice;

    // Display menu to user
    printf("Select the operation you want to perform:\n");
    printf("1. Calculate GCD\n");
    printf("2. Process Carpool Efficiency\n");
    printf("3. Process Daily High Temperatures\n");
    printf("4. Process Employee Time Cards\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            {
                int num1, num2;
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));
                break;
            }
        case 2:
            processCarpools();
            break;
        case 3:
            processTemperatures();
            break;
        case 4:
            processEmployeeTimeCards();
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

// Function to process carpool efficiency
void processCarpools() {
    FILE *inputFile, *outputFile;
    int minEfficiency, passengers;
    float distance, liters, efficiency, subsidy;

    inputFile = fopen("carpool.txt", "r");
    outputFile = fopen("effic.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fscanf(inputFile, "%d", &minEfficiency);
    fprintf(outputFile, "CARPOOLS MEETING MINIMUM PASSENGER EFFICIENCY OF %d PASSENGER KM/L\n", minEfficiency);
    fprintf(outputFile, " Passengers  Weekly Commute(km)  Gasoline Consumption(L)  Efficiency (pass km/L)  Weekly Subsidy($)\n");

    while (fscanf(inputFile, "%d %f %f", &passengers, &distance, &liters) == 3 && passengers != 0) {
        efficiency = passengers * distance / liters;
        subsidy = 0.08 * passengers * distance;
        if (efficiency >= minEfficiency) {
            fprintf(outputFile, " %10d %19.2f %22.2f %25.2f %20.2f\n", passengers, distance, liters, efficiency, subsidy);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Carpool efficiency data processed and saved to 'effic.txt'.\n");
}

// Function to process daily high temperatures
void processTemperatures() {
    int temp, hot = 0, pleasant = 0, cold = 0, count = 0, sum = 0;
    float avg;
    int temperatures[] = {55, 62, 68, 74, 59, 45, 41, 58, 60, 67, 65, 78, 82, 88, 91, 92, 90, 93, 87, 80, 78, 79, 72, 68, 61, 59};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);

    for (int i = 0; i < n; i++) {
        temp = temperatures[i];
        sum += temp;
        count++;
        if (temp >= 85) {
            hot++;
            printf("%d is a hot day.\n", temp);
        } else if (temp >= 60 && temp < 85) {
            pleasant++;
            printf("%d is a pleasant day.\n", temp);
        } else {
            cold++;
            printf("%d is a cold day.\n", temp);
        }
    }

    avg = (float)sum / count;
    printf("Hot days: %d\nPleasant days: %d\nCold days: %d\n", hot, pleasant, cold);
    printf("Average temperature: %.2f\n", avg);
}

// Function to process employee time cards
void processEmployeeTimeCards() {
    int id, hours;
    float wage, grossPay, netPay, totalPayroll = 0, avgPay = 0;
    int count = 0;

    printf("Enter employee details (ID, hourly wage, hours worked), input -1 to stop.\n");

    while (1) {
        printf("Employee ID: ");
        scanf("%d", &id);
        if (id == -1) break;

        printf("Hourly wage: ");
        scanf("%f", &wage);

        printf("Hours worked: ");
        scanf("%d", &hours);

        if (hours > 40) {
            grossPay = (40 * wage) + ((hours - 40) * 1.5 * wage);
        } else {
            grossPay = hours * wage;
        }

        netPay = grossPay * 0.96375; // Deduct 3.625% tax
        totalPayroll += netPay;
        count++;

        printf("Employee ID: %d, Net Pay: $%.2f\n", id, netPay);
    }

    if (count > 0) {
        avgPay = totalPayroll / count;
    }

    printf("Total payroll: $%.2f\n", totalPayroll);
    printf("Average pay: $%.2f\n", avgPay);
}
