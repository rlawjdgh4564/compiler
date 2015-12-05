#include <stdio.h>
#include "block.h"
#include <stdlib.h>

int main(){

	struct Block * block = (struct Block *) malloc (sizeof(struct Block));
	struct Block_list *list = (struct Block_list *) malloc (sizeof(struct Block_list));
	//initBlock(block);
	initBlock(block);
	initList(list);
	block->Block_num = 1;
	list->head->Block_num = 2;
	block = latest_block(list);
	printf("block->Block_num : %d\n", block->Block_num);


	return;
}