#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
struct Data {
	// START HERE
	// ADD THE VARIABLES YOU NEED HERE
	char kata[5];
	Data*atas,*bawah;
Data*parent;
	// END HERE
}*curr,*temp,*root;
Data *newNode(char kata[5]){
	Data * temp = (Data *)malloc(sizeof(Data));
	strcpy(temp->kata,kata);
	temp->atas = NULL;
	temp->bawah= NULL;
	temp->parent = NULL;
	return temp;
} 	
void push(Data *curr,char kata[5]){
	if(root == 0){
		root = newNode(kata);
	}else{
		if(kata < curr->kata){
			if(curr->bawah == NULL){
				curr->bawah = newNode(kata);
				curr->bawah->parent = curr;
			}else{
				push(curr->bawah,kata);		
			
			}else if(kata > curr->kata){
			if(curr->atas == NULL){
				curr->atas = newNode(kata);
				curr->atas->parent = curr;
			}else{
				push(curr->atas,kata);
			}}
		}else {
			printf("Duplicate data\n");
		
		}
	}
}

Data*postOrder(Data*curr,int counter=0){
		
		if(curr!=NULL){
		
		postOrder(curr->atas,counter++);
		for(int i=0;i<counter;i++)
		printf("\t");
	
		printf("%s\n",curr->kata);
	
		postOrder(curr->bawah,counter++);	
		for(int i=0;i<=counter;i++){
		printf("\t");
		}
		}
}


int main() {
	int choose = 0;
	int counter=0;
	do {
		system("cls");
		puts("1. Add Initial");
		puts("2. View Initial");
		puts("3. Exit");
		printf(">> ");
		scanf("%d", &choose); fflush(stdin);
		switch (choose) {
		case 1:
			char initial[5];
			puts("");

			// START HERE
			// ADD LOGIC FOR INPUT INITIAL
			do{
			printf("Input Initial [example: SW]: ");
			scanf("%[^\n]", &initial); fflush(stdin);
		}while(strlen(initial)>5||strlen(initial)<1);
			
			// END HERE

			// START HERE
			push(root,initial);
			
			// END HERE

			getchar();
			break;
		case 2:
			// START HERE
			// ADD LOGIC FOR VIEW ALL DATA IN THE TREE
		postOrder(root);
		getchar();
			// END HERE
			break;
		}
	} while (choose != 3);

	// START HERE
	// ADD LOGIC FOR POP ALL DATA IN THE LINKED LIST
	free(root);

	// END HERE

	puts("\nThanks for using this program");
	system("pause");
	return 0;
}
