#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
struct Data{

	char depan[3];
	char belakang[4];
	char nama[20];
	int plat;

Data*next,*prev;

}*curr,*temp,*head,*tail,motor[100];
Data *newNode(char depan[3],int plat,char belakang[4],char nama[20]){
	Data * temp = (Data *)malloc(sizeof(Data));
	strcpy(temp->depan,depan);
	strcpy(temp->belakang,belakang);
	strcpy(temp->nama,nama);
	temp->plat=plat;
	temp->next = NULL;
	temp->prev= NULL;
	return temp;
} 	
void push(char depan[3],int plat,char belakang[4],char nama[20]){
	if(head == 0){
		head =tail= newNode(depan,plat,belakang,nama) ;
	}else{
		curr=newNode(depan,plat,belakang,nama);
		tail->next=curr;
		curr->prev=tail;
		tail=curr;
	}
}
void pop(){
	if(!head){
		printf("tidak ada motor untuk dicuci");
	}else{
	if(head=tail){
		free(curr);
	}else{
	
	curr=head;
	head=head->next;
	head->prev=0;
	curr->next=0;
	free(curr);}
}
}




int main() {
	int choose = 0;
	int counter=0;
	do {
		system("cls");
		printf("total antrian: %d\n",counter);
		if(counter==0){
			printf("tidak ada motor yang perlu di cuci\n");
		}else{
		curr=head;
		for(int i=1;i<=counter;i++){
			printf("%d. %s: %s %d %s\n",i,curr->nama,curr->depan,curr->plat,curr->belakang);
			curr=curr->next;
		}
		}
		puts("Program antrian cucian motor");
		puts("1. Tambah motor antrian cuci");
		puts("2. Cuci 1 motor dari antrian");
		puts("3. keluar");
		printf(">> ");
		scanf("%d", &choose); fflush(stdin);
		switch (choose) {
		case 1:
			char awal[3],akhir[4],nama[20];
			int nomor;
			puts("");
			
			
			printf("Masukan jenis kendaraan : ");
			scanf("%[^\n]",nama);fflush(stdin);

			do{
			printf("Masukan No. Pol Motor [No. 3000-6999] :");
			scanf("%s %d %s", awal,&nomor,akhir); fflush(stdin);
			}while(nomor<3000||nomor>=7000||strlen(awal)>2||strlen(akhir)>3);
			
		
			push(awal,nomor,akhir,nama);
			counter ++;
			getchar();
			break;
		case 2:
		pop();
		counter--;
			break;
		}
	} while (choose != 3);
	free(head);
	

	return 0;
}
