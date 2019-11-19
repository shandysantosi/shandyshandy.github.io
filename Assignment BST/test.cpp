#include <stdio.h>
#include<string.h>
#include<stdlib.h>


struct data{
	
	char nama[100];
	//int plat ;
	char plat[100];

	data *prev;
	data *next;
}*head,*tail,*curr;


//void pushBelakang(char nama[],int plat,char depan[],char belakang[]){
//	curr = (data*)malloc(sizeof(data));
//	strcpy(curr->nama,nama);
//	strcpy(curr->depan,depan);
//	strcpy(curr->belakang,belakang);
//	//curr->plat = plat;
//	curr->next = NULL;
//	curr->prev = NULL;
//
//	if(head == NULL){
//		head = tail = curr;
//	}else{
//		tail->next = curr;
//		curr->prev = tail;
//		tail = curr;
//	}
//}

void pushBelakang(char nama[],char plat[]){
	curr = (data*)malloc(sizeof(data));
	strcpy(curr->nama,nama);
	strcpy(curr->plat,plat);
	curr->next = NULL;
	curr->prev = NULL;

	if(head == NULL){
		head = tail = curr;
	}else{
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}

void popDepan(){
	if(head == NULL){
		printf("Tidak ada Motor yang perlu di cuci");
	}else{
		curr = head;
		if(head == tail){
			free(curr);
		head = tail = NULL;
		}else{
			curr = head;
			head = head->next;
			head->prev = NULL;
			curr->next=NULL;
			free(curr);
		}

	}
}



//void view(){
//	
//	while(curr!=NULL){
//		printf(" %-1d.%-20s : %s%d%s\n",i,curr->nama,curr->depan,curr->plat,curr->belakang);
//		curr = curr->next;
//		i++;
//	}
//}


void viewAll(){
	int i=1;
	curr = head;
	int counter = 100;
	printf("Total antrian : %d",i-1);
	
	if(i-1 == 0){
		printf(" Tidak ada Motor di antrian");
	}else{
		for(i = 0;i < counter;i++){
		printf(" %-1d.%-20s : %s\n",i,curr->nama,curr->plat);
		curr= curr->next;
		}
	}
	i++;

}



int main(){
	
	int pilihan;
	do{
	
	
	 viewAll();
	printf("\n\nProgram Antrian Cuci Motor\n");
	printf("==================\n");
	printf("1. Tambah motor antrian cuci\n");
	printf("2. Cuci 1 motor dari antrian\n");
	printf("3. Keluar\n");
	printf("Pilih :");
	scanf("%d",&pilihan);fflush(stdin);
	switch(pilihan){
	

		case 1:
			
			char tempNama[100],tempDepan[100],tempBelakang[100];
			//int tempPlat;
			char tempPlat[100];

			printf("Masukan jenis kendaraan :");
			scanf("%[^\n]",tempNama);fflush(stdin);
			
			//do{
			printf("Masukan No. Pol Motor [No. 3000-6999] :");
			scanf("%[^\n]",tempPlat);fflush(stdin);
			//}while(strcmp(tempDepan, "AA") < 0 || strcmp(tempDepan, "ZZ") > 0 || strcmp(tempBelakang, "AA") < 0 || strcmp(tempBelakang, "ZZ") > 0 || tempPlat < 2999 || tempPlat > 7000 );
			
			pushBelakang(tempNama,tempPlat);

			break;

		case 2:
			popDepan();
			break;
	
		}
	}while(pilihan !=3);

	getchar();
	return 0;
}
