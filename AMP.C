/*

 ---------------------
|    APLUS STUDIOS    |
| COIMBATORE, 641-027 |
 ---------------------

AUTHOR:-
-------
	SATHEESH KUMAR D. [Developer ]
	SURESH   KUMAR D. [Betatester]

NOTE:-
------
This program is desiged for employees
details storing. This uses Files to
store the details.
*/

//Includes in code
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//File name Definitions
#define FNAME "Emp.cfg"
#define CDETAILS "ACC.DAT"
#define LOG "Log.txt"

//Functions used
int name_print(void);
void aexit(void);
void alog(char *);
void add_emp(void);
void dis_emp(void);
void sort_emp(void);

//Structure Employees
struct emp{
	int id;
	char name[50];
	char city[50];
	char location[50];
	char pin[7];
	char phno[10];
};

//Main Function
int main(){
	char ch;
	system("cls");
	if(name_print()==0){
		aexit();
	}
	alog("----------------------------\nAPPLICATION STARTED");
	printf("\n\n");
	printf("\t1.ADD EMPLOYEE\n\t2.DISPLAY EMPLOYEES LIST\n\t3.SORT EMPLOYEE\n\t4.Exit");
	printf("\n>");
	ch=getch();
	printf("\n");
	switch(ch){
		case '1':
			add_emp();
			break;
		case '2':
			dis_emp();
			break;
		case '3':
			sort_emp();
			break;
		default:
			aexit();
	}
	getch();
	return 0;
}

//Company details display function
int name_print(){
	char name[100],city[100],pin[100];
	FILE *fptr;
	fptr=fopen(FNAME,"r");
	if(fptr==NULL){
		alog("ERROR! Opening Emp.cfg File");
		printf("\nError in opening Emp.cfg file");
		return 0;
	}
	else{
		fscanf(fptr,"%s	%s	%s",name,city,pin);
		printf("\n%s\n%s,%s",name,city,pin);
		printf("\n______________________________");
		printf("\n\n");
		fclose(fptr);
		return 1;
	}
}

//Exit Function
void aexit(){
	printf("\nExiting Application..\n\n\n");
	printf("\n\t\t\tThanks For Using Our System........\n\n\n\n\n");
	alog("Application Exit");
	system("pause");
	exit(0);
}

//Data log system
void alog(char *a){
	FILE *lptr;
	lptr=fopen(LOG,"a");
	if(lptr==NULL){
		aexit();
	}
	else{
		fprintf(lptr,"%s\n",a);
		fclose(lptr);
	}
}

//Adding employees function
void add_emp(){
	FILE *eptr;
	struct emp e,f;
	int i=0;
	char ch,ct,cj,data[10000];
	system("cls");
	eptr=fopen(CDETAILS,"a+");
	if(eptr==NULL){
		alog("ERROR! Opening CDETAILS File");
		aexit();
	}
	while(fread(&f,sizeof(f),1,eptr)==1){
		i++;
	}
	i++;
	name_print();
	if(i==0){
		i=1;
	}
	do{
		printf("\nEmployee %d:",i);
		e.id=i;
		wrong:
		printf("\n\tName:");
		scanf("%s",e.name);
		printf("\n\tCity:");
		scanf("%s",e.city);
		printf("\n\tLocation:");
		scanf("%s",e.location);
		printf("\n\tMobile_No:");
		scanf("%s",e.phno);
		printf("\n\tPIN:");
		scanf("%s",e.pin);
		printf("\n\nNeed to change above info:[Y/N]..\n>");
		ct=getch();
		if(ct=='y'||ct=='y')
		{
			goto wrong;
		}
		fwrite(&e,sizeof(e),1,eptr);
		alog("\n\nEmployee added");
		printf("\n\nAdd Another Data:[Y/N]..\n>");
		ch=getch();
		if(ch=='y'||ch=='Y'){
			i++;
		}
		else{
			i=0;
		}
	}while(ch=='y'||ch=='Y');
	fclose(eptr);
	printf("\n\nExit:[Y/N]..\n>");
	cj=getch();
	if(cj=='y'||cj=='Y'){
		aexit();
	}
	else{
		main();
	}
}

//Displaying Employees Function
void dis_emp(){
	FILE *dptr;
	struct emp e,f;
	int i=0,j;
	char ch,c;
	char data[1000];
	system("cls");
	dptr=fopen(CDETAILS,"r");
	if(dptr==NULL){
		alog("ERROR! Opening file in CDETAILS File..");
		aexit();
	}
	while(fread(&f,sizeof(f),1,dptr)==1){
		i++;
	}
	rewind(dptr);
	name_print();
	printf("\n\nNo_Of_Employees:%d\n\n",i);
	printf("%3s     %-5s           %-5s   %-10s    %-10s  %-8s\n\n","ID","NAME","CITY","LOCATION","MOBILE","PIN");
	while(fread(&e,sizeof(e),1,dptr)==1){
		printf("%3d|  %-15s|  %-5s|  %-10s|  %-10s|  %-8s\n\n",e.id,e.name,e.city,e.location,e.phno,e.pin);
	}
	fclose(dptr);
	printf("\n\nExit:[Y/N]..\n>");
	ch=getch();
	if(ch=='y'||ch=='Y'){
		aexit();
	}
	else{
		main();
	}
}

//Sorting Employees Function
void sort_emp(){
	system("cls");
	int id;
	char ch,cj;
	printf("sort");
	name_print();
	FILE *sptr;
	struct emp e;
	sptr=fopen(CDETAILS,"r");
	if(sptr == NULL){
        alog("ERROR! Reading CDETAILS File");
        aexit();
	}
	do{
	printf("\n Enter Emp_Id:\n>");
	scanf("%d",&id);
	rewind(sptr);
    while(fread(&e,sizeof(e),1,sptr)==1){
            if(id==e.id){
                    printf("\nEmp_Id     : %d",e.id);
                    printf("\nEmp_Name   : %s",e.name);
                    printf("\nEmp_City   : %s",e.city);
                    printf("\nLocation   : %s",e.location);
                    printf("\nPin        : %s",e.pin);
                    printf("\nEmp_Mobile : %s",e.phno);
            }
	}
	printf("\n\nNeed to Sort Another data: [Y/N]\n>\n");
	ch=getch();
	}while(ch=='y' || ch=='Y');
	fclose(sptr);
    printf("\n\nExit:[Y/N]..\n>");
	cj=getch();
	if(cj=='y'||cj=='Y'){
		aexit();
	}
	else{
		main();
	}
}

/*Copyright:
	Aplus Studios 2016
	All rights reserved
*/
