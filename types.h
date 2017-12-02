/*types.h*/

#include <stdio.h>

typedef status_t (*destructor_t) (void*);
typedef status_t (*printer_t) (const void *, void *, void *);

typedef enum {
	ID_MSG,
	TIME_UTC,
	LATITUDE,
	N_S_INDIC,
	LONGITUDE,
	E_W_INDIC,
	STATIC_INDIC,
	USED_SATELITES,
	HDOP,
	SEA_LEVEL,
	SEA_LEVEL_UNIT,
	GEO_DISTANCE,
	GEO_DISTANCE_UNIT,
	AGE_OF_DIFF_CORR,
	DIFF_REF_STATION_ID,
	VERIF_SUM
} nmea_field_t;

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	ERROR_MEMORY,
	ERROR_INPUT_FILE,
	ERROR_PROG_INVOCATION,
	ERROR_DISK_SPACE,
	
} status_t;

typedef struct {
	void ** element;
	size_t size;
	size_t alloc_size;
} ADT_Vector_t;

typedef struct {
	FILE * fo;
	FILE * fi;
} file_t;

typedef struct {
	char delim = DELIM;
} setup_t;
