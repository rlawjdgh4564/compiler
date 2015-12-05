#include <stdio.h>
#include "expr.h"
#include "print.h"
#include <stdlib.h>
#include <string.h>

FILE *fp;
FILE *fp1;
int count = 0;
int whilec = 0;
int forc = 0;
int ifc = 0;
int switchc = 0;

char f[1000];
int main () {
   fp = fopen ("sample.out", "w");
   fp1 = fopen ("sample1.out", "w");

   if (!yyparse ())
      dfs ();
    
   fclose (fp);
   fclose (fp1);

   return 0;

}

void dfs() {
   if(head == NULL) {
      fprintf (stderr, "expression does not exist.\n");
      return;
   }
   
   Program (head);
}

void Program(struct PROGRAM *program){
   if(program == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(head == NULL){ }
   else if(program->func == NULL){
      Decl(program->decl);
   }
   else if(program->decl == NULL){
      Func(program->func);
   }
   else{
      Decl(program->decl);
      Func(program->func);
   }
}

void Decl(struct DECLARATION *declaration){

   count = 0;
   if(declaration == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(declaration->prev == NULL){
      Type(declaration->t);
      count++;
      if(declaration->t == eInt){
         fprintf (fp1,"     %d\tint", count);   
      }else{
         fprintf (fp1,"     %d\tfloat", count);
      }
      Ident(declaration->id);
   }
   else {
      Decl(declaration->prev);
      count++;
      Type(declaration->t);
      if(declaration->t == eInt){
         fprintf (fp1,"     %d\tint", count);
      }else{
         fprintf (fp1,"     %d\tfloat", count);
      }
      Ident(declaration->id);
      
   }
   fprintf(fp,";\n");

}

void Func(struct FUNCTION *function){
   strcpy(f, function->ID);

   whilec = 0;
   forc = 0;
   switchc = 0;
   ifc = 0;

   fprintf(fp1, "Function name : %s\n", function->ID);
   fprintf(fp1, "     count\ttype\tname\tarray\trole\n");

   if(function == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(function->prev == NULL){
      Type(function->t);
      fprintf(fp, "%s ", function->ID);
      fprintf(fp, "(");
      if(function->param == NULL){}
      else{
         Param(function->param);
      }
      fprintf(fp, ") ");
      Compound(function->cstmt);
   }
   else {
      Func(function->prev);
      Type(function->t);
      fprintf(fp, "%s ", function->ID);
      fprintf(fp, "(");
      if(function->param == NULL){}
      else{
         Param(function->param);
      }
      fprintf(fp, ") ");
      Compound(function->cstmt);
   }
}

void Ident(struct IDENTIFIER *ident){
   if(ident == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(ident->prev == NULL){
      if(ident->intnum == 0){
         fprintf(fp, "%s", ident->ID);
         fprintf(fp1, "\t%s\tvariable\n", ident->ID);
      }
      else{
         fprintf(fp, "%s", ident->ID);
         fprintf(fp, "[");
         fprintf(fp, "%d", ident->intnum);
         fprintf(fp, "]");
         fprintf(fp1, "\t%s\t%d\tvariable\n", ident->ID, ident->intnum);
      }
   }
   else {
      Ident(ident->prev);
      fprintf(fp, ",");
      if(ident->intnum == 0){
         fprintf(fp, "%s", ident->ID);
         fprintf(fp1, "\t%s\tvariable\n", ident->ID);
      }
      else{
         fprintf(fp, "%s", ident->ID);
         fprintf(fp, "[");
         fprintf(fp, "%d", ident->intnum);
         fprintf(fp, "]");
         fprintf(fp1, "\t%s\t%d\tvariable\n", ident->ID, ident->intnum);
      }
   }
}

void Param(struct PARAMETER *param){
   if(param == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(param->prev == NULL){
      Type(param->t);
      Ident(param->id);
   }
   else{
      Param(param->prev);
      fprintf(fp, ",");
      Type(param->t);
      Ident(param->id);
   }
}

void Compound(struct COMPOUNDSTMT *comp){
   
   if(comp == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   fprintf(fp, "{\n");
   if(comp->decl == NULL){
      Stmt(comp->stmt);
   }
   else{
      Decl(comp->decl);
      Stmt(comp->stmt);
   }   
   fprintf(fp, "}\n");      
}

void Stmt(struct STMT *stmt){
   if(stmt == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(stmt->prev == NULL){
      switch(stmt->s){
         case eAssign :
            AssignStmt(stmt->stmt.assign_);
            break;
         case eCall:            
            Call(stmt->stmt.call_);
            break;
         case eRet:
            fprintf(fp, "return ");
            if(stmt->stmt.return_ == NULL){}
            else {
               Expr(stmt->stmt.return_);
            }
            fprintf(fp, ";\n");
            break;
         case eWhile:
            While_s(stmt->stmt.while_);
            break;
         case eFor:
            For_s(stmt->stmt.for_);
            break;
         case eIf:
            If_s(stmt->stmt.if_);
            break;
         case eCompound:
            Compound(stmt->stmt.cstmt_);
            break;
         case eSwitch:
            Switch_s(stmt->stmt.switch_);
            break;
         default :
            fprintf(stderr,"no stmt.\n");
      }
   }
   else{
      Stmt(stmt->prev);
      switch(stmt->s){
         case eAssign :
            AssignStmt(stmt->stmt.assign_);
            break;
         case eCall:
            Call(stmt->stmt.call_);
            break;
         case eRet:
            fprintf(fp, "return ");
            if(stmt->stmt.return_ == NULL){}
            else {
               Expr(stmt->stmt.return_);
            }
            fprintf(fp, ";\n");
            break;
         case eWhile:
            While_s(stmt->stmt.while_);
            break;
         case eFor:
            For_s(stmt->stmt.for_);
            break;
         case eIf:
            If_s(stmt->stmt.if_);
            break;
         case eCompound:
            Compound(stmt->stmt.cstmt_);
            break;
         case eSwitch:
            Switch_s(stmt->stmt.switch_);
            break;
         default :
            fprintf(stderr,"no stmt.\n");
      }
   }
}

void Assign(struct ASSIGN *assign){
   if(assign == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(assign->index == NULL){
      fprintf(fp, "%s ", assign->ID);
      fprintf(fp, "= ");
      Expr(assign->expr);
   }
   else{
      fprintf(fp, "%s", assign->ID);
      fprintf(fp, "[");
      Expr(assign->index);
      fprintf(fp, "] ");
      fprintf(fp, "= ");
      Expr(assign->expr);
   }

}

void AssignStmt(struct ASSIGN *assign){
   if(assign == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   Assign(assign);
   fprintf(fp, ";\n");
}

void Call(struct CALL *call){
   if(call == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(call->arg == NULL){
      fprintf(fp, "%s()", call->ID);
   }
   else{
      fprintf(fp, "%s(", call->ID);
      Arg(call->arg);
      fprintf(fp, ")");
   }
   fprintf(fp, ";\n");
}


void While_s(struct WHILE_S *while_){
   
   if(while_ == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   count = 0;
   whilec ++;

   if(while_->stmt->s == eCompound){
      if(while_->stmt->stmt.cstmt_->decl){
         fprintf(fp1, "Function name : %s - WHILE(%d)\n", f, whilec);
         fprintf(fp1, "     count\ttype\tname\tarray\trole\n");
      }
   }
   
   if(while_->do_while == false){
      fprintf(fp, "while (");
      Expr(while_->cond);
      fprintf(fp, ") ");
      Stmt(while_->stmt);
   }
   else{
      fprintf(fp, "do ");
      Stmt(while_->stmt);
      fprintf(fp, "while (");
      Expr(while_->cond);
      fprintf(fp, ");\n");
   }
}

void For_s(struct FOR_S *for_){
   if(for_ == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   count = 0;
   forc ++;

   if(for_->stmt->s == eCompound){
      if(for_->stmt->stmt.cstmt_->decl){
         fprintf(fp1, "Function name : %s - FOR(%d)\n", f, forc);
         fprintf(fp1, "     count\ttype\tname\tarray\trole\n");
      }
   }

   fprintf(fp, "for (");
   Assign(for_->init);
   fprintf(fp, "; ");
   Expr(for_->cond);
   fprintf(fp, "; ");
   Assign(for_->inc);
   fprintf(fp, ") ");
   Stmt(for_->stmt);
}

void If_s(struct IF_S *if_){
   if(if_ == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   count = 0;
   ifc ++;
   if(if_->if_->s == eCompound){
      if(if_->if_->stmt.cstmt_->decl){
         fprintf(fp1, "Function name : %s - IF(%d)\n", f, ifc);
         fprintf(fp1, "     count\ttype\tname\tarray\trole\n");
      }
   }

   if(if_->else_ == NULL){
      fprintf(fp, "if (");
      Expr(if_->cond);
      fprintf(fp, ") ");
      Stmt(if_->if_);
   }
   else{
      fprintf(fp, "if (");
      Expr(if_->cond);
      fprintf(fp, ") ");
      Stmt(if_->if_);
      fprintf(fp, "else ");
      Stmt(if_->else_);
   }
}

void Switch_s(struct SWITCH_S *switch_){
   if(switch_ == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   count = 0;
   switchc ++;
   while(1){
      if(!switch_->case_){
         break;
      }
      if(switch_->case_->stmt->s == eCompound && switch_->case_->stmt->stmt.cstmt_->decl){
         fprintf(fp1, "Function name : %s - SWITCH(%d)\n", f, switchc);
         fprintf(fp1, "     count\ttype\tname\tarray\trole\n");
      }
      else{
         switch_->case_ = switch_->case_->prev;
      }
   }

   fprintf(fp, "switch (");
   Ident(switch_->identifier);
   fprintf(fp, "){\n");
   Case(switch_->case_);
   fprintf(fp, "}\n");
}

void Case(struct CASE *case_){
   if(case_ == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   
   if(case_->break_ == false){
      if(case_->prev == NULL){
         fprintf(fp, "case ");
         fprintf(fp, "%d:", case_->intnum);
         Stmt(case_->stmt);
      }
      else{
         if(case_->intnum == 0){
            Case(case_->prev);
            fprintf(fp, "default :");
            Stmt(case_->stmt);
         }
         else{
            Case(case_->prev);
            fprintf(fp, "case ");
            fprintf(fp, "%d:", case_->intnum);
            Stmt(case_->stmt);
         }
      }
   }
   else{
      if(case_->prev == NULL){
         fprintf(fp, "case ");
         fprintf(fp, "%d:", case_->intnum);
         Stmt(case_->stmt);
         fprintf(fp, "break ;\n");
      }
      else{
         if(case_->intnum == 0){
            Case(case_->prev);
            fprintf(fp, "default :");
            Stmt(case_->stmt);
            fprintf(fp, "break ;\n");
         }
         else{
            Case(case_->prev);
            fprintf(fp, "case ");
            fprintf(fp, "%d:", case_->intnum);
            Stmt(case_->stmt);
            fprintf(fp, "break ;\n");
         }
      }
   }
}

void Expr(struct EXPR *expr){
   if(expr == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   switch(expr->e){
      case eUnop :
         Unop(expr->expression.unop_);
         break;
      case eAddi:
         Addiop(expr->expression.addiop_);
         break;
      case eMulti:
         Multop(expr->expression.multop_);
         break;
      case eRela:
         Relaop(expr->expression.relaop_);
         break;
      case eEqlt:
         Eqltop(expr->expression.eqltop_);
         break;
      case eCallExpr:
         Call(expr->expression.call_);
         break;
      case eIntnum:
         fprintf(fp, "%d", expr->expression.intnum);
         break;
      case eFloatnum:
         fprintf(fp, "%f", expr->expression.floatnum);
         break;
      case eId:
         if(expr->expression.ID_->expr != NULL){
            Id_s(expr->expression.ID_);
         }
         else{
            fprintf(fp,"%s", expr->expression.ID_->ID);
         }
         break;
      case eExpr:
         fprintf(fp,"(");
         Expr(expr->expression.bracket);
         fprintf(fp,")");
         break;
      default :
         fprintf(stderr,"no stmt.\n");
   }
}

void Unop(struct UNOP *unop){
   if(unop == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   fprintf(fp, "-");
   Expr(unop->expr);
}

void Addiop(struct ADDIOP *add){
   if(add == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   switch(add->a){
      case ePlus:
         Expr(add->lhs);
         fprintf(fp, " + ");
         Expr(add->rhs);
         break;
      case eMinus:
         Expr(add->lhs);
         fprintf(fp, " - ");
         Expr(add->rhs);
         break;   
   }
}

void Multop(struct MULTOP *mult){
   if(mult == NULL){
      fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   switch(mult->m){
      case eMult:
         Expr(mult->lhs);
         fprintf(fp, " * ");
         Expr(mult->rhs);
         break;
      case eDiv:
         Expr(mult->lhs);
         fprintf(fp, " / ");
         Expr(mult->rhs);
         break;   
   }
}

void Relaop(struct RELAOP *rela){
   if(rela == NULL){
      fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   switch(rela->r){
      case eLT:
         Expr(rela->lhs);
         fprintf(fp, " < ");
         Expr(rela->rhs);
         break;
      case eGT:
         Expr(rela->lhs);
         fprintf(fp, " > ");
         Expr(rela->rhs);
         break;
      case eLE:
         Expr(rela->lhs);
         fprintf(fp, " <= ");
         Expr(rela->rhs);
         break;
      case eGE:
         Expr(rela->lhs);
         fprintf(fp, " >= ");
         Expr(rela->rhs);
         break;   
   }
}

void Eqltop(struct EQLTOP *eqlt){
   if(eqlt == NULL){
      fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   switch(eqlt->e){
      case eEQ:
         Expr(eqlt->lhs);
         fprintf(fp, "== ");
         Expr(eqlt->rhs);
         break;
      case eNE:
         Expr(eqlt->lhs);
         fprintf(fp, "!= ");
         Expr(eqlt->rhs);
         break;   
   }   
}

void Id_s(struct ID_S *id){
   if(id == NULL){
      fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   fprintf(fp, "%s[", id->ID);
   Expr(id->expr);
   fprintf(fp, "]");
}

void Arg(struct ARG *arg){
   if(arg == NULL){
      fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(arg->prev == NULL){
      Expr(arg->expr);
   }
   else{
      Arg(arg->prev);
      fprintf(fp, ", ");
      Expr(arg->expr);
   }
}

void Type(Type_e x){
   
   if(x == eInt){
      fprintf (fp, "int ");
   }
   if(x == eFloat){
      fprintf (fp, "float ");
   }
}