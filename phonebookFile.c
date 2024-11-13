#include <stdio.h>

typedef struct phonebook //구조체 선언 더 편리하게 쓰기 위해 typedef를 씀 
{
	char name[20];
	char number[20];
	char age[5];
}phonebook;

int all_n = 1;//총 입력된 전화번호 개수를 의미
int count = 0;
int add_number(phonebook book[])
{

	for (int i = count; i < all_n; i++) {
		printf("전화번호 입력\n");
		scanf("%s", book[i].number);
		printf("이름 입력\n");
		scanf("%s", book[i].name);
		printf("나이 입력\n");
		scanf("%s", book[i].age);
		printf("-------------------\n");
	}
	count++;

	all_n = (1 + all_n); //입력된 사람 수를 측정,인덱스 배열을 알기위함->프린트하기위함
}

void print_phonebook(phonebook book[])
{
	for (int i = 0; i < all_n - 1; i++)
		printf("이름: %3s 번호: %5s %3s살\n", book[i].name, book[i].number, book[i].age);


}

void save(phonebook book[])
{
	int i;
	FILE* fp;

	fp = fopen("phoneim.txt", "w");
	if (fp == NULL) {
		printf("생성 실패\n");
	}
	else {
		printf("생성 완료\n");
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
		printf("불러오기 실패\n");
	}
	else {
		printf("불러오기 완료\n");
	}

	while (!feof(fp)) {
		if ((fscanf(fp, "%s %s %s\n", book[all_n - 1].name, book[all_n - 1].number, book[all_n - 1].age) == 0)) {
			printf("실패");
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
	printf("검색할 이름을 입력해주세요\n");
	scanf("%s", &search_name);
	for (int i = 0; i < all_n; i++) {

		if (strcmp(search_name, book[i].name) == 0) {
			printf("번호는 %s 입니다\n", book[i].number);
			printf("나이는 %s 입니다\n", book[i].age);
			tof = 1;
			break;
		}


	}
	if (tof == 0)
	{
		printf("다시입력\n");
	}
}

void delete_num(phonebook book[])
{
	int i, j;
	char del_name[20];
	int tof = 0;
	printf("삭제할 이름 : ");
	scanf("%s", &del_name);

	for (i = 0; i < all_n; i++) {
		if (strcmp(book[i].name, del_name) == 0) {
			for (j = i; j < all_n; j++) {
				book[j] = book[j + 1];
			}    // 뒤의 자료들을 앞으로 당김 

			all_n--; // 인원 수 줄이기 

			strset(book[all_n].name, '\0');  // 마지막 자료 지우기 
			strset(book[all_n].number, '\0');
			strset(book[all_n].age, '\0');
			tof = 1;
		}
	}
	if (tof == 0) {
		printf("그런이름은 없습니다.\n");
	}
}


int main()
{



	phonebook book[100] = { 0 };


	while (1) {
		printf("-------------------------------------\n");
		printf("1.새로운 연락처 저장(또는 추가)\n");
		printf("2.출력\n");
		printf("3.삭제\n");
		printf("4.검색\n");
		printf("5.저장\n");
		printf("6.열기\n");
		printf("7.종료\n");
		printf("-------------------------------------\n");

		int num1;//케이스 번호

		scanf("%d", &num1);


		switch (num1)
		{

		case 1:

			add_number(book);
			break;

		case 2:

			print_phonebook(book);
			printf("총 %d명입니다\n", all_n - 1);
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
			printf("프로그램을 종료합니다");
			return 0;
		}
	}
}