#include <stdint.h>

// Define a structure to hold the regression result
typedef struct {
    double alpha;
    double beta;
} LinearRegressionResult;

// Function to calculate the mean of an array
double mean(int32_t *array, int32_t size) {
    double sum = 0.0;
    for (int32_t i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Function to calculate the slope (beta) and intercept (alpha)
void linear_regression(int32_t *x_values, int32_t *y_values, int32_t size, double *alpha, double *beta) {
    double x_mean = mean(x_values, size);
    double y_mean = mean(y_values, size);

    double num = 0.0;
    double den = 0.0;

    for (int32_t i = 0; i < size; i++) {
        num += (x_values[i] - x_mean) * (y_values[i] - y_mean);
        den += (x_values[i] - x_mean) * (x_values[i] - x_mean);
    }

    *beta = num / den;
    *alpha = y_mean - (*beta * x_mean);
}
