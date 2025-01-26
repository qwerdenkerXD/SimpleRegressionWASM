#include <stdint.h>

// Function to calculate the mean of an array
// Parameters:
// - array: Pointer to the array of integers
// - size: Number of elements in the array
// Returns:
// - The mean (average) value of the array elements
double mean(int32_t *array, int32_t size) {
    double sum = 0.0; // Initialize sum to 0
    for (int32_t i = 0; i < size; i++) { // Loop through each element in the array
        sum += array[i]; // Add the current element to the sum
    }
    return sum / size; // Return the mean value
}

// Function to calculate the slope (beta) and intercept (alpha) for linear regression
// Parameters:
// - x_values: Pointer to the array of x-values
// - y_values: Pointer to the array of y-values
// - size: Number of elements in the arrays
// - alpha: Pointer to the variable where the intercept will be stored
// - beta: Pointer to the variable where the slope will be stored
void linear_regression(int32_t *x_values, int32_t *y_values, int32_t size, double *alpha, double *beta) {
    double x_mean = mean(x_values, size); // Calculate the mean of x-values
    double y_mean = mean(y_values, size); // Calculate the mean of y-values

    double num = 0.0; // Initialize numerator for beta calculation
    double den = 0.0; // Initialize denominator for beta calculation

    for (int32_t i = 0; i < size; i++) { // Loop through each element in the arrays
        num += (x_values[i] - x_mean) * (y_values[i] - y_mean); // Calculate the numerator
        den += (x_values[i] - x_mean) * (x_values[i] - x_mean); // Calculate the denominator
    }

    *beta = num / den; // Calculate the slope (beta)
    *alpha = y_mean - (*beta * x_mean); // Calculate the intercept (alpha)
}
