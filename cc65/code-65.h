/*

  code-65.h

   (c) 1998 42Bastian Schick

   last modified:

   98/08/17   42BS  created

*/

#ifndef CODE_65_H

#define CODE_65_H

void ot(char * str);
void nl();
void ol(char * str);
void oljsr(char * str);
void oljsrpop(char * str);
void olstrdnl(char * str,uintptr_t num);
void olxxxhi();
void olxxxlo();
void konst1(uintptr_t k);
void konst3(uintptr_t k);
void startfun(char * name,int flag);
uintptr_t  char_t_p(char * tptr);
void getmem(char * lbl,char * tptr,char test_p);
void getlmem(uintptr_t lbl,char * tptr,char test_p);
void konst3s(uintptr_t offs);
#ifdef UNSIGNED_FIX
  void lda_helper(char * typestring,char * ext);
#endif
void getladr(uintptr_t offs);
void getloc(uintptr_t offs,char * tptr);
void putloc(uintptr_t offs,char * tptr);
void putmem(char * lab,char * tptr);
void putlmem(uintptr_t lab,char * tptr);
void putstk(struct expent * lval);
void indirect(struct expent * lval);
void save();
void rstr();
void immed(uintptr_t );
void immedgbl(uintptr_t i);
void immedlab(uintptr_t i);
void immedslt(uintptr_t i);

void tst();
void push();
void push1();
void swapstk();
void call(char * lbl,int narg);
void ret(uintptr_t ret);
void callstk(uintptr_t narg);
void jump(uintptr_t label);
void casejump();
void truejump(uintptr_t label,int invert);
void falsejump(uintptr_t labelint ,int invert);
void otx(char * str);
void mod_internal(uintptr_t k,char * verb1,char * verb2);
int  modstk(uintptr_t newsp);
void doublereg();
void add();
void sub();
void mult();
void _div();
void mod();
void or();
void xor();
void and();
void asr();
void asl();
void aslprim(uintptr_t n);
void incprim(uintptr_t n);
void decprim(uintptr_t n);
void neg();
void lneg();
void com();
void inc();
void dec();
void eq();
void eq0();
void ne();
void lt(int nosign);
void le(int nosign);
void gt(int nosign);
void ge(int nosign);
void outdec(uintptr_t numbr);
void outdecnl(uintptr_t n);
void outcch(uintptr_t numbr);
void outlabledef(uintptr_t lbl,uintptr_t value);
void outlab(uintptr_t lbl);
void outlabnl(uintptr_t lbl);
void outcdf(uintptr_t labl);
void outdat(uintptr_t n);
void outslt(uintptr_t n);
void outsp(uintptr_t n);
void outbv(char * bytes,int nbytes);
void wordpref();
void bytepref();
void outabsdecl(char *n,uintptr_t value);
void outgbl(char * name);
void outgblnl(char * name);
void outgblc(char * name);
void outgoe(char * sname);
void outext(char *);
int  popsp();
int  pushsp();
void SaveRegs(int base,int cnt);
void RestoreRegs(int base,int cnt);
void segdata();
void segtext();
void segbss();
void segbsszp();


#endif
