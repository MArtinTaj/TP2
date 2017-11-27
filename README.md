# TP2

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARGUMENTS 1  /*van en types.h */
#define CMD_ARG_FORMAT 0
#define CMD_ARG_OUT 1

typedef enum {} status_t ;

char * arg_flag[MAX_ARG_FLAG]={"-fmt","-out"}; /*son dos...no se si vale la pena hacer un arreglo */

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
  if((strcmp(argv[CMD_ARG_OUT+1],
  
