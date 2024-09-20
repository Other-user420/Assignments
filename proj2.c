#include <stdio.h>
#include <math.h>

#define MILE_TO_FEET 5280     
#define MILE_TO_METERS 1609.34 

// Function prototypes for the 13 problems
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
void problem11();
void problem12();
void problem13();

int main() {
    int choice;
    
    // Displaying problem options to the user
    printf("Choose a problem to solve (1-13):\n");
    printf("1. Loan Payment Calculator\n");
    printf("2. Shape Printer (Triangle & Rectangle)\n");
    printf("3. Intersecting Stars and Rectangle\n");
    printf("4. Stirling's Approximation\n");
    printf("5. Round to Two Decimal Places\n");
    printf("6. Runner Speed Calculation\n");
    printf("7. House Cost Calculation\n");
    printf("8. Cyclist Deceleration Calculation\n");
    printf("9. Cylindrical Container Cost\n");
    printf("10. Temperature at Depth\n");
    printf("11. Gearbox Speed Ratio\n");
    printf("12. Speed of Sound in Air\n");
    printf("13. Population Growth Prediction\n");

    // Taking the user's choice
    printf("Enter the number of the problem you want to solve: ");
    scanf("%d", &choice);

    // Switch-case structure to call the appropriate function
    switch (choice) {
        case 1: problem1(); break;
        case 2: problem2(); break;
        case 3: problem3(); break;
        case 4: problem4(); break;
        case 5: problem5(); break;
        case 6: problem6(); break;
        case 7: problem7(); break;
        case 8: problem8(); break;
        case 9: problem9(); break;
        case 10: problem10(); break;
        case 11: problem11(); break;
        case 12: problem12(); break;
        case 13: problem13(); break;
        default: printf("Invalid choice!\n");
    }

    return 0;
}

// Problem 1: Loan Payment Calculator
void problem1() {
    float down, principal, i, n;
    printf("Enter the down payment amount: ");
    scanf("%f", &down);
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the monthly interest rate: ");
    scanf("%f", &i);
    printf("Enter the total number of payments: ");
    scanf("%f", &n);

    float payment = (i * principal) / (1 - pow(1 + i, -1 * n));
    float time = down / payment;

    printf("Monthly Payment: %.2f\n", payment);
    printf("Time (in months): %.2f\n", time);
}

// Problem 2: Shape Printer (Triangle & Rectangle)
void problem2() {
    int n, a, b;
    printf("Enter triangle length: ");
    scanf("%d", &n);
    printf("Enter rectangle sides (height and width): ");
    scanf("%d %d", &a, &b);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) printf("*");
        printf("\n");
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) printf("*");
        printf("\n");
    }
}

// Problem 3: Intersecting Stars and Rectangle
void problem3() {
    int rows = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2 * (rows - i) - 1; j++) printf(" ");
        for (int k = 0; k < 2 * i + 1; k++) printf("* ");
        printf("\n");
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 11; j++) printf("*");
        printf("\n");
    }
}

// Problem 4: Stirling's Approximation
void problem4() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    float x = (2 * n + 1.0 / 3.0) * 3.14;
    float fact = pow(n, n) * pow(2.71, -1 * n) * sqrt(x);
    printf("Factorial Approximation: %.2f\n", fact);
}

// Problem 5: Round to Two Decimal Places
void problem5() {
    float n;
    printf("Enter a positive number with fractional part: ");
    scanf("%f", &n);
    printf("Rounded to two decimal places: %.2f\n", n);
}

// Problem 6: Runner Speed Calculation
void problem6() {
    int minutes, seconds;
    double speedFeet, speedMeters;
    printf("Enter race time in minutes and seconds: ");
    scanf("%d %d", &minutes, &seconds);
    int totalTimeInSeconds = (minutes * 60) + seconds;
    speedFeet = (double)MILE_TO_FEET / totalTimeInSeconds;
    speedMeters = (double)MILE_TO_METERS / totalTimeInSeconds;
    printf("Speed: %.2f ft/s, %.2f m/s\n", speedFeet, speedMeters);
}

// Problem 7: House Cost Calculation
void problem7() {
    double initialCost, annualFuelCost, annualTaxRate;
    printf("Enter the initial cost of the house: ");
    scanf("%lf", &initialCost);
    printf("Enter the annual fuel cost: ");
    scanf("%lf", &annualFuelCost);
    printf("Enter the annual tax rate (in decimal): ");
    scanf("%lf", &annualTaxRate);

    double fuelCostFor5Years = annualFuelCost * 5;
    double taxesFor5Years = annualTaxRate * initialCost * 5;
    double totalCost = initialCost + fuelCostFor5Years + taxesFor5Years;

    printf("Total cost of house after 5 years: %.2f\n", totalCost);
}

// Problem 8: Cyclist Deceleration Calculation
void problem8() {
    double initialSpeed = 10.0, finalSpeed = 2.5, timeInMinutes = 1.0;
    double timeInHours = timeInMinutes / 60.0;
    double acceleration = (finalSpeed - initialSpeed) / timeInHours;
    double timeToStop = -initialSpeed / acceleration * 60;
    printf("Acceleration: %.2f mi/hr²\n", acceleration);
    printf("Time to come to rest: %.2f minutes\n", timeToStop);
}

// Problem 9: Cylindrical Container Cost
void problem9() {
    double radius, height, costPerSqCm, surfaceArea, costPerContainer, totalCost;
    int quantity;

    // Display instructions to the user
    printf("This program calculates the cost of producing cylindrical containers.\n");
    printf("You will be prompted to enter the following details:\n");
    printf("1. Radius of the base of the container (in cm).\n");
    printf("2. Height of the container (in cm).\n");
    printf("3. Cost per square centimetre of material (in currency units).\n");
    printf("4. Number of containers to be produced.\n");

    // Take inputs from the user
    printf("Enter the radius of the base of the container (cm): ");
    scanf("%lf", &radius);

    printf("Enter the height of the container (cm): ");
    scanf("%lf", &height);

    printf("Enter the cost per square centimetre of the material: ");
    scanf("%lf", &costPerSqCm);

    printf("Enter the number of containers to be produced: ");
    scanf("%d", &quantity);

    // Compute the surface area of each container (base + lateral area)
    surfaceArea = M_PI * radius * radius + 2 * M_PI * radius * height;

    // Calculate the cost of producing each container
    costPerContainer = surfaceArea * costPerSqCm;

    // Calculate the total cost of producing all the containers
    totalCost = costPerContainer * quantity;

    // Display the results
    printf("\nThe surface area of each container is: %.2f square centimetres.\n", surfaceArea);
    printf("The cost to produce each container is: %.2f currency units.\n", costPerContainer);
    printf("The total cost to produce %d containers is: %.2f currency units.\n", quantity, totalCost);
}

// Problem 10: Temperature at Depth
void problem10() {
    float depth;
    printf("Enter the depth (in Km): ");
    scanf("%f", &depth);
    float cel = 10 * depth + 20;
    float fah = (cel * 9 / 5) + 32;
    printf("Temperature: %.2f °C, %.2f °F\n", cel, fah);
}

// Problem 11: Gearbox Speed Ratio
void problem11() {
    float M, m;
    printf("Enter max speed and min speed (in rpm): ");
    scanf("%f %f", &M, &m);
    float ratio = pow(M / m, 0.2);
    printf("Speed ratio: %.2f\n", ratio);
}

// Problem 12: Speed of Sound in Air
void problem12() {
    float T;
    printf("Enter the temperature (in Fahrenheit): ");
    scanf("%f", &T);
    float speed = 1086 * sqrt((5 * T + 297) / 247);
    printf("Speed of sound: %.3f ft/s\n", speed);
}

// Problem 13: Population Growth Prediction
void problem13() {
    int t;
    printf("Enter a year after 1990: ");
    scanf("%d", &t);
    float population = 2.184 * (t - 1990) + 52.966;
    printf("Predicted population in %d: %.3f thousand\n", t, population);
}
