#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef int ElemType;
typedef char ElemType_T;
typedef int Status;
#define OK 1
#define ERROR 0

//登陆操作
//账户：374551651
//密码：123456789qq 
void Register() {
	char account[20] = { 0 };
	char password[20] = { 0 };
	while (true) {
		printf("请输入账号：");
		scanf_s("%s", account, 20);
		if (strcmp(account, "374551651") == 0)	break;
		else {
			printf("该账户不存在！请重新输入！\n");
			system("pause");
			system("cls");
		}
	}
	while (true) {
		char temp;
		printf("请输入密码：");
		for (int i = 0; (temp = _getch()) != '\r'; ++i) {
			printf("*");
			password[i] = temp;
		}
		printf("%s", password);
		system("pause");
		if (strncmp(password, "123456789qq", 12) == 0)	break;
		else {
			password[11] = '\0';
			printf("\n密码错误！请重新输入！\n");
			system("pause");
			system("cls");
			printf("请输入账号：374551651\n");
		}
	}
}

//学生成绩结构体 
typedef struct score {
	ElemType math;
	ElemType chinese;
	ElemType english;
}score;

//学生结构体 
typedef struct Student {
	char id[20];	//12位有效数字 
	char name[20];	//规定为汉字 
	char sex[10];	//male或者female
	score grades;
	struct Student* next;
}Student, * StuList;

//教师评选得分结构体
typedef struct vote {
	ElemType_T poll_1;
	ElemType_T poll_2;
	ElemType_T poll_3;
}vote;

//老师结构体
typedef struct Teacher {
	char id[20];	//6位有效数字 
	char name[20];	//规定为汉字 
	char sex[10];	//male或者female 
	vote results;
	struct Teacher* next;
}Teacher, * TeaList;

//主界面
void ShowMenu() {
	system("cls");
	printf("新链表创建成功！\n");
	printf("=======================================\n");
	printf("*****\twelcome to the system\t*****\n");
	printf("=======================================\n");
	printf("=======================================\n");
	printf("*****\t按键1 - 进入学生系统\t*****\n");
	printf("*****\t按键2 - 进入老师系统\t*****\n");
	printf("*****\t按键0 - 退出系统\t*****\n");
	printf("=======================================\n");
}

//学生管理界面
void StuMenu() {
	system("cls");
	printf("=================================================\n");
	printf("*****\twelcome to the system of student\t*****\n");
	printf("=================================================\n");
	printf("=================================================\n");
	printf("*****\t按键1 - 添加学生信息\t*****\n");
	printf("*****\t按键2 - 查找学生信息\t*****\n");
	printf("*****\t按键3 - 显示学生信息\t*****\n");
	printf("*****\t按键4 - 修改学生信息\t*****\n");
	printf("*****\t按键5 - 删除学生信息\t*****\n");
	printf("*****\t按键6 - 清空学生信息\t*****\n");
	printf("*****\t按键7 - 销毁学生系统\t*****\n");
	printf("*****\t按键8 - 插入学生信息\t*****\n");
	printf("*****\t按键9 - 使用快速排序\t*****\n");
	printf("*****\t按键0 - 返回上一级\t*****\n");
	printf("=================================================\n");
}

//老师管理界面 
void TeaMenu() {
	system("cls");
	printf("=================================================\n");
	printf("*****\twelcome to the system of teacher\t*****\n");
	printf("=================================================\n");
	printf("=================================================\n");
	printf("*****\t按键1 - 添加老师信息\t*****\n");
	printf("*****\t按键2 - 查找老师信息\t*****\n");
	printf("*****\t按键3 - 显示老师信息\t*****\n");
	printf("*****\t按键4 - 修改老师信息\t*****\n");
	printf("*****\t按键5 - 删除老师信息\t*****\n");
	printf("*****\t按键6 - 清空老师信息\t*****\n");
	printf("*****\t按键7 - 销毁老师系统\t*****\n");
	printf("*****\t按键8 - 插入老师信息\t*****\n");
	printf("*****\t按键9 - 使用快速排序\t*****\n");
	printf("*****\t按键0 - 返回上一级\t*****\n");
	printf("=================================================\n");
}

//学生文件
void StuFile(StuList S) {
	FILE* fp;
	if ((fp = fopen("Student_base.txt", "w")) == NULL) {
		printf("cannot open file!\n");
		exit(0);
	}
	Student* p = S->next;
	char id[] = "学号\t\t姓名\t性别\t数学\t语文\t英语\n";
	fprintf(fp, "%s", id);
	while (p) {
		fprintf(fp, "%s\t", p->id);
		fprintf(fp, "%s\t", p->name);
		fprintf(fp, "%s\t", p->sex);
		fprintf(fp, "%d\t", p->grades.math);
		fprintf(fp, "%d\t", p->grades.chinese);
		fprintf(fp, "%d\t", p->grades.english);

		p = p->next;
	}
	return;
}

//老师文件
void TeaFile(TeaList T) {
	FILE* fp;
	if ((fp = fopen("Teacher_base.txt", "w")) == NULL) {
		printf("cannot open file!\n");
		exit(0);
	}
	Teacher* p = T->next;
	char id[] = "教工号\t姓名\t性别\t评一\t评二\t评三\n";
	fprintf(fp, "%s", id);
	while (p) {
		fprintf(fp, "%s\t", p->id);
		fprintf(fp, "%s\t", p->name);
		fprintf(fp, "%s\t", p->sex);
		fprintf(fp, "%c\t", p->results.poll_1);
		fprintf(fp, "%c\t", p->results.poll_2);
		fprintf(fp, "%c\t", p->results.poll_3);

		p = p->next;
	}
	return;
}

//公共--性别检测 
Status SexCheck(char sex[]) {
	if (strcmp(sex, "male") == 0 || strcmp(sex, "female") == 0)	return OK;
	return ERROR;
}

//公共--要插入的结点位置
int position() {
	int location;
	printf("输入您想要插入的位置：(首位为0)");
	scanf_s("%d", &location);
	return location;
}

//学生--判断空链表
Status StuIsEmpty(StuList S) {
	return S->next == NULL;
}

//学生--学号查重
Status StuID_Same(StuList S, char id[]) {
	Student* p = S->next;
	while (p) {
		if (strcmp(p->id, id) == 0)	return ERROR;
		p = p->next;
	}
	return OK;
}

//学生--学号位数检测 
Status StuIDcheck(char id[]) {
	if (strlen(id) == 12)	return OK;
	return ERROR;
}

//学生--成绩检测 
Status StuGradeCheck(ElemType grade) {
	if (grade >= 0 && grade <= 100)	return OK;
	return ERROR;
}

//学生--创建空链表
StuList StuInitList() {
	StuList S = (StuList)malloc(sizeof(Student));
	if (S != NULL)	S->next = NULL;
	return S;
}

//学生--测量链表长度
int StuLength(StuList S) {
	if (!S->next)	return 0;
	Student* p = S->next;
	int length = 0;
	while (p)
		length++;
	return length;
}

//学生--尾插法添加功能
StuList StuInsert(StuList S) {
	Student* p = (Student*)malloc(sizeof(Student));
	if (p != NULL)	p->next = NULL;
	StuList r = S;

	if (p != NULL) {
		printf("请输入您想要添加的学生相关信息：\n");
		printf("学号：(请输入12位有效数字)");
		while (true) {
			scanf_s("%s", p->id, 20);
			if (StuIDcheck(p->id))
				if (StuID_Same(r, p->id))	break;
				else	printf("该学号已存在！请重新输入！\n");
			else	printf("位数有误！请重新输入！\n");
		}
		printf("姓名：(限用汉字)");
		scanf_s("%s", p->name, 20);
		printf("性别：( 男-male || 女-female )");
		while (true) {
			scanf_s("%s", p->sex, 10);
			if (SexCheck(p->sex))	break;
			else	printf("请按规定输入！\n");
		}
		printf("数学成绩：(0-100)");
		while (true) {
			scanf_s("%d", &p->grades.math);
			if (StuGradeCheck(p->grades.math))	break;
			else	printf("格式有误！请重新输入！\n");
		}
		printf("语文成绩：(0-100)");
		while (true) {
			scanf_s("%d", &p->grades.chinese);
			if (StuGradeCheck(p->grades.chinese))	break;
			else	printf("格式有误！请重新输入！\n");
		}
		printf("英语成绩：(0-100)");
		while (true) {
			scanf_s("%d", &p->grades.english);
			if (StuGradeCheck(p->grades.english))	break;
			else	printf("格式有误！请重新输入！\n");
		}
	}

	//寻找尾结点
	while (r->next) {
		r = r->next;
	}

	//拼接 
	r->next = p;
	r = p;

	printf("添加成功！\n");
	return S;
}

//学生--插入功能
StuList StuInsert_location(StuList S) {
	int length = StuLength(S);
	int location = position();
	if (location < 0 || location > length) { printf("非法位置！请重新输入！\n"); return S; }
	Student* p = (Student*)malloc(sizeof(Student));
	if (p != NULL)	p->next = NULL;
	StuList r = S;
	int flag = 0;
	while (flag < location-1) { r = r->next; flag++; }

	if (p != NULL) {
		printf("请输入您想要插入的学生相关信息：\n");
		printf("学号：(请输入12位有效数字)");
		while (true) {
			scanf_s("%s", p->id, 20);
			if (StuIDcheck(p->id))
				if (StuID_Same(r, p->id))	break;
				else	printf("该学号已存在！请重新输入！\n");
			else	printf("位数有误！请重新输入！\n");
		}
		printf("姓名：(限用汉字)");
		scanf_s("%s", p->name, 20);
		printf("性别：( 男-male || 女-female )");
		while (true) {
			scanf_s("%s", p->sex, 10);
			if (SexCheck(p->sex))	break;
			else	printf("请按规定输入！\n");
		}
		printf("数学成绩：(0-100)");
		while (true) {
			scanf_s("%d", &p->grades.math);
			if (StuGradeCheck(p->grades.math))	break;
			else	printf("格式有误！请重新输入！\n");
		}
		printf("语文成绩：(0-100)");
		while (true) {
			scanf_s("%d", &p->grades.chinese);
			if (StuGradeCheck(p->grades.chinese))	break;
			else	printf("格式有误！请重新输入！\n");
		}
		printf("英语成绩：(0-100)");
		while (true) {
			scanf_s("%d", &p->grades.english);
			if (StuGradeCheck(p->grades.english))	break;
			else	printf("格式有误！请重新输入！\n");
		}
	}

	//进行拼接
	if (p) {
		p->next = r->next;
		r->next = p;
	}

	printf("插入成功！\n");
	return S;
}

//学生--根据学号查找功能
void StuQuery(StuList S) {
	if (StuIsEmpty(S)) {
		printf("链表为空！\n");
		return;
	}
	Student* p = S->next;
	char stu_id[20] = { 0 };
	printf("请输入您想要查询的学生学号：");
	scanf_s("%s", stu_id, 20);
	while (p) {
		if (strcmp(p->id, stu_id) == 0) {
			printf("查找成功！\n");
			printf("学号\t\t姓名\t性别\t数学\t语文\t英语\t平均成绩\n");
			printf("%s\t", p->id);
			printf("%s\t", p->name);
			printf("%s\t", p->sex);
			printf("%d\t", p->grades.math);
			printf("%d\t", p->grades.chinese);
			printf("%d\t", p->grades.english);
			int average = (p->grades.math + p->grades.chinese + p->grades.english) / 3;
			printf("%d\n", average);
			return;
		}
		p = p->next;
	}
	printf("抱歉！查无此人！\n");
	return;
}

//学生--显示功能
void StuShow(StuList S) {
	if (StuIsEmpty(S)) {
		printf("链表为空！\n");
		return;
	}
	Student* p = S->next;
	printf("学号\t\t姓名\t性别\t数学\t语文\t英语\t平均成绩\n");
	while (p) {
		printf("%s\t", p->id);
		printf("%s\t", p->name);
		printf("%s\t", p->sex);
		printf("%d\t", p->grades.math);
		printf("%d\t", p->grades.chinese);
		printf("%d\t", p->grades.english);
		int average = (p->grades.math + p->grades.chinese + p->grades.english) / 3;
		printf("%d\n", average);

		p = p->next;
	}
}

//学生--修改功能
StuList StuModify(StuList S) {
	char stu_id[20] = { 0 };
	printf("请输入您想要修改的学生学号：");
	scanf_s("%s", stu_id, 20);

	Student* p = S->next;
	Student* pos = S;
	Student* q = (Student*)malloc(sizeof(Student));
	if (q != NULL)	q->next = NULL;

	if (q != NULL) {
		while (p) {
			if (strcmp(p->id, stu_id) == 0) {
				int select;
				printf("--是否继续操作(注意：此操作不可逆！)--\n");
				printf("********** 1-确认|0-取消 **********\n");
				scanf_s("%d", &select);
				if (select) {
					printf("请输入您想要添加的学生相关信息：\n");
					printf("学号：(请输入12位有效数字)");
					while (true) {
						scanf_s("%s", q->id, 20);
						if (StuIDcheck(q->id))
							if (StuID_Same(S, q->id))	break;
							else	printf("该学号已存在！请重新输入！\n");
						else	printf("位数有误！请重新输入！\n");
					}
					printf("姓名：(限用汉字)");
					scanf_s("%s", q->name, 20);
					printf("性别：( 男-male || 女-female )");
					while (true) {
						scanf_s("%s", q->sex, 10);
						if (SexCheck(q->sex))	break;
						else	printf("请按规定输入！\n");
					}
					printf("数学成绩：(0-100)");
					while (true) {
						scanf_s("%d", &q->grades.math);
						if (StuGradeCheck(q->grades.math))	break;
						else	printf("格式有误！请重新输入！\n");
					}
					printf("语文成绩：(0-100)");
					while (true) {
						scanf_s("%d", &q->grades.chinese);
						if (StuGradeCheck(q->grades.chinese))	break;
						else	printf("格式有误！请重新输入！\n");
					}
					printf("英语成绩：(0-100)");
					while (true) {
						scanf_s("%d", &q->grades.english);
						if (StuGradeCheck(q->grades.english))	break;
						else	printf("格式有误！请重新输入！\n");
					}

					q->next = p->next;
					pos->next = q;
					printf("修改成功！\n");
					return S;
				}
				break;
			}
			p = p->next;
			pos = pos->next;
		}
	}
	if (!p)	printf("抱歉！查无此人！\n");
	return S;
}

//学生--删除功能
StuList StuDelete(StuList S) {
	char stu_id[20] = { 0 };
	printf("请输入您想要删除的学生学号：");
	scanf_s("%s", stu_id, 20);

	Student* p = S->next;
	StuList r = S;

	while (p) {
		if (strcmp(p->id, stu_id) == 0) {
			int select;
			printf("--是否继续操作(注意：此操作不可逆！)--\n");
			printf("********** 1-确认|0-取消 **********\n");
			scanf_s("%d", &select);
			if (select) {
				r->next = r->next->next;
				free(p);
				printf("删除成功！\n");
				return S;
			}
			break;
		}
		p = p->next;
		r = r->next;
	}
	if (!p)	printf("抱歉！查无此人！\n");
	return S;
}

//学生--清空功能
StuList StuClear(StuList S) {
	if (StuIsEmpty(S)) {
		printf("链表本身就是空链表！\n");
		return S;
	}
	int select;
	printf("--是否继续操作(注意：此操作不可逆！)--\n");
	printf("********** 1-确认|0-取消 **********\n");
	scanf_s("%d", &select);
	if (select) {
		Student* p, * q;
		p = S->next;
		q = S->next;
		while (p) {
			q = q->next;
			free(p);
			p = q;
		}
		printf("已清空！\n");
		S->next = NULL;
	}
	return S;
}

//学生--销毁功能
Status StuDestroy(StuList S) {
	Student* r = S;
	int select;
	printf("--是否继续操作(注意：此操作不可逆！)--\n");
	printf("********** 1-确认|0-取消 **********\n");
	scanf_s("%d", &select);
	if (select) {
		while (S) {
			S = S->next;
			free(r);
			r = S;
		}
		printf("成功销毁！\n");
	}
	StuList students = StuInitList();
	return OK;
}

//老师--判断空链表
Status TeaIsEmpty(TeaList T) {
	return T->next == NULL;
}

//老师--教工号查重
Status TeaID_Same(TeaList T, char id[]) {
	Teacher* p = T->next;
	while (p) {
		if (strcmp(p->id, id) == 0)	return ERROR;
		p = p->next;
	}
	return OK;
}

//老师--教工号位数检测 
Status TeaIDcheck(char id[]) {
	if (strlen(id) == 6)	return OK;
	return ERROR;
}

//老师--评选检测 
Status TeaPollCheck(ElemType_T poll) {
	if (poll >= 'A' && poll <= 'D')	return OK;
	return ERROR;
}

//老师--创建空链表
TeaList TeaInitList() {
	TeaList T = (TeaList)malloc(sizeof(Teacher));
	if (T != NULL)T->next = NULL;
	return T;
}

//老师--测量链表长度
int TeaLength(TeaList T) {
	if (!T->next)	return 0;
	Teacher* p = T->next;
	int length = 0;
	while (p)
		length++;
	return length;
}

//老师--尾插法添加功能
TeaList TeaInsert(TeaList T) {
	Teacher* p = (Teacher*)malloc(sizeof(Teacher));
	if (p != NULL)p->next = NULL;
	TeaList r = T;

	if (p != NULL) {
		printf("请输入您想要添加的老师相关信息：\n");
		printf("教工号：(请输入6位有效数字)");
		while (true) {
			scanf_s("%s", p->id, 20);
			if (TeaIDcheck(p->id))
				if (TeaID_Same(r, p->id))	break;
				else	printf("该教工号已存在！请重新输入！\n");
			else printf("位数输入有误！请重新输入！\n");
		}
		printf("姓名：(限用汉字)");
		scanf_s("%s", p->name, 20);
		printf("性别：( 男-male || 女-female )");
		while (true) {
			scanf_s("%s", p->sex, 10);
			if (SexCheck(p->sex))	break;
			else	printf("请按规定输入！\n");
		}
		int n = getchar();
		printf("评选一：(A-D)");
		while (true) {
			scanf_s("%c", &p->results.poll_1, 1);
			if (TeaPollCheck(p->results.poll_1))		break;
			else { printf("格式有误！请重新输入！\n"); int n = getchar(); }
		}
		n = getchar();
		printf("评选二：(A-D)");
		while (true) {
			scanf_s("%c", &p->results.poll_2, 1);
			if (TeaPollCheck(p->results.poll_2))		break;
			else { printf("格式有误！请重新输入！\n"); int n = getchar(); }
		}
		n = getchar();
		printf("评选三：(A-D)");
		while (true) {
			scanf_s("%c", &p->results.poll_3, 1);
			if (TeaPollCheck(p->results.poll_3))		break;
			else { printf("格式有误！请重新输入！\n"); int n = getchar(); }
		}
	}

	//寻找尾结点
	while (r->next) {
		r = r->next;
	}

	//拼接 
	r->next = p;
	r = p;

	printf("添加成功！\n");
	return T;
}

//老师--插入功能
TeaList TeaInsert_location(TeaList T) {
	int length = TeaLength(T);
	int location = position();
	if (location < 0 || location > length) { printf("非法位置！请重新输入！\n"); return T; }
	Teacher* p = (Teacher*)malloc(sizeof(Teacher));
	if (p != NULL)	p->next = NULL;
	TeaList r = T;
	int flag = 0;
	while (flag < location - 1) { r = r->next; flag++; }

	if (p != NULL) {
		printf("请输入您想要插入的老师相关信息：\n");
		printf("教工号：(请输入6位有效数字)");
		while (true) {
			scanf_s("%s", p->id, 20);
			if (TeaIDcheck(p->id))
				if (TeaID_Same(r, p->id))	break;
				else	printf("该教工号已存在！请重新输入！\n");
			else	printf("位数有误！请重新输入！\n");
		}
		printf("姓名：(限用汉字)");
		scanf_s("%s", p->name, 20);
		printf("性别：( 男-male || 女-female )");
		while (true) {
			scanf_s("%s", p->sex, 10);
			if (SexCheck(p->sex))	break;
			else	printf("请按规定输入！\n");
		}
		int n = getchar();
		printf("评选一：(A-D)");
		while (true) {
			scanf_s("%c", &p->results.poll_1, 1);
			if (TeaPollCheck(p->results.poll_1))		break;
			else { printf("格式有误！请重新输入！\n"); int n = getchar(); }
		}
		n = getchar();
		printf("评选二：(A-D)");
		while (true) {
			scanf_s("%c", &p->results.poll_2, 1);
			if (TeaPollCheck(p->results.poll_2))		break;
			else { printf("格式有误！请重新输入！\n"); int n = getchar(); }
		}
		n = getchar();
		printf("评选三：(A-D)");
		while (true) {
			scanf_s("%c", &p->results.poll_3, 1);
			if (TeaPollCheck(p->results.poll_3))		break;
			else { printf("格式有误！请重新输入！\n"); int n = getchar(); }
		}
	}

	//进行拼接
	if (p) {
		p->next = r->next;
		r->next = p;
	}

	printf("插入成功！\n");
	return T;
}

//老师--根据教工号查找功能
void TeaQuery(TeaList T) {
	if (TeaIsEmpty(T)) {
		printf("链表为空！\n");
		return;
	}
	Teacher* p = T->next;
	char tea_id[20] = { 0 };
	printf("请输入您想要查询的老师教工号：");
	scanf_s("%s", tea_id, 20);
	while (p) {
		if (strcmp(p->id, tea_id) == 0) {
			printf("查找成功！\n");
			printf("教工号\t姓名\t性别\t评一\t评二\t评三\t最大评分\n");
			printf("%s\t", p->id);
			printf("%s\t", p->name);
			printf("%s\t", p->sex);
			printf("%c\t", p->results.poll_1);
			printf("%c\t", p->results.poll_2);
			printf("%c\t", p->results.poll_3);
			char max = p->results.poll_1 > p->results.poll_2 ? p->results.poll_1 > p->results.poll_3 ? p->results.poll_1 : p->results.poll_3 : p->results.poll_2 > p->results.poll_3 ? p->results.poll_2 : p->results.poll_3 ;
			printf("%c\n", max);
			return;
		}
		p = p->next;
	}
	printf("抱歉！查无此人！\n");
	return;
}

//老师--显示功能
void TeaShow(TeaList T) {
	if (TeaIsEmpty(T)) {
		printf("链表为空！\n");
		return;
	}
	Teacher* p = T->next;
	printf("教工号\t姓名\t性别\t评一\t评二\t评三\t最大评分\n");
	while (p) {
		printf("%s\t", p->id);
		printf("%s\t", p->name);
		printf("%s\t", p->sex);
		printf("%c\t", p->results.poll_1);
		printf("%c\t", p->results.poll_2);
		printf("%c\t", p->results.poll_3);
		char max = p->results.poll_1 < p->results.poll_2 ? p->results.poll_1 < p->results.poll_3 ? p->results.poll_1 : p->results.poll_3 : p->results.poll_2 < p->results.poll_3 ? p->results.poll_2 : p->results.poll_3;
		printf("%c\n", max);

		p = p->next;
	}
}

//老师--修改功能
TeaList TeaModify(TeaList T) {
	char tea_id[20] = { 0 };
	printf("请输入您想要修改的老师教工号：");
	scanf_s("%s", tea_id, 20);

	Teacher* p = T->next;
	Teacher* pos = T;
	Teacher* q = (Teacher*)malloc(sizeof(Teacher));
	if (q != NULL)q->next = NULL;

	if (q != NULL) {
		while (p) {
			if (strcmp(p->id, tea_id) == 0) {
				int select;
				printf("--是否继续操作(注意：此操作不可逆！)--\n");
				printf("********** 1-确认|0-取消 **********\n");
				scanf_s("%d", &select);
				if (select) {
					printf("请输入您想要添加的老师相关信息：\n");
					printf("教工号：(请输入6位有效数字)");
					while (true) {
						scanf_s("%s", q->id, 20);
						if (TeaIDcheck(q->id))
							if (TeaID_Same(T, q->id))	break;
							else	printf("该教工号已存在！请重新输入！\n");
						else printf("位数输入有误！请重新输入！\n");
					}
					printf("姓名：(限用汉字)");
					scanf_s("%s", q->name, 20);
					printf("性别：( 男-male || 女-female )");
					while (true) {
						scanf_s("%s", q->sex, 20);
						if (SexCheck(q->sex))	break;
						else	printf("请按规定输入！\n");
					}
					int n = getchar();
					printf("评选一：(A-D)");
					while (true) {
						scanf_s("%c", &q->results.poll_1, 1);
						if (TeaPollCheck(q->results.poll_1))		break;
						else { printf("格式有误！请重新输入！\n"); int n = getchar(); }
					}
					n = getchar();
					printf("评选二：(A-D)");
					while (true) {
						scanf_s("%c", &q->results.poll_2, 1);
						if (TeaPollCheck(q->results.poll_2))		break;
						else { printf("格式有误！请重新输入！\n"); int n = getchar(); }
					}
					n = getchar();
					printf("评选三：(A-D)");
					while (true) {
						scanf_s("%c", &q->results.poll_3, 1);
						if (TeaPollCheck(q->results.poll_3))		break;
						else { printf("格式有误！请重新输入！\n"); int n = getchar(); }
					}

					q->next = p->next;
					pos->next = q;
					printf("修改成功！\n");
					return T;
				}
				break;
			}
			p = p->next;
			pos = pos->next;
		}
	}
	if (!p)	printf("抱歉！查无此人！\n");
	return T;
}

//老师--删除功能
TeaList TeaDelete(TeaList T) {
	char tea_id[20] = { 0 };
	printf("请输入您想要删除的老师教工号：");
	scanf_s("%s", tea_id, 20);

	Teacher* p = T->next;
	TeaList r = T;

	while (p) {
		if (strcmp(p->id, tea_id) == 0) {
			int select;
			printf("--是否继续操作(注意：此操作不可逆！)--\n");
			printf("********** 1-确认|0-取消 **********\n");
			scanf_s("%d", &select);
			if (select) {
				r->next = r->next->next;
				free(p);
				printf("删除成功！\n");
				return T;
			}
			break;
		}
		p = p->next;
		r = r->next;
	}
	if (!p)	printf("抱歉！查无此人！\n");
	return T;
}

//老师--清空功能
TeaList TeaClear(TeaList T) {
	if (TeaIsEmpty(T)) {
		printf("链表本身就是空链表！\n");
		return T;
	}
	int select;
	printf("--是否继续操作(注意：此操作不可逆！)--\n");
	printf("********** 1-确认|0-取消 **********\n");
	scanf_s("%d", &select);
	if (select) {
		Teacher* p, * q;
		p = T->next;
		q = T->next;
		while (p) {
			q = q->next;
			free(p);
			p = q;
		}
		printf("已清空！\n");
		T->next = NULL;
	}
	return T;
}

//老师--销毁功能
Status TeaDestroy(TeaList T) {
	Teacher* r = T;
	int select;
	printf("--是否继续操作(注意：此操作不可逆！)--\n");
	printf("********** 1-确认|0-取消 **********\n");
	scanf_s("%d", &select);
	if (select) {
		while (T) {
			T = T->next;
			free(r);
			r = T;
		}
		printf("成功销毁！\n");
	}
	TeaList teachers = TeaInitList();
	return OK;
}

//开始
Status Enter(StuList students, TeaList teachers) {
	while (true) {
		ShowMenu();//显示主界面 
		int select;
		printf("我的选择：");
		scanf_s("%d", &select);
		//进入学生选择界面 
		if (select == 1) {
			StuMenu();
			int stu_select;
			printf("我的选择：");
			scanf_s("%d", &stu_select);
			switch (stu_select) {
			case 1://添加 
				StuInsert(students);
				StuFile(students);
				system("pause");
				system("cls");
				break;
			case 2://查找 
				StuQuery(students);
				system("pause");
				system("cls");
				break;
			case 3://显示 
				StuShow(students);
				system("pause");
				system("cls");
				break;
			case 4://修改 
				StuModify(students);
				StuFile(students);
				system("pause");
				system("cls");
				break;
			case 5://删除 
				StuDelete(students);
				StuFile(students);
				system("pause");
				system("cls");
				break;
			case 6://清空 
				StuClear(students);
				StuFile(students);
				system("pause");
				system("cls");
				break;
			case 7://销毁 
				StuDestroy(students);
				system("pause");
				system("cls");
				break;
			case 8://插入
				StuInsert_location(students);
				system("pause");
				system("cls");
				break;
			case 0://返回上一级 
				break;
			}
		}
		//进入老师选择界面 
		else if (select == 2) {
			int tea_select;
			TeaMenu();
			printf("我的选择：");
			scanf_s("%d", &tea_select);
			switch (tea_select) {
			case 1://添加 
				TeaInsert(teachers);
				TeaFile(teachers);
				system("pause");
				system("cls");
				break;
			case 2://查找 
				TeaQuery(teachers);
				system("pause");
				system("cls");
				break;
			case 3://显示 
				TeaShow(teachers);
				system("pause");
				system("cls");
				break;
			case 4://修改 
				TeaModify(teachers);
				TeaFile(teachers);
				system("pause");
				system("cls");
				break;
			case 5://删除 
				TeaDelete(teachers);
				TeaFile(teachers);
				system("pause");
				system("cls");
				break;
			case 6://清空 
				TeaClear(teachers);
				TeaFile(teachers);
				system("pause");
				system("cls");
				break;
			case 7://销毁 
				TeaDestroy(teachers);
				system("pause");
				system("cls");
				break;
			case 8://插入
				TeaInsert_location(teachers);
				system("pause");
				system("cls");
			case 0://返回上一级 
				break;
			}
		}
		//退出 
		else if (select == 0) {
			printf("退出程序！\n");
			return 0;
		}
		//意外输入 
		else {
			printf("输入有误！请重新输入！\n");
			system("pause");
		}
	}
}

int main() {
	Register();//登陆操作 
	StuList students = StuInitList();
	TeaList teachers = TeaInitList();
	Enter(students, teachers);
	return 0;
	
}
