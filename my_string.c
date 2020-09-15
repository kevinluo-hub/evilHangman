#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"

struct my_string
{
  int size;
  int capacity;
  char* data;
};

typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
  My_string* pMy_string;
  pMy_string = (My_string*)malloc(sizeof(My_string));
  if (pMy_string != NULL)
    {
      pMy_string->capacity=7;
      pMy_string->size=0;
      pMy_string->data=(char*)malloc(sizeof(char)*7);
      if (pMy_string->data==NULL)
	{
	  return NULL;
	}
    }
  return (MY_STRING)pMy_string;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
  int i=0;
  My_string* pMy_string;
  pMy_string = (My_string*)malloc(sizeof(My_string));
  if (pMy_string != NULL)
    {
      while(c_string[i]!='\0')
	i++;
      pMy_string->size=i;
      pMy_string->capacity=i+1;
      pMy_string->data=(char*)malloc(sizeof(char)*pMy_string->capacity);
      if (pMy_string->data==NULL)
	return NULL;
      for (i=0;i<=pMy_string->size;i++)
	pMy_string->data[i]=c_string[i];
    }
  return (MY_STRING)pMy_string;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  My_string* pMy_string1 = (My_string*)hLeft_string;
  My_string* pMy_string2 = (My_string*)hRight_string;
  int i=0;
  while(i<pMy_string1->size)
    {
      if (i>=pMy_string2->size)
	return 1;
      if (pMy_string1->data[i]!=pMy_string2->data[i])
	return (int)pMy_string1->data[i]-(int)pMy_string2->data[i];
      i++;
    }
  if (i<pMy_string2->size)
    return -1;
  return 0;
}
Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
  My_string* pMy_string = (My_string*)hMy_string;
  char* temp;
  char c;
  pMy_string->size=0;
  c=fgetc(fp);
  while (isspace(c))
    {
      c=fgetc(fp);
    }
  if (c==EOF)
    {
      return FAILURE;
    }
  while (c!=EOF && !isspace(c))
    {
      pMy_string->data[pMy_string->size]=c;
      pMy_string->size++;
      if (pMy_string->size>=pMy_string->capacity)
	{
	  temp = realloc(pMy_string->data,(pMy_string->capacity)*2+1);
	  if (temp==NULL)
	    {
	      return FAILURE;
	    }
	  pMy_string->data=temp;
	  pMy_string->capacity=(pMy_string->capacity)*2+1;
	  }
      c=fgetc(fp);
    }
  ungetc(c,fp);
  // pMy_string->data[pMy_string->size]='\0';
  return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
  My_string* pMy_string = (My_string*)hMy_string;
  if (my_string_empty(hMy_string))
    return FAILURE;
  int i=0;
  for (i=0; i<pMy_string->size; i++)
    {
      fprintf(fp, "%c", pMy_string->data[i]);
    }
  return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
  char* temp;
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string->size+1>=pMy_string->capacity)
       {
         temp = realloc(pMy_string->data,(pMy_string->capacity)*2+1);
         if (temp==NULL)
           {
             return FAILURE;
           }
         pMy_string->data=temp;
         pMy_string->capacity=(pMy_string->capacity)*2+1;
       }
  pMy_string->data[pMy_string->size]=item;
  // pMy_string->data[pMy_string->size+1]='\0';
  pMy_string->size++;
  return SUCCESS;
}
Status my_string_pop_back(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string->size<=0)
    return FAILURE;
  // pMy_string->data[pMy_string->size]='\0';
  pMy_string->size--;
  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  My_string* pMy_string = (My_string*)hMy_string;
  if (index>=pMy_string->size)
    return NULL;
  return &(pMy_string->data[index]);
}

char* my_string_c_str(MY_STRING hMy_string)
{
  char* temp;
  My_string* pMy_string = (My_string*)hMy_string;
  if (pMy_string->size>=pMy_string->capacity)
       {
         temp = realloc(pMy_string->data,(pMy_string->capacity)+1);
         pMy_string->data=temp;
         pMy_string->capacity++;
       }
  pMy_string->data[pMy_string->size]='0';
  return pMy_string->data;
  }

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  My_string* pResult = (My_string*)hResult;
  My_string* pAppend = (My_string*)hAppend;
  int i, j;
  Status s;
  for (i=0; i<my_string_get_size(hAppend); i++)
    {
      s=my_string_push_back(pResult, *(my_string_at(pAppend, i)));
      if (s==FAILURE)
	{
	  for (j=0; j<i; j++)
	    my_string_pop_back(pResult);
	  return s;
	}
    }
  return s;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
  if (my_string_get_size(hMy_string)==0)
    return TRUE;
  return FALSE;    
}

void my_string_assignment(ITEM* pLeft, ITEM Right)
{
  int i=0;
  My_string* sLeft = (My_string*)*pLeft;
  My_string* sRight = (My_string*)Right;
  if(*pLeft!=NULL)
     my_string_destroy(pLeft);
  sLeft= my_string_init_default();
  for(i=0; i<sRight->size;i++)
  {
     my_string_push_back(sLeft, sRight->data[i]);
  }
  *pLeft=sLeft;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
  My_string* cwf = (My_string*) current_word_family;
  My_string* nk = (My_string*) new_key;
  My_string* w = (My_string*) word;
  int i;
  nk->size=0; 
  my_string_concat(nk, cwf);
  for(i=0; i<my_string_get_size(word); i++)
  {
    if(*my_string_at(w,i)==guess)
       nk->data[i]=guess;
  }
  return SUCCESS;
}

Boolean is_same_key(MY_STRING word, MY_STRING key)
{
	My_string* pWord = (My_string*)word;
	My_string* pKey = (My_string*)key;
	int i;
	for (i=0; i<pKey->size; i++)
	{
		if(pKey->data[i]!='_' && pWord->data[i]!=pKey->data[i])
			return FALSE;
	}
	return TRUE;
}

void my_string_destroy(ITEM* pItem)
{
  My_string* pMy_string = (My_string*)*pItem;
  free(pMy_string->data);
  free(pMy_string);
  *pItem=NULL;
  }
