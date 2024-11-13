#include <stdio.h>

typedef struct phonebook //����ü ���� �� ���ϰ� ���� ���� typedef�� �� 
{
	char name[20];
	char number[20];
	char age[5];
}phonebook;

int all_n = 1;//�� �Էµ� ��ȭ��ȣ ������ �ǹ�
int count = 0;
int add_number(phonebook book[])
{

	for (int i = count; i < all_n; i++) {
		printf("��ȭ��ȣ �Է�\n");
		scanf("%s", book[i].number);
		printf("�̸� �Է�\n");
		scanf("%s", book[i].name);
		printf("���� �Է�\n");
		scanf("%s", book[i].age);
		printf("-------------------\n");
	}
	count++;

	all_n = (1 + all_n); //�Էµ� ��� ���� ����,�ε��� �迭�� �˱�����->����Ʈ�ϱ�����
}

void print_phonebook(phonebook book[])
{
	for (int i = 0; i < all_n - 1; i++)
		printf("�̸�: %3s ��ȣ: %5s %3s��\n", book[i].name, book[i].number, book[i].age);


}

void save(phonebook book[])
{
	int i;
	FILE* fp;

	fp = fopen("phoneim.txt", "w");
	if (fp == NULL) {
		printf("���� ����\n");
	}
	else {
		printf("���� �Ϸ�\n");
	}
	for (i = 0; i < all_n; i++) {
		fprintf(fp, "%s %s %s\n", book[i].name, book[i].number, book[i].age);

	}

	fclose(fp);
}

void load(phonebook book[])
{
	int i;
	FILE* fp;

	fp = fopen("phoneim.txt", "r");
	if (fp == NULL) {
		printf("�ҷ����� ����\n");
	}
	else {
		printf("�ҷ����� �Ϸ�\n");
	}

	while (!feof(fp)) {
		if ((fscanf(fp, "%s %s %s\n", book[all_n - 1].name, book[all_n - 1].number, book[all_n - 1].age) == 0)) {
			printf("����");
			return;
		}
		all_n++;
		count++;
	}

	fclose(fp);
}


void search_num(phonebook book[])
{
	int tof = 0;
	char search_name[10];
	printf("�˻��� �̸��� �Է����ּ���\n");
	scanf("%s", &search_name);
	for (int i = 0; i < all_n; i++) {

		if (strcmp(search_name, book[i].name) == 0) {
			printf("��ȣ�� %s �Դϴ�\n", book[i].number);
			printf("���̴� %s �Դϴ�\n", book[i].age);
			tof = 1;
			break;
		}


	}
	if (tof == 0)
	{
		printf("�ٽ��Է�\n");
	}
}

void delete_num(phonebook book[])
{
	int i, j;
	char del_name[20];
	int tof = 0;
	printf("������ �̸� : ");
	scanf("%s", &del_name);

	for (i = 0; i < all_n; i++) {
		if (strcmp(book[i].name, del_name) == 0) {
			for (j = i; j < all_n; j++) {
				book[j] = book[j + 1];
			}    // ���� �ڷ���� ������ ��� 

			all_n--; // �ο� �� ���̱� 

			strset(book[all_n].name, '\0');  // ������ �ڷ� ����� 
			strset(book[all_n].number, '\0');
			strset(book[all_n].age, '\0');
			tof = 1;
		}
	}
	if (tof == 0) {
		printf("�׷��̸��� �����ϴ�.\n");
	}
}


int main()
{



	phonebook book[100] = { 0 };


	while (1) {
		printf("-------------------------------------\n");
		printf("1.���ο� ����ó ����(�Ǵ� �߰�)\n");
		printf("2.���\n");
		printf("3.����\n");
		printf("4.�˻�\n");
		printf("5.����\n");
		printf("6.����\n");
		printf("7.����\n");
		printf("-------------------------------------\n");

		int num1;//���̽� ��ȣ

		scanf("%d", &num1);


		switch (num1)
		{

		case 1:

			add_number(book);
			break;

		case 2:

			print_phonebook(book);
			printf("�� %d���Դϴ�\n", all_n - 1);
			break;

		case 3:
			delete_num(book);
			break;

		case 4:
			search_num(book);
			break;
		case 5:
			save(book);
			break;
		case 6:
			load(book);
			break;
		default:
			printf("���α׷��� �����մϴ�");
			return 0;
		}
	}
}