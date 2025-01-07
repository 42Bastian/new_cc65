
/*
   This software is copyright 1989 by John Dunning.  See the file
   'COPYLEFT.JRD' for the full copyright notice.
*/

/* entry pts for code generator */

#include "symtab.h"

void genlit(char byte);
void genbyte(int byte, int flags, SYM * sym);
void genword(int word, int flags, SYM * sym);
void gen_label();
int gen_n_passes();
