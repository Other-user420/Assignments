#include <stdio.h>
#include <math.h>

void problem_1() {
    printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
    double start, end, miles, reimbursement;
    printf("Enter beginning odometer reading=> ");
    scanf("%lf", &start);
    printf("Enter ending odometer reading=> ");
    scanf("%lf", &end);
    miles = end - start;
    reimbursement = miles * 0.35;
    printf("You traveled %.1f miles. At $0.35 per mile,\n", miles);
    printf("Your reimbursement is $%.2f.\n", reimbursement);
}

void problem_2() {
    printf("HYDROELECTRIC DAM POWER CALCULATOR\n");
    double height, flow_rate, power;
    printf("Enter the height of the dam (in meters): ");
    scanf("%lf", &height);
    printf("Enter the water flow rate (in cubic meters per second): ");
    scanf("%lf", &flow_rate);
    power = (1000 * 9.8 * height * flow_rate * 0.90) / 1e6;
    printf("The estimated power output is %.2f megawatts.\n", power);
}

void problem_3() {
    printf("FREEZER TEMPERATURE ESTIMATOR\n");
    int hours, minutes;
    double t, T;
    printf("Enter the number of hours since the power failure: ");
    scanf("%d", &hours);
    printf("Enter the number of minutes since the power failure: ");
    scanf("%d", &minutes);
    t = hours + minutes / 60.0;
    T = (4 * t * t) / (t + 2) - 20;
    printf("The estimated temperature in the freezer is %.1f°C.\n", T);
}

void problem_4() {
    printf("FAHRENHEIT TO CELSIUS CONVERTER\n");
    double fahrenheit, celsius;
    printf("Enter the temperature in degrees Fahrenheit=> ");
    scanf("%lf", &fahrenheit);
    celsius = (5.0 / 9.0) * (fahrenheit - 32);
    printf("The temperature in degrees Celsius is %.2f°C.\n", celsius);
}

void problem_5() {
    printf("IV INFUSION RATE CALCULATOR\n");
    double volume, minutes, rate;
    printf("Volume to be infused (ml) => ");
    scanf("%lf", &volume);
    printf("Minutes over which to infuse => ");
    scanf("%lf", &minutes);
    rate = (volume / minutes) * 60;
    printf("VTBI: %.0f ml\n", volume);
    printf("Rate: %.2f ml/hr\n", rate);
}

void problem_6() {
    printf("FINAL EXAM SCORE PREDICTOR\n");
    char desired_grade[3];
    double min_average, current_average, final_weight, needed_score;
    printf("Enter desired grade=> ");
    scanf("%s", desired_grade);
    printf("Enter minimum average required=> ");
    scanf("%lf", &min_average);
    printf("Enter current average in course=> ");
    scanf("%lf", &current_average);
    printf("Enter how much the final counts as a percentage of the course grade=> ");
    scanf("%lf", &final_weight);
    
    double final_weight_decimal = final_weight / 100;
    double current_weight = 1 - final_weight_decimal;
    
    needed_score = (min_average - (current_average * current_weight)) / final_weight_decimal;
    
    printf("You need a score of %.2f on the final to get a %s.\n", needed_score, desired_grade);
}

void problem_7() {
    printf("BTU HEAT DELIVERY CALCULATOR\n");
    double gallons, efficiency, total_btu;
    printf("Enter the number of gallons of oil burned=> ");
    scanf("%lf", &gallons);
    printf("Enter the furnace efficiency (percentage)=> ");
    scanf("%lf", &efficiency);
    
    total_btu = (gallons / 42) * 5800000 * (efficiency / 100);
    
    printf("Total BTUs delivered: %.2f BTU\n", total_btu);
}

void problem_8() {
    // This is the same as problem_7, so we'll just call that function
    problem_7();
}

void problem_9() {
    printf("LAWN MOWING TIME CALCULATOR\n");
    double yard_length, yard_width, house_length, house_width, grass_area, time_seconds;
    printf("Enter the length of the yard (feet)=> ");
    scanf("%lf", &yard_length);
    printf("Enter the width of the yard (feet)=> ");
    scanf("%lf", &yard_width);
    printf("Enter the length of the house (feet)=> ");
    scanf("%lf", &house_length);
    printf("Enter the width of the house (feet)=> ");
    scanf("%lf", &house_width);
    
    grass_area = (yard_length * yard_width) - (house_length * house_width);
    time_seconds = grass_area / 2;
    
    int minutes = (int)(time_seconds / 60);
    double seconds = fmod(time_seconds, 60);
    
    printf("Total area of grass to mow: %.2f square feet\n", grass_area);
    printf("Time required to mow the grass: %d minutes and %.2f seconds\n", minutes, seconds);
}

void problem_10() {
    printf("PERPENDICULAR BISECTOR CALCULATOR\n");
    double x1, y1, x2, y2;
    printf("Enter the x-coordinate of the first point=> ");
    scanf("%lf", &x1);
    printf("Enter the y-coordinate of the first point=> ");
    scanf("%lf", &y1);
    printf("Enter the x-coordinate of the second point=> ");
    scanf("%lf", &x2);
    printf("Enter the y-coordinate of the second point=> ");
    scanf("%lf", &y2);
    
    printf("The two points are: (%.1f, %.1f) and (%.1f, %.1f)\n", x1, y1, x2, y2);
    
    if (x1 == x2) {
        double midpoint_x = x1;
        printf("The equation of the perpendicular bisector is: x = %.2f\n", midpoint_x);
    } else if (y1 == y2) {
        double midpoint_y = y1;
        printf("The equation of the perpendicular bisector is: y = %.2f\n", midpoint_y);
    } else {
        double slope = (y2 - y1) / (x2 - x1);
        double perpendicular_slope = -1 / slope;
        double midpoint_x = (x1 + x2) / 2;
        double midpoint_y = (y1 + y2) / 2;
        double b = midpoint_y - perpendicular_slope * midpoint_x;
        printf("The equation of the perpendicular bisector is: y = %.2fx + %.2f\n", perpendicular_slope, b);
    }
}

void problem_11() {
    printf("PYTHAGOREAN TRIPLE GENERATOR\n");
    int m, n, side1, side2, hypotenuse;
    printf("Enter the value for m (m > n)=> ");
    scanf("%d", &m);
    printf("Enter the value for n (n < m)=> ");
    scanf("%d", &n);
    
    if (m <= n) {
        printf("Error: m must be greater than n.\n");
        return;
    }
    
    side1 = m*m - n*n;
    side2 = 2 * m * n;
    hypotenuse = m*m + n*n;
    
    printf("The Pythagorean triple is: (%d, %d, %d)\n", side1, side2, hypotenuse);
}

void problem_12() {
    printf("JET FIGHTER ACCELERATION CALCULATOR\n");
    double takeoff_speed_kmh, distance, takeoff_speed_ms, acceleration, time;
    printf("Enter the jet's takeoff speed (km/h)=> ");
    scanf("%lf", &takeoff_speed_kmh);
    printf("Enter the distance over which the jet is accelerated (m)=> ");
    scanf("%lf", &distance);
    
    takeoff_speed_ms = takeoff_speed_kmh / 3.6;
    acceleration = (takeoff_speed_ms * takeoff_speed_ms) / (2 * distance);
    time = takeoff_speed_ms / acceleration;
    
    printf("Acceleration: %.2f m/s²\n", acceleration);
    printf("Time to reach takeoff speed: %.2f seconds\n", time);
}

int main() {
    int choice;
    
    while (1) {
        printf("\nSelect a problem to solve (1-12) or 0 to exit:\n");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        } else if (choice >= 1 && choice <= 12) {
            switch (choice) {
                case 1: problem_1(); 
                break;
                case 2: problem_2(); 
                break;
                case 3: problem_3(); 
                break;
                case 4: problem_4(); 
                break;
                case 5: problem_5(); 
                break;
                case 6: problem_6(); 
                break;
                case 7: problem_7(); 
                break;
                case 8: problem_8(); 
                break;
                case 9: problem_9(); 
                break;
                case 10: problem_10(); 
                break;
                case 11: problem_11(); 
                break;
                case 12: problem_12(); 
                break;
            }
        } else {
            printf("Invalid choice. Please select a number between 1 and 12.\n");
        }
    }
    
    return 0;
}