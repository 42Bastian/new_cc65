
/*
  This software is copyright 1989 by John Dunning.  See the file
  'COPYLEFT.JRD' for the full copyright notice.
*/
#ifndef SYMTAB_H
#define SYMTAB_H
#include <stdint.h>

/* stuff for symbol table */

#define SYM struct sym

struct sym
{
  SYM * next;       /* next elt */
  short nbr;        /* for reloc files, sym nbr
                         when linking, module nbr of
                         module that defined it */
  uint16_t value;     /* sym's value */
  uint16_t flags;     /* sym flags */
  uint16_t line;      /* first use */
  uint16_t defline;   /* definition */
  uint16_t local;     /* if a local symbol, here is a counter to differ */
  SYM *rel;         /* rel. to this symbol by value */
  char name[1];     /* name this sym; really longer */
};

/* sym flags */

#define DEFINED  0x0001                 /* has some value */
#define THIS_SEG 0x0002                 /* defined in this seg */
#define GLOBAL   0x0004                 /* globally visible */
#define ABS      0x0008                 /* value is absolute */
#define SYMTEXT  0x0010
#define SYMDATA  0x0020
#define SYMBSS   0x0040
#define SYMBSSZP 0x0080
/* the following bits are only used within ra65 */
#define LOCAL    0x0100     /* only between globals */
#define XREF     0x0200
#define USED     0x0400
#define RELATIVE 0x0800     /* this symbol relative to another */

SYM * find_sym(char *name,int new_ok);
SYM * assign_sym(char *name,
                 char *suffix,
                 int value,
                 int no_redef);

void NextLocal();
#endif /*  SYMTAB_H */
