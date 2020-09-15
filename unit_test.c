#include <stdio.h>
#include <stdlib.h>
#include "unit_test.h"
int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
 {
 test_dbadams_test_init_default_returns_nonNULL,
 test_dbadams_test_get_size_on_init_default_returns_0,
 test_rluo_test_get_capacity_on_init_default_returns_7,
 test_rluo_test_if_empty_returns_TRUE,
 test_rluo_test_if_non_empty_returns_FALSE,
 test_rluo_test_init_c_string_non_empty,
 test_rluo_test_get_size_returns_size,
 test_rluo_test_get_capacity_returns_capacity,
 test_rluo_test_compare_same_string_returns_0,
 test_rluo_test_destroy,
 test_rluo_test_extraction_empty_file_returns_FAILURE,
 test_rluo_test_extraction_non_empty_file_returns_SUCCESS,
 test_rluo_test_extraction_ignore_leading_spaces,
 test_rluo_test_extraction_gets_data,
 test_rluo_test_insertion_when_empty_returns_FAILURE,
 test_rluo_test_insertion_when_non_empty_returns_SUCCESS,
 test_rluo_test_insertion_writes,
 test_rluo_test_push_back_size_correct,
 test_rluo_test_pop_back_size_correct,
 test_rluo_test_pop_back_empty_returns_FAILURE,
 test_rluo_test_my_string_at_correct,
 test_rluo_test_my_string_at_out_of_bound_returns_NULL,
 test_rluo_test_my_string_c_string_correct,
 test_rluo_test_concat_append_remains,
 test_rluo_test_concat_result_changes
 };
 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 int i;
 char buffer[500];
 int success_count = 0;
 int failure_count = 0;
 for(i=0; i<number_of_functions; i++)
 {
 if(tests[i](buffer, 500) == FAILURE)
 {
 printf("FAILED: Test %d failed miserably\n", i);
 printf("\t%s\n", buffer);
 failure_count++;
 }
 else
 {
// printf("PASS: Test %d passed\n", i);
// printf("\t%s\n", buffer);
 success_count++;
 }
 }
 printf("Total number of tests: %d\n", number_of_functions);
 printf("%d/%d Pass, %d/%d Failure\n", success_count,
 number_of_functions, failure_count, number_of_functions);
 return 0;
}
