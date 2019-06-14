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
			k=rand()%6;    //����������ŵĵ�ͼ             
			if(k==0)                 
				mazemap[i][j]=1;             
			else                
				mazemap[i][j]=0;         
		} 	 	    
	mazemap[1][0]=mazemap[1][1]=0;//�����ڳ���     
	return OK;
}
Status map::PrintMaze(int n)                //��ӡ�����㼣 
{       
	for(int i=0;i<n;i++)     
	{         
		for(int j=0;j<n;j++)         
		{            
			if(mazemap[i][j]==0)                 
				printf("  ");       //��������ߵ�λ��             
			if(mazemap[i][j]==1)                 
				printf("��");    // ����ǽ��             
			if(mazemap[i][j]==-1||mazemap[i][j]==-4)                
				printf("��");    // ��������             
			if(mazemap[i][j]==-2)                 
				printf("?");    //���������ӵ��� 			
			if(mazemap[i][j]==-3) 				
				printf("��");     //�������ӵ�Ŀ��λ�� 			
			if(mazemap[i][j]==5) 				
				printf("��");         
		}         
		printf("\n");    
	}      
	printf("\n");    
	return OK; 
}