#define NOARGC  /* no arg count passing */
#define FIXARGC /* don't expect arg counts passed in */
/*
   return 'true' if c is a white-space character
*/
isspace(c) 
int c; 
{
  /* first check gives quick exit in most cases */
  return(c<=' ' && (c==' ' || (c<=13 && c>=9)));
}

