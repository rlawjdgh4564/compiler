#ifndef PRINT_H
#define PRINT_H

#include "expr.h"

struct PROGRAM *head;

 void dfs (void);
 void Program(struct PROGRAM *program);
 void Decl(struct DECLARATION *declaration);
 void Func(struct FUNCTION *function);
 void Ident(struct IDENTIFIER *ident);
 void Param(struct PARAMETER *param);
 void Compound(struct COMPOUNDSTMT *comp);
 void Stmt(struct STMT *stmt);
 void Assign(struct ASSIGN *assign);
 void AssignStmt(struct ASSIGN *assign);
 void Call(struct CALL *call);
 void While_s(struct WHILE_S *while_);
 void For_s(struct FOR_S *for_);
 void If_s(struct IF_S *if_);
 void Switch_s(struct SWITCH_S *switch_);
 void Case(struct CASE *case_);
 void Expr(struct EXPR *expr);
 void Unop(struct UNOP *unop);
 void Addiop(struct ADDIOP *add);
 void Multop(struct MULTOP *mult);
 void Relaop(struct RELAOP *rela);
 void Eqltop(struct EQLTOP *eqlt);
 void Id_s(struct ID_S *id);
 void Arg(struct ARG *arg);
 void Type(Type_e x);
 void print_func_name(struct FUNCTION* function);
 void print_func_name2(struct COMPOUNDSTMT *comp);

#endif