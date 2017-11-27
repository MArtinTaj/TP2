# TP2

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARGUMENTS 1  /*van en types.h */
#define CMD_ARG_FORMAT 0
#define CMD_ARG_OUT 1

typedef enum {} status_t ;

char * arg_flag[MAX_ARG_FLAG]={"-fmt","-out"}; /*son dos...no se si vale la pena hacer un arreglo */
char * format_types[MAX_FORMAT_TYPES]={"csv","kml"};
/*./gpsviewer –fmt <formato> -out <salida> <entrada>*/
  
  
status_t validate_arguments(int argc,char * argv){

  if(argc!=MAX_ARGUMENTS){
		return ERROR_PROG_INVOCATION;
	}
  if(!strcmp(argv[CMD_ARG_FORMAT],arg_flag[CMD_ARG_FORMAT])){
		return ERROR_INVALID_FORMAT;
	}
  if(!strcmp(argv[CMD_ARG_OUT],arg_flag[CMD_ARG_OUT])){
		return ERROR_INVALID_OUT;
	}
  
  if((strcmp(argv[CMD_ARG_FORMAT+1],format_types[0]))!=0||(strcmp(argv[CMD_ARG_FORMAT+1],format_types[1]))!=0){
    return ERROR_INVALID_FORMAT_SELECTION;
    }
  /* es este caso no podemos validar contra algo el archivo de entrada y salida*/
  
  return OK;
  }
  
  status_t entrada(FILE * archivo_entrada){
  
 /* $GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E*/
 
 FILE * archivo_salida;
 
 	if((fopen(archivo_entrada,"rt"))==NULL) /*es de texto delimitado por comas nomas*/
		return ERROR_NULL_FILE;
	fopen(archivo_salida,"wt");/*no necesita validar porque lo crea?*/
	
	
