#include <stdio.h>
#include "expr.h"
#include "CFG.h"
#include <stdlib.h>
#include <string.h>
#include "block.h"

FILE *fp;
FILE *fp1;

int count = 0;
int arr[1000];

char f[100][100];
int fcount=0;
int temp = 0;
int start = 0;
int check = 0;

int NUM = 0;
struct Block_list *block_list;

int main () {

   block_list = (struct Block_list *)malloc(sizeof(struct Block_list));
   initList(block_list);

   fp  = fopen ("tree.txt", "w");
   fp1 = fopen ("table.txt", "w");
   if (!yyparse ())
      dfs ();
    
   fclose (fp);
   fclose (fp1);
   print_block(block_list);
   printf("\n");
   return 0;
}

void dfs() {
   if(head == NULL) {
      // //fprintf (stderr, "expression does not exist.\n");
      return;
   }
   
   Program (head);
}

void Program(struct PROGRAM *program){
   if(program == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(head == NULL){
   }
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

   if(declaration == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(declaration->prev == NULL){
      Type(declaration->t);
      if(declaration->t == eInt){
         declaration->id->t = eInt;
      }else{
         declaration->id->t = eFloat;
      }
      Ident(declaration->id);
   }
   else {
      Decl(declaration->prev);
      Type(declaration->t);
      if(declaration->t == eInt){
         declaration->id->t = eInt;
      }else{
         declaration->id->t = eFloat;
      }
      Ident(declaration->id);
      
   }
   //fprintf(fp,";\n");

}

void Func(struct FUNCTION *function){
   struct Block * block;
   strcpy(f[fcount++], function->ID);

   if(function == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(function->prev == NULL){

      //create Block===========================================================
      block = (struct Block *) malloc (sizeof(struct Block));
      initBlock(block);
      block->Block_num = NUM;
      NUM++;
      block->func_name = (char *) malloc (sizeof(char) * 20);
      strcat(block->func_name, function->ID);
      insertBlock(block, block_list);
      //=======================================================================

      Type(function->t);
      //fprintf(fp, "%s ", function->ID);
      //fprintf(fp, "(");

      print_func_name(function);
      check = 1;

      if(function->param == NULL){}
      else{
         Param(function->param);
      }
      //fprintf(fp, ") ");
      Compound(function->cstmt);
   }
   else {
      Func(function->prev);
      Type(function->t);
      //fprintf(fp, "%s ", function->ID);
      //fprintf(fp, "(");

      //create Block===========================================================
      block = (struct Block *) malloc (sizeof(struct Block));
      initBlock(block);
      block->Block_num = NUM;
      NUM++;
      block->func_name = (char *) malloc (sizeof(char) * 20);
      strcat(block->func_name, function->ID);
      insertBlock(block, block_list);
      //=======================================================================

      print_func_name(function);
      check = 1;

      if(function->param == NULL){}
      else{
         Param(function->param);
      }
      //fprintf(fp, ") ");
      Compound(function->cstmt);
   }
}

void Ident(struct IDENTIFIER *ident){
   if(ident == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   
   if(ident->prev == NULL){
      count++;

      if(ident->t == eInt){
         //fprintf (fp1,"%10d%10s", count, "int");
      }
      else if(ident->t == eFloat){
         //fprintf (fp1,"%10d%10s", count, "float");
      }

      if(ident->intnum == 0){
         //fprintf(fp, "%s", ident->ID);
         //if(ident->param != true)
            //fprintf(fp1, "%10s%10s%10s\n", ident->ID, "", "variable");
         //if(ident->param == true)
            //fprintf(fp1, "%10s%10s%10s\n", ident->ID, "", "parameter");
      }
      else{
         //fprintf(fp, "%s", ident->ID);
         //fprintf(fp, "[");
         //fprintf(fp, "%d", ident->intnum);
         //fprintf(fp, "]");

         //if(ident->param != true)
            //fprintf(fp1, "%10s%10d%10s\n", ident->ID, ident->intnum, "variable");
         //if(ident->param == true)
            //fprintf(fp1, "%10s%10d%10s\n", ident->ID, ident->intnum, "parameter"); 
      }
   }
   else {
      Ident(ident->prev);
      count++;

      if(ident->t == eInt){
         //fprintf (fp1,"%10d%10s", count, "int");
      }
      else if(ident->t == eFloat){
         //fprintf (fp1,"%10d%10s", count, "float");
      }

      //fprintf(fp, ",");
      if(ident->intnum == 0){
         //fprintf(fp, "%s", ident->ID);
         //if(ident->param != true)
            //fprintf(fp1, "%10s%10s%10s\n", ident->ID, "", "variable");
         //if(ident->param == true)
            //fprintf(fp1, "%10s%10s%10s\n", ident->ID, "", "parameter");
      }
      else{
         //fprintf(fp, "%s", ident->ID);
         //fprintf(fp, "[");
         //fprintf(fp, "%d", ident->intnum);
         //fprintf(fp, "]");
         //if(ident->param != true)
            //fprintf(fp1, "%10s%10d%10s\n", ident->ID, ident->intnum, "variable");
         //if(ident->param == true)
            //fprintf(fp1, "%10s%10d%10s\n", ident->ID, ident->intnum, "parameter");   
      }
   }
   
}

void Param(struct PARAMETER *param){
   if(param == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(param->prev == NULL){
      Type(param->t);
      if(param->t == eInt){
         param->id->t = eInt;
      }
      else if(param->t == eFloat){
         param->id->t = eFloat;
      }
      param->id->param = true;
      Ident(param->id);
   }
   else{
      Param(param->prev);
      //fprintf(fp, ",");
      Type(param->t);
      if(param->t == eInt){
         param->id->t = eInt;
      }
      else if(param->t == eFloat){
         param->id->t = eFloat;
      }
      param->id->param = true;
      Ident(param->id);
   }
}

void Compound(struct COMPOUNDSTMT *comp){
   if(comp == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   
   arr[temp]++;
   temp++;

   //fprintf(fp, "{\n");

   if(comp->decl == NULL){
      Stmt(comp->stmt);
   }
   else{
      if(check == 0)
         print_func_name2(comp);

      Decl(comp->decl);
      Stmt(comp->stmt);
   }   

   arr[temp] = 0;
   if(arr[1] == 0){
      fcount--;
   }
   temp--;

   //fprintf(fp, "}\n");
}

void Stmt(struct STMT *stmt){
   if(stmt == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
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
            //fprintf(fp, "return ");
            if(stmt->stmt.return_ == NULL){}
            else {
               Expr(stmt->stmt.return_);
            }
            //fprintf(fp, ";\n");
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
            check = 0;
            Compound(stmt->stmt.cstmt_);
            break;
         case eSwitch:
            Switch_s(stmt->stmt.switch_);
            break;
         //default :
            //fprintf(stderr,"no stmt.\n");
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
            //fprintf(fp, "return ");
            if(stmt->stmt.return_ == NULL){}
            else {
               Expr(stmt->stmt.return_);
            }
            //fprintf(fp, ";\n");
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
            check = 0;
            Compound(stmt->stmt.cstmt_);
            break;
         case eSwitch:
            Switch_s(stmt->stmt.switch_);
            break;
         //default :
            //fprintf(stderr,"no stmt.\n");
      }
   }
}

char *Assign(struct ASSIGN *assign){
   char *dst;
   char *str;
   if(assign == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(assign->index == NULL){
      dst = (char *) malloc(sizeof(char) * 40);
      str = (char *) malloc(sizeof(char) * 20);
      strcat(dst, "\t");
      strcat(dst, assign->ID);
      strcat(dst, " = ");
      strcpy(str, Expr(assign->expr));
      strcat(dst, str);
      strcat(dst , ";");
      return dst;
   }
   else{
      dst = (char *) malloc(sizeof(char) * 40);
      str = (char *) malloc(sizeof(char) * 20);
      strcat(dst, "\t");
      strcat(dst, assign->ID);
      strcat(dst, "[");
      strcat(dst, Expr(assign->index));
      strcat(dst, "]");   
      strcat(dst, " = ");
      strcpy(str, Expr(assign->expr));
      strcat(dst, str);
      strcat(dst , ";");
      return dst;
      //fprintf(fp, "%s", assign->ID);
      //fprintf(fp, "[");
      Expr(assign->index);
      //fprintf(fp, "] ");
      //fprintf(fp, "= ");
      Expr(assign->expr);
   }

}

void AssignStmt(struct ASSIGN *assign){
   char *str = (char *) malloc(sizeof(char) * 40);
   struct Block *block = (struct Block *) malloc (sizeof(struct Block));
   size_t contents_size;
   if(assign == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   initBlock(block);
   strcpy(str, Assign(assign));
   block = latest_block(block_list);
   contents_size = 0;   
   if(block->contents){
      contents_size = strlen(block->contents);   
   }
   if(contents_size == 0){
      block->contents = (char *)malloc(sizeof(char) * 40);
      strcat(block->contents, str);
   }
   else{
      char *str2 = (char *)malloc(sizeof(char) * (40 + contents_size));
      strcat(str2, block->contents);
      strcat(str2, "\n");
      strcat(str2, str);
      block->contents = str2;
   }
   //fprintf(fp, ";\n");
}

char *Expr(struct EXPR *expr){
   char *buffer;
   if(expr == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
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
         buffer = (char *) malloc (sizeof(char) * 20);
         snprintf(buffer, sizeof(char) * 20,"%d",expr->expression.intnum);
         return buffer;
         //fprintf(fp, "%d", expr->expression.intnum);
         break;
      case eFloatnum:
         buffer = (char *) malloc (sizeof(char) * 20);
         snprintf(buffer, sizeof(char) * 20,"%f",expr->expression.floatnum);
         fprintf(fp, "%f", expr->expression.floatnum);
         return buffer;
         break;
      case eId:
         if(expr->expression.ID_->expr != NULL){
            Id_s(expr->expression.ID_);
         }
         else{
            //fprintf(fp,"%s", expr->expression.ID_->ID);
         }
         break;
      case eExpr:
         //fprintf(fp,"(");
         Expr(expr->expression.bracket);
         //fprintf(fp,")");
         break;
      //default :
         //fprintf(stderr,"no stmt.\n");
   }
}

void Call(struct CALL *call){
   if(call == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(call->arg == NULL){
      //fprintf(fp, "%s()", call->ID);
   }
   else{
      //fprintf(fp, "%s(", call->ID);
      Arg(call->arg);
      //fprintf(fp, ")");
   }
   //fprintf(fp, ";\n");
}

void While_s(struct WHILE_S *while_){
   
   if(while_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   
   if(while_->do_while == false){
      //fprintf(fp, "while (");
      Expr(while_->cond);
      //fprintf(fp, ") ");
      Stmt(while_->stmt);
   }
   else{
      //fprintf(fp, "do ");
      Stmt(while_->stmt);
      //fprintf(fp, "while (");
      Expr(while_->cond);
      //fprintf(fp, ");\n");
   }
}

void For_s(struct FOR_S *for_){
   if(for_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   //fprintf(fp, "for (");
   Assign(for_->init);
   //fprintf(fp, "; ");
   Expr(for_->cond);
   //fprintf(fp, "; ");
   Assign(for_->inc);
   //fprintf(fp, ") ");
   Stmt(for_->stmt);
}

void If_s(struct IF_S *if_){
   if(if_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(if_->else_ == NULL){
      //fprintf(fp, "if (");
      Expr(if_->cond);
      //fprintf(fp, ") ");
      Stmt(if_->if_);
   }
   else{
      //fprintf(fp, "if (");
      Expr(if_->cond);
      //fprintf(fp, ") ");
      Stmt(if_->if_);
      //fprintf(fp, "else ");
      Stmt(if_->else_);
   }
}

void Switch_s(struct SWITCH_S *switch_){
   if(switch_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   //fprintf(fp, "switch (");
   switch_->identifier->param = true;
   //fprintf(fp, "%s", switch_->identifier->ID);
   //fprintf(fp, "){\n");
   Case(switch_->case_);
   //fprintf(fp, "}\n");
}

void Case(struct CASE *case_){
   if(case_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(case_->break_ == false){
      if(case_->intnum == 0){
            //fprintf(fp,"default :");
            Stmt(case_->stmt);
      }
      else if(case_->intnum != 0){
         if(case_->prev == NULL){
            //fprintf(fp, "case ");
            //fprintf(fp, "%d:", case_->intnum);
            Stmt(case_->stmt);
         }
         else if(case_->prev != NULL){
            //fprintf(fp, "case ");
            //fprintf(fp, "%d:", case_->intnum);
            Stmt(case_->stmt);
            Case(case_->prev);
         }
      }
   }
   else if(case_->break_ == true){
      if(case_->intnum == 0){
            //fprintf(fp,"default :\n");
            Stmt(case_->stmt);
            //fprintf(fp, "break ;\n");

      }
      else if(case_->intnum != 0){
         if(case_->prev == NULL){
            //fprintf(fp, "case ");
            //fprintf(fp, "%d:", case_->intnum);
            Stmt(case_->stmt);
            //fprintf(fp, "break ;\n");
         }
         else if(case_->prev != NULL){
            //fprintf(fp, "case ");
            //fprintf(fp, "%d:", case_->intnum);
            Stmt(case_->stmt);
            //fprintf(fp, "break ;\n");
            Case(case_->prev);
         }
      }
   }
   
}

void Unop(struct UNOP *unop){
   if(unop == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   //fprintf(fp, "-");
   Expr(unop->expr);
}

void Addiop(struct ADDIOP *add){
   if(add == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   switch(add->a){
      case ePlus:
         Expr(add->lhs);
         //fprintf(fp, " + ");
         Expr(add->rhs);
         break;
      case eMinus:
         Expr(add->lhs);
         //fprintf(fp, " - ");
         Expr(add->rhs);
         break;   
   }
}

void Multop(struct MULTOP *mult){
   if(mult == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   switch(mult->m){
      case eMult:
         Expr(mult->lhs);
         //fprintf(fp, " * ");
         Expr(mult->rhs);
         break;
      case eDiv:
         Expr(mult->lhs);
         //fprintf(fp, " / ");
         Expr(mult->rhs);
         break;   
   }
}

void Relaop(struct RELAOP *rela){
   if(rela == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   switch(rela->r){
      case eLT:
         Expr(rela->lhs);
         //fprintf(fp, " < ");
         Expr(rela->rhs);
         break;
      case eGT:
         Expr(rela->lhs);
         //fprintf(fp, " > ");
         Expr(rela->rhs);
         break;
      case eLE:
         Expr(rela->lhs);
         //fprintf(fp, " <= ");
         Expr(rela->rhs);
         break;
      case eGE:
         Expr(rela->lhs);
         //fprintf(fp, " >= ");
         Expr(rela->rhs);
         break;   
   }
}

void Eqltop(struct EQLTOP *eqlt){
   if(eqlt == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   switch(eqlt->e){
      case eEQ:
         Expr(eqlt->lhs);
         //fprintf(fp, "== ");
         Expr(eqlt->rhs);
         break;
      case eNE:
         Expr(eqlt->lhs);
         //fprintf(fp, "!= ");
         Expr(eqlt->rhs);
         break;   
   }   
}

void Id_s(struct ID_S *id){
   if(id == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   //fprintf(fp, "%s[", id->ID);
   Expr(id->expr);
   //fprintf(fp, "]");
}

void Arg(struct ARG *arg){
   if(arg == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(arg->prev == NULL){
      Expr(arg->expr);
   }
   else{
      Arg(arg->prev);
      //fprintf(fp, ", ");
      Expr(arg->expr);
   }
}

void Type(Type_e x){
   
   if(x == eInt){
      //fprintf (fp, "int ");
   }
   if(x == eFloat){
      //fprintf (fp, "float ");
   }
}

void print_func_name(struct FUNCTION* function){
   count = 0;
   
   if(! (function->cstmt->decl == NULL && function->param == NULL) ){
      int z=1;
      
      if(start != 0)
         //fprintf(fp1, "\n\n");
      start = 1;
      //fprintf(fp1, "Function name : %s", f[fcount-1]);
      while(arr[z]!=0){
         //fprintf(fp1, " - %d", arr[z]);
         z++;
      }
      //fprintf(fp1, "\n");
      //fprintf(fp1, "     count      type      name     array      role\n");
   }

   return;
}

void print_func_name2(struct COMPOUNDSTMT *comp){
   count = 0;
   
   if(! (comp->decl == NULL) ){
      int z=1;
      
      if(start != 0)
         //fprintf(fp1, "\n\n");
      start = 1;
      //fprintf(fp1, "Function name : %s", f[fcount-1]);
      while(arr[z]!=0){
         //fprintf(fp1, " - %d", arr[z]);
         z++;
      }
      //fprintf(fp1, "\n");
      //fprintf(fp1, "     count      type      name     array      role\n");
   }

   return;
}