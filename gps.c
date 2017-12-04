/*gps.c*/

status_t parse_gps_record_line (const char * line, ADTGPS_Record_t ** fields,ADT_Vector_t ** pv)
{
	double lat, _long, sea_lev;
	char * temp;
	status_t st;
	char delim = ',';
	size_t n_fields = MAX_FIELDS;
	if (str == NULL || pv == NULL)
		return ERROR_NULL_POINTER;
	
	if((st=split(line,n_fields ,fields,delim))!=OK)
		return st;


	
	


	if (_long = strtol (*fields [LONGITUDE], &temp, 10))
	{
		if (*temp)
			return ERROR_PARSE_DATA;
		(*temp) = NULL;
		if ((st = ADT_Vector_set_element (pv, &_long)) != OK)
				return st;
	}
	if (lat = strtol (*fields [LATITUDE], &temp, 10)
	{
		if (*temp)
			return ERROR_PARSE_DATA;
		(*temp) = NULL;
		if ((st = ADT_Vector_set_element (pv, &lat)) != OK)
			return st;
	}
	if (sea_lev = strtol (*fields [SEA_LVEL], &temp, 10)
	{
		if (*temp)
			return ERROR_PARSE_DATA;
		(*temp) = NULL;
		if ((st = ADT_Vector_set_element (pv, &sea_lev)) != OK)
			return st;
	}
	return OK;
}


