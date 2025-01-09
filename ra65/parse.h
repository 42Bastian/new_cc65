/*
   This software is copyright 1989 by John Dunning.  See the file
   'COPYLEFT.JRD' for the full copyright notice.
*/

#ifndef _PARSER_H_
#define _PARSER_H_
/* stuff for parser */

struct parse	{
  char * label;		/* line label */
  char * label_suffix;	/* stray non-white chars after label */
  char * opcode;		/* op str */
  char * arg[32];		/* up to 32 arg strings */
  char * comment;		/* comment str */
  int comment_column;	/* where the comment started */
};

/* parse a line into a parse struct */
void parse_line(char * line,struct parse * p,int macrodef);
#endif /* _PARSER_H_ */
