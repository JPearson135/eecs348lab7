#include <stdio.h> // include library

void find_combinations(int score); // Function prototype

int main() { // main function
    int score; // initialize score variable
    
    while (1) { // while loop
        printf("Enter the NFL score (0 or 1 to STOP): "); // print statement
        scanf("%d", &score); // scan input
        
        if (score <= 1) break; // Stop if 1 or 0
        
        if (score < 0) { // if score is less than 0
            printf("Please enter valid number.\n"); // print error
            continue; // continue
        }

        printf("Possible combinations of plays for a %d:\n", score); // print score in statement
        find_combinations(score); // run combinations function
    }
    return 0; // return to show code has worked
}

void find_combinations(int score) { // function to find combinations
    printf("Combinations of plays:\n"); // print statement
    int count = 0; // initialize count variable
    
    // Loop through all possible combinations
    for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {//loop for td with 2pt
        for (int tdfg = 0; tdfg * 7 <= score; tdfg++) {//loop for td with fg
            for (int td = 0; td * 6 <= score; td++) {//loop for td
                for (int fg = 0; fg * 3 <= score; fg++) {//loop for fg
                    for (int safety = 0; safety * 2 <= score; safety++) {//loop for safety
                        if (td2pt * 8 + tdfg * 7 + td * 6 + fg * 3 + safety * 2 == score) { // if combination is equal to score
                            printf("TD+2: %d  TD+FG: %d  TD: %d  FG: %d  Safety: %d\n", td2pt, tdfg, td, fg, safety);// print combinations
                            count++; // increase count
                        }
                    }
                }
            }
        }
    }
    
    if (count == 0) { // if no combinations found
        printf("No possible combinations for %d points.\n", score); // print error
    } else {
        printf("%d possible combinations.\n\n", count); // print total number of combinations
    }
}