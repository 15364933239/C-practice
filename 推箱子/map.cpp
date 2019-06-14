//#include "Box.h"
#include "iostream"
#include "map.h" 
#include "vehicle.h" 
#include "ctime" 
#include "Windows.h" 
typedef int Status; 
typedef int ElemType;   
#define OK        1 
#define ERROR     0 
#define TRUE      1 
#define FALSE     0 
#define OVERFLOW -2     
Status map::RandomMaze(int n,int m) 
{     
	int i,j,k;     
	srand(time(NULL));     
	for(i=0;i<n;i++)        
		mazemap[0][i]=mazemap[n-1][i]=1;    
	for(j=0;j<n;j++)         
		mazemap[j][0]=mazemap[j][n-1]=1;     
	for(i=1;i<n-1;i++)         
		for(j=1;j<n-1;j++)         
		{            
			k=rand()%6;    //随机生成整张的地图             
			if(k==0)                 
				mazemap[i][j]=1;             
			else                
				mazemap[i][j]=0;         
		} 	 	    
	mazemap[1][0]=mazemap[1][1]=0;//标记入口出口     
	return OK;
}
Status map::PrintMaze(int n)                //打印最后的足迹 
{       
	for(int i=0;i<n;i++)     
	{         
		for(int j=0;j<n;j++)         
		{            
			if(mazemap[i][j]==0)                 
				printf("  ");       //代表可以走的位置             
			if(mazemap[i][j]==1)                 
				printf("■");    // 代表墙壁             
			if(mazemap[i][j]==-1||mazemap[i][j]==-4)                
				printf("□");    // 代表箱子             
			if(mazemap[i][j]==-2)                 
				printf("?");    //代表推箱子的人 			
			if(mazemap[i][j]==-3) 				
				printf("◎");     //代表箱子的目标位置 			
			if(mazemap[i][j]==5) 				
				printf("☆");         
		}         
		printf("\n");    
	}      
	printf("\n");    
	return OK; 
}