char * inttype(int type){
	switch (type) {
		case EQUAL:{
			char * R = new char[32];
			strcpy(R, "EQUAL");
			return R;
			break;
		}
		case VALUE_TYPE_NUMBER:{
			char * R = new char[32];
			strcpy(R, "VALUE_TYPE_NUMBER");
			return R;
			break;
		}
		case VALUE_TYPE_STRING:{
			char * R = new char[32];
			strcpy(R, "VALUE_TYPE_STRING");
			return R;
			break;
		}
		case VALUE_TYPE_CHAR:{
			char * R = new char[32];
			strcpy(R, "VALUE_TYPE_CHAR");
			return R;
			break;
		}
		case VALUE_TYPE_NAME:{
			char * R = new char[32];
			strcpy(R, "VALUE_TYPE_NAME");
			return R;
			break;
		}
		case VALUE_TYPE_BOOL:{
			char * R = new char[32];
			strcpy(R, "VALUE_TYPE_BOOL");
			return R;
			break;
		}
		case 0:{
			char * R = new char[32];
			strcpy(R, "NULL");
			return R;
			break;
		}
		default:{
			char * R = new char[32];
			strcpy(R, "UNKNOWN");
			return R;
			break;
		}
	}
}
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
};