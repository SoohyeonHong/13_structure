#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//======================================================

#01
	
struct student{
	int ID;
	char name[10];
	double grade;
}; 

void main(void){
	struct student s1 = {14, "�ѿ�", 4.3};
	
	s1.ID = 123456;
	strcpy(s1.name, "Juyeop");
	s1.grade = 4.2;
	
	printf("ID : %d\n", s1.ID);
	printf("name : %s\n", s1.name);
	printf("grade : %f\n", s1.grade);



//======================================================

#02

int is_whitespace(char c)
{
	if( c == ' '  ||
		c == '\n' ||
		c == '\r' ||
		c == '\t' ||
		c == '('  )
	{
		return 1; //�´� 
	}
	
	return 0; //�ƴϴ� 
}

int fget_word(FILE* fp, char *word)
{
	int cnt;
	char c;
	
	while ((c = fgetc(fp)) != EOF)
	{
		if (is_whitespace(c) == 0) //������������� ���� �� 
			break;
	}
	if ( c == EOF )
	{
		return 0;
	}
	
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while ((word[cnt] = fgetc(fp)) != EOF)
	{
		if (is_whitespace(word[cnt]) == 1)
		{
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	
	return cnt;
}

int main(void){
 
	FILE *fp;
	char filepath[100];		//����ڰ� �Է��� ���ڿ� ���� 
	char word[100];
	
	//file open
	printf("input the file path : ");
	scanf("%s", filepath, "r"); //scanf�� ���ϰ�θ� �Է¹��� 
	fp = fopen(filepath, "r");
	
	if (fp == NULL)
	{
		printf("file path is wrong! %s\n", filepath);
		return -1; //���α׷� �������� 
	}
	
	
	//word reading & analysis
	while (fget_word(fp, word) != 0)
	{
		printf("%s\n", word);
	}
	
	fclose(fp);
	//output
	
	return 0;
}

