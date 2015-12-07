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

int compound_check = 0;
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
   
   compress(block_list);
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

      NUM = 0;

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

      compound_check = 1;
   
      Compound(function->cstmt);
   }
   else {

      Func(function->prev);
      Type(function->t);
      //fprintf(fp, "%s ", function->ID);
      //fprintf(fp, "(");

      NUM = 0;
      
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

      compound_check = 1;
   
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

   struct Block * pred_block = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block2 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * tmp = (struct Block *) malloc (sizeof(struct Block));

   int compound_checkp = 0;

   if(comp == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   
   arr[temp]++;
   temp++;

   compound_checkp = compound_check;
   compound_check = 0;
   // //create Block=====================================================

   if(compound_checkp == 0){
      initBlock(block);
      initBlock(block2);
      block -> Block_num = NUM;
      NUM++;
      block2 -> Block_num = NUM;
      NUM++;

      pred_block = latest_block(block_list);
      pre_block(block , pred_block);
      suc_block(pred_block, block);
      insertBlock(block, block_list);
   }
   // //=================================================================

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

   if(compound_checkp == 0){
      tmp = latest_block(block_list);
      pre_block(block2 , tmp);
      suc_block(tmp, block2);
      insertBlock(block2, block_list);
   }


   arr[temp] = 0;
   if(arr[1] == 0){
      fcount--;
   }
   temp--;

   //fprintf(fp, "}\n");
}

void Stmt(struct STMT *stmt){
   char *str = (char *) malloc(sizeof(char) * 40);
   struct Block *block = (struct Block *) malloc (sizeof(struct Block));
   size_t contents_size;

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
               strcat(str, "\treturn ");
               strcat(str, Expr(stmt->stmt.return_));
            }
            //fprintf(fp, ";\n");

            initBlock(block);
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
               strcat(str, "\treturn ");
               strcat(str, Expr(stmt->stmt.return_));
            }
            //fprintf(fp, ";\n");

            initBlock(block);
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
         buffer = (char *) malloc (sizeof(char) * 20);
         strcat(buffer, Unop(expr->expression.unop_));
         return buffer;
         break;
      case eAddi:
         buffer = (char *) malloc (sizeof(char) * 40);
         strcat(buffer, Addiop(expr->expression.addiop_));
         break;
      case eMulti:
         buffer = (char *) malloc (sizeof(char) * 40);
         strcat(buffer, Multop(expr->expression.multop_));
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
            buffer = (char *) malloc (sizeof(char) * 20);
            snprintf(buffer, sizeof(char) * 20,"%s",expr->expression.ID_->ID);
            fprintf(fp, "%f", expr->expression.floatnum);
            return buffer; 
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

   struct Block * block = (struct Block *) malloc (sizeof(struct Block));
   char * str = (char *) malloc(sizeof(char) * 40);
   size_t contents_size;

   if(call == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(call->arg == NULL){
      strcat(str, "\t");
      strcat(str, call->ID);
      strcat(str, "()");
      //fprintf(fp, "%s()", call->ID);
   }
   else{
      strcat(str, "\t");
      strcat(str, call->ID);
      strcat(str, "(");
      //fprintf(fp, "%s(", call->ID);
      strcat(str, Arg(call->arg));
      strcat(str, ")");
      //fprintf(fp, ")");
   }
   //fprintf(fp, ";\n");

   initBlock(block);
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
}

void While_s(struct WHILE_S *while_){
   struct Block * pred_block = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block2 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block3 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * tmp = (struct Block *) malloc (sizeof(struct Block));
   
   compound_check = 1;

   if(while_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   //create Block=====================================================
   initBlock(block);
   initBlock(block2);
   initBlock(block3);
   block -> Block_num = NUM;
   NUM++;
   block2 -> Block_num = NUM;
   NUM++;
   block3 -> Block_num = NUM;
   NUM++;
   //=================================================================
   
   if(while_->do_while == false){

      pred_block = latest_block(block_list);

      pre_block(block , pred_block);
      suc_block(pred_block, block);
      insertBlock(block, block_list);

      //fprintf(fp, "while (");
      Expr(while_->cond);

      pre_block(block2 , block);
      suc_block(block, block2);
      insertBlock(block2, block_list);

      //fprintf(fp, ") ");
      Stmt(while_->stmt);

      tmp = latest_block(block_list);
      pre_block(block , tmp);
      suc_block(tmp, block);

      pre_block(block3 , block);
      suc_block(block, block3);
      insertBlock(block3, block_list);
   }
   else{

      pred_block = latest_block(block_list);

      pre_block(block , pred_block);
      suc_block(pred_block, block);
      insertBlock(block, block_list);

      //fprintf(fp, "do ");
      Stmt(while_->stmt);

      tmp = latest_block(block_list);
      pre_block(block2 , tmp);
      suc_block(tmp, block2);
      insertBlock(block2, block_list);

      //fprintf(fp, "while (");
      Expr(while_->cond);

      pre_block(block , block2);
      suc_block(block2, block);
      pre_block(block3 , block2);
      suc_block(block2, block3);
      insertBlock(block3, block_list);
      //fprintf(fp, ");\n");
   }
}

void For_s(struct FOR_S *for_){
   struct Block * pred_block = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block5 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block2 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block3 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block4 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * tmp = (struct Block *) malloc (sizeof(struct Block));

   compound_check = 1;
   
   if(for_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   initBlock(block2);
   initBlock(block3);   
   initBlock(block4);
   initBlock(block5);
   
   block2 -> Block_num = NUM;
   NUM++;
   block3 -> Block_num = NUM;
   NUM++;
   block4 -> Block_num = NUM;
   NUM++;
   block5 -> Block_num = NUM;
   NUM++;
   //fprintf(fp, "for (");
   AssignStmt(for_->init);
   //fprintf(fp, "; ");
   pred_block = latest_block(block_list);

   pre_block(block2 , pred_block);
   suc_block(pred_block, block2);
   insertBlock(block2, block_list);

   Expr(for_->cond);

   pre_block(block3, block2);
   suc_block(block2, block3);
   insertBlock(block3, block_list);

   Stmt(for_->stmt);
  
   // block->func_name = (char *) malloc (sizeof(char) * 20);
   // strcat(block->func_name, function->ID);

   tmp = latest_block(block_list);
   pre_block(block4, tmp);
   suc_block(tmp, block4);
   insertBlock(block4, block_list);
   // insertBlock(block3, block_list);

   
   //fprintf(fp, "; ");
   AssignStmt(for_->inc);
   //fprintf(fp, ") ");
   
   pre_block(block2 , block4);
   suc_block(block4 , block2);

   pre_block(block5 , block2);
   suc_block(block2, block5);
   insertBlock(block5, block_list);
}

void If_s(struct IF_S *if_){

   struct Block * pred_block = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block2 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block3 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block4 = (struct Block *) malloc (sizeof(struct Block));
   struct Block * tmp = (struct Block *) malloc (sizeof(struct Block));

   compound_check = 1;
   
   if(if_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(if_->else_ == NULL){

      //create Block=====================================================
      initBlock(block);
      initBlock(block2);
      initBlock(block3);
      block -> Block_num = NUM;
      NUM++;
      block2 -> Block_num = NUM;
      NUM++;
      block3 -> Block_num = NUM;
      NUM++;
      //=================================================================

      //fprintf(fp, "if (");

      pred_block = latest_block(block_list);

      pre_block(block , pred_block);
      suc_block(pred_block, block);
      insertBlock(block, block_list);

      Expr(if_->cond); // goto eql or rel
      
      pre_block(block2 , block);
      suc_block(block, block2);
      insertBlock(block2, block_list);
      
      //fprintf(fp, ") ");
      Stmt(if_->if_);

      tmp = latest_block(block_list);
      pre_block(block3 , tmp);
      suc_block(tmp, block3);

      pre_block(block3 , block);
      suc_block(block, block3);
      insertBlock(block3, block_list);

   }
   else{

      //create Block=====================================================
      initBlock(block);
      initBlock(block2);
      initBlock(block3);
      initBlock(block4);
      block -> Block_num = NUM;
      NUM++;
      block2 -> Block_num = NUM;
      NUM++;
      block3 -> Block_num = NUM;
      NUM++;
      block4 -> Block_num = NUM;
      NUM++;
      //=================================================================

      //fprintf(fp, "if (");

      pred_block = latest_block(block_list);

      pre_block(block , pred_block);
      suc_block(pred_block, block);
      insertBlock(block, block_list);

      Expr(if_->cond);

      pre_block(block2 , block);
      suc_block(block, block2);
      pre_block(block3 , block);
      suc_block(block, block3);
      insertBlock(block2, block_list);
      
      //fprintf(fp, ") ");
      Stmt(if_->if_);

      tmp = latest_block(block_list);
      pre_block(block4 , tmp);
      suc_block(tmp, block4);
      
      insertBlock(block3, block_list);
      //fprintf(fp, "else ");
      Stmt(if_->else_);

      tmp = latest_block(block_list);
      pre_block(block4 , tmp);
      suc_block(tmp, block4);
      insertBlock(block4, block_list);
   }
}

void Switch_s(struct SWITCH_S *switch_){

   struct Block * pred_block = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block = (struct Block *) malloc (sizeof(struct Block));
   char *str = (char *) malloc (sizeof(char) * 40);

   if(switch_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   compound_check = 1;
   

   //create Block=====================================================
   initBlock(block);
   block -> Block_num = NUM;
   NUM++;
   //=================================================================

   pred_block = latest_block(block_list);
   pre_block(block , pred_block);
   suc_block(pred_block, block);

   strcat(str, "swithc (");
   strcat(str, switch_->identifier->ID);
   strcat(str, ")");
   block -> contents = (char *) malloc (sizeof(char) * 40);
   block -> contents = str;
   //fprintf(fp, "switch (");
   switch_->identifier->param = true;
   //fprintf(fp, "%s", switch_->identifier->ID);
   //fprintf(fp, "){\n");
   Case(switch_->case_);
   //fprintf(fp, "}\n");
}

void Case(struct CASE *case_){

   struct Block * pred_block = (struct Block *) malloc (sizeof(struct Block));
   struct Block * block = (struct Block *) malloc (sizeof(struct Block));
   char *str = (char *) malloc (sizeof(char) * 40);

   if(case_ == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   //create Block=====================================================
   initBlock(block);
   block -> Block_num = NUM;
   NUM++;
   //=================================================================

   if(case_->break_ == false){
      if(case_->intnum == 0){
            //fprintf(fp,"default :");
            Stmt(case_->stmt);
      }
      else if(case_->intnum != 0){
         if(case_->prev == NULL){

            pred_block = latest_block(block_list);
            pre_block(block , pred_block);
            suc_block(pred_block, block);

            insertBlock(block);
            strcat(str, "case ");
            strcat(str, itoa(case_->intnum));
            block -> contents = (char *) malloc (sizeof(char) * 40);
            block -> contents = str;
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

            pred_block = latest_block(block_list);
            pre_block(block , pred_block);
            suc_block(pred_block, block);

            insertBlock(block);
            strcat(str, "case ");
            strcat(str, itoa(case_->intnum));
            block -> contents = (char *) malloc (sizeof(char) * 40);
            block -> contents = str;
            
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

char *Unop(struct UNOP *unop){
   char *str = (char *) malloc(sizeof(char) * 20);
   if(unop == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   strcat(str, "-");
   strcat(str, Expr(unop->expr));
   return str;
   //fprintf(fp, "-");
}

char *Addiop(struct ADDIOP *add){
   char *str = (char *) malloc(sizeof(char) * 40);

   if(add == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   switch(add->a){
      case ePlus:
         strcat(str, Expr(add->lhs));
         strcat(str, " + ");
         strcat(str, Expr(add->rhs));
         //fprintf(fp, " + ");
         break;
      case eMinus:
         strcat(str, Expr(add->lhs));
         strcat(str, " - ");
         strcat(str, Expr(add->rhs));
         //fprintf(fp, " - ");
         break;   
   }
}

char *Multop(struct MULTOP *mult){
   char *str = (char *) malloc(sizeof(char) * 40);

   if(mult == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   switch(mult->m){
      case eMult:
         strcat(str, Expr(mult->lhs));
         strcat(str, " * ");
         strcat(str, Expr(mult->rhs));
         //fprintf(fp, " * ");
         break;
      case eDiv:
         strcat(str, Expr(mult->lhs));
         strcat(str, " / ");
         strcat(str, Expr(mult->rhs));
         //fprintf(fp, " / ");
         break;   
   }
}

void Relaop(struct RELAOP *rela){
   char *str = (char *) malloc(sizeof(char) * 40);
   struct Block *block = (struct Block *) malloc (sizeof(struct Block));
   block = latest_block(block_list);
   size_t contents_size;

   if(rela == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   contents_size = 0;   
   if(block->contents){
      contents_size = strlen(block->contents);   
   }

   switch(rela->r){
      case eLT:
         strcat(str, "\t");
         strcat(str, Expr(rela->lhs));
         strcat(str, " < ");
         strcat(str, Expr(rela->rhs));
         //fprintf(fp, " < ");
         break;
      case eGT:
         strcat(str, "\t");
         strcat(str, Expr(rela->lhs));
         strcat(str, " > ");
         strcat(str, Expr(rela->rhs));
         //fprintf(fp, " > ");
         break;
      case eLE:
         strcat(str, "\t");
         strcat(str, Expr(rela->lhs));
         strcat(str, " <= ");
         strcat(str, Expr(rela->rhs));
         //fprintf(fp, " <= ");
         break;
      case eGE:
         strcat(str, "\t");
         strcat(str, Expr(rela->lhs));
         strcat(str, " >= ");
         strcat(str, Expr(rela->rhs));
         //fprintf(fp, " >= ");
         break;   
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
}

void Eqltop(struct EQLTOP *eqlt){
   char *str = (char *) malloc(sizeof(char) * 40);
   struct Block *block = (struct Block *) malloc (sizeof(struct Block));
   block = latest_block(block_list);
   size_t contents_size;

   if(eqlt == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }

   contents_size = 0;   
   if(block->contents){
      contents_size = strlen(block->contents);   
   }

   switch(eqlt->e){
      case eEQ:
         strcat(str, "\t");
         strcat(str, Expr(eqlt->lhs));
         strcat(str, " == ");
         strcat(str, Expr(eqlt->rhs));
         //fprintf(fp, "== ");
         break;
      case eNE:
         strcat(str, "\t");
         strcat(str, Expr(eqlt->lhs));
         strcat(str, " != ");
         strcat(str, Expr(eqlt->rhs));
         strcat(str, "\n");
         //fprintf(fp, "!= ");
         break;   
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
}

char *Id_s(struct ID_S *id){
   char *str = (char *) malloc(sizeof(char) * 20);
   if(id == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");   
      return;
   }
   strcat(str, id->ID);
   strcat(str, "[");
   strcat(str, Expr(id->expr));
   strcat(str, "]");
   return str;
   //fprintf(fp, "%s[", id->ID);
   //fprintf(fp, "]");
}

char *Arg(struct ARG *arg){
   char *str = (char *) malloc(sizeof(char) * 40);
   char *tmp = (char *) malloc(sizeof(char) * 40);
   if(arg == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   if(arg->prev == NULL){
      strcat(tmp, Expr(arg->expr));
      return tmp;
   }
   else{
      strcat(tmp, Arg(arg->prev));
      strcat(tmp, ", ");
      strcat(tmp, Expr(arg->expr));
      //fprintf(fp, ", ");
   }
   return tmp;
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