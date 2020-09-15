#include <stdlib.h>
#include <stdio.h>
#include "generic_vector.h"

//known type
struct generic_vector
{
        int size; //number of items the vector holds
	int capacity; //number of items the vector CAN hold
	ITEM* data;
};

typedef struct generic_vector Generic_vector;

GENERIC_VECTOR generic_vector_init_default(void)
{
	Generic_vector* pVector;
	int i;
	pVector = (Generic_vector*)malloc(sizeof(Generic_vector));
	if (pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = (ITEM*)malloc(sizeof(ITEM)* pVector->capacity);
		if (pVector->data == NULL)
		{
			free(pVector);
			return NULL;
		}
		for(i=0; i<pVector->capacity; i++)
        {
		    pVector->data[i] = NULL;
        }
	}
	return (GENERIC_VECTOR) pVector;
}

int GENERIC_VECTOR_get_size(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->size;
}

int GENERIC_VECTOR_get_capacity(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->capacity;
}

Status GENERIC_VECTOR_push_back(GENERIC_VECTOR hVector, ITEM hItem)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	int i;
	ITEM* pTemp;
	if (pVector->size >= pVector->capacity)
	{
	        pTemp = malloc(sizeof(ITEM) * (4 * pVector->capacity/3+1));
		if (pTemp == NULL)
		{
			return FAILURE;
		}
		for (i=0; i<pVector->capacity*4/3+1; i++)
		{
			pTemp[i]=NULL;
		}
		for (i = 0; i < pVector->size; i++)
		{
		        my_string_assignment(&pTemp[i], pVector->data[i]);
		}
		for (i=0; i< pVector->size; i++)
		{
			my_string_destroy(&pVector->data[i]);
		}
		free(pVector->data);
		pVector->data = pTemp;
		pVector->capacity = pVector->capacity*4/3+1;
		}
	my_string_assignment(&(pVector->data[pVector->size]),hItem);
	pVector->size++;
	return SUCCESS; 
}

Status GENERIC_VECTOR_pop_back(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	if (pVector->size <= 0)
	{
		return FAILURE;
	}
	my_string_destroy(&(pVector->data[pVector->size-1]));
	pVector->size--;
	return SUCCESS;
}

ITEM* GENERIC_VECTOR_at(GENERIC_VECTOR hVector, int index)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	if (index<0 || index>pVector->capacity)
	{
		return NULL;
	}
	return &(pVector->data[index]);
}

GENERIC_VECTOR copy_key(GENERIC_VECTOR hVector, MY_STRING key)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	Generic_vector* temp = generic_vector_init_default();
	int i;
	for (i=0; i<pVector->size; i++)
	{
		if(is_same_key(pVector->data[i], key))
			GENERIC_VECTOR_push_back(temp, pVector->data[i]);
	}
	return (GENERIC_VECTOR)temp;
}

void GENERIC_VECTOR_destroy(GENERIC_VECTOR* phVector)
{
	Generic_vector* pVector = (Generic_vector*)*phVector;
	int i;
	for (i=0; i<pVector->capacity; i++)
    {
	    if (pVector->data[i]!=NULL)
        {
	        my_string_destroy(&pVector->data[i]);
        }
    }
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}
