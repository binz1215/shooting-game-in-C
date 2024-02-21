#include <stdio.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>

static struct termios initial_settings, new_settings;
static int peek_character = -1;

void init_keyboard();
void close_keyboard();
int kbhit();
int readch();
void ft_kbhit();

//원본

// int main()
// {
//     int ch = 0;

//     init_keyboard();
//     while(ch != 'q') {
//         printf("looping\n");
//         sleep(1);
//         if(kbhit()) {
//             ch = readch();
//             printf("you hit %c\n",ch);
//         }
//     }
//     close_keyboard();
//     return (0);
// }

//테스트 용 main

// int main() //
// {
//     // int ch = 0;

//     // init_keyboard();
//     // while(1) {
//     //     printf("looping\n");
//     //     sleep(1);
//     //     if(kbhit()) {
//     //         ch = readch();
//     //         printf("you hit %c\n",ch);
// 	// 		break;
//     //     }
//     // }
//     // close_keyboard();
// 	ft_kbhit();

//     return (0);
// }

//자체제작 kbhit();
void ft_kbhit()
{
	int ch = 0;

    init_keyboard();
    while(1) {
        printf("looping\n");
        sleep(1);
        if(kbhit()) {
            ch = readch();
            printf("you hit %c\n",ch);
			break;
        }
    }
    close_keyboard();
}

void init_keyboard()
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}

void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}

int kbhit()
{
    char ch;
    int nread;

    if(peek_character != -1)
        return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);

    if(nread == 1) {
        peek_character = ch;
        return 1;
    }
    return 0;
}

int readch()
{
    char ch;

    if(peek_character != -1) {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0,&ch,1);
    return ch;
}
//출처: https://davinno.tistory.com/entry/OS-X에서의-실시간-키보드-입력-받기 [Davinnovation:티스토리]