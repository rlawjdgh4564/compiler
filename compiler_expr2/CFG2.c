void Assign(struct ASSIGN *assign){
   if(assign == NULL){
      // fprintf (stderr, "additive operand does not exist.\n");
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
      // fprintf (stderr, "additive operand does not exist.\n");
      return;
   }

   Assign(assign);
   fprintf(fp, ";\n");
}

void Expr(struct EXPR *expr){
   if(expr == NULL){
      // fprintf (stderr, "additive operand does not exist.\n");
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
