
	
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
	size_t i,j,variable_to_export;
	status_t st;
	ADT_Vector_t * v;
	char ** split_str;
	printer_t pf;
	
	if (argv == NULL || file == NULL)
		return ERROR_NULL_POINTER;
	
	i = 0;/*inicializar al ppio o en la variable, nunca suelto*/
	

		/*separar una cosa de cada otra*/

	if (!strcmp (argv[i], CMD_ARG_FMT))
	{
			return ERROR_PROG_INVOCATION;
	}
	
/*hacer un arreglo de los formatos, nos mandan 10 tipos de casos y nos llenamos de if*/

char * export_formats[MAX_ARR]={FMT_CSV,FMT_KML}
	
	for(j=0;j<MAX_ARR;j++)
	{

		if (!strcmp (argv[i+1], export_format[j]))/*si la i=0, es esto, usar macro #define CMD_ARG_FORMAT 1*/
		{
			variable_to_export=j; /*esta nos va a decir que tipo d formato es*/
			break;/*buscar nombre mas representativo.... no se me ocurrio ninguno*/
		}
	}
	if(j==MAX_ARR)
	{
		return ERROR_INVALID_FORMAT;/* si es MAX_ARR significa que no era uno de los que teniamos, por eso el break , ademas como guardamos la variable en tal lado desp nos sirve para imprimir, si es csv o kml con un swith*/
	}

	if (!strcmp (argv[i], CMD_ARG_OUT))
	{
		if ((file->fi = fopen (INPUT_FILE_DIR, "rt")) == NULL)
			return ERROR_INPUT_FILE;
		
		st = get_gga_data (&split_str, file->fi);
		if (fclose (file->fi) == EOF)
			return ERROR_DISK_SPACE;
		if (st != OK)	
			return st;
		if ((st = ADT_Vector_new (&v)) != OK)
			return st;
		if ((st = parse_gga_data (&split_str, &v)) != OK)
			return st;
			valor=ADT_Vector_get_size (const ADT_Vector_t * v);/*conseguir el largo del vector, para hacer un for de tal e ir imprimiendo, preguntar a santi lo que dijo pablo(imprimir los 3 de una, hacer funcion switch que cambie de lugar para csv, o guardar en arreglo esos valores y punto*/

		switch(variable_to_export)
		{
			case OPC_CSV:/*macro*/
					pf=&printer

			case OPC_KML:/*macro*/
					ADT_Vector_get_size (const ADT_Vector_t * v)
					pf=printer (v,delim, size_t element_count, INPUT_FILE_DIR)


		
		
		
	/*terminar validacion de -out*/
	
	

