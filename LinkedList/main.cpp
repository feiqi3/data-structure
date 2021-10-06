#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"List.hpp"
#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -1
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef struct {
	char sno[4];
	char sname[10];
	int sage;
	char sdept[3];
}StuType;
typedef StuType ElemType;


int main()
{
	List<StuType> L;
	ElemType stu,stu_tmp;
	int func,pos;

	if (!L.init()) 
	{
		printf("overflow!\n");
		exit(-1);
	}
	for (int j=0;;j++)
	{
		printf("Please select the function:\n0--Exit\n1--insert student\n2--delete student\n3--update student name\n4--search student with sno\n5--show all student\n6--count the student\n Please input:");
		scanf("%d",&func);
		switch (func)
		{
		case 0: 
			exit(1);
			break;
		case 1: //插入学生信息
			printf("sno: ");
			scanf("%s", &stu.sno);
			printf("sname: ");
			scanf("%s", &stu.sname);
			printf("sage: ");
			scanf("%d", &stu.sage);
			printf("sdept: ");
			scanf("%s", &stu.sdept);
			L.push_back(stu);
            //L.insert(L.Length(),stu);
			break;
		case 2://删除指定学号的学生信息
			printf("input the sno:");
			scanf("%s",&stu.sno);
			pos=L.locate(stu,[](StuType a,StuType b){return (int)(strcmp(a.sno,b.sno)==0);});
			if (pos>0)
				L.deleteItem(pos);
			else
				printf("The student is not exist!\n");
			break;	
		case 3://更新指定学号的学生姓名
			printf("input the sno of the student to be updated:");
			scanf("%s",&stu.sno);
			pos=L.locate(stu,[](StuType a,StuType b){return (int)(strcmp(a.sno,b.sno)==0);});
			if (pos>0)
			{
				printf("input the new name:");
				scanf("%s",&stu.sname);
				L.get(pos,stu_tmp);
				stu.sage=stu_tmp.sage;
				strcpy(stu.sdept,stu_tmp.sdept);
				L.set(pos,stu);
			}
			else
				printf("The student is not exist!\n");
			break;
		case 4://查找指定学号的学生信息
			printf("input the sno:");
			scanf("%s",&stu.sno);
			pos=L.locate(stu,[](StuType a,StuType b){return (int)(strcmp(a.sno,b.sno)==0);});
			if (pos>0)
			{
				L.get(pos,stu_tmp);
				printf("%s\t%s\t%d\t%s\n",stu_tmp.sno,stu_tmp.sname,stu_tmp.sage,stu_tmp.sdept);
			}
			else
				printf("The student is not exist!\n");
			break;
		case 5: //输出所有学生信息
			L.listPrint([](StuType a){printf("%s\t%s\t%d\t%s\n",a.sno,a.sname,a.sage,a.sdept);});
			break;
		case 6: //输出学生数量
			printf("The student count is %d\n",L.Length());
			break;
		}
	}
}
