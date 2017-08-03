#include <stdio.h> 
#include <string.h> 

struct contract//�������ݽṹ 
{ 
char name[20];//����
char addr[20]; //��ַ
char tel[20];//�绰
char post[20];//�ʱ�

}data[20]; //����ṹ������ 

int addcount=0;  //ͨѶ¼�����Ŀ���� 
int readcount=0; //ͨѶ¼��ȡ��Ŀ����

int menu_book();//��ҳ
int newwork(); //�½�ͨѶ¼
int add(); //���һ����¼
void show(); //��ʾ
void save(); //����
void load(); //����
int search(); //����
void change(); //�޸�
void del();//ɾ��

//////////// ������ /////////////////
int main() 
{
int flag1=1;
while(flag1) 
{ 
switch(menu_book()) 
{ 

case 1 : newwork() ; break; 
case 2 : add() ; break; 
case 3 : show() ; break; 
case 4 : save() ; break; 
case 5 : load(); break; 
case 6 : search() ; break; 
case 7 : change() ; break; 
case 8 : del() ; break; 
case 9 : flag1=0;printf("�˳�\n"); break;
} 
} 
} 
///////////////// ��ҳ //////////////////////////////
int menu_book() 
{ 
int c; 
printf("*******************ͨѶ¼����ϵͳ******************\n"); 
printf("*                   1.�½�                        *\n");
printf("*                   2.���                        *\n");  
printf("*                   3.��ʾ                        *\n"); 
printf("*                   4.�洢                        *\n"); 
printf("*                   5.װ��                        *\n");  
printf("*                   6.��ѯ                        *\n"); 
printf("*                   7.�޸�                        *\n");
printf("*                   8.ɾ��                        *\n");
printf("*                   9.�˳�                        *\n");
printf("***************************************************\n"); 
do 
{
	printf("\n��ѡ��(1-9):"); 
    scanf("%d",&c); 
} 
while(c<0||c>9); 

return c; 
} 

//////////////////////////////////////////////////////////////////////////
///////////////////  1.�½�ͨѶ¼ ////////
int newwork() 
{ 
int i=0; 
char ch[20]; 
while(1) 
{ 
    if(strcmp(ch,"0")==0) 
        break; 
    printf("�����%d��������:\n",i+1); 
    scanf("%s",data[i].name); 
    printf("�����%d���˵�ַ:\n",i+1); 
    scanf("%s",data[i].addr); 
    printf("�����%d���˵绰:\n",i+1); 
    scanf("%s",data[i].tel); 
    printf("�����%d�����ʱ�:\n",i+1); 
    scanf("%s",data[i].post); 
    printf("���롰0��ֹͣ,��������������:"); 
    scanf("%s",ch); 
    i++; 
} 
addcount=i; 
printf("����%d����Ϣ����ص���ҳ����4������\n",addcount); 
printf("\n����������ص���ҳ:\n"); 
getch(); 
return addcount; 
} 
//////////////////////////////////////////////////////
////////////// 2. ���һ����¼ ////////////////////
int add()
{FILE *fp;
printf("�����%d��������:\n",readcount);
scanf("%s",data[readcount-1].name); 
printf("�����%d���˵�ַ:\n",readcount); 
scanf("%s",data[readcount-1].addr); 
printf("�����%d���˵绰:\n",readcount); 
scanf("%s",data[readcount-1].tel); 
printf("�����%d�����ʱ�:\n",readcount); 
scanf("%s",data[readcount-1].post);
///////--------------------------------------

if((fp=fopen("FF.txt","a"))==NULL) 
{ 
    puts("open file error!"); 
    exit(0); 
} 

if(fwrite(&data[readcount-1],sizeof(struct contract),1,fp)==0) 
puts("write error!"); 
 
if( fclose(fp) ){			        	// �ر��ļ�  
       	printf( "Can not close the file!\n" );
        exit(0);
    }
else
///////--------------------------------------
printf("�ѱ������ļ�\n");
readcount++;
printf("\n����������ص���ҳ:\n"); 
getch();
return addcount;  
}
/////////////////////////////////////////
///////////// 3.��ʾ //////////
void show()
{ 
int i; 
printf("��� ����    ��ַ      �绰          �ʱ�\n"); 
for(i=0;i<addcount;i++) 
    printf("%d. %s     %s     %s     %s\n",i+1,data[i].name,data[i].addr,data[i].tel,data[i].post);
printf("\n����������ص���ҳ:\n"); 
getch(); 
} 
//////////////////////////////////////
/////// 4.���� ////////////
void save()
{
FILE *fp;
int readcount=addcount;  
int i; 
if((fp=fopen("FF.txt","w"))==NULL) 
{ 
    puts("open file error!"); 
    exit(0); 
} 

for(i=0;i<readcount;i++) 
{ 
if(fwrite(&data[i],sizeof(struct contract),1,fp)==0) 
    puts("write error!"); 

} 
if( fclose(fp) ){			        	// �ر��ļ�  
       	printf( "Can not close the file!\n" );
        exit(0);
    }
else
printf("�������!\n");
printf("\n����������ص���ҳ:\n"); 
getch(); 
} 
//////// 5. װ�� //////////////////
void load() 
{ 
FILE *fp; 
int i=0; 
readcount=0; 
if((fp=fopen("FF.txt","rb"))!=NULL) 
{ 
printf("����   ��ַ           �绰      �ʱ�\n"); 
while(!feof(fp))
{ 
    fread(&data[i],sizeof(struct contract),1,fp); 
    readcount++; 
    printf("%s   %s   %s     %s\n",data[i].name,data[i].addr,data[i].tel,data[i].post); 
    i++; 
} 
} 
else 
    puts("open error!"); 
fclose(fp);
printf("\n����������ص���ҳ:\n"); 
getch();  
} 
///////////////// 6.��ѯ //////////////
int search() 
{
int i; int flag=0;
char chaxun[20]; 
printf("��������ѯ\n") ; 
printf("����������:\n"); 
scanf("%s",chaxun);
printf("��� ����   ��ַ    �绰        �ʱ�\n"); 
for(i=0;i<readcount;i++) 
{ 
if(strcmp(data[i].name,chaxun)==0) 
{   flag=1;
    printf("%d. %s    %s    %s   %s\n", i+1,data[i].name,data[i].addr,data[i].tel,data[i].post); 
    //break; 
} 
}
if(flag==0)//�ж�������Ϣ�Ƿ����
printf("�޴�����Ϣ"); 
 
printf("\n����������ص���ҳ:\n"); 
getch(); 
return readcount;
} 
//////////////////////////////////////////////////////
/////////// 7.�޸� ///////////////////
void change() 
{ FILE *fp;
int p,q,i=0,j=0,m=0,flag2=0,flag3=0;
int a[20]; 
char name[20]; 
char tel[20]; 
char post[20]; 
char addr[20]; 

printf("��������:\n"); 
scanf("%s",name); 
printf("��� ����     ��ַ    �绰       �ʱ�\n");
for(p=0;p<readcount;p++) 
{ 
if(strcmp(data[p].name,name)==0) 
{
    printf("%d. %s     %s     %s     %s\n",p+1,data[p].name,data[p].addr,data[p].tel,data[p].post);
	a[m]=p+1;
	m++;
	flag2=1;
    //break; 
} 
}
if(flag2==0)//�ж�������Ϣ�Ƿ����
{
    printf("�޴�����Ϣ\n"); 
    printf("����������ص���ҳ:\n");
	getch();
}
else
{
printf("���������޸�\n");
printf("������Ҫ�޸ĵ���Ϣ���:");
scanf("%d",&q);
for(j=0;j<m;j++)
	if(a[j]-q==0)
	{
	    printf("�������µ�ַ���绰���ʱ�:\n"); 
	    scanf("%s%s%s",data[q-1].addr,data[q-1].tel,data[q-1].post);
		flag3=1;break;
	}
if(flag3==0)//�ж���������Ƿ���ȷ
{
    printf("������Ŵ���!\n");
	printf("����������ص���ҳ:\n");
	getch();
}
else//�����޸������ļ�
{
///////--------------------------------------

if((fp=fopen("FF.txt","wb+"))==NULL) 
{ 
    puts("open file error!"); 
    exit(0); 
} 
while(!feof(fp))
{ 
    fread(&data[i],sizeof(struct contract),1,fp); 
    i++; 
}

for(i=0;i<readcount-1;i++) 
{ 
    if(fwrite(&data[i],sizeof(struct contract),1,fp)==0) 
        puts("write error!"); 
}

if( fclose(fp) ){			        	// �ر��ļ�  
       	printf( "Can not close the file!\n" );
        exit(0);
    }
else
///////--------------------------------------
printf("�޸���ɣ��ѱ������ļ�"); 
printf("\n����������ص���ҳ:\n"); 
getch();  
} 
}
}
/////////////////////////////
/////////// 8.ɾ�� //////////
void del()
{ FILE *fp;
int d,p,q,i=0,j=0,m=0,flag2=0,flag3=0;
int a[20]; 
char name[20]; 
char tel[20]; 
char post[20]; 
char addr[20]; 

printf("������Ҫɾ��������:\n"); 
scanf("%s",name); 
printf("��� ����    ��ַ      �绰          �ʱ�\n"); 
for(p=0;p<readcount;p++) 
{ 
if(strcmp(data[p].name,name)==0) 
{
    printf("%d. %s     %s     %s     %s\n",p+1,data[p].name,data[p].addr,data[p].tel,data[p].post);
	a[m]=p+1;
	m++;
	flag2=1;
    //break; 
} 
}
if(flag2==0)//�ж�������Ϣ�Ƿ����
{
    printf("�޴�����Ϣ\n"); 
    printf("����������ص���ҳ:\n");
	getch();
}
else
{
	printf("������Ҫɾ������Ϣ���:");
    scanf("%d",&q);
	printf("�Ƿ�ȷ��ɾ��?(����1ȷ��������0�ص���ҳ):");
	scanf("%d",&d);
	if (d==1)
	{
		if((fp=fopen("FF.txt","wb+"))==NULL) 
		{ 
            puts("open file error!"); 
            exit(0); 
		} 
        while(!feof(fp))
		{ 
            fread(&data[i],sizeof(struct contract),1,fp);  
            i++; 
		}
        for(j=q-1;j<readcount-1;j++)
		{
			strcpy(data[j].name,data[j+1].name);
			strcpy(data[j].addr,data[j+1].addr);
			strcpy(data[j].tel,data[j+1].tel);
			strcpy(data[j].post,data[j+1].post);
		}
        for(i=0;i<readcount-1;i++) 
		{ 
            if(fwrite(&data[i],sizeof(struct contract),1,fp)==0) 
            puts("write error!"); 
		}

        if( fclose(fp) ){			        	// �ر��ļ�  
       	printf( "Can not close the file!\n" );
        exit(0);
		}
        else
///////--------------------------------------
            printf("ɾ����ɣ��ѱ������ļ�!"); 
printf("\n����������ص���ҳ:\n"); 
getch();  
	}
}
}