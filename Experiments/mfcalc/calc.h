#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef double (*func_t) (double);
//Data type for links in the chain of symbols
struct symrec {
	char *name; /* name of symbol */
	int type; /* type of symbol: either VAR or FNCT */
	union {
		double var_double; /* value of a VAR as a double*/
		int var_int; /* value of a VAR as as integer*/
		func_t fnctptr; /* value of a FNCT */
	} value;
	struct symrec *next; /* link field */
};
typedef struct symrec symrec;
/* The symbol table: a chain of 'struct symrec'. */
extern symrec *sym_table;
symrec *putsym (char const *, int);
symrec *getsym (char const *);
struct init {
	char const *fname;
	double (*fnct) (double);
};
struct cons {
	char const *cname;
	double value;	
};
struct init const arith_fncts[] = {
	{"sin", sin},
	{"arcsin", asin},
	{"cos", cos},
	{"arccos", acos},
	{"tan", tan},
	{"arctan", atan},
	{"exp", exp},
	{"ln", log},
	{"sqrt", sqrt},
	{0, 0},
};
struct cons const arith_consts[] = {
	{"pi", 3.14159},
	{"e", 2.71828},
	{0, 0},
};
/* The symbol table: a chain of 'struct symrec'. */
symrec *sym_table;
/* Put arithmetic functions in table. */
