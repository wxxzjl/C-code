//三子棋游戏
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
//初始化数组函数
void Init_board(char board[ROW][COL],int row,int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row;i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
//棋盘函数
void Display_board(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row;i++) {
		int j = 0;
		for (j = 0; j < col;j++) {
			//两个空格是因为棋盘的---有三个，中间存数据
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col;j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
//下棋
void play_move(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("玩家走：\n");
	while(1){
		printf("请输入要下的坐标：");
		scanf("%d%d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("该坐标被占用\n");
			}
		}
		else {
			printf("坐标输入非法，重新输入\n");
		}
	}
}
void computer_game(char board[ROW][COL], int row, int col){
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	while(1){
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}//返回1表示棋盘满了,返回0表示棋盘没满
int is_full(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;//没满
			}
		}
	}return 1;//满了
}
//告诉我们四种游戏状态：
//玩家赢'*'电脑赢'#' 平局'Q' 继续'C'
char is_win(char board[ROW][COL], int row, int col) {
	int i = 0;
	//横三行
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}
	//竖三列
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') {
			return board[1][i];
		}
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	//判断是否平局
	if (1 == is_full(board, ROW, COL)) {
		return 'Q';
	}return 'C';
}
//游戏算法实现
void true_game() {
	char ret = 0;
	//数组存放信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Init_board(board,ROW,COL);
	//打印棋盘
	Display_board(board, ROW, COL);
	while (1){
		//玩家下棋
		play_move(board, ROW, COL);
		Display_board(board, ROW, COL);
		//判断玩家是否赢
	    ret=is_win(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//电脑下棋
		computer_game(board, ROW, COL);
		Display_board(board, ROW, COL);
		//判断电脑是否赢
		ret=is_win(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}if (ret=='*') {
		printf("玩家赢\n");
	}
	else if (ret == '#') {
		printf("电脑赢\n");
	}
	else {
		printf("平局\n");
	}
	
}
void star_game() {
	printf("######################\n");
	printf("##1play        0exit##\n");
	printf("######################\n");
}
void game() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		star_game();
		printf("请选择：\n");
		scanf("%d", &input);
		switch(input){
		case 1:
			true_game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误\n");
			break;

		}
	} while (input);
}
int main() {
	game();
	return 0;
}
