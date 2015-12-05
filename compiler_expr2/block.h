struct Block{
	int Block_num;
	char *contents;
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
   for(i = 0; i < 10; i++){
      block -> predecessor[i] = NULL;
      block -> successor[i] = NULL;
   }
   block->next = NULL;
}


void initList(struct Block_list * list){
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
	struct Block *block;
	for (block = list->head; block->next != list->tail; block = block->next){
	}
	return block;
}