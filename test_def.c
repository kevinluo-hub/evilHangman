#include "unit_test.h"

Status test_dbadams_test_init_default_returns_nonNULL(char* buffer, int length)
{
 MY_STRING hString = NULL;
 hString = my_string_init_default();
 if(hString == NULL)
 {
 my_string_destroy(&hString);
 strncpy(buffer, "test_init_default_returns_nonNULL\n"
 "my_string_init_default returns NULL", length);
 return FAILURE;
 }
 else
 {
 my_string_destroy(&hString);
 strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
 return SUCCESS;
 }
}

Status test_dbadams_test_get_size_on_init_default_returns_0(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_default();
 if(my_string_get_size(hString) != 0)
 {
 status = FAILURE;
 printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
 strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
 "Did not receive 0 from get_size after init_default\n", length);
 }
 else
 {
 status = SUCCESS;
 strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
 , length);
 }
 my_string_destroy(&hString);
 return status;
}

Status test_rluo_test_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(my_string_get_capacity(hString) != 7)
  {
  status = FAILURE;
  printf("Expected a capacity of 7 but got %d\n", my_string_get_size(hString));
  strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n"
  "Did not receive 7 from get_capacity after init_default\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}
Status test_rluo_test_if_empty_returns_TRUE(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(my_string_empty(hString)!=TRUE)
  {
  status = FAILURE;
  printf("Expected TRUE to be returned when an empty string is passed in\n");
  strncpy(buffer, "test_if_empty_returns_TRUE\n"
  "TRUE wasn't returned\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "if_empty_return_TRUE\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}
Status test_rluo_test_if_non_empty_returns_FALSE(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if(my_string_empty(hString)!=FALSE)
  {
  status = FAILURE;
  printf("Expected FALSE to be returned when an non empty string is passed in\n");
  strncpy(buffer, "test_if_non_empty_returns_FALSE\n"
  "FALSE wasn't returned\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "if_non_empty_return_FALSE\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_init_c_string_non_empty(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if(my_string_empty(hString)==TRUE)
  {
  status = FAILURE;
  printf("Expected string that initialized through c string to be not empty\n");
  strncpy(buffer, "test_if_non_empty_returns_FALSE\n"
  "It is empty\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "init_c_string_non_empty\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}


Status test_rluo_test_get_size_returns_size(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if(my_string_get_size(hString)!=5)
  {
  status = FAILURE;
  printf("Expected a size of 5 for \"hello\" but got %d\n", my_string_get_size(hString));
  strncpy(buffer, "test_get_size_return_size\n"
  "Did not receive the correct size for the string\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "get_size_return_size\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}
Status test_rluo_test_get_capacity_returns_capacity(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if(my_string_get_capacity(hString)!=6)
  {
  status = FAILURE;
  printf("Expected a capacity of 6 for \"hello\" but got %d\n", my_string_get_capacity(hString));
  strncpy(buffer, "test_get_capacity_return_capacity\n"
  "Did not receive the correct capacity for the string\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "get_capacity_return_capacity\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_compare_same_string_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if(my_string_compare(hString, hString) != 0)
  {
  status = FAILURE;
  printf("Expected a result of 0 but got %d\n", my_string_compare(hString, hString));
  strncpy(buffer, "test_compare_same_string_returns_0\n"
  "Did not receive 0 from compare after passing in the same string\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "test_rluo_test_compare_same_string_returns_0\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_destroy(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hi");
  my_string_destroy(&hString);
  if(hString!=NULL)
  {
  status = FAILURE;
  printf("Expected hString to be NULL after destroy");
  strncpy(buffer, "test_destroy\n"
  "Did not turn hString to NULL after destroy\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "test_rluo_test_destroy turns hString to NULL\n"
  , length);
  }

  return status;
}

Status test_rluo_test_extraction_empty_file_returns_FAILURE(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  FILE* fp = fopen("empty.txt", "r");
  if(my_string_extraction(hString,fp)!=FAILURE)
  {
  status = FAILURE;
  printf("Expected a FAILURE status when extracts from empty file");
  strncpy(buffer, "test_extraction_empty_file_returns_FAILURE\n"
  "Did not report FAILURE\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "test_rluo_test_extraction_empty_file_returns_FAILURE succeeded\n"
  , length);
  }
  fclose(fp);
  fp=NULL;
  my_string_destroy(&hString);
  return status;
}
Status test_rluo_test_extraction_non_empty_file_returns_SUCCESS(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  FILE* fp = fopen("simple.txt", "r");
  if(my_string_extraction(hString,fp)!=SUCCESS)
  {
  status = FAILURE;
  printf("Expected a SUCCESS status when extracts from non empty file");
  strncpy(buffer, "test_extraction_non_empty_file_returns_SUCCESS\n"
  "Did not report SUCCESS\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "test_rluo_test_extraction_non_empty_file_returns_SUCCESS\n"
  , length);
  }
  fclose(fp);
  fp=NULL;
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_extraction_ignore_leading_spaces(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  FILE* fp = fopen("leading_space.txt", "r");
  my_string_extraction(hString, fp);
  if((my_string_c_str(hString))[0]==' ')
  {
  status = FAILURE;
  printf("Expected extraction to ignores leading spaces");
  strncpy(buffer, "test_extraction_ignore_leading_spaces\n"
  "Did not ignore leading spaces\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "extraction successfully ignores leading spaces\n"
  , length);
  }
  fclose(fp);
  fp=NULL;
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_extraction_gets_data(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  FILE* fp = fopen("leading_space.txt", "r");
  my_string_extraction(hString, fp);
  if(my_string_empty(hString))
  {
  status = FAILURE;
  printf("Expected extraction to read and store file in hString");
  strncpy(buffer, "test_extraction_gets_data\n"
  "Did not get data\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "extraction successfully reads data\n"
  , length);
  }
  fclose(fp);
  fp=NULL;
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_insertion_when_empty_returns_FAILURE(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if(my_string_insertion(hString, stdout)!=FAILURE)
  {
  status = FAILURE;
  printf("Expected insertion to send FAILURE when string is empty");
  strncpy(buffer, "test_rluo_test_insertion_when_empty_returns_FAILURE\n"
  "Did not send FAILURE\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "FAILURE sent when string is empty\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}
Status test_rluo_test_insertion_when_non_empty_returns_SUCCESS(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if(my_string_insertion(hString, stdout)!=SUCCESS)
  {
  status = FAILURE;
  printf("Expected insertion to send SUCCESS when string is not empty");
  strncpy(buffer, "test_rluo_test_insertion_when_non_empty_returns_SUCCESS\n"
  "Did not send SUCCESS\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "SUCCESS sent when string is not empty\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_insertion_writes(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  FILE* fp = fopen("write.txt", "w");
  int noc=0;
  char buff[10];
  hString = my_string_init_c_string("Hello");
  my_string_insertion(hString, fp);
  noc=fscanf(fp, "%s", buff);
  if(noc==0)
  {
  status = FAILURE;
  printf("Expected insertion to write in file when string is not empty");
  strncpy(buffer, "test_rluo_test_insertion_writes\n"
  "Did not write in file\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "inserted string in file successfully\n"
  , length);
  }
  fclose(fp);
  fp=NULL;
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_push_back_size_correct(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int size;
  hString = my_string_init_c_string("hello");
  size=my_string_get_size(hString);
  my_string_push_back(hString, 'o');
  if (my_string_get_size(hString)!=(size+1))
  {
  status = FAILURE;
  printf("Expected an increase by 1 in size");
  strncpy(buffer, "test_push_back_size_correct\n"
  "Did not add 1 in size after push back\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "size added by 1 after push back\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_pop_back_size_correct(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int size;
  hString = my_string_init_c_string("hello");
  size=my_string_get_size(hString);
  my_string_pop_back(hString);
  if (my_string_get_size(hString)!=(size-1))
  {
  status = FAILURE;
  printf("Expected an decrease by 1 in size");
  strncpy(buffer, "test_pop_back_size_correct\n"
  "Did not minus 1 in size after pop back\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "size decreased by 1 after pop back\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_pop_back_empty_returns_FAILURE(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_default();
  if (my_string_pop_back(hString)!=FAILURE)
  {
  status = FAILURE;
  printf("Expected an FAILURE when pop back on empty string");
  strncpy(buffer, "test_pop_back_empty_returns_FAILURE\n"
  "Did not return FAILURE\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "return FAILURE when pop back on empty string\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_my_string_at_correct(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if (*(my_string_at(hString, 1))!='e')
  {
  status = FAILURE;
  printf("Expected an 'e' at index 1 of \"hello\"");
  strncpy(buffer, "test_my_string_at_correct\n"
  "Did not return 'e' at index 1 of \"hello\"\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "returned 'e' at index 1 of \"hello\"\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_my_string_at_out_of_bound_returns_NULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  hString = my_string_init_c_string("hello");
  if (my_string_at(hString, 6)!=NULL)
  {
  status = FAILURE;
  printf("Expected NULL at index 6 of \"hello\" because out of bound");
  strncpy(buffer, "test_my_string_at_out_of_bound_return_NULL\n"
  "Did not return NULL at index 6 of \"hello\"\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "returned NULL at index 6 of \"hello\"\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_my_string_c_string_correct(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int i=0;
  hString = my_string_init_c_string("hello");
  char* s = my_string_c_str(hString);
  while (s[i+1]!='\0')
   i++;
 // printf("\nthe value of i: %d\n", i);
  if (i!=my_string_get_size(hString))
  {
  status = FAILURE;
  printf("Expected hString to be NULL terminated after function call c string");
  strncpy(buffer, "test_my_string_c_string_correct\n"
  "Did not become NULL terminated\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "hString is NULL terminated after function call c string\n"
  , length);
  }
  my_string_destroy(&hString);
  return status;
}

Status test_rluo_test_concat_append_remains(char* buffer, int length)
{
  Status status;
  MY_STRING hResult = my_string_init_c_string("hello");
  MY_STRING hAppend = my_string_init_c_string("world");
  int size= my_string_get_size(hAppend);
  my_string_concat(hResult, hAppend);
  if (my_string_get_size(hAppend)!=size)
  {
  status = FAILURE;
  printf("Expected hAppend to remain the same after the function call");
  strncpy(buffer, "test_concat_append_remains\n"
  "Append changed\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "Append remained the same after the function call\n"
  , length);
  }
  my_string_destroy(&hResult);
  my_string_destroy(&hAppend);
  return status;
}

Status test_rluo_test_concat_result_changes(char* buffer, int length)
{
  Status status;
  MY_STRING hResult = my_string_init_c_string("hello");
  MY_STRING hAppend = my_string_init_c_string("world");
  int size= my_string_get_size(hResult);
  my_string_concat(hResult, hAppend);
  if (my_string_get_size(hResult)!=(size+my_string_get_size(hAppend)))
  {
  status = FAILURE;
  printf("Expected hResult to be concated with hAppend after function call");
  strncpy(buffer, "test_concat_result_changes\n"
  "Result did not change\n", length);
  }
  else
  {
  status = SUCCESS;
  strncpy(buffer, "result became the two combined after the function call\n"
  , length);
  }
  my_string_destroy(&hResult);
  my_string_destroy(&hAppend);
  return status;
}

