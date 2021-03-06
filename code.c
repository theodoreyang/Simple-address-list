#include <stdio.h> 
#include <string.h> 

struct contract//定义数据结构 
{ 
char name[20];//姓名
char addr[20]; //地址
char tel[20];//电话
char post[20];//邮编

}data[20]; //定义结构体数组 

int addcount=0;  //通讯录添加条目控制 
int readcount=0; //通讯录读取条目控制

int menu_book();//主页
int newwork(); //新建通讯录
int add(); //添加一条记录
void show(); //显示
void save(); //保存
void load(); //载入
int search(); //查找
void change(); //修改
void del();//删除

//////////// 主函数 /////////////////
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
case 9 : flag1=0;printf("退出\n"); break;
} 
} 
} 
///////////////// 主页 //////////////////////////////
int menu_book() 
{ 
int c; 
printf("*******************通讯录管理系统******************\n"); 
printf("*                   1.新建                        *\n");
printf("*                   2.添加                        *\n");  
printf("*                   3.显示                        *\n"); 
printf("*                   4.存储                        *\n"); 
printf("*                   5.装入                        *\n");  
printf("*                   6.查询                        *\n"); 
printf("*                   7.修改                        *\n");
printf("*                   8.删除                        *\n");
printf("*                   9.退出                        *\n");
printf("***************************************************\n"); 
do 
{
	printf("\n请选择(1-9):"); 
    scanf("%d",&c); 
} 
while(c<0||c>9); 

return c; 
} 

//////////////////////////////////////////////////////////////////////////
///////////////////  1.新建通讯录 ////////
int newwork() 
{ 
int i=0; 
char ch[20]; 
while(1) 
{ 
    if(strcmp(ch,"0")==0) 
        break; 
    printf("输入第%d个人姓名:\n",i+1); 
    scanf("%s",data[i].name); 
    printf("输入第%d个人地址:\n",i+1); 
    scanf("%s",data[i].addr); 
    printf("输入第%d个人电话:\n",i+1); 
    scanf("%s",data[i].tel); 
    printf("输入第%d个人邮编:\n",i+1); 
    scanf("%s",data[i].post); 
    printf("输入“0”停止,输入其他数继续:"); 
    scanf("%s",ch); 
    i++; 
} 
addcount=i; 
printf("共有%d条信息，请回到主页按“4”保存\n",addcount); 
printf("\n输入任意键回到主页:\n"); 
getch(); 
return addcount; 
} 
//////////////////////////////////////////////////////
////////////// 2. 添加一条记录 ////////////////////
int add()
{FILE *fp;
printf("输入第%d个人姓名:\n",readcount);
scanf("%s",data[readcount-1].name); 
printf("输入第%d个人地址:\n",readcount); 
scanf("%s",data[readcount-1].addr); 
printf("输入第%d个人电话:\n",readcount); 
scanf("%s",data[readcount-1].tel); 
printf("输入第%d个人邮编:\n",readcount); 
scanf("%s",data[readcount-1].post);
///////--------------------------------------

if((fp=fopen("FF.txt","a"))==NULL) 
{ 
    puts("open file error!"); 
    exit(0); 
} 

if(fwrite(&data[readcount-1],sizeof(struct contract),1,fp)==0) 
puts("write error!"); 
 
if( fclose(fp) ){			        	// 关闭文件  
       	printf( "Can not close the file!\n" );
        exit(0);
    }
else
///////--------------------------------------
printf("已保存至文件\n");
readcount++;
printf("\n输入任意键回到主页:\n"); 
getch();
return addcount;  
}
/////////////////////////////////////////
///////////// 3.显示 //////////
void show()
{ 
int i; 
printf("序号 姓名    地址      电话          邮编\n"); 
for(i=0;i<addcount;i++) 
    printf("%d. %s     %s     %s     %s\n",i+1,data[i].name,data[i].addr,data[i].tel,data[i].post);
printf("\n输入任意键回到主页:\n"); 
getch(); 
} 
//////////////////////////////////////
/////// 4.保存 ////////////
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
if( fclose(fp) ){			        	// 关闭文件  
       	printf( "Can not close the file!\n" );
        exit(0);
    }
else
printf("保存完成!\n");
printf("\n输入任意键回到主页:\n"); 
getch(); 
} 
//////// 5. 装入 //////////////////
void load() 
{ 
FILE *fp; 
int i=0; 
readcount=0; 
if((fp=fopen("FF.txt","rb"))!=NULL) 
{ 
printf("姓名   地址           电话      邮编\n"); 
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
printf("\n输入任意键回到主页:\n"); 
getch();  
} 
///////////////// 6.查询 //////////////
int search() 
{
int i; int flag=0;
char chaxun[20]; 
printf("按姓名查询\n") ; 
printf("请输入姓名:\n"); 
scanf("%s",chaxun);
printf("序号 姓名   地址    电话        邮编\n"); 
for(i=0;i<readcount;i++) 
{ 
if(strcmp(data[i].name,chaxun)==0) 
{   flag=1;
    printf("%d. %s    %s    %s   %s\n", i+1,data[i].name,data[i].addr,data[i].tel,data[i].post); 
    //break; 
} 
}
if(flag==0)//判断输入信息是否存在
printf("无此人信息"); 
 
printf("\n输入任意键回到主页:\n"); 
getch(); 
return readcount;
} 
//////////////////////////////////////////////////////
/////////// 7.修改 ///////////////////
void change() 
{ FILE *fp;
int p,q,i=0,j=0,m=0,flag2=0,flag3=0;
int a[20]; 
char name[20]; 
char tel[20]; 
char post[20]; 
char addr[20]; 

printf("输入姓名:\n"); 
scanf("%s",name); 
printf("序号 姓名     地址    电话       邮编\n");
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
if(flag2==0)//判断输入信息是否存在
{
    printf("无此人信息\n"); 
    printf("输入任意键回到主页:\n");
	getch();
}
else
{
printf("姓名不可修改\n");
printf("请输入要修改的信息序号:");
scanf("%d",&q);
for(j=0;j<m;j++)
	if(a[j]-q==0)
	{
	    printf("请输入新地址，电话，邮编:\n"); 
	    scanf("%s%s%s",data[q-1].addr,data[q-1].tel,data[q-1].post);
		flag3=1;break;
	}
if(flag3==0)//判断输入序号是否正确
{
    printf("输入序号错误!\n");
	printf("输入任意键回到主页:\n");
	getch();
}
else//保存修改数据文件
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

if( fclose(fp) ){			        	// 关闭文件  
       	printf( "Can not close the file!\n" );
        exit(0);
    }
else
///////--------------------------------------
printf("修改完成，已保存至文件"); 
printf("\n输入任意键回到主页:\n"); 
getch();  
} 
}
}
/////////////////////////////
/////////// 8.删除 //////////
void del()
{ FILE *fp;
int d,p,q,i=0,j=0,m=0,flag2=0,flag3=0;
int a[20]; 
char name[20]; 
char tel[20]; 
char post[20]; 
char addr[20]; 

printf("输入需要删除的姓名:\n"); 
scanf("%s",name); 
printf("序号 姓名    地址      电话          邮编\n"); 
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
if(flag2==0)//判断输入信息是否存在
{
    printf("无此人信息\n"); 
    printf("输入任意键回到主页:\n");
	getch();
}
else
{
	printf("请输入要删除的信息序号:");
    scanf("%d",&q);
	printf("是否确定删除?(输入1确定，输入0回到主页):");
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

        if( fclose(fp) ){			        	// 关闭文件  
       	printf( "Can not close the file!\n" );
        exit(0);
		}
        else
///////--------------------------------------
            printf("删除完成，已保存至文件!"); 
printf("\n输入任意键回到主页:\n"); 
getch();  
	}
}
}