%{
#include <stdlib.h>
#include <string.h>

#include "expr.tab.h"
#include "expr.h"
%}

space [ \t\r\n]
unop [\-]
addiop [\+]
multop [\*\/]
relaop [\<\>][\=]?
eqltop [\=\!][\=]
brac [\(\)\{\}\[\]]
intnum [0-9]+
floatnum [0-9]+.[0-9]+
int int
float float
for for
return return
while while
if if
do do
else else
switch switch
case case
default default
break break
id [A-Za-z][A-Za-z0-9\_]*

%%

{space} {
	break;
}

{unop} { 
	return UNOP;
}

{addiop} {
	
	if(yytext[0] == '+'){
		return '+';
	}else if(yytext[0] == '-'){
		return '-';
	}	
}

{multop} {
	struct MULTOP *mult = (struct MULTOP *) malloc (sizeof(struct MULTOP));
	if(yytext[0] == '*'){	
		mult->m = eMult;			
	}else{
		mult->m = eDiv;
	}
	yylval.ptr_mult = mult;
	return MULT;
}

{relaop} {
	struct RELAOP *rela = (struct RELAOP *) malloc (sizeof(struct RELAOP));
	if(yytext[0] == '<'){
		rela->r = eLT;
	}else if(yytext[0] == '>'){
		rela->r = eGT;
	}else if( !strcmp(yytext,"<=")){
		rela->r = eLE;
	}else if( !strcmp(yytext,">=")){
		rela->r = eGE;
	}
	yylval.ptr_rela = rela;
	return RELA;
}

{eqltop} {
	struct EQLTOP *eqlt = (struct EQLTOP *) malloc (sizeof (struct EQLTOP));
	if(!strcmp(yytext,"==")){
		eqlt->e = eEQ;		
	}else if(!strcmp(yytext,"!=")){
		eqlt->e = eNE;
	}
	yylval.ptr_eqlt = eqlt;
	return EQLT;
}

{brac} {

	if(yytext[0] == '('){
		return L;
	}else if(yytext[0] == ')'){
		return R;
	}else if(yytext[0] == '{'){
		return LL;
	}else if(yytext[0] == '}'){
		return RR;
	}else if(yytext[0] == '['){
		return LLL;
	}else if(yytext[0] == ']'){
		return RRR;
	}
	
}

"," {
	return COMMA;
}

";" {
	return SEMI;
}

"=" { 
	return INSERT; 
}

":" { 
	return COLON; 
}

{intnum} {
	yylval.intnum = atoi (yytext);
	return INTNUM;
}

{floatnum} {
	yylval.floatnum = atof (yytext);
	return FLOATNUM;
}

{int} { 
	return INT; 
}

{float} { 
	return FLOAT; 
}

{for} { 
	return FOR;
}

{return} { 
	return RETURN;
}

{while} { 
	return WHILE;
}

{if} { 
	return IF;
}

{do} { 
	return DO;
}

{else} { 
	return ELSE;
}

{switch} { 
	return SWITCH;
}

{case} { 
	return CASE;
}

{default} { 
	return DEFAULT;
}

{break} { 
	return BREAK;
}

{id} {
	yylval.id = strdup(yytext); 
	return Id; 
}
