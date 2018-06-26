#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct Data {
	//卡号、姓名、时间、消费额、消费地点、消费类型
	//增、删、改、浏览、查询、搜索
	char id[50];
	char name[50];
	char date[50];
	char consumption[50];
	char where[50];
	char category[50];
};
void view();
void del(int n);
void change(int n);
void add();
int main() {
	for (int y = 0; y < 9999; y++){
		//开始界面
		printf("        ┌------连锁超市会员消费记录管理-------┐\n");
		printf("         |                                    |\n");
		printf("         |             1.浏览                 |\n");
		printf("         |             2.添加                 |\n");
		printf("         |             3.更改                 |\n");
		printf("         |             4.删除                 |\n");
		printf("         |             5.查询                 |\n");
		printf("         |             6.搜索                 |\n");
		printf("         |             7.退出                 |\n");
		printf("         |                                    |\n");
		printf("        └-------------------------------------┘\n");
		printf("*********************************************************\n");
		printf("         ######请输入数字进行相应的操作#######\n");

		//接受输入数字进行处理
		int number;
		printf("         请输入：");
		scanf("%d", &number);
		system("cls");
		if (number == 7) {
			break;
		}
		//预处理信息
		//
		int hao;
		switch (number)
		{
		case 1://浏览
			view();
			break;

		case 2://添加
			add();
			break;

		case 3://更改
			view();
			printf("\n请选择你要更改数据的序号：");
			scanf("%d", &hao);
			change(hao);
			break;

		case 4://删除
			view();
			printf("\n请选择你要删除数据的序号：");
			scanf("%d", &hao);
			del(hao);
			break;

		case 7:




			break;
		}

		system("pause");
		system("cls");
		
	}
	return 0;
}

void view() {
	char a[1000];
	FILE *file = fopen("infor.txt", "a+");
	printf("\n序号 卡号  姓名 时间 消费额 消费地点 消费类型\n");
	/*while ((ch = getc(file)) != EOF) {
	putchar(ch);
	}*/
	for (int i = 1; i < 666; i++) {
		if (fgets(a, 100, file) != NULL) {
			printf(" %d    %s", i, a);
		}
		else {
			break;
		}
	}
	fclose(file);
}
void add() {
	struct Data temp;
	FILE *file = fopen("infor.txt", "r+");
	printf("请依次输入：\n卡号 姓名 时间 消费额 消费地点 消费类型\n");
	scanf("%s %s %s %s %s %s", &temp.id, &temp.name, &temp.date, &temp.consumption, &temp.where, &temp.category);
	fprintf(file, "%s %s %s %s %s %s\n", temp.id, temp.name, temp.date, temp.consumption, temp.where, temp.category);
	printf("添加成功\n");
	fclose(file);
}

void change(int n) {
	char a[50];
	FILE *file = fopen("infor.txt", "a+");
	for (int i = 1; i < 666; i++) {
		if (fgets(a, 100, file) != NULL) {
			if (i == n) {
				break;
			}
		}
	}
	fclose(file);
	//对字符串进行处理，切割字符串
	int i = 0;
	char str[99][99];
	char*temp = strtok(a, " ");
	while (temp) {
		//printf("%s\n", temp);
		strcpy(str[i], temp);//后面的是要拷贝的内容
		i++;
		temp = strtok(NULL, " ");
	}
	system("cls");
	printf("您选择的项是：\n");
	printf("序号 卡号 姓名 时间 消费额 消费地点 消费类型\n");
	for (i = 0; i < 6; i++) {
		printf("%s ", str[i]);
	}
	printf("\n请问您要更改什么值?\n");
	printf("1.卡号  2.姓名  3.时间  4.消费额  5.消费地点  6.消费类型\n请选择序号：");
	int num;
	char new[20];
	char new_str[100];
	scanf("%d", &num);
	printf("请输入新的值:");
	scanf("%s", &new);
	switch (num)
	{
	case 1:
		strcpy(str[0], new);
		break;
	case 2:
		strcpy(str[1], new);
		break;
	case 3:
		strcpy(str[2], new);
		break;
	case 4:
		strcpy(str[3], new);
		break;
	case 5:
		strcpy(str[4], new);
		break;
	case 6:
		strcpy(str[5], new);
		break;
	}
	del(n);
	FILE *new_file = fopen("infor.txt", "a+");
	for (i = 0; i < 6; i++) {
		fprintf(new_file, "%s", str[i]);
		if (i!=6){
			fprintf(new_file, " ");
		}
	}
	fclose(new_file);

}

void del(int n) {
	char a[50][50];
	int x=0;
	FILE *file = fopen("infor.txt", "r+");
	for (int i = 1; i < 666; i++) {
		if (fgets(a[x], 100, file) != NULL) {
			if (i != n) {
				x++;
			}
		}
		else {
			break;
		}
	}
	fclose(file);
	FILE *file_temp = fopen("infor.txt", "w");
	fprintf(file_temp, "");
	fclose(file_temp);
	FILE *temp = fopen("infor.txt", "a+");
	for ( int i = 0; i < x; i++){
		fprintf(temp, "%s", a[i]);
	}//123 123 王企鹅 阿萨德 十大 王企鹅
	printf("************操作成功************\n\n");
	fclose(temp);
}

