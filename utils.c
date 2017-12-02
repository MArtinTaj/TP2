/*utils.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "data.h"

status_t hola (char * str, FILE * fi)
{
	if (str == NULL)
		return ERROR_NULL_POINTER;
	
	if ((fi = fopen (KML_FILE_DIR, "rt")) == NULL)
		return ERROR_INPUT_FILE;
	
	if (fgets (str, MAX_STR, fi) == NULL)
		return ERROR_NULL_POINTER;
		
}

status_t get_gga_data (ADT_Vector_t ** pv, FILE * fi)
{
	char str [MAX_STR];
	char ** split_str;
	status_t st;
	
	if (pv == NULL || fi == NULL)
		return ERROR_NULL_POINTER;
	
	while (fgets (str, MAX_STR, fi) != NULL)
	{
		if (strncmp (str, DATA_TYPE_GGA, strlen (DATA_TYPE_GGA)) == 0)
		{
			if ((st = split (str, &split_str)) != OK)
				return st;
			if (split_str [LONGITUDE] && split_str [LATITUDE] && split_str [SEA_LEVEL])
			{
				if ((st = ADT_Vector_set_element (pv, split_str [LATITUDE])) != OK)
					return st;
				if ((st = ADT_Vector_set_element (pv, split_str [LONGITUDE])) != OK)
					return st;
				if ((st = ADT_Vector_set_element (pv, split_str [SEA_LEVEL])) != OK)
					return st;
			}
		}
	}
	return OK;
}

status_t split (const char * str, char *** sp)
{
	size_t i, j = 0, k;
	
	if (str == NULL || sp == NULL)
		return ERROR_NULL_POINTER;
	if (((*sp) = (char **) malloc (sizeof (char *) * INIT_CHOP)) == NULL)
		return ERROR_MEMORY;
	
	for (i = 0; i < MAX_NMEA_FIELD; i++)
	{
		if ((((*sp) [i]) = (char *) malloc (sizeof (char) * INIT_CHOP)) == NULL)
		{
			free (*sp);
			return ERROR_MEMORY;
		}
		for (k = 0; str [j] != COMA_CHAR && str [j]; j++, k++)
			(*sp) [i][k] = str[j];
		(*sp) [i][k] = '\0';
		j++;
	}
	return OK;
}

status_t csv_printer (const ADT_Vector_t * data, char * delim, FILE * fo)
{	
	if (data == NULL || delim == NULL || fo == NULL)
		return ERROR_NULL_POINTER;
	
	fprintf (fo, "%s%c", data);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
