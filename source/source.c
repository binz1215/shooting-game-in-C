#include "header.h"

// int main(void)
// {
// 	char c;

// 	// scanf("%c", &c);

// 	// c = getch(); // 여기 에러남
// 	// printf("키 : %c \n", c);

// 	ft_kbhit(); // 여기 안에 while문 들어있음.
	
// }

int main() //
{
	char pressKey;
	//키가 입력되면 잡아준다.
    init_keyboard();
    while(true) {
        // printf("looping\n");
        // sleep(1);
        if(kbhit()) {
            pressKey = readch();//getch()대신
			// printf("%c\n", pressKey);
			switch (pressKey)
			{
				case 'w':
					printf("화살표 위쪽 키 \n");
					break;
				case 's':
					printf("화살표 아래쪽 키 \n");
					break;
				case 'a':
					printf("화살표 왼쪽 키 \n");
					break;
				case 'd':
					printf("화살표 오른쪽 키 \n");
					break;
			}
        }
    }
    close_keyboard();
    return (0);
}

//여기까지 1강 내용