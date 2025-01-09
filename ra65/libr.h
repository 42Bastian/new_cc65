
/*
  This software is copyright 1989 by John Dunning.  See the file
  'COPYLEFT.JRD' for the full copyright notice.
*/

/* defs for library files
   A library file consists of a header lump, as described below, some number
   of module descriptors, and images of files.

   magic number identifies library files */

#ifndef _LIBR_H_
#define _LIBR_H_

#include <stdint.h>

#define LIBR_HEADER 0xFCFC

struct librfile
{
  uint16_t l_header;	/* magic num, as above */
  uint16_t type;		/* type of library, values below */
  uint16_t n_modules;	/* number modules this library */
  uint16_t l_flags;		/* (l_flags) library flags, defined below */
};

/* library types */
#define LT_OLB	1			/* an object library */

/* flags for object libraries */
#define LOLB_DEF	0x0001		/* library contains a symbol dictionary */

/* a module of the library */
struct librmod
{
  char m_name[12];		/* entry name, typically file name */
  uint16_t m_nbytes;		/* n bytes in entry */
};

#endif /* _LIBR_H_ */
