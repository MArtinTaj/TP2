/*main.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "main.h"
#include "data.h"
#include "utils.h"
#include "adt_vector.h"


status_t validate_arguments (int argc, char *argv[],config_t * config)
{
	status_t st;
	FILE * fi, * fo;
	ADV_Vector_t * v;
	doc_type_t doc;

	if (argv == NULL)
		return ERROR_NULL_POINTER;
	if (argc != MAX_ARGS)
		return ERROR_PROG_INVOCATION;

	if (!strcmp (argv[ARG_FMT], CMD_ARG_FMT))
	{	
		if (!strcmp (argv [ARG_FMT_TYPE], FMT_CSV))
		{
			config->doc_format=DOC_TYPE_CSV;/*nos da el tipo de archivo de salida*/
		}
		else if (!strcmp (argv [ARG_FMT_TYPE], FMT_KML)
		{
			config->doc_format=DOC_TYPE_KML;
		}
		else
			return ERROR_PROG_INVOCATION;
	}
		
					
	if (!strcmp (argv[ARG_OUTPUT], CMD_ARG_OUT))
	{
		
			if((fi=fopen(argv[CMD_ARG_INPUT_TYPE],"rt"))==NULL)/*prueba si abren*/
				return ERROR_INPUT_FILE;
			if((fo=fopen(argv[CMD_ARG_OUTPUT_FILE],"wt"))==NULL)
			{
				if(fclose(fi)==EOF)
					return ERROR_DISK_SPACE;		
				return ERROR_OUTPUT_FILE;
			}	
			if(fclose(fi)==EOF)
					return ERROR_DISK_SPACE;		
			if(fclose(fo)==EOF)
					return ERROR_DISK_SPACE;	/*cierra porque no hace nada mas solo valida*/	
	}
	return OK;
}



int main (int argc, char *argv[])
{
	status_t st;
	
	if ((st = validate_arguments (argc, argv)) != OK)
		return st;
	if(( st = process_gps_records (



	return 0;
}
