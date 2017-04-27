char * inttype(int type){
	switch (type) {
		case EQUAL:{
			char * R = new char[32];
			strcpy(R, "EQUAL");
			return R;
			break;
		}
		case NUMBER:{
			char * R = new char[32];
			strcpy(R, "NUMBER");
			return R;
			break;
		}
		case STRING:{
			char * R = new char[32];
			strcpy(R, "STRING");
			return R;
			break;
		}
		case CHAR:{
			char * R = new char[32];
			strcpy(R, "CHAR");
			return R;
			break;
		}
		case NAME:{
			char * R = new char[32];
			strcpy(R, "NAME");
			return R;
			break;
		}
		case BOOL:{
			char * R = new char[32];
			strcpy(R, "BOOL");
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