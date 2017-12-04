/*utils.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "data.h"
#include "utils.h"
#include "adt_vector.h"
#include "error.h"

status_t get_gga_data (char *** split_str, FILE * fi)
{
	char * str;
	status_t st;
	
	if (split_str == NULL || fi == NULL)
		return ERROR_NULL_POINTER;
	
	if ((str = malloc (sizeof (char) * MAX_STR)) == NULL)
		return ERROR_MEMORY;
	
	if (fgets (str, MAX_STR, fi) != NULL)
	{
		if (strncmp (str, DATA_TYPE_GGA, strlen (DATA_TYPE_GGA)) == 0)
		{
			if ((st = verif_sum (str
			
			if ((st = split (str, split_str)) != OK)
				return st;
		}
	}
	else 
		return FILE_READ;
	return OK;
}
/*
status_t parse_gga_data (const char *** ps, ADT_Vector_t ** pv)
{
	double lat, _long, sea_lev;
	char * temp;
	status_t st;


	if (ps == NULL || pv == NULL)
		return ERROR_NULL_POINTER;
	
	if (_long = strtol (*ps [LONGITUDE], &temp, 10))
	{
		if (*temp)
			return ERROR_PARSE_DATA;
		(*temp) = NULL;
		if ((st = ADT_Vector_set_element (pv, &_long)) != OK)
				return st;
	}
	if (lat = strtol (*ps [LATITUDE], &temp, 10)
	{
		if (*temp)
			return ERROR_PARSE_DATA;
		(*temp) = NULL;
		if ((st = ADT_Vector_set_element (pv, &lat)) != OK)
			return st;
	}
	if (sea_lev = strtol (*ps [SEA_LVEL], &temp, 10)
	{
		if (*temp)
			return ERROR_PARSE_DATA;
		(*temp) = NULL;
		if ((st = ADT_Vector_set_element (pv, &sea_lev)) != OK)
			return st;
	}
	return OK;
}
*/
status_t split (const char * str,size_t n, ADT_Record_t *** fields, char delim)
{
	size_t i, j = 0, k;
	status_t st;


	if (str == NULL || ps == NULL)
		return ERROR_NULL_POINTER;
	if (((aux) = (char **) malloc (sizeof (char *) * INIT_CHOP)) == NULL)
		return ERROR_MEMORY;
	
	for (i = 0; i < n; i++)
	{
		if ((((aux) [i]) = (char *) malloc (sizeof (char) * INIT_CHOP)) == NULL)
		{
			free (*ps);
			(aux) = NULL;
			return ERROR_MEMORY;
		}
		for (k = 0; str [j] != delim && str [j]; j++, k++)
			(aux) [i][k] = str[j];
		(aux) [i][k] = '\0';
		j++;
		if(i==0)/*el primer valor*/
			continue;

		if(st=ADT_Record_set_element(*field, aux[i]))!=OK)
			return st;
	}
	return OK;
}

status_t verif_sum (char * str)
{
	size_t i;
	uchar aux;
	char * temp;
	
	if (str == NULL)
		return ERROR_NULL_POINTER;
	
	
	for(i = 1, aux = 0; str[i] != '*'; i++)
	aux ^= str[i];
	
	i++;
	aux &= MASK;
	if (aux != strtol(str, &temp, 16))
		return ERROR_SUM_VERIF;

	return OK;
}


	/*pf (v->element[i], context, fo))*/

status_t printer (const ADT_Vector_t * v, FILE * fo, void * context)
{
	if( v == NULL || fo == NULL || context == NULL)
		return ERROR_NULL_POINTER;

	fprintf(fo,"%s%c%s%c%s\n",v->element[0],context,v->element[1],context,v->element[2]);

return OK;
}


	


status_t get_position_parameters(const ADT_Vector_t * record,ADT_Vector_t * rec){

	status_t st;
	
	if(record==NULL || rec==NULL)
		return ERROR_NULL_POINTER;
	

	if ((st = ADT_Vector_set_element (&rec, record->element[LONGITUDE-1]))!=OK)
		return st;

	if ((st = ADT_Vector_set_element (&rec, record->element[LATITUDE-1]))!=OK)
		return st;

	if ((st = ADT_Vector_set_element (&rec, record->element[SEA_LEVEL-1]))!=OK)
		return st;

		
	return Ok;
}
