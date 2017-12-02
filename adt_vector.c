/*ADT_Vector functions*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "data.h"

status_t ADT_Vector_new (ADT_Vector_t ** pv)
{	
	if (pv == NULL)
		return ERROR_NULL_POINTER;
		
	if ((*pv =  (ADT_Vector_t *) malloc (sizeof (ADT_Vector_t))) == NULL)
		return ERROR_MEMORY;
	
	if (((*pv)->element = (void**) malloc (sizeof (void*) * ADT_VECTOR_INIT_CHOP)) == NULL)
			free (*pv);
			(*pv) = NULL;
			return ERROR_MEMORY;
			
	(*pv)->alloc_size = ADT_VECTOR_INIT_CHOP;
	
	for (i = 0; i < (*pv)->alloc_size -1; i++)
		(*pv)->element[i] = NULL;
		
	(*pv)->size = 0;
	return OK;
}

status_t ADT_Vector_delete (ADT_Vector_t ** pv, destructor_t pf)
{
	size_t i;
	status_t st;
	
	if (pv == NULL)
		return ERROR_NULL_POINTER;
	
	for (i = 0; i < (*pv)->size; i++)
	{
		if ((st = pf ((*pv)->element[i])) != OK)
			return st;
	}
	free ((*pv)->element);
	(*pv)->element = NULL;
	free (*pv);
	(*pv) = NULL;
	return OK;
}

/*Esta función no acepta punteros nulos*/

size_t ADT_Vector_get_size (const ADT_Vector_t * v)
{
	if (v == NULL)
		return 0;
	
	return v->size;
}

void * ADT_Vector_get_element (const ADT_Vector_t *v, size_t pos)
{
	if (v == NULL)
		return NULL;
	
	if (pos > v->size)
		return NULL;
	
	return v->element [pos];
}



status_t ADT_Vector_export_as_csv (const ADT_Vector_t * v, FILE * fo, void * delim, printer_t pf)
{
	status_t st;
	size_t i;
	if (v == NULL || fo == NULL)
		return ERROR_NULL_POINTER;
	
	for (i = 0; i < v->size; i++)
	{
		if ((st = pf  (v->element [i], delim, fo)) != OK)
			return st;
	}
	return OK;
}

status_t ADT_Vector_export_as_kml (const ADT_Vector_t * v, FILE * fo, void * context, printer_t pf)
{
	status_t st;
	size_t i;
	if (v == NULL || context == NULL)
		return ERROR_NULL_POINTER;
	
	for (i = 0; i < v->size; i++)
	{
		if ((st = pf (v->element[i], context, fo)) != OK)
			return st;
		
	}
	return OK;
}

status_t ADT_Vector_set_element (ADT_Vector_t ** pv, const void * data)
{
	ADT_Vector_t * aux;
	
	if (v == NULL || data == NULL)
		return ERROR_NULL_POINTER;
	
	if ((*pv)->alloc_size -1 == (*pv)->size)
	{
		if ((aux = realloc ((*pv)->element, sizeof (void*) * ADT_VECTOR_CHOP_SIZE)) == NULL)
			return ERROR_MEMORY;
		(*pv)->element = aux;
		(*pv)->alloc_size += ADT_VECTOR_CHOP_SIZE;
	}
	
	(*pv)->element[(*pv)->size++] = data;
	
	return OK;
}
