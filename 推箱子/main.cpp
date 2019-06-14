#pragma once
#include "cstdio" 
#include "cstring"
#include "algorithm" 
#include "conio.h" 
#include "ctime"
#include "windows.h" 
#include "iostream" 
#include "stdlib.h" 
#include "queue" 
#include "vector"
#include "map.h" 
#include "vehicle.h" 
//#include "Box.h" 
#include "game.h" 
//#include "Clannad.h"
using namespace std;
#define INF 1<<27 
#define OK        1 
#define ERROR     0 
#define TRUE      1 
#define FALSE     0 
#define OVERFLOW -2 
#define INIT_STACK_SIZE 100 
#define INCREASESIZE    10   
const int MAX_X = INF;
const int MAX_Y = INF;
const int MAX_N = 1000;
typedef int Status;
typedef int ElemType;
typedef pair <int, int>P;
//bool used[MAX_X][MAX_Y];  
map A;
Vehicle V;
//Box B[];
game C;
int dir[4][3] = { {0,1},{0,-1},{1,0},{-1,0} };
bool  used[1000][1000];
bool bfs_judge_bypeople(int final_x, int final_y)      //第一重bfs 	
{
	queue<P>que;
	memset(used, 0, sizeof(used));
	used[final_x][final_y] = true;
	que.push(P(final_x, final_y));
	while (!que.empty())
	{
		P p = que.front();
		que.pop();
		if (p.first == 1 && p.second == 0)
			return true;
		for (int i = 0; i <= 3; i++)
		{
			int nx = p.first + dir[i][0], ny = p.second + dir[i][1];
			if (A.mazemap[nx][ny] != 1 && !used[nx][ny])
			{
				que.push(P(nx, ny));
				used[nx][ny] = true;
			}
		}
	}
	return false;
}
struct node
{
	int first, second, direction;      //用于储存坐标值和上一次的方向 		
	node() {}
	node(int a, int b, int c)
	{
		first = a; second = b; direction = c;
	}
};
bool bfs_judge_bycase(int m)    //第二重bfs 	
{
	for (int i = 1; i <= m; i++)
	{
		int rand_x = rand() % 19, rand_y = rand() % 19, rand_c = rand() % 19, rand_d = rand() % 19;
		if (rand_x == rand_c && rand_y == rand_d)
		{
			i--;
			continue;
		}
		if (rand_x > 1 && rand_y > 1 && bfs_judge_bypeople(rand_x, rand_y) && rand_c > 1 && rand_d > 1 && A.mazemap[rand_c][rand_d] == 0)
		{
			A.mazemap[rand_x][rand_y] = -1;    //随机生成箱子的位置 				
			A.mazemap[rand_c][rand_d] = -3;   //随机生成箱子的目标位置 				
		}             //构建一个箱子和目标位置的组合 			
		else
		{
			i--;
			continue;
		}
		memset(used, 0, sizeof(used));
		used[rand_c][rand_d] = true;
		queue<node>que;
		que.push(node(rand_c, rand_d, 0));
		bool judge = false;
		while (!que.empty())
		{
			node p = que.front();
			que.pop();
			if (A.mazemap[p.first][p.second] == -1)
			{
				//A.PrintMaze(20); 						
				if (!bfs_judge_bypeople(p.first + dir[p.direction][0], p.second + dir[p.direction][1]))
					continue;
				A.mazemap[p.first][p.second] = -4;
				judge = true;
				break;
			}
			for (int j = 0; j <= 3; j++)
			{
				int nx = p.first + dir[j][0], ny = p.second + dir[j][1];
				if ((A.mazemap[nx][ny] == -1 || A.mazemap[nx][ny] == 0) && !used[nx][ny] && A.mazemap[nx + dir[j][0]][ny + dir[j][1]] == 0)
				{
					que.push(node(nx, ny, j));
					used[nx][ny] = true;
				}
			}
		}
		if (judge == false)
		{
			A.mazemap[rand_x][rand_y] = 0;
			A.mazemap[rand_c][rand_d] = 0;
			i--;
			continue;
		}
	}
	return true;
}
void delete_by_position(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A.mazemap[i][j] == -1 || A.mazemap[i][j] == -4 || A.mazemap[i][j] == -2) {
				C.SetPos((j) * 2, i);
				printf("  ");
			}
		}
	}
}
void create_by_position(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A.mazemap[i][j] == -1 || A.mazemap[i][j] == -4)
			{
				C.SetPos((j) * 2, i);
				printf("□");    // 代表箱子 				
			}
			if (A.mazemap[i][j] == -2)
			{
				C.SetPos((j) * 2, i);
				printf("○");    // 代表人的位置 				
			}
			//代表推箱子的人 			
			if (A.mazemap[i][j] == 5)
			{
				C.SetPos((j) * 2, i);
				printf("☆");    //代表箱子的目标位置已经成功 				
			}
		}
	}
}

int main(void)
{
	cout << "==请问要从上一关开始吗？==需要输入1...不需要输入0 *^▁^*" << endl;
	int judge_bynumber;
	int n = 20;
	scanf("%d", &judge_bynumber);
	int m; 	int cnt = 0;
	if (judge_bynumber == 1)
	{
		freopen("hehe.in", "r", stdin);
		C.SetPos(0, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				scanf("%d", &A.mazemap[i][j]);
		}
		scanf("%d", &m);
		scanf("%d%d%d", &V.x, &V.y, &cnt);
		fclose(stdin);
	}
	else
	{
		cout << "=========请输入要的箱子数====" << endl;
		scanf("%d", &m);
		cout << "============地图规模为20*20======" << endl;
		cout << "=======请耐心等待地图生成======" << endl;
		cout << "=======地图生成如果太久请重试======" << endl;
		do
		{
			A.RandomMaze(n, m);   //生成迷宫地图 			
		} while (!bfs_judge_bypeople(n - 2, n - 1));
		bfs_judge_bycase(m);
		A.mazemap[1][0] = -2;
		V.x = 1;
		V.y = 0;
		cnt = 0;
	}
	C.SetPos(0, 0);
	A.PrintMaze(n);                           //打印迷宫地图     
	cout << "==================迷宫.......==================" << endl;
	cout << "说明:■不能走的区域\t◇走不通的区域" << endl;
	cout << "    “空格”代表未到过的区域" << endl;
	cout << "     ?代表您的所在位置" << endl;
	cout << "     □代表箱子的位置 " << endl;
	cout << "     ◎代表箱子的目标位置" << endl;
	cout << "     ☆代表已经成功的目标位置" << endl;
	cout << "      按s键存档" << endl;
	cout << "把所有的箱子推到位就胜利了(?? . ??)" << endl;
	cout << "============================================" << endl;
	while (1)
	{
		if (cnt == m)
		{
			C.SetPos(0, n + 1);
			printf("========您太厉害了(^O^)=======\n");
			break;
		}
		int k = C.WaitKey(10.0);
		if (k == 224 || k == 0)
			continue;
		if (k == 115)
		{
			freopen("hehe.in", "w", stdout);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					printf("%d ", A.mazemap[i][j]);
				}
				printf("\n");
			}
			printf("%d %d %d %d", m, V.x, V.y, cnt);
			fclose(stdout);
			C.SetPos(0, n + 1);
			break;
		}
		if (k != 75 && k != 77 & k != 72 && k != 80)
			continue;
		delete_by_position(n);
		if (k == 75 && A.mazemap[V.x][V.y - 1] != 1)     //left             
		{
			if (A.mazemap[V.x][V.y - 1] == -1 || A.mazemap[V.x][V.y - 1] == -4)
			{
				if (A.mazemap[V.x][V.y - 2] == 0)
				{
					A.mazemap[V.x][V.y] = 0;
					A.mazemap[V.x][V.y - 1] = -2;
					A.mazemap[V.x][V.y - 2] = -4;
					V.LoadMap("left");
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
				if (A.mazemap[V.x][V.y - 2] == -3)
				{
					A.mazemap[V.x][V.y] = 0;
					A.mazemap[V.x][V.y - 1] = -2;
					A.mazemap[V.x][V.y - 2] = 5;
					cnt++;
					V.LoadMap("left");
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
				else
				{
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
			}
			else if (A.mazemap[V.x][V.y - 1] == 0)
			{
				A.mazemap[V.x][V.y] = 0;
				A.mazemap[V.x][V.y - 1] = -2;
				V.LoadMap("left");
				create_by_position(n);
				C.SetPos(0, n + 1);
				continue;
			}
		}
		else if (k == 77 && A.mazemap[V.x][V.y + 1] != 1)    //right      
		{
			if (A.mazemap[V.x][V.y + 1] == -1 || A.mazemap[V.x][V.y + 1] == -4)
			{
				if (A.mazemap[V.x][V.y + 2] == 0)
				{
					A.mazemap[V.x][V.y] = 0;

					A.mazemap[V.x][V.y + 1] = -2;
					A.mazemap[V.x][V.y + 2] = -4;
					V.LoadMap("right");
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
				if (A.mazemap[V.x][V.y + 2] == -3)
				{
					A.mazemap[V.x][V.y] = 0;
					A.mazemap[V.x][V.y + 1] = -2;
					A.mazemap[V.x][V.y + 2] = 5;
					cnt++;
					V.LoadMap("right");
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
				else
				{
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
			}
			
			else if (A.mazemap[V.x][V.y + 1] == 0)
			{
				A.mazemap[V.x][V.y] = 0;
				A.mazemap[V.x][V.y + 1] = -2;
				V.LoadMap("right");
				create_by_position(n);
				C.SetPos(0, n + 1);
				continue;
			}
		}
		else if (k == 72 && A.mazemap[V.x - 1][V.y] != 1)    //up        
		{
			if (A.mazemap[V.x - 1][V.y] == -1 || A.mazemap[V.x - 1][V.y] == -4)
			{
				if (A.mazemap[V.x - 2][V.y] == 0)
				{
					A.mazemap[V.x][V.y] = 0;
					A.mazemap[V.x - 1][V.y] = -2;
					A.mazemap[V.x - 2][V.y] = -4;
					V.LoadMap("up");
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
				if (A.mazemap[V.x - 2][V.y] == -3)
				{
					A.mazemap[V.x][V.y] = 0;
					A.mazemap[V.x - 1][V.y] = -2;
					A.mazemap[V.x - 2][V.y] = 5;
					cnt++;
					V.LoadMap("up");
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
				else
				{
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
			}
			else if (A.mazemap[V.x - 1][V.y] == 0)
			{
				A.mazemap[V.x][V.y] = 0;
				A.mazemap[V.x - 1][V.y] = -2;
				V.LoadMap("up");
				create_by_position(n);
				C.SetPos(0, n + 1);
				continue;
			}
		}
		else if (k == 80 && A.mazemap[V.x + 1][V.y] != 1)     //down             
		{
			if (A.mazemap[V.x + 1][V.y] == -1 || A.mazemap[V.x + 1][V.y] == -4)
			{
				if (A.mazemap[V.x + 2][V.y] == 0)
				{
					A.mazemap[V.x][V.y] = 0;
					A.mazemap[V.x + 1][V.y] = -2;
					A.mazemap[V.x + 2][V.y] = -4;
					V.LoadMap("down");
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
				if (A.mazemap[V.x + 2][V.y] == -3)
				{
					A.mazemap[V.x][V.y] = 0;
					A.mazemap[V.x + 1][V.y] = -2;
					A.mazemap[V.x + 2][V.y] = 5;
					V.LoadMap("down");
					cnt++;
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
				else
				{
					create_by_position(n);
					C.SetPos(0, n + 1);
					continue;
				}
			}
			else if (A.mazemap[V.x + 1][V.y] == 0)
			{
				A.mazemap[V.x][V.y] = 0;
				A.mazemap[V.x + 1][V.y] = -2;
				V.LoadMap("down");
				create_by_position(n);
				C.SetPos(0, n + 1);
				continue;
			}
		}
		else
			create_by_position(n);
		C.SetPos(0, n + 1);
	}
	return 0;
}
