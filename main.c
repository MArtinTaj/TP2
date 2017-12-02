/*main.c*/

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "types.h"
#include "main.h"

int main (int argc, char *argv[])
{
	status_t st;
	setup_t setup;
	
	if (validate_arguments (argc, argv, &setup) != OK)
		return st;
	
	return OK;
}

status_t validate_arguments (int argc, char *argv[], file_t * file)
{
	size_t i;
	ADT_Vector_t ** pv;
	status_t st;
	
	if (argv == NULL || file == NULL)
		return ERROR_NULL_POINTER;
	
	i = 0;
	
	if (!strcmp (argv[i], CMD_ARG_FMT))
	{
		if (!strcmp (argv[i+1], FMT_CSV))
		{
			
		}
		else if (!strcmp (argv[i+1], FMT_KML))
		{
			
		}
		else 
			return ERROR_PROG_INVOCATION;
	}
	
	if (!strcmp (argv[i], CMD_ARG_OUT))
	{
		if ((file->fi = fopen (INPUT_FILE_DIR, "rt")) == NULL)
			return ERROR_INPUT_FILE;
		
		if ((st = get_gga_data (pv, file->fi)) != OK)
		{
			if (fclose (file->fi) == EOF)
				return ERROR_DISK_SPACE;
			return st;
		}
		
		
	/*terminar validacion de -out*/
	
	
	
	























