#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct Data {
	//���š�������ʱ�䡢���Ѷ���ѵص㡢��������
	//����ɾ���ġ��������ѯ������
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
		//��ʼ����
		printf("        ��------�������л�Ա���Ѽ�¼����-------��\n");
		printf("         |                                    |\n");
		printf("         |             1.���                 |\n");
		printf("         |             2.���                 |\n");
		printf("         |             3.����                 |\n");
		printf("         |             4.ɾ��                 |\n");
		printf("         |             5.��ѯ                 |\n");
		printf("         |             6.����                 |\n");
		printf("         |             7.�˳�                 |\n");
		printf("         |                                    |\n");
		printf("        ��-------------------------------------��\n");
		printf("*********************************************************\n");
		printf("         ######���������ֽ�����Ӧ�Ĳ���#######\n");

		//�����������ֽ��д���
		int number;
		printf("         �����룺");
		scanf("%d", &number);
		system("cls");
		if (number == 7) {
			break;
		}
		//Ԥ������Ϣ
		//
		int hao;
		switch (number)
		{
		case 1://���
			view();
			break;

		case 2://���
			add();
			break;

		case 3://����
			view();
			printf("\n��ѡ����Ҫ�������ݵ���ţ�");
			scanf("%d", &hao);
			change(hao);
			break;

		case 4://ɾ��
			view();
			printf("\n��ѡ����Ҫɾ�����ݵ���ţ�");
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
	printf("\n��� ����  ���� ʱ�� ���Ѷ� ���ѵص� ��������\n");
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
	printf("���������룺\n���� ���� ʱ�� ���Ѷ� ���ѵص� ��������\n");
	scanf("%s %s %s %s %s %s", &temp.id, &temp.name, &temp.date, &temp.consumption, &temp.where, &temp.category);
	fprintf(file, "%s %s %s %s %s %s\n", temp.id, temp.name, temp.date, temp.consumption, temp.where, temp.category);
	printf("��ӳɹ�\n");
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
	//���ַ������д����и��ַ���
	int i = 0;
	char str[99][99];
	char*temp = strtok(a, " ");
	while (temp) {
		//printf("%s\n", temp);
		strcpy(str[i], temp);//�������Ҫ����������
		i++;
		temp = strtok(NULL, " ");
	}
	system("cls");
	printf("��ѡ������ǣ�\n");
	printf("��� ���� ���� ʱ�� ���Ѷ� ���ѵص� ��������\n");
	for (i = 0; i < 6; i++) {
		printf("%s ", str[i]);
	}
	printf("\n������Ҫ����ʲôֵ?\n");
	printf("1.����  2.����  3.ʱ��  4.���Ѷ�  5.���ѵص�  6.��������\n��ѡ����ţ�");
	int num;
	char new[20];
	char new_str[100];
	scanf("%d", &num);
	printf("�������µ�ֵ:");
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
	}//123 123 ����� ������ ʮ�� �����
	printf("************�����ɹ�************\n\n");
	fclose(temp);
}

