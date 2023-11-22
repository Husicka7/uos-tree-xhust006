#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nahoda(int min, int max) {

    // Random number in interval [min, max]
    return rand() % (max - min + 1) + min;
}

int main() {

    // Number of records in the dataset
    const int DATASET_SIZE = 50;

    // Seed random number generator with current time
    srand(time(NULL));

    printf("%s\n", // Dataset header (must match the number of columns)
        "clouds,a_pressure,temperature,humidity,rainy_tomorrow"
    );

    for (int i = 0; i < DATASET_SIZE; i++) {

        printf(
            "%d,%d,%d,%d,%s\n",
            nahoda(0, 100),                     // clouds in %
            nahoda(970, 1050),                  // atmospheric pressure in hPa 
            nahoda(-10, 35),                    // temperature in °C
            nahoda(30, 95),                     // relative humidity in %
            nahoda(0, 1) ? "\"yes\"" : "\"no\"" // rainy or not
        );
    }

    return 0;
}

