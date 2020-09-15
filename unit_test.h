#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"
#include <string.h>
//adams
Status test_dbadams_test_init_default_returns_nonNULL(char* buffer, int length);
Status test_dbadams_test_get_size_on_init_default_returns_0(char* buffer, int length);

//my tests
Status test_rluo_test_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_rluo_test_if_empty_returns_TRUE(char* buffer, int length);
Status test_rluo_test_if_non_empty_returns_FALSE(char* buffer, int length);
Status test_rluo_test_init_c_string_non_empty(char* buffer, int length);
Status test_rluo_test_get_size_returns_size(char* buffer, int length);
Status test_rluo_test_get_capacity_returns_capacity(char* buffer, int length);
Status test_rluo_test_compare_same_string_returns_0(char* buffer, int length);
Status test_rluo_test_destroy(char* buffer, int length);
Status test_rluo_test_extraction_empty_file_returns_FAILURE(char* buffer, int length);
Status test_rluo_test_extraction_non_empty_file_returns_SUCCESS(char* buffer, int length);
Status test_rluo_test_extraction_ignore_leading_spaces(char* buffer, int length);
Status test_rluo_test_extraction_gets_data(char* buffer, int length);
Status test_rluo_test_insertion_when_empty_returns_FAILURE(char* buffer, int length);
Status test_rluo_test_insertion_when_non_empty_returns_SUCCESS(char* buffer, int length);
Status test_rluo_test_insertion_writes(char* buffer, int length);
Status test_rluo_test_push_back_size_correct(char* buffer, int length);
Status test_rluo_test_pop_back_size_correct(char* buffer, int length);
Status test_rluo_test_pop_back_empty_returns_FAILURE(char* buffer, int length);
Status test_rluo_test_my_string_at_correct(char* buffer, int length);
Status test_rluo_test_my_string_at_out_of_bound_returns_NULL(char* buffer, int length);
Status test_rluo_test_my_string_c_string_correct(char* buffer, int length);
Status test_rluo_test_concat_append_remains(char* buffer, int length);
Status test_rluo_test_concat_result_changes(char* buffer, int length);

#endif
