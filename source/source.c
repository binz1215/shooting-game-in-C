#include <stdio.h>
#include <unistd.h>
#include <curses.h>// getch()함수 라이브러리

//#include <conio.h> //키와 완련된 라이브러리... mac에는 없음.
void ft_kbhit();


int main(void)
{
	char c;

	// scanf("%c", &c);

	// c = getch(); // 여기 에러남
	// printf("키 : %c \n", c);

	ft_kbhit(); // 여기 안에 while문 들어있음.
	
}