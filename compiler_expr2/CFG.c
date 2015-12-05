char *Assign(struct ASSIGN *assign){
   if(assign == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }
   if(assign->index == NULL){
      //fprintf(fp, "%s ", assign->ID);
      //fprintf(fp, "= ");
      //char *dst = (char *) malloc(sizeof(char) * 20);
      //char *str = (char *) malloc(sizeof(char) * 10);
      //strcat(dst, assign->ID);
      //strcpy(str, Expr(assign->expr));
      //strcat(dst, str);
      //return str;
      return NULL;
   }
   else{
      //fprintf(fp, "%s", assign->ID);
      //fprintf(fp, "[");
      Expr(assign->index);
      //fprintf(fp, "] ");
      //fprintf(fp, "= ");
      Expr(assign->expr);
   }

}

void AssignStmt(struct ASSIGN *assign){
   if(assign == NULL){
      // //fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   /*char *str = (char *) malloc(sizeof(char) * 20);
   strcpy(str, Assign(assign));
   struct Block * block = latest_block(block_list);
   int contents_size = strlen(block->contents);
   if(contents_size == 0){
      block->contents = (char *)malloc(sizeof(char) * 20);
      strcat(block->contents, str);
   }
   else{
      char *str2 = (char *)malloc(sizeof(char) * (20 + contents_size));
      strcat(str2, block->contents);
      strcat(str2, "\n");
      strcat(str2, str);
      block->contents = str2;
   }*/
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
         return NULL;
         break;
      case eAddi:
         Addiop(expr->expression.addiop_);
         return NULL;
         break;
      case eMulti:
         Multop(expr->expression.multop_);
         return NULL;
         break;
      case eRela:
         Relaop(expr->expression.relaop_);
         return NULL;
         break;
      case eEqlt:
         Eqltop(expr->expression.eqltop_);
         break;
      case eCallExpr:
         Call(expr->expression.call_);
         return NULL;
         break;
      case eIntnum:
         //buffer = (char *) malloc (sizeof(char) * 10);
         //snprintf(buffer, sizeof(char) * 10,"%d",expr->expression.intnum);
         return NULL;
         //fprintf(fp, "%d", expr->expression.intnum);
         break;
      case eFloatnum:
         //fprintf(fp, "%f", expr->expression.floatnum);
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
         //fprintf(stderr,"no stmt.\n");
   }
   return NULL;
}