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
bool bfs_judge_bypeople(int final_x, int final_y)      //��һ��bfs 	
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
	int first, second, direction;      //���ڴ�������ֵ����һ�εķ��� 		
	node() {}
	node(int a, int b, int c)
	{
		first = a; second = b; direction = c;
	}
};
bool bfs_judge_bycase(int m)    //�ڶ���bfs 	
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
			A.mazemap[rand_x][rand_y] = -1;    //����������ӵ�λ�� 				
			A.mazemap[rand_c][rand_d] = -3;   //����������ӵ�Ŀ��λ�� 				
		}             //����һ�����Ӻ�Ŀ��λ�õ���� 			
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
				printf("��");    // �������� 				
			}
			if (A.mazemap[i][j] == -2)
			{
				C.SetPos((j) * 2, i);
				printf("��");    // �����˵�λ�� 				
			}
			//���������ӵ��� 			
			if (A.mazemap[i][j] == 5)
			{
				C.SetPos((j) * 2, i);
				printf("��");    //�������ӵ�Ŀ��λ���Ѿ��ɹ� 				
			}
		}
	}
}

int main(void)
{
	cout << "==����Ҫ����һ�ؿ�ʼ��==��Ҫ����1...����Ҫ����0 *^�x^*" << endl;
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
		cout << "=========������Ҫ��������====" << endl;
		scanf("%d", &m);
		cout << "============��ͼ��ģΪ20*20======" << endl;
		cout << "=======�����ĵȴ���ͼ����======" << endl;
		cout << "=======��ͼ�������̫��������======" << endl;
		do
		{
			A.RandomMaze(n, m);   //�����Թ���ͼ 			
		} while (!bfs_judge_bypeople(n - 2, n - 1));
		bfs_judge_bycase(m);
		A.mazemap[1][0] = -2;
		V.x = 1;
		V.y = 0;
		cnt = 0;
	}
	C.SetPos(0, 0);
	A.PrintMaze(n);                           //��ӡ�Թ���ͼ     
	cout << "==================�Թ�.......==================" << endl;
	cout << "˵��:�������ߵ�����\t���߲�ͨ������" << endl;
	cout << "    ���ո񡱴���δ����������" << endl;
	cout << "     ?������������λ��" << endl;
	cout << "     ���������ӵ�λ�� " << endl;
	cout << "     ��������ӵ�Ŀ��λ��" << endl;
	cout << "     ������Ѿ��ɹ���Ŀ��λ��" << endl;
	cout << "      ��s���浵" << endl;
	cout << "�����е������Ƶ�λ��ʤ����(?? . ??)" << endl;
	cout << "============================================" << endl;
	while (1)
	{
		if (cnt == m)
		{
			C.SetPos(0, n + 1);
			printf("========��̫������(^O^)=======\n");
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
