#include <stdio.h>//include library
#include <stdlib.h>//include library

float celsius_to_fahrenheit(float celsius);//initialize function
float fahrenheit_to_celsius(float fahrenheit);//initialize function
float celsius_to_kelvin(float celsius);//initialize function
float kelvin_to_celsius(float kelvin);//initialize function
void categorize_temperature(float celsius);//initialize function
void display_advisory(float celsius);//initialize function

int main() {
    float temp, converted_temp;//initialize variables
    int originscale, goalscale;//initialize variables
    
    printf("Enter the temperature: ");//prompt for temperature
    if (scanf("%f", &temp) != 1) {//if input is not a number
        printf("Please enter valid temperature.\n");
        return 1; //Exit
    }
    printf("Choose system of measurement\n");//prompt for input scale
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");//prompt for input
    if (scanf("%d", &originscale) != 1 || originscale < 1 || originscale > 3) {//if input is not 1, 2, or 3
        printf("Please enter a valid number 1-3\n");//prompt for valid input
        return 1;//Exit
    }
    printf("Choose the goal system of measurement\n");//prompt for output scale
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");//prompt for output
    if (scanf("%d", &goalscale) != 1 || goalscale < 1 || goalscale > 3) {//if output is not 1, 2, or 3
        printf("Please enter a valid number 1-3\n");//prompt for valid input
        return 1;//Exit
    }

    //set to celsius for conversion
    float intermediate_celsius;//initialize variable
    switch (originscale) {//switch case to make all temperatures celsius
        case 1: // Celsius
            intermediate_celsius = temp;//set intermediate_celsius to temp (already in celsius)
            break;//exit
        case 2: // Fahrenheit
            intermediate_celsius = fahrenheit_to_celsius(temp);//set intermediate_celsius to fahrenheit conversion
            break;//exit
        case 3: // Kelvin
            intermediate_celsius = kelvin_to_celsius(temp);//set intermediate_celsius to kelvin conversion
            break;//exit
    }
    switch (goalscale) {//switch case to convert to measurement
        case 1: // Celsius
            converted_temp = intermediate_celsius;//set converted_temp to intermediate_celsius
            break;//exit
        case 2: // Fahrenheit
            converted_temp = celsius_to_fahrenheit(intermediate_celsius);//set converted_temp to celsius to fahrenheit conversion
            break;//exit
        case 3: // Kelvin
            converted_temp = celsius_to_kelvin(intermediate_celsius);//set converted_temp to celsius to kelvin conversion
            break;//exit
    }
    printf("\nConverted temperature: %.2f ", converted_temp);//display converted temperature
    switch (goalscale) {//switch case to display scale
        case 1: printf("Celsius\n"); break;//display celsius
        case 2: printf("Fahrenheit\n"); break;//display fahrenheit
        case 3: printf("Kelvin\n"); break;//display kelvin
    }
    if (originscale == 1 || goalscale == 1) {//if either scale is celsius
        categorize_temperature(intermediate_celsius);//display temperature category
        display_advisory(intermediate_celsius);//display advisory
    }
    return 0;//exit
}

float celsius_to_fahrenheit(float celsius) {//function to convert celsius to fahrenheit
    return (celsius * 9/5) + 32;//convert celsius to fahrenheit
}

float fahrenheit_to_celsius(float fahrenheit) {//function to convert fahrenheit to celsius
    return (fahrenheit - 32) * 5/9;//convert fahrenheit to celsius
}

float celsius_to_kelvin(float celsius) {//function to convert celsius to kelvin
    return celsius + 273.15;//convert celsius to kelvin
}

float kelvin_to_celsius(float kelvin) {//function to convert kelvin to celsius
    return kelvin - 273.15;//convert kelvin to celsius
}

void categorize_temperature(float celsius) {//function to categorize temperature
    printf("Temperature category: ");//display temperature category
    if (celsius < 0) {//if temperature is less than 0
        printf("Freezing\n");//display freezing
    } else if (celsius < 10) {//if temperature is less than 15
        printf("Cold\n");//display cold
    } else if (celsius < 25) {//if temperature is less than 25
        printf("Comfortable\n");//display comfortable
    } else if (celsius < 35) {//if temperature is less than 35
        printf("Hot\n");//display hot
    } else {//if temperature is greater than 35
        printf("Extreme Heat\n");//display extreme heat
    }
}

void display_advisory(float celsius) {//function to display advisory
    printf("Advisory: ");//display advisory
    if (celsius < 0) {//if temperature is less than 0
        printf("Stay Inside\n");//display stay inside
    } else if (celsius < 10) {//if temperature is less than 10
        printf("Cold, Wear Heavy Jacket.\n");//display cold, wear heavy jacket
    } else if (celsius < 25) {//if temperature is less than 25
        printf("Cool Weather, Wear A Light Jacket.\n");//display cool weather, wear a light jacket
    } else if (celsius < 35) {//if temperature is less than 35
        printf("Comfortable Weather.\n");//display comfortable weather
    } else {//if temperature is greater than 35
        printf("Heat warning, Stay Inside.\n");//display heat warning, stay inside
    }
}