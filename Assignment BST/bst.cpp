#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>


struct Data {
	// START HERE
	// ADD THE VARIABLES YOU NEED HERE
	char kata[5];
	int depth;
	Data*top,*bot;
Data*parent;
	// END HERE
}*curr,*temp,*root;

Data *newNode(char kata[5], int depth){
	Data * temp = (Data *)malloc(sizeof(Data));
	strcpy(temp->kata,kata);
	temp->depth = depth;
	temp->top = NULL;				
	temp->bot= NULL;				//bot = bottom
//	temp->parent = NULL;
	return temp;
} 	

void push(struct Data **curr,char *kata, int depth = 0){
//printf("asdd");
	if(*curr != NULL && strcmp(kata, (*curr)->kata)==0) {
		printf("Duplicate data\n");
	}else if(*curr == NULL){
		*curr = newNode(kata, depth+1);
	}else{
		if(strcmp(kata,(*curr)->kata)<0){
//			if(curr->bot == NULL){
//				curr->bot = newNode(kata);
//				curr->bot->parent = curr;
//			}else{
				push(&(*curr)->bot,kata, depth+1);		
//			}
		}else {
//			if(curr->top == NULL){
//				curr->top = newNode(kata);
//				curr->top->parent = curr;
//			}else{
				push(&(*curr)->top,kata, depth+1);
//			}
		}
	}
}

void print(struct Data *curr){
		
		if(curr!=NULL){
			print(curr->top);
			
			for(int i = 0; i< curr->depth; i++) printf("\t"); 	
			printf("%s\n",curr->kata);
		
			print(curr->bot);	
		}
//		return curr;
}


int main() {
	int choose = 0;
	int counter=0;
	char initial[5];
	do {
		system("cls");
		puts("1. Add Initial");
		puts("2. View Initial");
		puts("3. Exit");
		printf(">> ");
		scanf("%d", &choose); fflush(stdin);
		switch (choose) {
		case 1:
			puts("");

			// START HERE
			// ADD LOGIC FOR INPUT INITIAL
			do{
				printf("Input Initial [example: SW]: ");
				scanf("%[^\n]%*c", initial); fflush(stdin);
			}while(strcmp(initial, "AA") < 0 || strcmp(initial, "ZZ") > 0 || strlen(initial)!=2);
			
			
			// END HERE

			// START HERE
			push(&root,initial);
			// END HERE

			getchar();
			break;
		case 2:
			// START HERE
			// ADD LOGIC FOR VIEW ALL DATA IN THE TREE
		print(root);
		getchar();
			// END HERE
			break;
		}
	} while (choose != 3);

	// START HERE
	// ADD LOGIC FOR POP ALL DATA IN THE LINKED LIST
	free(root);

	// END HERE

	puts("\nThanks for using this progAram");
	system("pause");
	return 0;
}
