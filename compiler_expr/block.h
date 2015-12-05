#include <stdlib.h>
#include "expr.h"

struct Block{
	int Block_num;
	char *contents;
   char *func_name;
	struct Block *predecessor[10];
	struct Block *successor[10];
	struct Block *next;
};

struct Block_list{
	struct Block *head;
	struct Block *tail;
};

void initBlock(struct Block * block){
   int i;
   block -> Block_num = 0;
   block -> contents = NULL;
   block -> func_name = NULL;
   for(i = 0; i < 10; i++){
      block -> predecessor[i] = NULL;
      block -> successor[i] = NULL;
   }
   block->next = NULL; 
}


void initList(struct Block_list * list){
   list->head = (struct Block *) malloc (sizeof(struct Block));
   list->tail = (struct Block *) malloc (sizeof(struct Block));
   initBlock(list->head);
   initBlock(list->tail);

   list -> head -> next = list -> tail;
}

void insertBlock(struct Block *inblock, struct Block_list *list){
   struct Block *block;
   for (block = list->head; block->next != list->tail; block = block->next){
   }
   inblock->next = block->next;
   block->next = inblock;
}

int Bnum_in_list(struct Block_list *list){
	int num = 0;
	struct Block *block;
	for (block = list->head; block->next != list->tail; block = block->next){
		num++;
   }
   return num;
}

struct Block * latest_block(struct Block_list *list){
	struct Block *block = (struct Block *) malloc (sizeof(struct Block));
	for (block = list->head; block->next != list->tail; block = block->next){
	}
	return block;
}

void print_block(struct Block_list *list){
   struct Block *block = (struct Block *) malloc (sizeof(struct Block));
   struct Block *block2 = (struct Block *) malloc (sizeof(struct Block));
   int i;

   for (block = list->head; block->next != list->tail; block = block->next){
      block2 = block -> next;
      printf("\n%s\n\n", block2->func_name);
      printf("B%d\n{\n%s\n}\n",block2->Block_num, block2->contents);
      if(block2 -> func_name != NULL){
         printf("Predecessor: start");
         for(i = 0; i < 10; i++){
            if(block2 -> predecessor[i] != NULL)
               printf(", B%d", block2 -> predecessor[i] -> Block_num);
            else{
               break;
            }
         }
         printf("\nSuccesor:");
         for(i = 0; i < 10; i++){
            if(block2 -> successor[i] != NULL)
               printf(" B%d,", block2 -> successor[i] -> Block_num);
            else{
               break;
            }
         }
         printf(" end\n\n");
      }
      else{

      }
   }
}

void pre_block(struct Block *dst_block, struct Block *pre_block){
   struct Block *block = (struct Block *) malloc (sizeof(struct Block));
   struct Block *block2 = (struct Block *) malloc (sizeof(struct Block));
   int i;
   block = dst_block;
   block2 = pre_block;

   for(i = 0; i < 10; i++){
      if(block -> predecessor[i] == NULL)
         block -> predecessor[i] = block2;
   }
}

void suc_block(struct Block *dst_block, struct Block *suc_block){
   struct Block *block = (struct Block *) malloc (sizeof(struct Block));
   struct Block *block2 = (struct Block *) malloc (sizeof(struct Block));
   int i;
   block = dst_block;
   block2 = suc_block;

   for(i = 0; i < 10; i++){
      if(block -> successor[i] == NULL)
         block -> successor[i] = block2;
   }
}

