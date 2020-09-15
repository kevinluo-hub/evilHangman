#include "tree.h"

void scan_dictionary(GENERIC_VECTOR* arr, int arr_size);
void play(GENERIC_VECTOR* arr, int arr_size);
void clear_keyboard_buffer(void);
int ask_length(void);
char ask_guess(void);
int ask_time(void);
Boolean end_game(MY_STRING key);
Boolean check_past(MY_STRING past, char guess);

int main(int argc, char* argv[])
{
  int i;
  GENERIC_VECTOR arr[30];
  scan_dictionary(arr, 30);
  play(arr, 30);
  for (i=0; i<30; i++)
  {
     GENERIC_VECTOR_destroy(&arr[i]);
  }

  return 0;
}

void play(GENERIC_VECTOR* arr, int arr_size)
{
  int i=0;
  char guess;
  int life=ask_time();
  int length = ask_length();
  MY_STRING past = my_string_init_default();
  MY_STRING key = my_string_init_default();
  for (i=0; i<length; i++)
    my_string_push_back(key, '_');
  MY_STRING temp;
  MY_STRING word = my_string_init_default();
  TREE t;
  GENERIC_VECTOR pool = generic_vector_init_default();
  for (i=0; i<GENERIC_VECTOR_get_size(arr[length]); i++)
	GENERIC_VECTOR_push_back(pool, *(GENERIC_VECTOR_at(arr[length], i)));
  int oof=0;
 do{
	printf("word: ");
        my_string_insertion(key, stdout);
        printf("\n");
	do
	{
	if (!my_string_empty(past))
	{
	  printf("used letters: ");
	  for (i=0; i<my_string_get_size(past); i++)
	  {
		printf("%c ", *(my_string_at(past, i)));
	  }
	  printf("\n");
	}
        guess = ask_guess();
	}while (check_past(past, guess));
	my_string_push_back(past, guess);
	t = tree_init_default();
	for (i=0; i<GENERIC_VECTOR_get_size(pool); i++)
	{
	   temp=my_string_init_default();
           my_string_assignment(&word, *(GENERIC_VECTOR_at(pool, i)));
           get_word_key_value(key, temp, word, guess);
	   t=tree_insert(t, temp, word);
           my_string_destroy(&temp);
	}
	oof = 0;
	my_string_assignment(&temp, key);
	print_in_order(t);
	swap_vector(t, &oof, &key, &pool);
	if (my_string_compare(temp,key)==0)
	{
	   life--;
	   printf("you guess it wrong, you have %d life remaining.\n", life);
	}
	my_string_destroy(&temp);
	tree_destroy(&t);
  }while(life!=0 && !end_game(key));
  if (life==0)
  {
	printf("You lost. The word is ");
	my_string_insertion(*(GENERIC_VECTOR_at(pool, 0)), stdout);
	printf(".\n");
  }
  my_string_destroy(&key);
  my_string_destroy(&word);
  my_string_destroy(&past);
  GENERIC_VECTOR_destroy(&pool);
}

Boolean check_past(MY_STRING past, char guess)
{
  int i=0;
  for (i=0; i<my_string_get_size(past); i++)
  {
	if(guess==*(my_string_at(past, i)))
	{
		printf("You have guessed %c already, please use a new letter.\n", guess);
		return TRUE;
	} 
 }
  return FALSE;
}

Boolean end_game(MY_STRING key)
{
  int i=0;
  for (i=0; i<my_string_get_size(key); i++)
  {
	if (*(my_string_at(key, i))=='_')
		return FALSE;
  }
  printf("You guess the word \"");
  my_string_insertion(key, stdout);
  printf("\" successfully, congrats!\n");
  return TRUE;
}

char ask_guess(void)
{
  char guess;
  printf("Enter a lower case character as your guess\n");
  scanf("%c", &guess);
  clear_keyboard_buffer();
  return guess;
}

int ask_time(void)
{
  int noc=0;
  int time;
  printf("How many guesses do you want?\n");
  noc=scanf("%d",&time);
  clear_keyboard_buffer();
  while (noc!=1)
  {
    printf("The value u entered is not a number.\n");
    printf("please enter a value\n");
    noc=scanf("%d", &time);
    clear_keyboard_buffer();
  }
  return time;
}

int ask_length(void)
{
  int noc=0;
  int length;
  printf("How long is the word?\n");
  noc=scanf("%d",&length);
  clear_keyboard_buffer();
  while (noc!=1 || (length<2 || length>29 || length==23 || (length>=25 && length<=27)))
  {
    printf("The value u entered is either not valid or there is no word with such length\n");
    printf("please re-enter a value\n");
    noc=scanf("%d", &length);
    clear_keyboard_buffer();
  }
  return length; 
}

void scan_dictionary(GENERIC_VECTOR* arr, int arr_size)
{
  int i=0;
  FILE* fp;
  fp=fopen("dictionary.txt", "r");
  for (i=0; i<arr_size; i++)
  {
     arr[i]=generic_vector_init_default();
  }
  MY_STRING temp = my_string_init_default();
  Status s=SUCCESS;
  while (s)
  {
     s=my_string_extraction(temp,fp);
     if (my_string_get_size(temp)<=arr_size-1)
     {
       GENERIC_VECTOR_push_back(arr[my_string_get_size(temp)],temp);
     }
 }
  my_string_destroy(&temp);
  fclose(fp);
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}

