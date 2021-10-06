#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef int ElemType ;
typedef int Status ;
#define OK 1
#define ERROR 0

//��½����
//�˻���374551651
//���룺123456789qq 
void Register(){
	char account[10] ;
	char password[20] ;
	while(true){
		printf("�������˺ţ�") ;
		scanf("%s",account) ;
		if(strcmp(account,"374551651") == 0)	break ;
		else{
			printf("���˻������ڣ����������룡\n") ;
			system("pause") ;
			system("cls") ;
		}
	} 
	while(true){
		char temp ;
		printf("���������룺") ;
		for(int i = 0;(temp = getch()) != '\r';++ i){
			printf("*") ;
			password[i] = temp ;
		}
		if(strncmp(password,"123456789qq",12) == 0)	break ;
		else{
			password[11] = '\0' ;
			printf("\n����������������룡\n") ;
			system("pause") ;
			system("cls") ;
			printf("�������˺ţ�374551651\n") ;
		}
	}
} 

//ѧ���ɼ��ṹ�� 
typedef struct score{
	ElemType math ;
	ElemType chinese ;
	ElemType english ;
}score;

//ѧ���ṹ�� 
typedef struct Student{
	char id[20] ;	//12λ��Ч���� 
	char name[20] ;	//�涨Ϊ���� 
	char sex[10] ;	//male����female 
	score grades ;
	struct Student *next ; 
}Student,*StuList;

//��ʦ��ѡ�÷ֽṹ��
typedef struct vote{
	ElemType poll_1 ;
	ElemType poll_2 ;
	ElemType poll_3 ;
}vote; 

//��ʦ�ṹ��
typedef struct Teacher{
	char id[20] ;	//6λ��Ч���� 
	char name[20] ;	//�涨Ϊ���� 
	char sex[10] ;	//male����female 
	vote results ;
	struct Student *next ; 
}Teacher,*TeaList; 

//������
void ShowMenu(){
	system("cls") ;
	printf("=======================================\n") ;
	printf("*****\twelcome to the system\t*****\n") ;
	printf("=======================================\n") ;
	printf("=======================================\n") ;
	printf("*****\t����1 - ����ѧ��ϵͳ\t*****\n") ;
	printf("*****\t����2 - ������ʦϵͳ\t*****\n") ;
	printf("*****\t����0 - �˳�ϵͳ\t*****\n") ;
	printf("=======================================\n") ;
} 

//ѧ���������
void StuMenu(){
	system("cls") ;
	printf("=================================================\n") ;
	printf("*****\twelcome to the system of student\t*****\n") ;
	printf("=================================================\n") ;
	printf("=================================================\n") ;
	printf("*****\t����1 - ���ѧ����Ϣ\t*****\n") ;
	printf("*****\t����2 - ����ѧ����Ϣ\t*****\n") ;
	printf("*****\t����3 - ��ʾѧ����Ϣ\t*****\n") ;
	printf("*****\t����4 - �޸�ѧ����Ϣ\t*****\n") ;
	printf("*****\t����5 - ɾ��ѧ����Ϣ\t*****\n") ;
	printf("*****\t����6 - ���ѧ����Ϣ\t*****\n") ;
	printf("*****\t����7 - ����ѧ��ϵͳ\t*****\n") ;
	printf("*****\t����0 - ������һ��\t*****\n") ;
	printf("=================================================\n") ;
} 

//��ʦ������� 
void TeaMenu(){
	system("cls") ;
	printf("=================================================\n") ;
	printf("*****\twelcome to the system of teacher\t*****\n") ;
	printf("=================================================\n") ;
	printf("=================================================\n") ;
	printf("*****\t����1 - �����ʦ��Ϣ\t*****\n") ;
	printf("*****\t����2 - ������ʦ��Ϣ\t*****\n") ;
	printf("*****\t����3 - ��ʾ��ʦ��Ϣ\t*****\n") ;
	printf("*****\t����4 - �޸���ʦ��Ϣ\t*****\n") ;
	printf("*****\t����5 - ɾ����ʦ��Ϣ\t*****\n") ;
	printf("*****\t����6 - �����ʦ��Ϣ\t*****\n") ;
	printf("*****\t����7 - ������ʦϵͳ\t*****\n") ;
	printf("*****\t����0 - ������һ��\t*****\n") ;
	printf("=================================================\n") ;
}

//ѧ��--�жϿ�����
Status StuIsEmpty(StuList S){
	return S->next == NULL ;
} 

//ѧ��--β�巨��ӹ���
StuList StuInsert(StuList S){
	Student *p = (Student*)malloc(sizeof(Student)) ;
	p->next = NULL ;
	StuList r = S ;
	
	printf("����������Ҫ��ӵ�ѧ�������Ϣ��\n") ;
	printf("ѧ�ţ�(������12λ��Ч����)") ;
	scanf("%s",p->id) ;
	printf("������(���ú���)") ;
	scanf("%s",p->name) ;
	printf("�Ա�( ��-male || Ů-female )") ;
	scanf("%s",p->sex) ;
	printf("��ѧ�ɼ���(0-100)") ;
	scanf("%d",&p->grades.math) ;
	printf("���ĳɼ���(0-100)") ;
	scanf("%d",&p->grades.chinese) ;
	printf("Ӣ��ɼ���(0-100)") ;
	scanf("%d",&p->grades.english) ;
	
	//Ѱ��β���
	while(r->next){
		r = r->next ;
	} 
	
	//ƴ�� 
	r->next = p ;
	r = p ;
	
	printf("��ӳɹ���\n") ;
	return S ; 
}

//ѧ��--����ѧ�Ų��ҹ���
void StuQuery(StuList S){
	if(StuIsEmpty(S)){
		printf("����Ϊ�գ�\n") ;
		return ;
	}
	Student *p = S->next ;
	char stu_id[20] ;
	printf("����������Ҫ��ѯ��ѧ��ѧ�ţ�") ;
	scanf("%s",stu_id) ;
	while(p){
		if(strcmp(p->id,stu_id) == 0){
			printf("���ҳɹ���\n") ;
			printf("ѧ��\t\t����\t�Ա�\t��ѧ\t����\tӢ��\n") ;
			printf("%s\t",p->id) ;
			printf("%s\t",p->name) ;
			printf("%s\t",p->sex) ;
			printf("%d\t",p->grades.math) ;
			printf("%d\t",p->grades.chinese) ;
			printf("%d\n",p->grades.english) ;
			return ;
		}
		p = p->next ;
	}
	printf("��Ǹ�����޴��ˣ�\n") ;
	return ;
}

//ѧ��--��ʾ����
void StuShow(StuList S){
	if(StuIsEmpty(S)){
		printf("����Ϊ�գ�\n") ;
		return ;
	}
	Student *p = S->next ;
	printf("ѧ��\t\t����\t�Ա�\t��ѧ\t����\tӢ��\n") ;
	while(p){
		printf("%s\t",p->id) ;
		printf("%s\t",p->name) ;
		printf("%s\t",p->sex) ;
		printf("%d\t",p->grades.math) ;
		printf("%d\t",p->grades.chinese) ;
		printf("%d\n",p->grades.english) ;
		
		p = p->next ;
	}
}

//ѧ��--�޸Ĺ���
StuList StuModify(StuList S){
	char stu_id[20] ;
	printf("����������Ҫ�޸ĵ�ѧ��ѧ�ţ�") ;
	scanf("%s",stu_id) ;
	
	Student *p = S->next ;
	Student *pos = S ;
	Student *q = (Student*)malloc(sizeof(Student)) ;
	q->next = NULL ;
	
	while(p){
		if(strcmp(p->id,stu_id) == 0){
			int select ;
			printf("--�Ƿ��������(ע�⣺�˲��������棡)--\n") ;
			printf("********** 1-ȷ��|0-ȡ�� **********\n") ; 
			scanf("%d",&select);
			if(select){
				printf("����������Ҫ��ӵ�ѧ�������Ϣ��\n") ;
				printf("ѧ�ţ�(������12λ��Ч����)") ;
				scanf("%s",q->id) ;
				printf("������(���ú���)") ;
				scanf("%s",q->name) ;
				printf("�Ա�( ��-male || Ů-female )") ;
				scanf("%s",q->sex) ;
				printf("��ѧ�ɼ���(0-100)") ;
				scanf("%d",&q->grades.math) ;
				printf("���ĳɼ���(0-100)") ;
				scanf("%d",&q->grades.chinese) ;
				printf("Ӣ��ɼ���(0-100)") ;
				scanf("%d",&q->grades.english) ;
				
				q->next = p->next ;
				pos->next = q ;
				printf("�޸ĳɹ���\n") ; 
				return S ;
			}
			break ;
		}
		p = p->next ;
		pos = pos->next ;
	}
	if(!p)	printf("��Ǹ�����޴��ˣ�\n") ;
	return S ;
}

//ѧ��--ɾ������
StuList StuDelete(StuList S){
	char stu_id[20] ;
	printf("����������Ҫɾ����ѧ��ѧ�ţ�") ;
	scanf("%s",stu_id) ;
	
	Student *p = S->next ;
	StuList r = S ;
	
	while(p){
		if(strcmp(p->id,stu_id) == 0){
			int select ;
			printf("--�Ƿ��������(ע�⣺�˲��������棡)--\n") ;
			printf("********** 1-ȷ��|0-ȡ�� **********\n") ; 
			scanf("%d",&select);
			if(select){
				r->next = r->next->next ;
				free(p) ;
				printf("ɾ���ɹ���\n") ;
				return S ;
			}
			break ;
		}
		p = p->next ;
		r = r->next ;
	}
	if(!p)	printf("��Ǹ�����޴��ˣ�\n") ;
	return S ;
}

//ѧ��--��չ���
StuList StuClear(StuList S){
	if(StuIsEmpty(S)){
		printf("��������ǿ�����\n") ;
		return S;
	}
	int select ;
	printf("--�Ƿ��������(ע�⣺�˲��������棡)--\n") ;
	printf("********** 1-ȷ��|0-ȡ�� **********\n") ; 
	scanf("%d",&select);
	if(select){
		Student *p,*q ;
		p = S->next ;
		q = S->next ;
		while(p){
			q = q->next ;
			free(p) ;
			p = q ;
		}
		printf("����գ�\n") ;
		S->next = NULL ;
	}
	return S ;
}

//ѧ��--���ٹ���
StuList StuDestroy(StuList S){
	
}

//��ʦ--�жϿ�����
Status TeaIsEmpty(TeaList T){
	return T->next == NULL ;
} 

//��ʦ--β�巨��ӹ���
TeaList TeaInsert(TeaList T){
	
}

//��ʦ--���ݽ̹��Ų��ҹ���
void TeaQuery(TeaList T){
	
}

//��ʦ--��ʾ����
void TeaShow(TeaList T){
	
}

//��ʦ--�޸Ĺ���
TeaList TeaModify(TeaList T){
	
}

//��ʦ--ɾ������
TeaList TeaDelete(TeaList T){
	
}

//��ʦ--��չ���
TeaList TeaClear(TeaList T){
	
}

//��ʦ--���ٹ���
TeaList TeaDestroy(TeaList T){
	
}

int main(){
	Register() ;//��½���� 
	StuList students = (StuList)malloc(sizeof(Student)) ;
	TeaList teachers = (TeaList)malloc(sizeof(Teacher)) ;
	while(true){
		ShowMenu() ;//��ʾ������ 
		int select ;
		printf("�ҵ�ѡ��") ;
		scanf("%d",&select) ;
		//����ѧ��ѡ����� 
		if(select == 1){	
			StuMenu() ;
			int stu_select ;
			printf("�ҵ�ѡ��") ;
			scanf("%d",&stu_select) ;
			switch(stu_select){
				case 1://��� 
					StuInsert(students) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 2://���� 
					StuQuery(students) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 3://��ʾ 
					StuShow(students) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 4://�޸� 
					StuModify(students) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 5://ɾ�� 
					StuDelete(students) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 6://��� 
					StuClear(students) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 7://���� 
					StuDestroy(students) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 0://������һ�� 
					break ;
			}
		}
		//������ʦѡ����� 
		else if(select == 2){
			int tea_select ;
			TeaMenu() ;
			printf("�ҵ�ѡ��") ;
			scanf("%d",&tea_select) ;
			switch(tea_select){
				case 1://��� 
					TeaInsert(teachers) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 2://���� 
					TeaQuery(teachers) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 3://��ʾ 
					TeaShow(teachers) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 4://�޸� 
					TeaModify(teachers) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 5://ɾ�� 
					TeaDelete(teachers) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 6://��� 
					TeaClear(teachers) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 7://���� 
					TeaDestroy(teachers) ;
					system("pause") ;
					system("cls") ;
					break ;
				case 0://������һ�� 
					break ;
			}
		}
		//�˳� 
		else if(select == 0){
			printf("�˳�����\n") ;
			return 0 ; 
		}
		//�������� 
		else{
			printf("�����������������룡\n") ;
			system("pause") ;
		}	
	} 
	return 0 ;
}
