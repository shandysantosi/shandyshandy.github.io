#include<stdio.h>
#include<string.h>
int main (){
int a , b, c[100],e,res=0,count=0;
char d[100],f[100];
do{
scanf("%d",&a);
}while(a>100||a<1);
for(int i=1;i<=a;i++){
	do{
	scanf("%d",c[i]);
}while(c[i]>60||c[i]<0);
}
do{
scanf("%d %[^\n]",&b ,&d);
}while(b>a||b<1||strcmp(d,"right")!=0||strcmp(d,"left")!=0);
do{
scanf("%d %[^\n]",&e ,&f);
}while(e>a||e<1||strcmp(f,"right")!=0||strcmp(f,"left")!=0);
if(strcmp(d,"right")==0){
	for(int i=a;i>=a-b;i--){
		res+=c[i];
	}
}
else if(strcmp(d,"left")==0){
	for(int i=1;i<=b;i++){
		res+=c[i];
	}
}

if(strcmp(f,"right")==0){
	for(int i=a;i>=a-b;i--){
	  if(c[i]==0){
	  	count++;
	  }
	}
}
else if(strcmp(f,"left")==0){
	for(int i=1;i<=b;i++){
	 if(c[i]==0){
	  	count++;
	  }
	}
}
printf("%d %d\n",res,count);





}
