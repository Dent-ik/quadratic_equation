#include "test_quadratic_equation.h"

START_TEST(quadratic_equation_test_1) {
  double *roots = solve_equation(5, 4, -1);
  ck_assert_double_eq(0.2, roots[0]);
  ck_assert_double_eq(-1, roots[1]);
  if (roots != NULL) {
    free(roots);
  }
}
END_TEST

START_TEST(quadratic_equation_test_2) {
  double *roots = solve_equation(2, 5, 2);
  ck_assert_double_eq_tol(-2, roots[1], 1e-4);
  ck_assert_double_eq_tol(-0.5, roots[0], 1e-4);
  if (roots != NULL) {
    free(roots);
  }
}
END_TEST

START_TEST(quadratic_equation_test_3) {
  double *roots = solve_equation(0, 0, 0);
  ck_assert_double_nan(roots[0]);
  ck_assert_double_nan(roots[1]);
  if (roots != NULL) {
    free(roots);
  }
}
END_TEST

START_TEST(quadratic_equation_test_4) {
  double *roots = solve_equation(-2, 7, -2);
  ck_assert_double_eq_tol(0.3138, roots[0], 1e-4);
  ck_assert_double_eq_tol(3.1861, roots[1], 1e-4);
  if (roots != NULL) {
    free(roots);
  }
}
END_TEST

Suite *test_solve_equation(void) {
  Suite *suite = suite_create("solve_equation");
  TCase *tc = tcase_create("quadratic_equation_tc");
  tcase_add_test(tc, quadratic_equation_test_1);
  tcase_add_test(tc, quadratic_equation_test_2);
  tcase_add_test(tc, quadratic_equation_test_3);
  tcase_add_test(tc, quadratic_equation_test_4);
  suite_add_tcase(suite, tc);
  return suite;
}

int main(void) {
  Suite *suite = test_solve_equation();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}