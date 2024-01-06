#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
        char SID[10];
        char NAME[25];
        char BRANCH[5];
        int SEM;
        char ADD[100];
};
typedef struct Student stud;

void CheckFile(FILE *fp)
{
        if(fp == NULL)
        {
                printf("File Not Found..\n");
                exit(1);
        }
}

void InsertStudent()
{
        stud s;
        FILE *fp;
        fp = fopen("Data.txt","a");
        CheckFile(fp);
        fflush(stdin);
        printf("\n\n\t\tRECORD DETAILS\n\n");
        printf("Enter SID : ");
        scanf("%s",s.SID);
        printf("Enter Name : ");
        scanf("%s",s.NAME);
        printf("Enter Branch : ");
        scanf("%s",s.BRANCH);
        printf("Enter Semester : ");
        scanf("%d",&s.SEM);
        printf("Enter Address : ");
        scanf("%s",s.ADD);
        fwrite(&s,sizeof(s),1,fp);
        fclose(fp);

}

void Modify()
{
        FILE *fp,*temp;
        stud s;
        int flag = 0;
        char id[10];
        printf("Enter SID : ");
        scanf("%s",id);
        temp = fopen("temp.txt","a+");

        fp = fopen("Data.txt","a+");
        CheckFile(fp);
        fflush(stdin);
        while(fread(&s,sizeof(s),1,fp)==1)
        {
                if(strcmp(id,s.SID)==0)
                {
                        flag = 1;
                        printf("Enter Address : ");
                        scanf("%s",s.ADD);
                        fwrite(&s,sizeof(s),1,temp);
                }
                else
                        fwrite(&s,sizeof(s),1,temp);

        }
        if(flag == 0)
                printf("Invalid ID... \n");
        fclose(fp);
        fclose(temp);
        remove("Data.txt");
        rename("temp.txt","Data.txt");

}

void Delete()
{
        FILE *fp,*temp;
        stud s;
        char id[10];
        printf("Enter SID : ");
        scanf("%s",id);
        temp = fopen("temp.txt","a+");

        fp = fopen("Data.txt","r");
        CheckFile(fp);
        while(fread(&s,sizeof(s),1,fp)==1)
        {
                if(strcmp(id,s.SID) != 0)
                {
                        fwrite(&s,sizeof(s),1,temp);
                }
        }
        fclose(fp);
        fclose(temp);
        remove("Data.txt");
        rename("temp.txt","Data.txt");
}

void ListStudents(){
        FILE *fp;
        stud s;
        printf("SID\tName\t\tBranch\tSemester\tAddress\n");
        fp = fopen("Data.txt","r");
        CheckFile(fp);
        while(fread(&s,sizeof(s),1,fp)==1)
                printf("%s\t%s\t\t%s\t%d\t%s\n",s.SID,s.NAME,s.BRANCH,s.SEM,s.ADD);
        fclose(fp);
}

void ListBranch()
{
        char branch[5];
        FILE *fp;
        stud s;
        printf("Enter Branch : ");
        scanf("%s",branch);
        printf("SID\tName\t\tBranch\tSemester\tAddress\n");
        fp = fopen("Data.txt","r");
        CheckFile(fp);
        fflush(stdin);
        while(fread(&s,sizeof(s),1,fp)==1)
        {
                if(strcmp(branch,s.BRANCH)==0)
                {
                        printf("%s\t%s\t\t%s\t%d\t%s\n",s.SID,s.NAME,s.BRANCH,s.SEM,s.ADD);
                }
        }
        fclose(fp);
}
void ListBranchAddress()
{
        char branch[5],Address[100];
        FILE *fp;
        stud s;
        printf("Enter Branch : ");
        scanf("%s",branch);
        printf("Enter Address : ");
        scanf("%s",Address);
        printf("SID\tName\t\tBranch\tSemester\tAddress\n");
        fp = fopen("Data.txt","r");
        CheckFile(fp);
        fflush(stdin);
        while(fread(&s,sizeof(s),1,fp)==1)
        {
                if(strcmp(branch,s.BRANCH)==0 && strcmp(Address,s.ADD)==0)
                {
                        printf("%s\t%s\t\t%s\t%d\t%s\n",s.SID,s.NAME,s.BRANCH,s.SEM,s.ADD);
                }
        }
        fclose(fp);
}



void main()
{
        int ch = 99;
        while(ch!=0)
        {
                printf("Enter Choice : \n1.Add Record\n2.Modify Record\n3.Delete Record\n4.List Students\n5.List Branch Students\n6.List Kuvempunagar Students\n0.Exit\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1 : InsertStudent();break;
                        case 2 : Modify();break;
                        case 3 : Delete();break;
                        case 4 : ListStudents();break;
                        case 5 : ListBranch();break;
                        case 6 : ListBranchAddress();break;
                        case 0 : printf("Exitting...\n");
                                 exit(0);break;
                        default : printf("Invalid Choice...\n");break;
                }
        }
}
