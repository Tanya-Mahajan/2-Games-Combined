#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
#include <unistd.h>

int board[10] = {2,2,2,2,2,2,2,2,2,2};
int turn = 1,flag = 0;
int player,comp;
char name[20];

int i,j,k,e,length = 20, breadth = 20;
int gameover, score;
int x, y, targetx, targety, flag;
int endX[100],endY[50];
int count=0;

//tic tac toe game
void menu();
void go(int n);
void start_game();
void check_draw();
void draw_board();
void player_first();
void put_X_O(char ch,int pos);
COORD coord= {0,0}; 

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void fordelay(int j)
{   int e,k;
    for(e=0;e<j;e++)
         k=e;
}

void main()
{
	
    system("cls");
    system("color 9");
    welcome();

}

int welcome()
{
	int choice;
	printf("\n\n\t\t\t\tWelcome To Gaming World");
	 for(e=0;e<=7;e++)
        {
            fordelay(100000000);
            printf(".");
        }
    printf("\n\n\t\tEnter Player Name:");
    scanf("%s",name);
    printf("\n\n\t\t------- GAME MENU --------");
    printf("\n\n\t\t1 : Tic Tac Toe");
    printf("\n\n\t\t2 : Snake Game");
    printf("\n\n\t\t3 : Exit");
    printf("\n\n\t\tEnter your choice:>");
    scanf("%d",&choice);
    if (choice==1)
       login();
    if (choice==2)
       login1();
    if (choice==3)
        exit(1);

        system("pause");
        system("cls");
    
}

int login(void)
{
  system("cls");
  system("color 6");
  char pass[10],password[10]="18july";
  printf("\n\n\t\t\t\t!!!!  Welcome to Tic Tac Toe Game  !!!!");
  printf("\n\n\t\t\tEnter the PIN Code:");
  scanf("%s", &pass);
  if (strcmp(pass,password)==0)
    {
      printf("\n\nPIN Matched!\nLOADING");
        for(e=0;e<=6;e++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
      menu();
    }
  else
    {
      printf("Invalid\n Try Again");
      login();
    }
  return 0;
}

void menu()
{
    int choice;
    system("cls");
    printf("\n\n\t--------  Game Options  --------");
    printf("\n\n\t1 : Play with X");
    printf("\n\n\t2 : Play with O");
    printf("\n\n\t3 : Exit");
    printf("\n\nEnter your choice:>");
    scanf("%d",&choice);
    turn = 1;
    switch (choice)
    {
    case 1:
        player = 1;
        comp = 0;
        player_first();
        break;
    case 2:
        player = 0;
        comp = 1;
        start_game();
        break;
    case 3:
        exit(1);
    default:
        menu();
    }
}

int make2()
{
    if(board[5] == 2)
        return 5;
    if(board[2] == 2)
        return 2;
    if(board[4] == 2)
        return 4;
    if(board[6] == 2)
        return 6;
    if(board[8] == 2)
        return 8;
    return 0;
}

int make4()
{
    if(board[1] == 2)
        return 1;
    if(board[3] == 2)
        return 3;
    if(board[7] == 2)
        return 7;
    if(board[9] == 2)
        return 9;
    return 0;
}

int posswin(int p)
{

    int i;
    int check_val,pos;

    if(p == 1)
        check_val = 18;
    else
        check_val = 50;

    i = 1;
    while(i<=9)//row check
    {
        if(board[i] * board[i+1] * board[i+2] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+1] == 2)
                return i+1;
            if(board[i+2] == 2)
                return i+2;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)//column check
    {
        if(board[i] * board[i+3] * board[i+6] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+3] == 2)
                return i+3;
            if(board[i+6] == 2)
                return i+6;
        }
        i++;
    }

    if(board[1] * board[5] * board[9] == check_val)
    {
        if(board[1] == 2)
            return 1;
        if(board[5] == 2)
            return 5;
        if(board[9] == 2)
            return 9;
    }

    if(board[3] * board[5] * board[7] == check_val)
    {
        if(board[3] == 2)
            return 3;
        if(board[5] == 2)
            return 5;
        if(board[7] == 2)
            return 7;
    }
    return 0;
}

void go(int n)
{
    if(turn % 2)
        board[n] = 3;
    else
        board[n] = 5;
    turn++;
}

void player_first()
{
    int pos,w;

    check_draw();
    draw_board();
    gotoxy(30,18);
    printf("Your Turn :> ");
    scanf("%d",&pos);

    if(board[pos] != 2)
        player_first();

    if(pos == posswin(player))
    {
        go(pos);
        draw_board();
        gotoxy(30,20);
        int sml=3;
        system("color 2");
        printf("%s Won: ",name);
        for(e=0;e<4;e++)
		{
		  printf("%c",sml);	
		 } 
        gotoxy(30,21);
        printf("Game Over !!!!");
        
        getch();
        exit(0);
    }

    go(pos);
    draw_board();
    start_game();
}

void start_game()
{

    if(posswin(comp))
    {
        go(posswin(comp));
        flag = 1;
    }
    else if(posswin(player))
        go(posswin(player));
    else if(make2())
        go(make2());
    else
        go(make4());
    draw_board();

    if(flag)
    {
        gotoxy(30,20);
        int sml=2;
        system("color 4");
        printf("Computer won: ");
        for(e=0;e<4;e++)
		{
		  printf("%c",sml);	
	    }
	    gotoxy(30,21);
        printf("Game Over !!!!");
        getch();
    }
    else
        player_first();
}

void check_draw()
{
    if(turn > 9)
    {
        gotoxy(30,20);
        int sml=5;
        system("color F");
        printf("Game Drawn: ");
        for(e=0;e<4;e++)
		{
		  printf("%c",sml);	
	    }
	    gotoxy(30,21);
        printf("Game Over !!!!");
        getch();
        exit(0);
    }
}

void draw_board()
{
    int j;

    for(j=9; j<17; j++)
    {
        gotoxy(35,j);
        printf("|       |");
    }
    gotoxy(28,11);
    printf("-----------------------");
    gotoxy(28,14);
    printf("-----------------------");

    for(j=1; j<10; j++)
    {
        if(board[j] == 3)
            put_X_O('X',j);
        else if(board[j] == 5)
            put_X_O('O',j);
    }
}

void put_X_O(char ch,int pos)
{
    int m;
    int x = 31, y = 10;

    m = pos;

    if(m > 3)
    {
        while(m > 3)
        {
            y += 3;
            m -= 3;
        }
    }
    if(pos % 3 == 0)
        x += 16;
    else
    {
        pos %= 3;
        pos--;
        while(pos)
        {
            x+=8;
            pos--;
        }
    }
    gotoxy(x,y);
    printf("%c",ch);
}


//snake game

int login1(void)
{
  system("cls");
  system("color 6");
  char pass[10],password[10]="18july";
  printf("\n\n\t\t\t\t!!!!  Welcome to Snake Game  !!!!");
  printf("\n\n\t\t\tEnter the PIN Code:");
  scanf("%s", &pass);
  if (strcmp(pass,password)==0)
    {
      printf("\n\nPIN Matched!\nLOADING");
        for(e=0;e<=6;e++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
      main1();
    }
  else
    {
      printf("Invalid\n Try Again");
      login1();
    }
  return 0;
}

void draw_boundary()
{
    system("cls");
    for (i = 0; i < length; i++) {
        for (j = 0; j < breadth; j++) {
            if (i == 0 || i == breadth - 1 || j == 0 || j == length - 1) {
                printf("#");
            }
            else {
                if (i == x && j == y)
                    printf("S");
                else if (i == targetx && j == targety)
                    printf("*");
                else
                     { 
                    int ch=0;
                    for(k=0;k<count;k++)
                    {
                        if(i==endX[k] && j==endY[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                      printf(" ");
                }
                    
            }
        }
        printf("\n");
    }
  
    printf("\n%s score = %d",name,score);
    printf("\n");
    printf("press X to quit the game");
}

void set_target()
{
    gameover = 0;
  
    x = length / 2;
    y = breadth/ 2;
label1:
    targetx = rand() % 20;
    if (targetx == 0)
        goto label1;
label2:
    targety = rand() % 20;
    if (targety == 0)
        goto label2;
    score = 0;
}

void input()
{
    if (kbhit()) {
        switch (getch()) {
        case 75:
            flag = 1;
            break;
        case 80:
            flag = 2;
            break;
        case 77:
            flag = 3;
            break;
        case 72:
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}
  
void logic()
{
	int i;
    int prevx=endX[0];
    int prevy=endY[0];
    int prev2x,prev2y;
    endX[0]=x;
    endY[0]=y;
    
    for(i=1;i<count;i++)
    {
        prev2x=endX[i];
        prev2y=endY[i];
        endX[i]=prevx;
        endY[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
  
    if (x < 0 || x > length || y < 0 || y > breadth)
        gameover = 1;
    for(i=0;i<count;i++)
     {
        if(x==endX[i]  && y==endY[i])
           gameover=1;
     }
    if (x == targetx && y == targety) {
    label3:
        targetx = rand() % 20;
        if (targetx == 0)
            goto label3;
  
    label4:
        targety = rand() % 20;
        if (targety == 0)
            goto label4;
        score += 10;
        count++;
    }
}

void main1()
{
    int m, n;
    set_target();
  
    while (!gameover) {
  
        draw_boundary();
        input();
        logic();
        for(m=0;m<2500;m++){
            for(n=0;n<10000;n++){
             }
        }
        for(m=0;m<1000;m++){
            for(n=0;n<10000;n++){
             }
        }
    }
}
  

