%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"
#include "print.h"
%}

%union {
   struct PROGRAM *ptr_prog;
   struct DECLARATION *ptr_decl;
   struct FUNCTION *ptr_func;
   struct IDENTIFIER *ptr_ident;
   struct PARAMETER *ptr_param;
   struct COMPOUNDSTMT *ptr_comp;
   struct STMT *ptr_stmt;
   struct CASE *ptr_case;
   struct SWITCH_S *ptr_switch;
   struct ASSIGN *ptr_ass;
   struct CALL *ptr_call;
   struct ARG *ptr_arg;
   struct WHILE_S *ptr_while;
   struct FOR_S *ptr_for;
   struct IF_S *ptr_if;
   struct EXPR *ptr_expr;
   struct UNOP *ptr_unop;
   struct ADDIOP *ptr_addi;
   struct MULTOP *ptr_mult;
   struct RELAOP *ptr_rela;
   struct EQLTOP *ptr_eqlt;
   struct ID_S *ptr_id;
   int ptr_type;
   int intnum;
   float floatnum;
   char* id;
}

%token <intnum>INTNUM <floatnum>FLOATNUM <id>Id INT FLOAT COLON RETURN WHILE IF DO ELSE FOR SWITCH CASE DEFAULT BREAK COMMA SEMI


%right INSERT
%left <ptr_eqlt>EQLT
%left <ptr_rela>RELA
%left '+' '-'
%left <ptr_mult>MULT
%right UNOP
%left L R
%left LL RR
%left LLL RRR
// %left '*' '/'
// %left '+' '-'

%type <ptr_prog> Program;
%type <ptr_decl> DeclList;
%type <ptr_decl> Declaration;
%type <ptr_func> Function;
%type <ptr_func> FuncList;
%type <ptr_ident> Identifier;
%type <ptr_ident> IdentList;
%type <ptr_param> ParamList;
%type <ptr_comp> CompoundStmt;
%type <ptr_stmt> StmtList;
%type <ptr_stmt> Stmt;
%type <ptr_case> CaseList;
%type <ptr_switch> SwitchStmt;
%type <ptr_ass> AssignStmt;
%type <ptr_ass> Assign;
%type <ptr_call> Call;
%type <ptr_call> CallStmt;
%type <ptr_arg> ArgList;
%type <ptr_while> WhileStmt;
%type <ptr_for> ForStmt;
%type <ptr_if> IfStmt;
%type <ptr_expr> RetStmt;
%type <ptr_expr> Expr;
%type <ptr_type> Type;

%%
Program : DeclList FuncList {
   printf("decl func\n");
   struct PROGRAM *program = (struct PROGRAM *) malloc (sizeof (struct PROGRAM));


   program->decl = $1;
   program->func = $2;

   head = program;
   
   $$ = program;
}
   | DeclList {
      printf("decl\n");
      struct PROGRAM *program = (struct PROGRAM *) malloc (sizeof (struct PROGRAM));

      head = program;
      program->decl = $1;      
      program->func = NULL;
      $$ = program;
}
   | FuncList {
      printf("func\n");
      struct PROGRAM *program = (struct PROGRAM *) malloc (sizeof (struct PROGRAM));

      head = program;
      program->decl = NULL;
      program->func = $1;
      $$ = program;
}
   | {
      head = NULL;
      $$ = NULL;
   }

   ;

DeclList : Declaration {
   printf("declist\n");
   $$ = $1;
}
   | DeclList Declaration {
      printf("decl declaration\n");
      $2->prev = $1;
      $$ = $2;
}
;

FuncList : Function {
   printf("function\n");
   $$ = $1;
}
   | FuncList Function {
      printf("func function\n");
      $2->prev = $1;
      $$ = $2;
}
;

Declaration : Type IdentList SEMI {
   printf("declaration\n");
   struct DECLARATION *declaration = (struct DECLARATION *) malloc (sizeof (struct DECLARATION));

   declaration->t = $1;
   declaration->id = $2;

   $$ = declaration;
   
}
;

IdentList : Identifier {
   printf("identlist\n");
   $$ = $1;
}
   | IdentList COMMA Identifier {
      printf("identlist,\n");
      $3->prev = $1;
      $$ = $3;
}
;

Identifier : Id {
   printf("identifier\n");
   struct IDENTIFIER * identifier = (struct IDENTIFIER *) malloc (sizeof (struct IDENTIFIER));

   identifier->ID = $1;
   identifier->intnum = 0;
   $$ = identifier;
}
   | Id LLL INTNUM RRR {
      printf("id[intnum]\n");
      struct IDENTIFIER * identifier = (struct IDENTIFIER *) malloc (sizeof (struct IDENTIFIER));

      identifier->ID = $1;
      identifier->intnum = $3;
      $$ = identifier;      
}
;

Function : Type Id L R CompoundStmt {
   printf("func()\n");
   struct FUNCTION *func = (struct FUNCTION *) malloc (sizeof (struct FUNCTION));

   func->t = $1;
   func->ID = $2;
   func->param = NULL;
   func->cstmt = $5;
   $$ = func;
}
   | Type Id L ParamList R CompoundStmt {
      printf("func(param)\n");
   struct FUNCTION *func = (struct FUNCTION *) malloc (sizeof (struct FUNCTION));

   func->t = $1;
   func->ID = $2;
   func->param = $4;
   func->cstmt = $6;
   $$ = func;
}
;

ParamList : Type Identifier {
   printf("type identifier\n");
   struct PARAMETER *param = (struct PARAMETER *) malloc (sizeof (struct PARAMETER));

   param->t = $1;
   param->id = $2;
   $$ = param;
} 
   | ParamList COMMA Type Identifier {
      printf("prarm, prarm\n");
      struct PARAMETER *param = (struct PARAMETER *) malloc (sizeof (struct PARAMETER));

      param->t = $3;
      param->id = $4;
      param->prev = $1;
      $$ = param;      
}
;

Type : INT {
   printf("int\n");
   $$ = eInt;
}
   | FLOAT {
      printf("float\n");
      $$ = eFloat;
}
;   

CompoundStmt : LL StmtList RR {
   printf("{ stmt }\n");
   struct COMPOUNDSTMT *comp = (struct COMPOUNDSTMT *) malloc (sizeof (struct COMPOUNDSTMT));

   comp->decl = NULL;
   comp->stmt = $2;   
   $$ = comp;
}
   | LL DeclList StmtList RR {
      printf("{ decl stmt }\n");
      struct COMPOUNDSTMT *comp = (struct COMPOUNDSTMT *) malloc (sizeof (struct COMPOUNDSTMT));

      comp->decl = $2;
      comp->stmt = $3;
      $$ = comp;
}
;

StmtList : Stmt {
      $$ = $1;
}
   | StmtList Stmt {
      printf(" stmtlist \n");
      $2->prev = $1;
      $$ = $2;
}
   | { 
      struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));
      st = NULL;
      $$ = st;
   }
;

Stmt : AssignStmt {
      printf("assignstmt\n");
      struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eAssign;
      st->stmt.assign_ = $1;
       $$ = st;
}
    | CallStmt {
       printf("callstmt\n");
      struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eCall;
      st->stmt.call_ = $1;
      $$ = st;
}
    | RetStmt {
       printf("retstmt\n");
       struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eRet;
      st->stmt.return_ = $1;
      $$ = st;
}
    | WhileStmt {
       printf("whilestmt\n");
       struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eWhile;
      st->stmt.while_ = $1;
      $$ = st;
}
     | ForStmt {
        printf("forstmt\n");
        struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eFor;
      st->stmt.for_ = $1;
      $$ = st;
}
     | IfStmt {
        printf("ifstmt\n");
         struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eIf;
      st->stmt.if_ = $1;
      $$ = st;
}
    | SwitchStmt {
       printf("swtichstmt\n");
       struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eSwitch;
      st->stmt.switch_ = $1;
      $$ = st;
}
    | CompoundStmt {
       printf("compoundstmt\n");
       struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eCompound;
      st->stmt.cstmt_ = $1;
      $$ = st;
}
   | SEMI {
      struct STMT *st = (struct STMT *) malloc (sizeof (struct STMT));

      st->s = eSemi;
      $$ = st;
}
;

AssignStmt : Assign SEMI{
   printf("assignst\n");
   $$ = $1;
}
;

Assign : Id INSERT Expr {
   printf("id = expr \n");
   struct ASSIGN *ass = (struct ASSIGN *) malloc (sizeof (struct ASSIGN));

   ass->ID = strdup($1);
   ass->index = NULL;
   ass->expr = $3;
   $$ = ass;

}
   | Id LLL Expr RRR INSERT Expr {
      printf("id[expr] = expr\n");
      struct ASSIGN *ass = (struct ASSIGN *) malloc (sizeof (struct ASSIGN));

      ass->ID = strdup($1);
      ass->index = $3;
      ass->expr = $6;
      $$ = ass;
}
;

CallStmt : Call SEMI{
   printf("callst\n");
   $$ = $1;
}
;

Call : Id L R {
   printf("id ()\n");
   struct CALL *call = (struct CALL *) malloc (sizeof (struct CALL));

   call->ID = strdup($1);
   $$ = call;
}
   | Id L ArgList R {
      printf("id (arg)\n");
      struct CALL *call = (struct CALL *) malloc (sizeof (struct CALL));

      call->ID = strdup($1);
      call->arg = $3;

      $$ = call;      
}
;

RetStmt : RETURN SEMI{
   printf("return ;\n");
   $$ = NULL;
}
   | RETURN Expr SEMI {
      printf("return expr\n");
      $$ = $2;
}
;

WhileStmt : WHILE L Expr R Stmt {
   printf("while(expr) stmt\n");
   struct WHILE_S *wh = (struct WHILE_S *) malloc (sizeof (struct WHILE_S));

   wh->do_while = false;
   wh->cond = $3;
   wh->stmt = $5;
   $$ = wh;   
}
   | DO Stmt WHILE L Expr R SEMI {
      printf("do stmt while (expr);\n");
      struct WHILE_S *wh = (struct WHILE_S *) malloc (sizeof (struct WHILE_S));

      wh->do_while = true;
      wh->cond = $5;
      wh->stmt = $2;
      $$ = wh;         
}
;

ForStmt : FOR L Assign SEMI Expr SEMI Assign R Stmt {
   printf("for (assign;expr;assign) stmt\n");
   struct FOR_S *fo = (struct FOR_S *) malloc (sizeof (struct FOR_S));

   fo->init = $3;
   fo->cond = $5;
   fo->inc = $7;
   fo->stmt = $9;
   $$ = fo;
}
;

IfStmt : IF L Expr R Stmt {
   printf("if(expr) stmt\n");
   struct IF_S *if_s = (struct IF_S *) malloc (sizeof (struct IF_S));

   if_s->cond = $3;
   if_s->if_ = $5;
   if_s->else_ = NULL;
   $$ = if_s;
}
   | IF L Expr R Stmt ELSE Stmt {
      printf("if(expr) stmt else stmt\n");
      struct IF_S *if_s = (struct IF_S *) malloc (sizeof (struct IF_S));

      if_s->cond = $3;
      if_s->if_ = $5;
      if_s->else_ = $7;
      $$ = if_s;
}
;

SwitchStmt : SWITCH L Identifier R LL CaseList RR {
   printf("switch (identifier) { caselist }\n");
   struct SWITCH_S *swi = (struct SWITCH_S *) malloc (sizeof (struct SWITCH_S));

   swi->identifier = $3;
   swi->case_ = $6;
   $$ = swi;
}
;

CaseList : CASE INTNUM COLON StmtList{
   printf("case 1: stmt\n");
    struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));
    
    ca->break_ = false;
    ca->intnum = $2;
    ca->stmt = $4;
    ca->prev = NULL;
    $$ = ca;
}
    | CASE INTNUM COLON StmtList BREAK SEMI{
       printf("case 1: stmt break;\n");
       struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));
        
        ca->break_ = true;
        ca->intnum = $2;
        ca->stmt = $4;
        ca->prev = NULL;
        $$ = ca;
}
    | DEFAULT COLON StmtList {
       printf("default : stmt\n");
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca->break_ = false;
        ca->intnum = 0;
        ca->stmt = $3;
        ca->prev = NULL;
        $$ = ca;
}
   | DEFAULT COLON StmtList BREAK SEMI {
         printf("default : stmt break;\n");
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca->break_ = true;
        ca->intnum = 0;
        ca->stmt = $3;
        ca->prev = NULL;
        $$ = ca;
}
   | CASE INTNUM COLON StmtList CaseList {
      printf("case 1 : stmt caselist\n");
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca->break_ = false;
        ca->intnum = $2;
        ca->stmt = $4;
        ca->prev = $5;
        $$ = ca;
}
   | CASE INTNUM COLON StmtList BREAK SEMI CaseList {
      printf("case 1 : stmtlist break; caselist\n");
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca->break_ = true;
        ca->intnum = $2;
        ca->stmt = $4;
        ca->prev = $7;
        $$ = ca;
}
   | {      
        struct CASE *ca = (struct CASE *) malloc (sizeof (struct CASE));

        ca = NULL;
        $$ = ca;
}
;

Expr : UNOP Expr {
   printf("-expr\n");
   struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
   struct UNOP *un = (struct UNOP *) malloc (sizeof (struct UNOP));

   ex->e = eUnop;
   un->u = eNegative;
   un->expr = $2;
   ex->expression.unop_ = un;
   
   $$ = ex;
}
   | Expr '+' Expr {
      printf("expr addi expr\n");
      struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
      struct ADDIOP *addi = (struct ADDIOP *) malloc (sizeof (struct ADDIOP));

      ex->e = eAddi;
      addi->a = ePlus;
      addi->lhs = $1;
      addi->rhs = $3;
      ex->expression.addiop_ = addi;
      
      $$ = ex;

}
   | Expr UNOP Expr {
      printf("expr addi expr\n");
      struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
      struct ADDIOP *addi = (struct ADDIOP *) malloc (sizeof (struct ADDIOP));

      ex->e = eAddi;
      addi->a = eMinus;
      addi->lhs = $1;
      addi->rhs = $3;
      ex->expression.addiop_ = addi;
      
      $$ = ex;

}
    | Expr MULT Expr {
       printf("expr mult expr\n");
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct MULTOP *mult = $2;

       ex->e = eMulti;
       mult->lhs = $1;
       mult->rhs = $3;
       ex->expression.multop_ = mult;

       $$ = ex;
}   
    | Expr RELA Expr {
       printf("expr rela expr\n");
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct RELAOP *rela = $2;

       ex->e = eRela;       
       rela->lhs = $1;
       rela->rhs = $3;
       ex->expression.relaop_ = rela;

       $$ = ex;
}
    | Expr EQLT Expr {
       printf("expr eqlt expr\n");
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct EQLTOP *eql = $2;

       ex->e = eEqlt;       
       eql->lhs = $1;
       eql->rhs = $3;
       ex->expression.eqltop_ = eql;

       $$ = ex;

}
    | Call {
       printf("call!!\n");
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct CALL *call = (struct CALL *) malloc (sizeof (struct CALL));

       ex->e = eCallExpr;   
       ex->expression.call_ = $1;
       $$ = ex;
}
    | INTNUM {
       printf("intnum\n");
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));

       ex->e = eIntnum;
       ex->expression.intnum = $1;
       $$ = ex;
}   
    | FLOATNUM {
       printf("floatnum\n");
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));

       ex->e = eFloatnum;
       ex->expression.floatnum = $1;
       $$ = ex;
}
    | Id {
       printf("id\n");
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct ID_S *id = (struct ID_S *) malloc (sizeof (struct ID_S));

       ex->e = eId;
       id->ID = strdup($1);
       ex->expression.ID_ = id;
       $$ = ex;
}
    | Id LLL Expr RRR {
       printf("id[expr]\n");
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));
       struct ID_S *id = (struct ID_S *) malloc (sizeof (struct ID_S));

       ex->e = eId;
       id->ID = strdup($1);
       id->expr = $3;
       ex->expression.ID_ = id;
       $$ = ex;
}
    | L Expr R {
       printf("(expr)\n");
       struct EXPR *ex = (struct EXPR *) malloc (sizeof (struct EXPR));       

       ex->e = eExpr;
       ex->expression.bracket = $2;
       $$ = ex;
}
;

ArgList : Expr {
      printf("arg expr\n");
       struct ARG *arg = (struct ARG *) malloc(sizeof(struct ARG ));
       arg->expr = $1;
       arg->prev = NULL;
       $$ = arg;
}
   | ArgList COMMA Expr {
         printf("arg, expr\n");
       struct ARG *arg = (struct ARG *) malloc(sizeof(struct ARG ));
       arg->expr = $3;
       arg->prev = $1;
       $$ = arg;
}
;    
%%

int yyerror (char *s) {
   return fprintf (stderr, "%s\n", s);
}