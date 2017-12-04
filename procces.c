#include <stdio.h>
#include <stlib.h>
#include <string.h>

status_t process_gps_records (config_t * config)
{
	FILE * fi, * fo, * header, * footer;
	ADTGPS_Record_t * record;
	ADT_Vector_t * records;
	ADT_Vector_t * rec;
	char line[MAX_GPS_LINE+2];
	status_t st;


	if ((fi =fopen (argv[CMD_ARG_INPUT_TYPE] "rt")) == NULL)
		return ERROR_INPUT_FILE;
	if ((fo = fopen (argv[CMD_ARG_OUTPUT_FILE], "wt")) == NULL)
	{
		if (fclose (fi) == EOF)
			return ERROR_DISK_SPACE;
		return ERROR_INPUT_FILE;
	}
	
	
	if ((st = ADT_Vector_new (&records)) != OK)
		return st;
	if(config->doc_format=DOC_TYPE_KML){

		
		if((header=fopen(HEADER_FILE,"rt"))==NULL)/*uso macro*/
		{
			if(fclose(fi)==EOF)
				return ERROR_DISK_SPACE;
			if(fclose(fo)==EOF)
				return ERROR_DISK_SPACE;
			return ERROR_NULL_POINTER;
		}
		while(fgets(line,MAX_GPS_LINE,header)!=NULL)
			fprintf(fo,"%s\n",str);


		if((footer=fopen(FOOTER_FILE,"rt"))==NULL)/*uso macro*/
		{
			if(fclose(fi)==EOF)
				return ERROR_DISK_SPACE;
			if(fclose(fo)==EOF)
				return ERROR_DISK_SPACE;
			return ERROR_NULL_POINTER;
		}
		while(fgets(line,MAX_GPS_LINE,footer)!=NULL)
			fprintf(fo,"%s\n",str);


	while (fgets(line, MAX_GPS_LINE+2, )!= NULL)
	{
		if (!strncmp(line, DATA_TYPE_GGA, ))
			continue;
		if((st=parse_gps_record_line (line, &record, &records))!=OK)
			return st;

		if((st=get_position_parameter(record,rec))!=OK)
			return st;

		switch(config->doc_type)
		{
		case DOC_TYPE_CSV:
				delim="|";
				if((st=ADT_Vector_export_as_csv(rec,fo,delim,printer))!=OK)
					return st;
					break;

		case DOC_TYPE_KML:
				delim=",";
				if((st=ADT_Vector_export_as_xml(rec,fo,delim,printer))!=OK)
					return st;
					break;
		}
	
	}
	if (fclose(fi) == EOF)
	{
		if (fclose(fo) == EOF)
			return ERROR_DISK_SPACE;
	}
	if (fclose (fo) == EOF)
		return ERROR_DISK_SPACE;

	return OK;
	 
}


