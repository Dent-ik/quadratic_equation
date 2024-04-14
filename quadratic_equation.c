#include "quadratic_equation.h"

double *solve_equation(double a, double b, double c) {
  double *roots = (double *)malloc(2 * sizeof(double));
  if (roots == NULL) {
    return NULL;
  }
  double discriminant = b * b - 4 * a * c;
  double sqrt_discriminant = sqrt(discriminant);
  roots[0] = (-b + sqrt_discriminant) / (2 * a);
  roots[1] = (-b - sqrt_discriminant) / (2 * a);
  return roots;
}