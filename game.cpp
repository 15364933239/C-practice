//游戏编程建议
// https://www.zhihu.com/question/22108858/answer/51858521

//本人啃谭浩强的《C程序设计》整整两个小时才写出来的……高人莫笑 
#if 0
//http://tieba.baidu.com/p/271364353
#include <iostream> 
using namespace std; 
double shengmingli=1000;//定义主角初始生命力 
int gongjili=10;//定义主角初始攻击力 
int fangyuli=6;//定义主角初始防御力 
int money=0;//定义主角初始金钱数量 
bool guoguan;//定义是否通关判定 
void wuqidian();//定义武器店函数 
void yaodian();//定义药店函数 
void guaiwu1();//定义小怪物函数 
void guaiwu2();//定义大怪物函数 
int main() 
{ 
cout<<"欢迎你开始玩打怪物小游戏！\n"; 
cout<<"小镇\n"; 
cout<<"一个1000年的小镇。周围有一条河，有一片树林，很多房子和很多人。\n有一家药店"<<endl; 
cout<<"和一家武器店。\n"; 
int xiaozhen;//定义选择项目 
cout<<"1.去武器店"<<endl; 
cout<<"2.去药品店"<<endl; 
cout<<"3.去打小怪物"<<endl; 
cout<<"4.去打大怪物"<<endl; 
cout<<"5.退出游戏"<<endl; 
cout<<"6.显示你的状态"<<endl; 
cin>>xiaozhen; 
while(xiaozhen!=5)//输入5时退出游戏 
{ 
if(shengmingli<=0)//主角生命力小于等于0时游戏结束 
{ 
cout<<"你死啦！"<<endl; 
break; 
} 
if(guoguan) 
{ 
cout<<"恭喜通关！"<<endl; 
break; 
} 
if(xiaozhen==6)//输入6可检测自己的状态 
{ 
cout<<"你的生命力:"<<shengmingli<<endl; 
cout<<"你的攻击力:"<<gongjili<<endl; 
cout<<"你的防御力:"<<fangyuli<<endl; 
cout<<"你拥有的钱:"<<money<<endl; 
} 
else 
switch(xiaozhen) 
{ 
case 1 : wuqidian();break; 
case 2 : yaodian();break; 
case 3 : guaiwu1();break; 
case 4 : guaiwu2();break; 
default : cout<<"请不要乱选！"<<endl;break; 
} 
cin>>xiaozhen; 
} 
if(xiaozhen==5) 
{ 
cout<<"正在退出游戏……"<<endl; 
} 
cin.get(); 
cin.get(); 
return 0; 
} 
void wuqidian() 
{ 
cout<<"欢迎来到武器店！"<<endl; 
cout<<"1、买小刀（10M加2攻击力）"<<endl; 
cout<<"2、买短剑（80M加20攻击力）"<<endl; 
cout<<"3、买大砍刀（140M加40攻击力)"<<endl; 
cout<<"4、买双节棍（200M加60攻击力）"<<endl; 
cout<<"5、买盾牌（60M加30防御力）"<<endl; 
cout<<"6、买铠甲（100M加60防御力）"<<endl; 
cout<<"7、离开武器店"<<endl; 
int wuqidian; 
cin>>wuqidian; 
while(wuqidian!=7)//输入7时结束函数 
{ 
switch(wuqidian) 
{ 
case 1 : if(money<10) 
cout<<"你的钱不够"<<endl;//钱不够时返回Flase 
else  
cout<<"购买成功！"<<endl;//钱足够时返回True 
gongjili+=2; 
money-=1; 
break; 
case 2 : if(money<80) 
cout<<"你的钱不够"<<endl; 
else  
cout<<"购买成功！"<<endl; 
gongjili+=20; 
money-=20; 
break; 
case 3 : if(money<140) 
cout<<"你的钱不够"<<endl; 
    else  
cout<<"购买成功！"<<endl; 
gongjili+=40; 
money-=99; 
break; 
case 4 : if(money<200) 
cout<<"你的钱不够"<<endl; 
else  
cout<<"购买成功！"<<endl; 
gongjili+=60; 
money-=200; 
break; 
case 5 : if(money<60) 
cout<<"你的钱不够"<<endl; 
else  
cout<<"购买成功！"<<endl; 
gongjili+=30; 
money-=50; 
break; 
case 6 : if(money<100) 
cout<<"你的钱不够"<<endl; 
else  
cout<<"购买成功！"<<endl; 
gongjili+=60; 
money-=100; 
break; 
default : cout<<"无"<<endl; 
    break; 
}  
cin>>wuqidian; 
} 
if(wuqidian==7) 
{  //返回main()主函数 
cout<<"欢迎下次再来！"<<endl; 
cout<<"欢迎你开始玩打怪物小游戏！\n"; 
cout<<"小镇\n"; 
cout<<"一个1000年的小镇。周围有一条河，有一片树林，很多房子和很多人。\n有一家药店"<<endl;
cout<<"和一家武器店。\n"; 
cout<<"1.去武器店"<<endl; 
cout<<"2.去药品店"<<endl; 
cout<<"3.去打小怪物"<<endl; 
cout<<"4.去打大怪物"<<endl; 
cout<<"5.退出游戏"<<endl; 
cout<<"6.显示你的状态"<<endl; 
} 
} 
/* 
yaodian()的设置与wuqidian()相同,可参照阅读. 
*/ 
void yaodian() 
{ 
cout<<"欢迎来到药品店！"<<endl; 
cout<<"1、买1号补血药（10M加200生命）"<<endl; 
cout<<"2、买2号补血药（50M加1000生命力）"<<endl; 
cout<<"3、买3号补血药（100M加2200生命力)"<<endl; 
cout<<"4、离开武器店"<<endl; 
int yaodian; 
cin>>yaodian; 
while(yaodian!=4) 
{ 
switch(yaodian) 
{ 
case 1 : if(money<10) 
cout<<"你的钱不够"<<endl; 
else  
cout<<"购买成功！"<<endl; 
gongjili+=2; 
money-=1; 
break; 
case 2 : if(money<50) 
cout<<"你的钱不够"<<endl; 
else  
cout<<"购买成功！"<<endl; 
gongjili+=20; 
money-=20; 
break; 
case 3 : if(money<100) 
cout<<"你的钱不够"<<endl; 
else  
cout<<"购买成功！"<<endl; 
gongjili+=40; 
money-=99; 
break; 
default : cout<<"无"<<endl; 
break; 
} 
cin>>yaodian; 
} 
if(yaodian==4) 
{   
cout<<"欢迎下次再来！"<<endl;   
cout<<"欢迎你开始玩打怪物小游戏！\n"; 
cout<<"小镇\n"; 
cout<<"一个1000年的小镇。周围有一条河，有一片树林，很多房子和很多人。\n有一家药店"<<endl; 
cout<<"和一家武器店。\n"; 
cout<<"1.去武器店"<<endl; 
cout<<"2.去药品店"<<endl; 
cout<<"3.去打小怪物"<<endl; 
cout<<"4.去打大怪物"<<endl; 
cout<<"5.退出游戏"<<endl; 
cout<<"6.显示你的状态"<<endl; 
} 
} 
/*这里是两个战斗函数,使用指针来处理.避免造成内存崩溃.*/ 
void guaiwu1() 
{ 
cout<<"开始与小怪物战斗！！！"<<endl; 
double* g_shengmingli=new double;//定义怪物生命 
int* g_gongjili=new int;//定义怪物攻击力 
int* g_fangyuli=new int;//定义怪物防御力 
    int* g_money=new int;//定义怪物金钱 
*g_shengmingli=100; 
*g_gongjili=5; 
*g_fangyuli=3; 
*g_money=5; 
double* tongji1=new double;//用来计算主角对怪物的杀伤 
double* tongji2=new double;//用来计算怪物对主角的杀伤 
*tongji1=0; 
*tongji2=0; 
int* huihe=new int;//定义回合数 
*huihe=1; 
cout<<"你开始对小怪物进行攻击！"<<endl; 
int* xuanze=new int; 
/* 
攻击计算公式 
杀伤=攻击力*2-防御力 
玩家每回合可以选择攻击与逃跑 
*/ 
while((*g_shengmingli)>0 && shengmingli>0 && (*xuanze)!=2) 
{ 
cout<<"现在是"<<"第"<<*huihe<<"回合！"<<endl; 
cout<<"请选择你的动作:\n"; 
cout<<"1、攻击\n2、逃跑\n"; 
cin>>*xuanze; 
switch((*xuanze)) 
{ 
case 1 : cout<<"你对小怪物发动了攻击！"<<endl; 
*g_shengmingli-=gongjili*2-(*g_fangyuli); 
*tongji1=gongjili*2-(*g_fangyuli); 
cout<<"你打掉了小怪物"<<*tongji1<<"的生命！"<<endl; 
cout<<"小怪物还剩"<<(*g_shengmingli)-(*tongji1)<<"点生命"<<endl; 
shengmingli-=(*g_gongjili)*2-fangyuli; 
*tongji2=(*g_gongjili)*2-fangyuli; 
cout<<"小怪物对你发动了攻击！"<<endl; 
cout<<"小怪物打掉了你"<<*tongji2<<"的生命！"<<endl; 
cout<<"你还剩"<<shengmingli-(*tongji2)<<"点生命"<<endl;break; 
case 2 : cout<<"你决定逃跑！"<<endl; 
cout<<"逃跑成功！"<<endl;continue; 
default : cout<<"请不要乱选！"<<endl; 
} 
(*huihe)++; 
} 
if((*g_shengmingli)<=0) 
{//杀死怪物后的返回 
cout<<"小怪物被你杀死了！你真厉害！！！"<<endl;
money+=(*g_money); 
cout<<"欢迎你开始玩打怪物小游戏！\n"; 
cout<<"小镇\n"; 
cout<<"一个1000年的小镇。周围有一条河，有一片树林，很多房子和很多人。\n有一家药店"<<endl; 
cout<<"和一家武器店。\n"; 
cout<<"1.去武器店"<<endl; 
cout<<"2.去药品店"<<endl; 
cout<<"3.去打小怪物"<<endl; 
cout<<"4.去打大怪物"<<endl; 
cout<<"5.退出游戏"<<endl; 
cout<<"6.显示你的状态"<<endl; 
} 
else 
if(shengmingli<=0) 
{//被怪物杀死后的返回 
cout<<"你被小怪物杀死了！游戏结束！！！"<<endl; 
} 
else 
if((*xuanze)==2) 
{//逃跑的返回 
cout<<"你逃回了小镇！"<<endl; 
cout<<"欢迎你开始玩打怪物小游戏！\n"; 
cout<<"小镇\n"; 
cout<<"一个1000年的小镇。周围有一条河，有一片树林，很多房子和很多人。\n有一家药店"<<endl; 
cout<<"和一家武器店。\n"; 
cout<<"1.去武器店"<<endl; 
cout<<"2.去药品店"<<endl; 
cout<<"3.去打小怪物"<<endl; 
cout<<"4.去打大怪物"<<endl; 
cout<<"5.退出游戏"<<endl; 
cout<<"6.显示你的状态"<<endl; 
} 
delete g_shengmingli; 
delete g_gongjili; 
delete g_fangyuli; 
delete g_money; 
delete tongji1; 
delete tongji2; 
} 
/* 
设置均与void函数guaiwu1()相同,可参照上例阅读. 
*/ 
void guaiwu2() 
{ 
cout<<"开始与大怪物战斗！！！"<<endl; 
double* g_shengmingli=new double; 
int* g_gongjili=new int; 
int* g_fangyuli=new int; 
*g_shengmingli=3600; 
*g_gongjili=500; 
*g_fangyuli=500; 
double* tongji1=new double; 
double* tongji2=new double; 
*tongji1=0; 
*tongji2=0; 
int* huihe=new int; 
*huihe=1; 
cout<<"你开始对大怪物进行攻击！"<<endl; 
int* xuanze=new int; 
while((*g_shengmingli)>0 && shengmingli>0 && (*xuanze)!=2) 
{ 
cout<<"现在是"<<"第"<<*huihe<<"回合！"<<endl; 
cout<<"请选择你的动作:\n"; 
cout<<"1、攻击\n2、逃跑\n"; 
cin>>*xuanze; 
switch((*xuanze)) 
{ 
case 1 : cout<<"你对大怪物发动了攻击！"<<endl; 
*g_shengmingli-=gongjili*2-(*g_fangyuli); 
*tongji1=gongjili*2-(*g_fangyuli); 
cout<<"你打掉了大怪物"<<*tongji1<<"的生命！"<<endl; 
cout<<"大怪物还剩"<<(*g_shengmingli)-(*tongji1)<<"点生命"<<endl; 
shengmingli-=(*g_gongjili)*2-fangyuli; 
*tongji2=(*g_gongjili)*2-fangyuli; 
cout<<"大怪物对你发动了攻击！"<<endl; 
cout<<"大怪物打掉了你"<<*tongji2<<"的生命！"<<endl; 
cout<<"你还剩"<<shengmingli-(*tongji2)<<"点生命"<<endl;break; 
case 2 : cout<<"你决定逃跑！"<<endl; 
cout<<"逃跑成功！"<<endl;continue; 
default : cout<<"请不要乱选！"<<endl; 
} 
(*huihe)++; 
} 
if((*g_shengmingli)<=0) 
{ 
    cout<<"大怪物被你杀死了！你真厉害！！！"<<endl; 
guoguan=true; 
cout<<"欢迎你开始玩打怪物小游戏！\n"; 
cout<<"小镇\n"; 
cout<<"一个1000年的小镇。周围有一条河，有一片树林，很多房子和很多人。\n有一家药店"<<endl; 
cout<<"和一家武器店。\n"; 
cout<<"1.去武器店"<<endl; 
cout<<"2.去药品店"<<endl; 
cout<<"3.去打小怪物"<<endl; 
cout<<"4.去打大怪物"<<endl; 
cout<<"5.退出游戏"<<endl; 
cout<<"6.显示你的状态"<<endl; 
} 
else 
if(shengmingli<=0) 
{ 
cout<<"你被大怪物杀死了！游戏结束！！！"<<endl; 
} 
else 
if((*xuanze)==2) 
{ 
cout<<"你逃回了小镇！"<<endl; 
cout<<"欢迎你开始玩打怪物小游戏！\n"; 
cout<<"小镇\n"; 
cout<<"一个1000年的小镇。周围有一条河，有一片树林，很多房子和很多人。\n有一家药店"<<endl; 
cout<<"和一家武器店。\n"; 
cout<<"1.去武器店"<<endl; 
cout<<"2.去药品店"<<endl; 
cout<<"3.去打小怪物"<<endl; 
cout<<"4.去打大怪物"<<endl; 
cout<<"5.退出游戏"<<endl; 
cout<<"6.显示你的状态"<<endl; 
} 
delete g_shengmingli; 
delete g_gongjili; 
delete g_fangyuli; 
delete tongji1; 
delete tongji2; 
}
#endif

//贪吃蛇  👍 √
#if 0

//原链接 http://blog.csdn.net/ckcz123/article/details/8204365
// 辅助链接  http://blog.csdn.net/silence1772/article/details/55005008
/************************贪吃蛇***********************/  
/**********************2012-11-20*********************/  
  
#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <ctime>  
#include <conio.h>  
#include <cmath>  
#include <windows.h>  
using namespace std;  
  
/*** 光标定位 ***/  
HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);  
COORD coord;  
  
void locate(int x,int y)  
{  
    coord.X=y;  
    coord.Y=x;  
    SetConsoleCursorPosition(hout,coord);  
};  
  
/*** 隐藏光标 ***/  
void hide()  
{  
    CONSOLE_CURSOR_INFO cursor_info={1,0};  
    SetConsoleCursorInfo(hout, &cursor_info);  
}  
  
/*** 生成随机数 ***/  
double random(double start, double end)  
{  
    return start+(end-start)*rand()/(RAND_MAX + 1.0);  
}  
  
/*** 定义地图的长宽，蛇的坐标，长度，方向，食物的位置 ***/  
int m,n;  
  
struct node  
{  
    int x,y;  
}snake[1000];  
  
int snake_length,dir;  
node food;  
int direct[4][2]={{-1,0},{1,0},{0,-1},{0,1}};  
  
/*** 输出墙 ***/  
void print_wall()  
{  
    cout << " ";  
    for (int i=1;i<=n;i++)  
        cout << "-";  
    cout << endl;  
    for (int j=0;j<=m-1;j++)  
    {  
        cout << "|";  
        for (int i=1;i<=n;i++) cout << " ";  
        cout << "|" << endl;  
    }  
    cout << " ";  
    for (int i=1;i<=n;i++)  
        cout << "-";  
}  
  
/*** 首次输出蛇，其中snake[0]代表头 ***/  
void print_snake()  
{  
    locate(snake[0].x,snake[0].y);  
    cout << "@";  
    for (int i=1;i<=snake_length-1;i++)  
    {  
        locate(snake[i].x,snake[i].y);  
        cout << "*";  
    }  
}  
  
/*** 判断是否撞墙或者自撞 ***/  
bool is_correct()  
{  
    if (snake[0].x==0 || snake[0].y==0 || snake[0].x==m+1 || snake[0].y==n+1) return false;  
    for (int i=1;i<=snake_length-1;i++)  
    {  
        if (snake[0].x==snake[i].x && snake[0].y==snake[i].y) return false;  
    }  
    return true;  
}  
  
/*** 随机生成并输出食物位置 ***/  
bool print_food()  
{  
    srand((unsigned)time(0));  
    bool e;  
    while (1)  
    {  
        e=true;  
        int i=(int) random(0,m)+1,j=(int) random(0,n)+1;  
        food.x=i;food.y=j;  
        for (int k=0;k<=snake_length-1;k++)  
        {  
            if (snake[k].x==food.x && snake[k].y==food.y)  
            {  
                e=false;break;  
            }  
        }  
        if (e) break;  
    }  
    locate(food.x,food.y);  
    cout << "$";  
    return true;  
}   
/*** 蛇的前进 ***/  
bool go_ahead()  
{  
    node temp;  
    bool e=false;  
    temp=snake[snake_length-1];  
    for (int i=snake_length-1;i>=1;i--)  
        snake[i]=snake[i-1];  
    snake[0].x+=direct[dir][0];  
    snake[0].y+=direct[dir][1];  
    locate(snake[1].x,snake[1].y);  
    cout << "*";  
    /*** 吃到了食物 ***/  
    if (snake[0].x==food.x && snake[0].y==food.y)  
    {  
        snake_length++;  
        e=true;  
        snake[snake_length-1]=temp;  
    }  
    /*** 输出此时蛇状态 ***/  
    if (!e)  
    {  
        locate(temp.x,temp.y);  
        cout << " ";  
    }  
    else  
        print_food();  
    locate(snake[0].x,snake[0].y);  
    cout << "@";  
    /*** 如果自撞 ***/  
    if (!is_correct())  
    {  
        system("cls");  
        cout << "You lose!" << endl << "Length: " << snake_length << endl;  
        return false;  
    }  
    return true;  
}  
  
/*** 主函数 ***/  
int main()  
{  
    cout << "--------------------贪吃蛇---------------------" << endl;  
    cout << "请先输入两个数,表示地图大小.要求长宽均不小于10." << endl;  
    cout << "请注意窗口大小,以免发生错位.建议将窗口调为最大【小于25x40】." << endl;  
    cout << "再选择难度.请在1-10中输入1个数,1最简单,10则最难" << endl;  
    cout << "然后进入游戏画面,以方向键控制方向.祝你游戏愉快!" << endl;  
    cout << "-----------------------------------------------" << endl;  
    cin >> m >> n;  
    if (m<10 || n<10 || m>25 || n>40)  
    {  
        cout << "ERROR" << endl;  
        system("pause");  
        return 0;  
    }  
    int hard;  
    cin >> hard;  
    if (hard<=0 || hard>100)  
    {  
        cout << "ERROR" << endl;  
        system("pause");  
        return 0;  
    }  
    /*** 数据全部初始化，包括蛇长，位置，方向 ***/  
    snake_length=5;  
    clock_t a,b;  
    char ch;  
    double hard_len;  
    for (int i=0;i<=4;i++)  
    {  
        snake[i].x=1;  
        snake[i].y=5-i;  
    }  
    dir=3;  
    /*** 输出初始地图，蛇与食物 ***/  
    system("cls");  
    hide();  
    print_wall();  
    print_food();  
    print_snake();  
    locate(m+2,0);  
    cout << "Now length: ";  
    /*** 开始游戏 ***/  
    while (1)  
    {  
        /*** 难度随长度增加而提高 ***/  
        hard_len=(double)snake_length/(double) (m*n);  
        /*** 调节时间，单位是ms ***/  
        a=clock();  
        while (1)  
        {  
            b=clock();  
            if (b-a>=(int)(400-30*hard)*(1-sqrt(hard_len))) break;  
        }  
        /*** 接受键盘输入的上下左右，并以此改变方向 ***/  
        if (kbhit())  
        {  
            ch=getch();  
            if (ch==-32)  
            {  
                ch=getch();  
                switch(ch)  
                {  
                case 72:  
                    if (dir==2 || dir==3)  
                        dir=0;  
                    break;  
                case 80:  
                    if (dir==2 || dir==3)  
                        dir=1;  
                    break;  
                case 75:  
                    if (dir==0 || dir==1)  
                        dir=2;  
                    break;  
                case 77:  
                    if (dir==0 || dir==1)  
                        dir=3;  
                    break;  
                }  
            }  
        }  
        /*** 前进 ***/  
        if (!go_ahead()) break;  
        /*** 在最后输出此时长度 ***/  
        locate(m+2,12);  
        cout << snake_length;  
    }  
    system("pause");  
    return 0;  
}  


#endif

//C++小游戏——走迷宫
#if 0
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<iostream>
using namespace std;
char pr[10]={1,' ','E','O'} ;
int level,n,m,map[50][50],i,j,x,y,k,ex,ey;
char c[1001];
int main(){
    system("cls");
    puts("if you no full screen,please press full screen");
    getch();
    system("cls");
    puts("please choose level");
    again:;
    cin>>level;
    if(level>1||level<1){
        puts("haven't this level");
        goto again;
    }
    puts("loading...");
    sprintf(c,"%d.map",level);
    freopen(c,"r",stdin);
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>map[i][j];
    fclose(stdin);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(map[i][j]==3){
                x=i;
                y=j;
            }
            else if(map[i][j]==2){
                ex=i;
                ey=j;
            }
    while(x!=ex&&y!=ey){
        system("cls");
        for(i=1;i<=n;i++,putchar('\n'))
            for(j=1;j<=m;j++)
                putchar(pr[map[i][j]]);
        k=getch();
        if(k=='w')
            if(map[x-1][y]&&(x-1)){
                map[x-1][y]=3;
                map[x][y]=1;
                x--;
            }
        if(k=='s')
            if(map[x+1][y]&&(x+1)<=n){
                map[x+1][y]=3;
                map[x][y]=1;
                x++;
            }
        if(k=='a')
            if(map[x][y-1]&&(y-1)){
                map[x][y-1]=3;
                map[x][y]=1;
                y--;
            }
        if(k=='d')
            if(map[x][y+1]&&(y+1)<=m){
                map[x][y+1]=3;
                map[x][y]=1;
                y++;
            }
    }
    system("cls");
    return 0;
}

#endif

//2048  👍
#if 0
//http://blog.csdn.net/one_piece_luffy/article/details/44240295
#include <iostream>  
#include <windows.h>  
#include <ctime>  
using namespace std;  
  
int const ROW = 4;  
int const COL = 4;  
int game[ROW][COL] = {0};  
  
//上下左右  
int const UP = 1;  
int const DOWN = 2;  
int const LEFT = 3;  
int const RIGHT = 4;  
  
//游戏所处的状态  
int const GAME_OVER = 1;  
int const GAME_WIN = 2;  
int const GAME_CONTINUE = 3;  
  
enum GameNum  
{  
    Game_2 = 2,  
    Game_4 = 4,  
    Game_8 = 8,  
    Game_16 = 16,  
    Game_32 = 32,  
    Game_64 = 64,  
    Game_128 = 128,  
    Game_256 = 256,  
    Game_512 = 512,  
    Game_1024 = 1024,  
    Game_2048 = 2048,  
};  
  
//打印所得的数组  
void Print()  
{  
    system("cls");  
    cout << "*****************  2048 控 制 台 版  ******************" << endl;  
    cout << "*****************  By Tanzf (Intern) ******************" << endl << endl;  
    for (int i = 0; i < ROW; ++i)  
    {  
        cout << "---------------------------------"<< endl;  
        for (int j = 0; j < COL; ++j)  
        {  
            if (game[i][j] == 0)  
            {  
                cout <<"|   \t";  
            }  
            else   
            {  
                cout <<"|   " << game[i][j] << "\t";  
            }  
        }  
        cout << "|" << endl;  
    }  
    cout << "---------------------------------"<< endl;  
}  
  
  
bool CreateNumber()  
{  
    int x = -1;  
    int y = -1;  
    int times = 0;  
    int maxTimes = ROW * COL;  
    //三分之二的概率生成2，三分之一的概率生成4  
    int whitch = rand() % 3;  
    do   
    {  
        x = rand() % ROW;  
        y = rand() % COL;  
        ++times;  
    } while (game[x][y] != 0 && times <= maxTimes);  
  
    //说明格子已经满了  
    if(times >= maxTimes)  
    {  
        return false;  
    }  
    else  
    {  
        GameNum num;  
        if(whitch == 0)  
        {  
            num = Game_4;  
        }  
        else if(whitch)  
        {  
            num = Game_2;  
        }  
        game[x][y] = num;  
    }  
  
    return true;  
}  
  
void Process(int direction)  
{  
    switch (direction)  
    {  
    case UP:  
        //最上面一行不动  
        for(int row = 1; row < ROW; ++row)  
        {  
            for(int crow = row; crow >= 1; --crow)  
            {  
                for(int col = 0; col < COL; ++col)  
                {  
                    //上一个格子为空  
                    if(game[crow-1][col] == 0)  
                    {  
                        game[crow-1][col] = game[crow][col];  
                        game[crow][col] = 0;  
                    }  
                    else   
                    {  
                        //合并  
                        if(game[crow-1][col] == game[crow][col])  
                        {  
                            game[crow - 1][col] *= 2;  
                            game[crow][col] = 0;  
                        }  
  
                    }  
                }  
            }  
        }  
        break;  
    case DOWN:  
        //最下面一行不动  
        for(int row = ROW - 2; row >= 0; --row)  
        {  
            for(int crow = row; crow < ROW - 1; ++crow)  
            {  
                for(int col = 0; col < COL; ++col)  
                {  
                    //上一个格子为空  
                    if(game[crow + 1][col] == 0)  
                    {  
                        game[crow + 1][col] = game[crow][col];  
                        game[crow][col] = 0;  
                    }  
                    else   
                    {  
                        //合并  
                        if(game[crow + 1][col] == game[crow][col])  
                        {  
                            game[crow + 1][col] *= 2;  
                            game[crow][col] = 0;  
                        }  
  
                    }  
                }  
            }  
        }  
        break;  
    case LEFT:  
        //最左边一列不动  
        for(int  col = 1; col < COL; ++col)  
        {  
            for(int ccol = col; ccol >= 1; --ccol)  
            {  
                for(int row = 0; row < ROW; ++row)  
                {  
                    //上一个格子为空  
                    if(game[row][ccol-1] == 0)  
                    {  
                        game[row][ccol - 1] = game[row][ccol];  
                        game[row][ccol] = 0;  
                    }  
                    else   
                    {  
                        //合并  
                        if(game[row][ccol - 1] == game[row][ccol])  
                        {  
                            game[row][ccol - 1] *= 2;  
                            game[row][ccol] = 0;  
                        }  
  
                    }  
                }  
            }  
        }  
        break;  
    case RIGHT:  
        //最右边一列不动  
        for(int  col = COL - 2; col >= 0; --col)  
        {  
            for(int ccol = col; ccol <= COL - 2; ++ccol)  
            {  
                for(int row = 0; row < ROW; ++row)  
                {  
                    //上一个格子为空  
                    if(game[row][ccol + 1] == 0)  
                    {  
                        game[row][ccol + 1] = game[row][ccol];  
                        game[row][ccol] = 0;  
                    }  
                    else   
                    {  
                        //合并  
                        if(game[row][ccol + 1] == game[row][ccol])  
                        {  
                            game[row][ccol + 1] *= 2;  
                            game[row][ccol] = 0;  
                        }  
  
                    }  
                }  
            }  
        }  
        break;  
    }  
  
}  
  
//处理输入输出，返回上下左右  
int Input()  
{  
    //读取上下左右四个方向键  
    int upArrow = 0;  
    int downArrow = 0;  
    int leftArrow = 0;  
    int rightArrow = 0;  
    int direction = 0;  
    while (true)  
    {  
        upArrow = GetAsyncKeyState(VK_UP);  
        downArrow = GetAsyncKeyState(VK_DOWN);  
        leftArrow = GetAsyncKeyState(VK_LEFT);  
        rightArrow = GetAsyncKeyState(VK_RIGHT);  
  
        if(upArrow)  
        {  
            direction = UP;  
            break;  
        }  
        else if(downArrow)  
        {  
            direction = DOWN;  
            break;  
        }  
        else if(leftArrow)  
        {  
            direction = LEFT;  
            break;  
        }  
        else if(rightArrow)  
        {  
            direction = RIGHT;  
            break;  
        }  
  
        Sleep(100);  
    }  
  
    return direction;  
}  
  
//判断游戏状态  
int Judge()  
{  
    //赢得游戏  
    for(int i = 0; i < ROW; ++i)  
    {  
        for(int j = 0; j < COL; ++j)  
        {  
            if(game[i][j] == 2048)  
            {  
                return GAME_WIN;  
                break;  
            }  
        }  
    }  
  
    //横向检查  
    for(int i = 0 ; i < ROW; ++i)  
    {  
        for(int j = 0; j < COL - 1; ++j)  
        {  
            if(!game[i][j] || (game[i][j] == game[i][j+1]))  
            {  
                return GAME_CONTINUE;  
                break;  
            }  
        }  
    }  
    //纵向检查  
    for(int j = 0; j< COL; ++j)  
    {  
        for(int i = 0; i < ROW -1; ++i)  
        {  
            if(!game[i][j] || (game[i][j] == game[i+1][j]))  
            {  
                return GAME_CONTINUE;  
                break;  
            }  
        }  
    }  
  
    //不符合上述两种状况，游戏结束  
    return GAME_OVER;  
  
}  
  
int main()  
{  
    //设置一个随机数种子  
    srand((unsigned int)time(0));  
    CreateNumber();  
    CreateNumber();  
    Print();  
    int direction = 0;  
    int gameState = -1;  
    while(true)  
    {  
        direction = Input();  
  
        gameState = Judge();  
        if(direction && gameState == GAME_CONTINUE)  
        {  
            Process(direction);  
            CreateNumber();  
            Print();  
            Sleep(100);  
        }  
        else if(gameState == GAME_WIN)  
        {  
            Print();  
            cout << "You Win！" << endl;  
            break;  
        }  
        else if(gameState == GAME_OVER)  
        {  
            Print();  
            cout <<"You lose!" << endl;  
            break;  
        }  
    }  
  
    return 0;  
}  

#endif

//打飞机 👍
#if 0
//http://blog.csdn.net/cnyali_ljf/article/details/51340363
#include<iostream>  
#include<windows.h>  
#include<conio.h>  
#include<time.h>  
#include<string>  
using namespace std;  
  
/*=============== all the structures ===============*/  
  
typedef struct Frame  
{  
    COORD position[2];  
    int flag;  
}Frame;  
  
  
/*=============== all the functions ===============*/  
  
void SetPos(COORD a)// set cursor   
{  
    HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleCursorPosition(out, a);  
}  
  
void SetPos(int i, int j)// set cursor  
{  
    COORD pos={i, j};  
    SetPos(pos);  
}  
  
void HideCursor()  
{  
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};   
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);  
}  
  
//把第y行，[x1, x2) 之间的坐标填充为 ch  
void drawRow(int y, int x1, int x2, char ch)  
{  
    SetPos(x1,y);  
    for(int i = 0; i <= (x2-x1); i++)  
        cout<<ch;  
}  
  
//在a, b 纵坐标相同的前提下，把坐标 [a, b] 之间填充为 ch  
void drawRow(COORD a, COORD b, char ch)  
{  
    if(a.Y == b.Y)  
        drawRow(a.Y, a.X, b.X, ch);  
    else  
    {  
        SetPos(0, 25);  
        cout<<"error code 01：无法填充行，因为两个坐标的纵坐标(x)不相等";  
        system("pause");  
    }  
}  
  
//把第x列，[y1, y2] 之间的坐标填充为 ch  
void drawCol(int x, int y1, int y2, char ch)  
{  
    int y=y1;  
    while(y!=y2+1)  
    {  
        SetPos(x, y);  
        cout<<ch;  
        y++;  
    }  
}  
  
//在a, b 横坐标相同的前提下，把坐标 [a, b] 之间填充为 ch  
void drawCol(COORD a, COORD b, char ch)  
{  
    if(a.X == b.X)  
        drawCol(a.X, a.Y, b.Y, ch);  
    else  
    {  
        SetPos(0, 25);  
        cout<<"error code 02：无法填充列，因为两个坐标的横坐标(y)不相等";  
        system("pause");  
    }  
}  
  
//左上角坐标、右下角坐标、用row填充行、用col填充列  
void drawFrame(COORD a, COORD  b, char row, char col)  
{  
    drawRow(a.Y, a.X+1, b.X-1, row);  
    drawRow(b.Y, a.X+1, b.X-1, row);  
    drawCol(a.X, a.Y+1, b.Y-1, col);  
    drawCol(b.X, a.Y+1, b.Y-1, col);  
}  
  
void drawFrame(int x1, int y1, int x2, int y2, char row, char col)  
{  
    COORD a={x1, y1};  
    COORD b={x2, y2};  
    drawFrame(a, b, row, col);  
}  
  
void drawFrame(Frame frame, char row, char col)  
{  
    COORD a = frame.position[0];  
    COORD b = frame.position[1];  
    drawFrame(a, b, row, col);  
}  
  
void drawPlaying()  
{  
    drawFrame(0, 0, 48, 24, '=', '|');//    draw map frame;  
    drawFrame(49, 0, 79, 4, '-', '|');//        draw output frame  
    drawFrame(49, 4, 79, 9, '-', '|');//        draw score frame  
    drawFrame(49, 9, 79, 20, '-', '|');//   draw operate frame  
    drawFrame(49, 20, 79, 24, '-', '|');//  draw other message frame  
    SetPos(52, 6);  
    cout<<"得分：";  
    SetPos(52, 7);  
    cout<<"称号：";  
    SetPos(52,10);  
    cout<<"操作方式：";  
    SetPos(52,12);  
    cout<<"  a,s,d,w 控制战机移动。";  
	SetPos(52,14);  
    cout<<"  k 发射子弹。";  
    SetPos(52,16);  
    cout<<"  p 暂停游戏。";  
    SetPos(52,18);  
    cout<<"  e 退出游戏。";  
}  
  
//在[a, b)之间产生一个随机整数  
int random(int a, int b)  
{  
    int c=(rand() % (a-b))+ a;  
    return c;  
}  
  
//在两个坐标包括的矩形框内随机产生一个坐标  
COORD random(COORD a, COORD b)  
{  
    int x=random(a.X, b.X);  
    int y=random(a.Y, b.Y);  
    COORD c={x, y};  
    return c;  
}  
  
bool  judgeCoordInFrame(Frame frame, COORD spot)  
{  
    if(spot.X>=frame.position[0].X)  
        if(spot.X<=frame.position[1].X)  
            if(spot.Y>=frame.position[0].Y)  
                if(spot.Y<=frame.position[0].Y)  
                    return true;  
    return false;  
}  
  
void printCoord(COORD a)  
{  
    cout    <<"( "<<a.X<<" , "<<a.Y<<" )";  
}  
  
void printFrameCoord(Frame a)  
{  
    printCoord(a.position[0]);  
    cout    <<" - ";  
    printCoord(a.position[1]);  
}  
  
int drawMenu()  
{  
    SetPos(30, 1);  
    cout<<"P l a n e  W a r";  
    drawRow(3, 0, 79, '-');  
    drawRow(5, 0, 79, '-');  
    SetPos(28, 4);  
    cout<<"w 和 s 选择， k 确定";  
    SetPos(15, 11);  
    cout<<"1. 简单的敌人";  
    SetPos(15, 13);  
    cout<<"2. 冷酷的敌人";  
    drawRow(20, 0, 79, '-');  
    drawRow(22, 0, 79, '-');  
    SetPos(47, 11);  
    cout<<"简单的敌人：";  
    SetPos(51, 13);  
    cout<<"简单敌人有着较慢的移动速度。";  
    SetPos(24, 21);  
    cout<<"制作：LJF神犇";  
    int j=11;  
    SetPos(12, j);  
    cout<<">>";  
  
    //drawFrame(45, 9, 79, 17, '=', '|');  
  
    while(1)  
    {   if( _kbhit() )  
        {     
            char x=_getch();  
            switch (x)  
            {  
            case 'w' :  
                    {     
                        if( j == 13)  
                        {  
                            SetPos(12, j);  
                            cout<<"　";  
                            j = 11;  
                            SetPos(12, j);  
                            cout<<">>";  
                            SetPos(51, 13);  
                            cout<<"　　　　　　　　　　　　";  
                            SetPos(47, 11);  
                            cout<<"简单的敌人：";  
                            SetPos(51, 13);  
                            cout<<"简单敌人有着较慢的移动速度，比较容易对付";  
                        }  
                        break;  
                    }  
            case 's' :  
                    {     
                        if( j == 11 )  
                        {  
                            SetPos(12, j);  
                            cout<<"　";          
                            j = 13;  
                            SetPos(12, j);  
                            cout<<">>";  
                            SetPos(51, 13);  
                            cout<<"　　　　　　　　　　　　　　";  
                            SetPos(47, 11);  
                            cout<<"冷酷的敌人：";  
                            SetPos(51, 13);  
                            cout<<"冷酷的敌人移动速度较快，难对付哟。";  
                        }  
                        break;  
                    }  
            case 'k' :  
                    {     
                        if (j == 8) return 1;  
                        else return 2;  
                    }  
            }  
        }  
    }  
}  
  
/*  
DWORD WINAPI MusicFun(LPVOID lpParamte) 
{ 
    //DWORD OBJ; 
    sndPlaySound(TEXT("bgm.wav"), SND_FILENAME|SND_ASYNC); 
    return 0; 
} 
*/  
  
  
/*================== the Game Class ==================*/  
  
class Game  
{  
public:  
    COORD position[10];  
    COORD bullet[10];  
    Frame enemy[8];  
    int score;  
    int rank;  
    int rankf;  
    string title;  
    int flag_rank;  
  
    Game ();  
      
    //初始化所有  
    void initPlane();  
    void initBullet();  
    void initEnemy();  
  
    //初始化其中一个  
    //void initThisBullet( COORD );  
    //void initThisEnemy( Frame );  
  
    void planeMove(char);  
    void bulletMove();  
    void enemyMove();  
      
    //填充所有  
    void drawPlane();  
    void drawPlaneToNull();  
    void drawBullet();  
    void drawBulletToNull();  
    void drawEnemy();  
    void drawEnemyToNull();  
  
    //填充其中一个  
    void drawThisBulletToNull( COORD );  
    void drawThisEnemyToNull( Frame );  
  
    void Pause();  
    void Playing();  
    void judgePlane();  
    void judgeEnemy();  
  
    void Shoot();  
  
    void GameOver();  
    void printScore();  
};  
  
Game::Game()  
{  
    initPlane();  
    initBullet();  
    initEnemy();  
    score = 0;  
    rank = 25;  
    rankf = 0;  
    flag_rank = 0;  
}  
  
void Game::initPlane()  
{  
    COORD centren={39, 22};  
    position[0].X=position[5].X=position[7].X=position[9].X=centren.X;  
    position[1].X=centren.X-2;    
    position[2].X=position[6].X=centren.X-1;  
    position[3].X=position[8].X=centren.X+1;  
    position[4].X=centren.X+2;  
    for(int i=0; i<=4; i++)  
        position[i].Y=centren.Y;  
    for(int i=6; i<=8; i++)  
        position[i].Y=centren.Y+1;  
    position[5].Y=centren.Y-1;  
    position[9].Y=centren.Y-2;  
}  
  
void Game::drawPlane()  
{  
    for(int i=0; i<9; i++)  
    {  
        SetPos(position[i]);  
        if(i!=5)  
            cout<<"O";  
        else if(i==5)  
            cout<<"|";          
    }  
}  
  
void Game::drawPlaneToNull()  
{  
    for(int i=0; i<9; i++)  
    {  
        SetPos(position[i]);  
        cout<<" ";  
    }     
}  
  
void Game::initBullet()  
{  
    for(int i=0; i<10; i++)  
        bullet[i].Y = 30;  
}  
  
void Game::drawBullet()  
{  
    for(int i=0; i<10; i++)  
    {  
        if( bullet[i].Y != 30)  
        {  
            SetPos(bullet[i]);  
            cout<<"^";      
        }  
    }  
}  
  
void Game::drawBulletToNull()  
{  
    for(int i=0; i<10; i++)  
        if( bullet[i].Y != 30 )  
            {  
                COORD pos={bullet[i].X, bullet[i].Y+1};  
                SetPos(pos);  
                cout<<" ";  
            }     
}  
  
void Game::initEnemy()  
{  
    COORD a={1, 1};  
    COORD b={45, 15};  
    for(int i=0; i<8; i++)  
    {  
        enemy[i].position[0] = random(a, b);  
        enemy[i].position[1].X = enemy[i].position[0].X + 3;  
        enemy[i].position[1].Y = enemy[i].position[0].Y + 2;  
    }  
}  
  
void Game::drawEnemy()  
{  
    for(int i=0; i<8; i++)  
        drawFrame(enemy[i].position[0], enemy[i].position[1], '-', '|');  
}  
  
void Game::drawEnemyToNull()  
{  
    for(int i=0; i<8; i++)  
    {  
        drawFrame(enemy[i].position[0], enemy[i].position[1], ' ', ' ');  
    }         
}  
  
void Game::Pause()  
{  
    SetPos(61,2);  
    cout<<"               ";  
    SetPos(61,2);  
    cout<<"暂停中...";  
    char c=_getch();  
    while(c!='p')  
        c=_getch();  
    SetPos(61,2);  
    cout<<"         ";  
}  
  
void Game::planeMove(char x)  
{  
    if(x == 'a')  
        if(position[1].X != 1)  
            for(int i=0; i<=9; i++)  
                position[i].X -= 2;  
                  
    if(x == 's')  
        if(position[7].Y != 23)  
            for(int i=0; i<=9; i++)  
                position[i].Y += 1;  
  
    if(x == 'd')  
        if(position[4].X != 47)  
            for(int i=0; i<=9; i++)  
                position[i].X += 2;  
  
    if(x == 'w')  
        if(position[5].Y != 3)  
            for(int i=0; i<=9; i++)  
                position[i].Y -= 1;  
}  
  
void Game::bulletMove()  
{  
    for(int i=0; i<10; i++)  
    {  
        if( bullet[i].Y != 30)  
        {  
            bullet[i].Y -= 1;  
            if( bullet[i].Y == 1 )  
            {  
                COORD pos={bullet[i].X, bullet[i].Y+1};  
                drawThisBulletToNull( pos );  
                bullet[i].Y=30;  
            }  
                  
        }  
    }  
}  
  
void Game::enemyMove()  
{  
    for(int i=0; i<8; i++)  
    {  
        for(int j=0; j<2; j++)  
            enemy[i].position[j].Y++;  
  
        if(24 == enemy[i].position[1].Y)  
        {  
            COORD a={1, 1};  
            COORD b={45, 3};  
            enemy[i].position[0] = random(a, b);  
            enemy[i].position[1].X = enemy[i].position[0].X + 3;  
            enemy[i].position[1].Y = enemy[i].position[0].Y + 2;  
        }  
    }  
}  
  
void Game::judgePlane()  
{  
    for(int i = 0; i < 8; i++)  
        for(int j=0; j<9; j++)  
            if(judgeCoordInFrame(enemy[i], position[j]))  
            {  
                SetPos(62, 1);  
                cout<<"坠毁";  
                drawFrame(enemy[i], '+', '+');  
                Sleep(1000);  
                GameOver();  
                break;  
            }  
}  
  
void Game::drawThisBulletToNull( COORD c)  
{  
    SetPos(c);  
    cout<<" ";  
}  
  
void Game::drawThisEnemyToNull( Frame f )  
{  
    drawFrame(f, ' ', ' ');  
}  
  
void Game::judgeEnemy()  
{  
    for(int i = 0; i < 8; i++)  
        for(int j = 0; j < 10; j++)  
            if( judgeCoordInFrame(enemy[i], bullet[j]) )  
            {  
                score += 5;  
                drawThisEnemyToNull( enemy[i] );  
                COORD a={1, 1};  
                COORD b={45, 3};  
                enemy[i].position[0] = random(a, b);  
                enemy[i].position[1].X = enemy[i].position[0].X + 3;  
                enemy[i].position[1].Y = enemy[i].position[0].Y + 2;                      
                drawThisBulletToNull( bullet[j] );  
                bullet[j].Y = 30;  
            }  
}  
  
void Game::Shoot()  
{  
    for(int i=0; i<10; i++)  
        if(bullet[i].Y == 30)  
        {  
            bullet[i].X = position[5].X;  
            bullet[i].Y = position[5].Y-1;  
            break;  
        }  
}  
  
void Game::printScore()  
{  
    if(score == 120 && flag_rank == 0)  
    {  
        rank -= 3;  
        flag_rank = 1;  
    }  
  
    else if( score == 360 && flag_rank == 1)  
    {  
        rank -= 5;  
        flag_rank = 2;  
    }  
    else if( score == 480 && flag_rank == 2)  
    {  
        rank -= 5;  
        flag_rank = 3;  
    }  
    int x=rank/5;  
    SetPos(60, 6);  
    cout<<score;  
  
    if( rank!=rankf )  
    {  
        SetPos(60, 7);  
        if( x == 5)  
            title="初级飞行员";  
        else if( x == 4)  
            title="中级飞行员";  
        else if( x == 3)  
            title="高级飞行员";  
        else if( x == 2 )  
            title="王牌飞行员";  
        cout<<title;  
    }  
    rankf = rank;  
}  
  
void Game::Playing()  
{  
    //HANDLE MFUN;  
    //MFUN= CreateThread(NULL, 0, MusicFun, NULL, 0, NULL);   
  
    drawEnemy();  
    drawPlane();  
  
    int flag_bullet = 0;  
    int flag_enemy = 0;  
  
    while(1)  
    {  
        Sleep(8);  
        if(_kbhit())  
        {  
            char x = _getch();  
            if ('a' == x || 's' == x || 'd' == x || 'w' == x)  
            {  
                drawPlaneToNull();  
                planeMove(x);  
                drawPlane();  
                judgePlane();  
            }             
            else if ('p' == x)  
                Pause();  
            else if( 'k' == x)  
                Shoot();  
            else if( 'e' == x)  
            {  
                //CloseHandle(MFUN);  
                GameOver();  
                break;  
            }  
                  
        }  
        /* 处理子弹 */  
        if( 0 == flag_bullet )  
        {  
            bulletMove();  
            drawBulletToNull();  
            drawBullet();  
            judgeEnemy();  
        }             
        flag_bullet++;  
        if( 5 == flag_bullet )  
            flag_bullet = 0;  
  
        /* 处理敌人 */  
        if( 0 == flag_enemy )  
        {  
            drawEnemyToNull();  
            enemyMove();              
            drawEnemy();  
            judgePlane();  
        }  
        flag_enemy++;  
        if( flag_enemy >= rank )  
            flag_enemy = 0;  
  
        /* 输出得分 */  
        printScore();  
    }  
}  
  
void Game::GameOver()  
{  
    system("cls");                
    COORD p1={28,9};  
    COORD p2={53,15};  
    drawFrame(p1, p2, '=', '|');  
    SetPos(36,12);  
    string str="Game Over!";  
    for(int i=0; i<str.size(); i++)  
    {  
        Sleep(80);  
        cout<<str[i];  
    }  
    Sleep(1000);  
    system("cls");  
    drawFrame(p1, p2, '=', '|');  
    SetPos(31, 11);  
    cout<<"击落敌机："<<score/5<<" 架";  
    SetPos(31, 12);  
    cout<<"得　　分："<<score;  
    SetPos(31, 13);  
    cout<<"获得称号："<<title;  
    SetPos(30, 16);  
    Sleep(1000);  
    cout<<"继续？ 是（y）| 否（n）制作：最牛的LJF";  
as:  
    char x=_getch();  
    if (x == 'n')  
        exit(0);  
    else if (x == 'y')  
    {  
        system("cls");  
        Game game;  
        int a = drawMenu();  
        if(a == 2)  
            game.rank = 20;  
        system("cls");  
        drawPlaying();  
        game.Playing();  
    }  
    else goto as;  
}  
  
/*================== the main function ==================*/  
int main()  
{  
    //游戏准备  
    srand((int)time(0));    //随机种子  
    HideCursor();   //隐藏光标  
      
    Game game;  
    int a = drawMenu();  
    if(a == 2)  
        game.rank = 20;  
    system("cls");  
    drawPlaying();  
    game.Playing();  
}  

#endif

//扫雷
#if 0
//http://blog.csdn.net/buptlrw/article/details/41961773
//<span style="font-weight: normal;"><span style="font-size:14px;">#include <ctime>  
#include <cstdlib>  
#include <iostream>  
#include <cstring>  
using namespace std;  
int map[12][12];    // 为避免边界的特殊处理，故将二维数组四周边界扩展1  
int derection[3] = { 0, 1, -1 };  //用于处理中心周围8个点的数组  
int type;  
class bombsweep  
{  
public:  
    int calculate ( int x, int y )  
    {  
        int counter = 0;  
        for ( int i = 0; i < 3; i++ )  
            for ( int j = 0; j < 3; j++ )  
                if ( map[ x+derection[i]][ y+derection[j] ] == 9 )  
                    counter++;                 // 统计以(x,y)为中心周围8个点的地雷数目  
        return counter;  
    }  
    void game ( int x, int y )  
    {  
        if ( calculate ( x, y ) == 0 )  
        {  
            map[x][y] = 0;  
            for ( int i = 0; i < 3; i++ )  
            {  
                // 若点到一个空白，则系统自动向外扩展  
                for ( int j = 0; j < 3; j++ )  
                    if ( x+derection[i] <= 9 && y+derection[j] <= 9 && x+derection[i] >= 1 && y+derection[j] >= 1  
                            && !( derection[i] == 0 && derection[j] == 0 ) &&  map[x+derection[i]][y+derection[j]] == -1 )  
                        game( x+derection[i], y+derection[j] ); // 一是不可以让两个方向坐标同时为0，否则递归调用本身！  
            }                                                      //二是递归不能出界.三是要保证不返回调用。  
        }  
        else  
            map[x][y] = calculate(x,y);  
    }  
  
    void print (int x,int y)  
    {  
        cout << "  |";  
        for (int i=1; i<10; i++)  
            cout << " " << i;  
        cout << endl;  
        cout << "__|__________________Y" ;  
        cout << endl;  
        for ( int i = 1; i < 10; i++ )  
        {  
            cout << i << " |";  
            for ( int j = 1; j < 10; j++ )  
            {  
                if(map[i][j]==-2)  
                    cout <<" B";  
                else if ( map[i][j] == -1 || map[i][j] == 9 )  
                    cout << " #";  
                else  
                    cout << " "<< map[i][j];  
  
            }  
            cout << "\n";  
        }  
        cout << "  X\n";  
    }  
    bool check ()  
    {  
        int counter = 0;  
        for ( int i = 1; i < 10; i++ )  
            for ( int j = 1; j < 10; j++ )  
                if ( map[i][j] != -1 )  
                    counter++;  
        if ( counter == 10 )  
            return true;  
        else  
            return false;  
    }  
};  
  
int main ()  
{  
  
    int i, j, x, y;  
    char ch;  
    //srand ( time ( 0 ) );  
  
    do  
    {  
        //初始化阵列  
        memset ( map, -1, sizeof(map) );  
  
        for ( i = 0; i < 10;  )  
        {  
            x = rand()%9 + 1;  
            y = rand()%9 + 1;  
            if ( map[x][y] != 9 )  
            {  
                map[x][y] = 9;  
                i++;  
            }  
        }  
  
        cout << "  |";  
        for (i=1; i<10; i++)  
            cout << " " << i;  
        cout << endl;  
        cout << "__|__________________Y" ;  
        cout << endl;  
        for ( i = 1; i < 10; i++ )  
        {  
            cout << i << " |";  
            for ( j = 1; j < 10; j++ )  
                cout << " "<< "#";  
            cout << "\n";  
        }  
        cout << "  X\n";  
        cout << "Please input location x,press enter then input location y: \n";  
        while ( cin >> x >> y )  
        {  
            cout << "Please select:1.dig, 2.sign, 3.cancel sign, 4.restart, 5.exit: \n";  
            cin >>type;  
            switch(type)  
            {  
            case 1:  
            {  
                if ( map[x][y] == 9 || map[x][y]==-2)  
                {  
                    cout << "YOU LOSE!" << endl;  
                    cout << "  |";  
                    for (i=1; i<10; i++)  
                        cout << " " << i;  
                    cout << endl;  
                    cout << "__|__________________Y"<<endl ;  
                    for ( i = 1; i < 10; i++ )  
                    {  
                        cout << i << " |";  
                        for ( j = 1; j < 10; j++ )  
                        {  
                            if ( map[i][j] == 9 || map[i][j]==-2)  
                                cout << " @";  
                            else  
                                cout << " #";  
                        }  
                        cout << "\n";  
                    }  
                    cout << "  X\n";  
                    exit(0);  
                }  
  
                bombsweep bs;  
                bs.game(x,y);  
                bs.print(x,y);  
                cout << "Please input location x,press enter then input location y: \n";  
  
                if ( bs.check())  
                {  
                    cout << "YOU WIN" << endl;  
                    break;  
                }  
                continue;  
            }  
  
            case 2:  
            {  
                bombsweep bs;  
                map[x][y]=-2;  
                bs.print(x,y);  
                cout << "Please input location x,press enter then input location y: \n";  
                continue;  
            }  
  
            case 3:  
            {  
                bombsweep bs;  
                map[x][y]=-1;  
                bs.print(x,y);  
                cout << "Please input location x,press enter then input location y: \n";  
                continue;  
            }  
  
            case 4:  
            {  
                memset ( map, -1, sizeof(map) );  
  
                for ( i = 0; i < 10;  )  
                {  
                    x = rand()%9 + 1;  
                    y = rand()%9 + 1;  
                    if ( map[x][y] != 9 )  
                    {  
                        map[x][y] = 9;  
                        i++;  
                    }  
                }  
  
                cout << "  |";  
                for (i=1; i<10; i++)  
                    cout << " " << i;  
                cout << endl;  
                cout << "__|__________________Y" ;  
                cout << endl;  
                for ( i = 1; i < 10; i++ )  
                {  
                    cout << i << " |";  
                    for ( j = 1; j < 10; j++ )  
                        cout << " "<< "#";  
                    cout << "\n";  
                }  
                cout << "  X\n";  
                cout << "Please input location x,press enter then input location y: \n";  
                continue;  
            }  
            case 5:  
                cout << "Game Ended\n";  
                exit(0);  
                break;  
            default:  
                cout<< "Invalid input, try again: \n";  
                continue;  
            }//end switch  
  
        }//end while(cin >> x >>y)  
        cout << "Do you want to play again?(y/n):" << endl;  
        cin >> ch;  
    }//end do  
    while ( ch == 'y' );  
    return 0;  
}//end main()  
//</span></span>  

#endif

//俄罗斯方块 👍
#if 0
//https://www.cnblogs.com/yonggandefeng/p/6322561.html
//"俄罗斯方块"V1.0
//李国良于2017年1月20日编写完成
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

using namespace std;

int block00[4][4] = { { 10,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } };
int block01[4][4] = { { 11,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } };
int block02[4][4] = { { 12,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,1,0,0 } };
int block03[4][4] = { { 13,0,0,0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } };
int block04[4][4] = { { 14,0,0,0 },{ 0,0,0,0 },{ 0,1,0,0 },{ 1,1,1,0 } };
int block05[4][4] = { { 15,0,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,1,0,0 } };
int block06[4][4] = { { 16,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 1,0,0,0 } };
int block07[4][4] = { { 17,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 } };
int block08[4][4] = { { 18,0,0,0 },{ 0,0,0,0 },{ 0,0,1,0 },{ 1,1,1,0 } };
int block09[4][4] = { { 19,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 } };
int block10[4][4] = { { 20,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,0,1,0 } };
int block11[4][4] = { { 21,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 1,1,0,0 } };
int block12[4][4] = { { 22,0,0,0 },{ 0,0,0,0 },{ 1,0,0,0 },{ 1,1,1,0 } };
int block13[4][4] = { { 23,0,0,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,1,0,0 } };
int block14[4][4] = { { 24,0,0,0 },{ 0,0,0,0 },{ 0,1,1,0 },{ 1,1,0,0 } };
int block15[4][4] = { { 25,0,0,0 },{ 1,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } };
int block16[4][4] = { { 26,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 0,1,1,0 } };
int block17[4][4] = { { 27,0,0,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 } };
int block18[4][4] = { { 28,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 1,1,0,0 } };

void initialWindow(HANDLE hOut);//初始化窗口
void initialPrint(HANDLE hOut);//初始化界面
void gotoXY(HANDLE hOut, int x, int y);//移动光标
void roundBlock(HANDLE hOut, int block[4][4]);//随机生成方块并打印到下一个方块位置
bool collisionDetection(int block[4][4], int map[21][12], int x, int y);//检测碰撞
void printBlock(HANDLE hOut, int block[4][4], int x, int y);//打印方块
void clearBlock(HANDLE hOut, int block[4][4], int x, int y);//消除方块
void myLeft(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);//左移
void myRight(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);//右移
void myUp(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);//顺时针旋转90度
int myDown(HANDLE hOut, int block[4][4], int map[21][12], int &x, int y);//加速下落
void myStop(HANDLE hOut, int block[4][4]);//游戏暂停
void gameOver(HANDLE hOut, int block[4][4], int map[21][12]);//游戏结束
void eliminateRow(HANDLE hOut, int map[21][12], int &val, int &fraction, int &checkpoint);//判断是否能消行并更新分值
int main()
{
    int map[21][12];
    int blockA[4][4];//候选区的方块
    int blockB[4][4];//下落中的方块
    int positionX, positionY;//方块左上角的坐标
    bool check;//检查方块还能不能下落
    char key;//用来存储按键
    int val;//用来控制下落速度
    int fraction;//用来存储得分
    int checkpoint;//用来存储关卡
    int times;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出设备句柄
    initialWindow(hOut);
initial:
    gotoXY(hOut, 0, 0);
    initialPrint(hOut);
    check = true;
    val = 50;
    fraction = 0;
    checkpoint = 1;
    times = val;
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 1; j < 11; ++j)
        {
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < 20; ++i)
    {
        map[i][0] = map[i][11] = 1;
    }
    for (int i = 0; i < 12; ++i)
    {
        map[20][i] = 1;
    }

    srand((unsigned)time(NULL));
    roundBlock(hOut, blockA);
    while (true)
    {
        if (check)
        {
            eliminateRow(hOut, map, val, fraction, checkpoint);
            check = false;
            positionX = -3;
            positionY = 4;
            if (collisionDetection(blockA, map, positionX, positionY))
            {
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        blockB[i][j] = blockA[i][j];
                    }
                }
                roundBlock(hOut, blockA);
            }
            else
            {
                gameOver(hOut, blockA, map);
                goto initial;
            }
        }
        printBlock(hOut, blockB, positionX, positionY);
        if (_kbhit())
        {
            key = _getch();
            switch (key)
            {
            case 72:
                myUp(hOut, blockB, map, positionX, positionY);
                break;
            case 75:
                myLeft(hOut, blockB, map, positionX, positionY);
                break;
            case 77:
                myRight(hOut, blockB, map, positionX, positionY);
                break;
            case 80:
                switch (myDown(hOut, blockB, map, positionX, positionY))
                {
                case 0:
                    check = false;
                    break;
                case 1:
                    check = true;
                    break;
                case 2:
                    gameOver(hOut, blockB, map);
                    goto initial;
                default:
                    break;
                }
                break;
            case 32:
                myStop(hOut, blockA);
                break;
            case 27:
                exit(0);
            default:
                break;
            }
        }
        Sleep(20);
        if (0 == --times)
        {
            switch (myDown(hOut, blockB, map, positionX, positionY))
            {
            case 0:
                check = false;
                break;
            case 1:
                check = true;
                break;
            case 2:
                gameOver(hOut, blockB, map);
                goto initial;
            default:
                break;
            }
            times = val;
        }
    }
    cin.get();
    return 0;
}

void initialWindow(HANDLE hOut)
{
    //SetConsoleTitle("俄罗斯方块");
    COORD size = { 80, 25 };
    SetConsoleScreenBufferSize(hOut, size);
    SMALL_RECT rc = { 0, 0, 79, 24 };
    SetConsoleWindowInfo(hOut, true, &rc);
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(hOut, &cursor_info);
}

void initialPrint(HANDLE hOut)
{
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < 20; ++i)
    {
        cout << "■                    ■☆                      ☆" << endl;
    }
    gotoXY(hOut, 26, 0);
    cout << "☆☆☆☆☆☆☆☆☆☆☆";
    gotoXY(hOut, 0, 20);
    cout << "■■■■■■■■■■■■☆☆☆☆☆☆☆☆☆☆☆☆☆";
    gotoXY(hOut, 26, 1);
    cout << "分    数：      ";
    gotoXY(hOut, 26, 2);
    cout << "关    卡：      ";
    gotoXY(hOut, 26, 4);
    cout << "下一方块：";
    gotoXY(hOut, 26, 9);
    cout << "操作方法：";
    gotoXY(hOut, 30, 11);
    cout << "↑：旋转 ↓：速降";
    gotoXY(hOut, 30, 12);
    cout << "→：右移 ←：左移";
    gotoXY(hOut, 30, 13);
    cout << "空格键：开始/暂停";
    gotoXY(hOut, 30, 14);
    cout << "Esc 键：退出";
    gotoXY(hOut, 26, 16);
    cout << "关    于：";
    gotoXY(hOut, 30, 18);
    cout << "俄罗斯方块V1.0";
    gotoXY(hOut, 35, 19);
    cout << "作者：李国良";
}

void gotoXY(HANDLE hOut, int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}

void roundBlock(HANDLE hOut, int block[4][4])
{
    clearBlock(hOut, block, 5, 15);
    switch (rand() % 19)
    {
    case 0:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block00[i][j];
            }
        }
        break;
    case 1:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block01[i][j];
            }
        }
        break;
    case 2:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block02[i][j];
            }
        }
        break;
    case 3:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block03[i][j];
            }
        }
        break;
    case 4:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block04[i][j];
            }
        }
        break;
    case 5:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block05[i][j];
            }
        }
        break;
    case 6:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block06[i][j];
            }
        }
        break;
    case 7:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block07[i][j];
            }
        }
        break;
    case 8:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block08[i][j];
            }
        }
        break;
    case 9:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block09[i][j];
            }
        }
        break;
    case 10:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block10[i][j];
            }
        }
        break;
    case 11:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block11[i][j];
            }
        }
        break;
    case 12:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block12[i][j];
            }
        }
        break;
    case 13:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block13[i][j];
            }
        }
        break;
    case 14:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block14[i][j];
            }
        }
        break;
    case 15:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block15[i][j];
            }
        }
        break;
    case 16:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block16[i][j];
            }
        }
        break;
    case 17:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block17[i][j];
            }
        }
        break;
    case 18:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block18[i][j];
            }
        }
        break;
    default:
        break;
    }
    printBlock(hOut, block, 5, 15);
}

bool collisionDetection(int block[4][4], int map[21][12], int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (x + i >= 0 && y + j >= 0 && map[x + i][y + j] == 1 && block[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

void printBlock(HANDLE hOut, int block[4][4], int x, int y)
{
    switch (block[0][0])
    {
    case 10:
    case 11:
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 16:
    case 17:
    case 18:
    case 19:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 20:
    case 21:
    case 22:
    case 23:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 24:
    case 25:
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 26:
    case 27:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 28:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        break;
    default:
        break;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (i + x >= 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (block[i][j] == 1)
                {

                    gotoXY(hOut, 2 * (y + j), x + i);
                    cout << "■";
                }
            }
        }
    }
}

void clearBlock(HANDLE hOut, int block[4][4], int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        if (i + x >= 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (block[i][j] == 1)
                {
                    gotoXY(hOut, 2 * (y + j), x + i);
                    cout << "  ";
                }
            }
        }
    }
}

void gameOver(HANDLE hOut, int block[4][4], int map[21][12])
{
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    gotoXY(hOut, 9, 8);
    cout << "GAME OVER";
    gotoXY(hOut, 8, 9);
    cout << "空格键：重来";
    gotoXY(hOut, 8, 10);
    cout << "ESC键：退出";
    char key;
    while (true)
    {
        key = _getch();
        if (key == 32)
        {
            return;
        }
        if (key == 27)
        {
            exit(0);
        }
    }
}

int myDown(HANDLE hOut, int block[4][4], int map[21][12], int &x, int y)
{
    if (collisionDetection(block, map, x + 1, y))
    {
        clearBlock(hOut, block, x, y);
        ++x;
        return 0;
    }
    if (x < 0)
    {
        return 2;
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (block[i][j] == 1)
            {
                map[x + i][y + j] = 1;
                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                gotoXY(hOut, 2 * (y + j), x + i);
                cout << "■";
            }
        }
    }
    return 1;
}

void myLeft(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y)
{
    if (collisionDetection(block, map, x, y - 1))
    {
        clearBlock(hOut, block, x, y);
        --y;
    }
}

void myRight(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y)
{
    if (collisionDetection(block, map, x, y + 1))
    {
        clearBlock(hOut, block, x, y);
        ++y;
    }
}

void myUp(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y)
{
    switch (block[0][0])
    {
    case 10:
        if (collisionDetection(block01, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block01[i][j];
                }
            }
        }
        break;
    case 11:
        if (collisionDetection(block00, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
        }
        else if (collisionDetection(block00, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block00, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
            ++y;
        }
        else if (collisionDetection(block00, map, x, y - 2))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
            y = y - 2;
        }
        else if (collisionDetection(block00, map, x, y + 2))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
            y = y + 2;
        }
        break;
    case 12:
        if (collisionDetection(block03, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block03[i][j];
                }
            }
        }
        else if (collisionDetection(block03, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block03[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block03, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block03[i][j];
                }
            }
            ++y;
        }
        break;
    case 13:
        if (collisionDetection(block04, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block04[i][j];
                }
            }
        }
        else if (collisionDetection(block04, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block04[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block04, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block04[i][j];
                }
            }
            ++y;
        }
        break;
    case 14:
        if (collisionDetection(block05, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block05[i][j];
                }
            }
        }
        else if (collisionDetection(block05, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block05[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block05, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block05[i][j];
                }
            }
            ++y;
        }
        break;
    case 15:
        if (collisionDetection(block02, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block02[i][j];
                }
            }
        }
        else if (collisionDetection(block02, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block02[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block02, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block02[i][j];
                }
            }
            ++y;
        }
        break;

    case 16:
        if (collisionDetection(block07, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block07[i][j];
                }
            }
        }
        else if (collisionDetection(block07, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block07[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block07, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block07[i][j];
                }
            }
            ++y;
        }
        break;
    case 17:
        if (collisionDetection(block08, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block08[i][j];
                }
            }
        }
        else if (collisionDetection(block08, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block08[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block08, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block08[i][j];
                }
            }
            ++y;
        }
        break;
    case 18:
        if (collisionDetection(block09, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block09[i][j];
                }
            }
        }
        else if (collisionDetection(block09, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block09[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block09, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block09[i][j];
                }
            }
            ++y;
        }
        break;
    case 19:
        if (collisionDetection(block06, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block06[i][j];
                }
            }
        }
        else if (collisionDetection(block06, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block06[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block06, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block06[i][j];
                }
            }
            ++y;
        }
        break;
    case 20:
        if (collisionDetection(block11, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block11[i][j];
                }
            }
        }
        else if (collisionDetection(block11, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block11[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block11, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block11[i][j];
                }
            }
            ++y;
        }
        break;
    case 21:
        if (collisionDetection(block12, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block12[i][j];
                }
            }
        }
        else if (collisionDetection(block12, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block12[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block12, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block12[i][j];
                }
            }
            ++y;
        }
        break;
    case 22:
        if (collisionDetection(block13, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block13[i][j];
                }
            }
        }
        else if (collisionDetection(block13, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block13[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block13, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block13[i][j];
                }
            }
            ++y;
        }
        break;
    case 23:
        if (collisionDetection(block10, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block10[i][j];
                }
            }
        }
        else if (collisionDetection(block10, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block10[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block10, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block10[i][j];
                }
            }
            ++y;
        }
        break;
    case 24:
        if (collisionDetection(block15, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block15[i][j];
                }
            }
        }
        else if (collisionDetection(block15, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block15[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block15, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block15[i][j];
                }
            }
            ++y;
        }
        break;
    case 25:
        if (collisionDetection(block14, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block14[i][j];
                }
            }
        }
        else if (collisionDetection(block14, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block14[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block14, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block14[i][j];
                }
            }
            ++y;
        }
        break;
    case 26:
        if (collisionDetection(block17, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block17[i][j];
                }
            }
        }
        else if (collisionDetection(block17, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block17[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block17, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block17[i][j];
                }
            }
            ++y;
        }
        break;
    case 27:
        if (collisionDetection(block16, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block16[i][j];
                }
            }
        }
        else if (collisionDetection(block16, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block16[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block16, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block16[i][j];
                }
            }
            ++y;
        }
        break;
    default:
        break;
    }
}

void myStop(HANDLE hOut, int block[4][4])
{
    clearBlock(hOut, block, 5, 15);
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    gotoXY(hOut, 30, 7);
    cout << "游戏暂停";
    char key;
    while (true)
    {
        key = _getch();
        if (key == 32)
        {
            gotoXY(hOut, 30, 7);
            cout << "        ";
            printBlock(hOut, block, 5, 15);
            return;
        }
        if (key == 27)
        {
            exit(0);
        }
    }
}

void eliminateRow(HANDLE hOut, int map[21][12], int &val, int &fraction, int &checkpoint)
{
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (int i = 19; i >= 0; --i)
    {
        int x = 0;
        for (int j = 1; j < 11; ++j)
        {
            x += map[i][j];
        }
        if (x == 10)
        {
            fraction += 100;
            if (val > 1 && fraction / 1000 + 1 != checkpoint)
            {
                checkpoint = fraction / 1000 + 1;
                val -= 5;
            }
            for (int m = i; m > 0; --m)
            {
                for (int n = 1; n < 11; ++n)
                {
                    map[m][n] = map[m - 1][n];
                    gotoXY(hOut, 2 * n, m);
                    if (map[m][n] == 1)
                    {
                        cout << "■";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
            }
            ++i;
        }
    }
    gotoXY(hOut, 36, 1);
    cout << fraction;
    gotoXY(hOut, 36, 2);
    cout << checkpoint;
}

#endif

//无子棋【人机】👍
#if 0
//http://bbs.csdn.net/topics/360235460
#include<iostream>
#include<cstdlib> 
using namespace std;
const char outstr[11][4]={"┌","┬","┐","├","┼","┤","└","┴","┘","○","●"};
int com[15][15],luozi[15][15];
int c,d;
void jushi()                                   //这是判断落子重要性的函数 
{
      int x,y,i,m,n,lianzi1=0,lianzi2=0,life=0;
      memset(com,0,sizeof(com));
      for(x=0;x<=14;x++)
      for(y=0;y<=14;y++)
      {
          if(luozi[x][y]==0)
          {
              for(m=-1;m<=1;m++) 
              for(n=-1;n<=1;n++)
              {
              if(m!=0 || n!=0)
              {       
                      for(i=1;i<=4;i++)
                      {
                           if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && luozi[x+i*m][y+i*n]==1 )
                           {lianzi1++;}
                           else
                           if(luozi[x+i*m][y+i*n]==0)
                           {life++; break;}
                           else
                           {break;}
}                    
                      for(i=-1;i>=-4;i--)
                      {
                           if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && luozi[x+i*m][y+i*n]==1 )
                           {lianzi1++;}
                           else
                           if(luozi[x+i*m][y+i*n]==0)
                           {life++; break;}
                           else
                           {break;}
                      }
                      if(lianzi1==1)    {com[x][y]+=1;}
                      else if(lianzi1==2) 
                               {
                                    if(life==1)   {com[x][y]+=5;}
                                    else if(life==2)   {com[x][y]+=10;}
}
                      else if(lianzi1==3)
                               {
                                    if(life==1)   {com[x][y]+=20;}
                                    else if(life==2)   {com[x][y]+=100;}
                               }
                      else if(lianzi1==4)    {com[x][y]+=500;}
                      life=0;         
                      for(i=1;i<=4;i++)
                      {
                           if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && luozi[x+i*m][y+i*n]==2 )
                           {lianzi2++;}
                           else
                           if(luozi[x+i*m][y+i*n]==0)
                           {life++; break;}
                           else
                           {break;}
}                    
                      for(i=-1;i>=-4;i--)
                      {
                           if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && luozi[x+i*m][y+i*n]==2 )
                           {lianzi2++;}
                           else
                           if(luozi[x+i*m][y+i*n]==0)
                           {life++; break;}
                           else
                           {break;}
                      }
                      if(lianzi2==1)    {com[x][y]+=2;}
                      else if(lianzi2==2)
                      {
                                    if(life==1)   {com[x][y]+=8;}
                                    else if(life==2)   {com[x][y]+=30;}
                      }
else if(lianzi2==3)
                      {
                                    if(life==1)   {com[x][y]+=50;}
                                    else if(life==2)   {com[x][y]+=200;}
                      }
                      else if(lianzi2==4)    {com[x][y]+=1000;}
                      lianzi1=0;
                      lianzi2=0;
                      life=0;
              }
              }
          }    
      }                     
}
void computer(int a[15][15])           //这是电脑落子的函数 
{
      int i,j,max=0;
      jushi();
      for(i=0;i<=14;i++)
      for(j=0;j<=14;j++)
      {
          if(com[i][j]>max)
          {
                     max=com[i][j];
                     c=i;
                     d=j;
          }
      }
      a[c][d]=10;
      luozi[c][d]=2;
}

int panduan(int x,int y,int sum)         //判断胜负的函数 
{
     int m,n,i,lianzi=0;
              for(m=-1;m<=1;m++)
              for(n=-1;n<=1;n++)
              {
              if(m!=0 || n!=0)
              {
                      for(i=1;i<=4;i++)
                      {
                           if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && luozi[x+i*m][y+i*n]==sum )
                           {lianzi++;}
                           else
                           {break;}
                      }                    
                      for(i=-1;i>=-4;i--)
                      {
                           if( x+i*m>=0 && x+i*m<=14 && y+i*n>=0 && y+i*n<=14 && luozi[x+i*m][y+i*n]==sum )
                           {lianzi++;}
                           else
                           {break;}
                      }
                      if(lianzi>=4)

{
                      return 1;
                      }
                      else
                      {
                      lianzi=0;
                      }
              }
              }
              return 0;   
}

int main()              //主函数 ，主要进行人落子工作 
{
 system ("color 2f");
 system ("mode con cols=50 lines=25");
 system ("title 五子棋！");
     int a[15][15]={0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5, 
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,  
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                    3,4,4,4,4,4,4,4,4,4,4,4,4,4,5, 
                    6,7,7,7,7,7,7,7,7,7,7,7,7,7,8};
     int x,y,i,j;
     memset(luozi,0,sizeof(luozi));
     cout<<" 0 1 2 3 4 5 6 7 8 9 10 1 2 3 4"<<endl;
     for(i=0;i<=14;i++)
     {
                 if(i!=0)
                 cout<<endl;
                 cout<<i%10;
                 for(j=0;j<=14;j++)
                 {
cout<<outstr[a[i][j]];
                 }
     }
     cout<<endl;
 cout<<"更多程序登陆http://742332134.ys168.com/ 或联系QQ：742332134\n";
 cout<<"请输入您要下的棋子 行\\列 用空格隔开:";   
     while(cin>>x>>y)
     {
         if(luozi[x][y]==0 && x>=0 && x<=14 && y>=0 && y<=14)
         {
             a[x][y]=9;
             luozi[x][y]=1;
             if(panduan(x,y,1)==0)
             {
                system ("cls");
                computer(a);
                if(panduan(c,d,2)==0) 
                {
                cout<<" 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4"<<endl;
                for(i=0;i<=14;i++)
                {
                 if(i!=0)
                 cout<<endl;
                 cout<<i%10;
                 for(j=0;j<=14;j++)
                 {
                     cout<<outstr[a[i][j]];
                 }
                }
                cout<<endl;
    cout<<"您的棋子落在"<<x<<"行"<<" "<<y<<"列"<<endl; 
                cout<<"电脑的棋子落在"<<c<<"行"<<" "<<d<<"列"<<endl; 
    cout<<"请输入您要下的棋子";   
                }
                else
                {
                cout<<" 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4"<<endl;
                for(i=0;i<=14;i++)
                {
                 if(i!=0)
                 cout<<endl;
                 cout<<i%10;
                 for(j=0;j<=14;j++)
                 {
                     cout<<outstr[a[i][j]];
                 }
                }
                cout<<endl;
                cout<<"电脑的棋子落在"<<c<<"行"<<" "<<d<<"列"<<endl; 
                cout<<"电脑获胜!"<<endl;
                break;
                } 
                }
             else
             {
             system ("cls");                 //清屏
                 cout<<" 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4"<<endl;
                for(i=0;i<=14;i++)
                {
                 if(i!=0)
                 cout<<endl;
                 cout<<i%10;
                 for(j=0;j<=14;j++)
                 {
                     cout<<outstr[a[i][j]];
                 }
                }
                cout<<endl;
                cout<<"您获胜啦!"<<endl;
                break;
             }
         }
         else
         {
             cout<<"输入错误，请重新输入:"<<endl;
         }     
     }
  system ("title 游戏结束，谢谢使用！");
  system ("color 03");
  cout<<"游戏结束，谢谢使用"<<endl;
     system("pause>nul");
     return 0;
}

#endif

//张琛琳学长
#if 0
/*********************************************************************
* 工程：贪吃蛇
* 文件：main.cpp
* 时间：2017.11.27
* 编译环境：windows 10
*           codeblock
* 简要概述：通过键盘上‘w’，‘a’，’s‘，‘d’，控制蛇身移动
* 不足： 1.只有按键蛇身才会动
*        2.代码略显冗长
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

#define WIDTH 50
#define HEIGHT 25

enum direction { up, down, right, left };   //方向枚举
enum direction g_direc = right;         //全局变量
int array[HEIGHT][WIDTH] = { 0, 0 };      //界面数组

/*****************************链表相关函数***********************************/
//创建链表结构体
struct node
{
	int x;
	int y;
	struct node *next;
};
struct node *head = NULL;

//链表输出
void out_date(struct node *p)
{
	if (p->next == NULL)
	{
		printf("没有数据\n");
	}
	else
	{
		printf("数据为");
		while (p->next)
		{
			p = p->next;
			printf("x=%d ", p->x);
			printf("y=%d ", p->y);
		}
		printf("\n");
	}
}

//链表增加一位
void insert(struct node *p, int val_x, int val_y)
{
	struct node *pt = p;

	//新节点
	struct node *pn = NULL;
	//动态获取长度
	pn = (struct node *)malloc(sizeof(struct node));
	pn->x = val_x;
	pn->y = val_y;
	pn->next = NULL;

	if (pt->next == NULL)
	{
		pt->next = pn;
	}
	else
	{
		while (pt->next)
		{
			pt = pt->next;
			if (pt->next == NULL)
			{
				pt->next = pn;
				break;
			}
		}
	}
}
/*****************************链表相关函数***********************************/


/****************************************************************************
10 代表围墙
0  代表空
1  代表蛇身
2  代表食物
****************************************************************************/
//更新地图
void update()
{
	system("cls");
	int ii = 0, jj = 0;
	for (ii = 0; ii < HEIGHT; ii++)
	{
		for (jj = 0; jj < WIDTH; jj++)     //遍历每行
		{
			if (array[ii][jj] == 10)
				printf("#");
			if (array[ii][jj] == 0)
				printf(" ");
			if (array[ii][jj] == 1)
				printf("*");
			if (array[ii][jj] == 2)
				printf("@");
		}
		printf("\n");
	}
}
//初始化函数
void init()
{
	//打印围墙
	int i = 0, j = 0;
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)     //遍历每行
		{
			if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
			{
				array[i][j] = 10;       //10代表围墙
			}
			else array[i][j] = 0;
		}
	}
	//打印蛇身(位置：正中间)
	int k = 0;
	for (k = 0; k < 4; k++)
	{
		array[HEIGHT / 2][WIDTH / 2 - 4 + k] = 1;
	}
	//打印食物
	srand((unsigned)time(NULL));
	int food_x = (rand() % (WIDTH - 1 - 1)) + 1;
	int food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
	while (array[food_y][food_x] == 1)   //避免随机数出现在蛇身
	{
		printf("sdsafd");
		food_x = (rand() % (WIDTH - 1 - 1)) + 1;
		food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
	}
	array[food_y][food_x] = 2;

	//链表初始化
	head = (struct node *)malloc(sizeof(struct node));
	head->x = 0;
	head->y = 0;
	head->next = NULL;

	//添加蛇身数据到链表
	insert(head, WIDTH / 2 - 4 + 0, HEIGHT / 2);
	insert(head, WIDTH / 2 - 4 + 1, HEIGHT / 2);
	insert(head, WIDTH / 2 - 4 + 2, HEIGHT / 2);
	insert(head, WIDTH / 2 - 4 + 3, HEIGHT / 2);
	//out_date(head);

	//初始化显示
	update();
}
//移动：向上
void move_up()
{
	if (g_direc != down)    //上一次运动不能为向下
	{
		struct node *temp = head;
		temp = temp->next;      //蛇尾
		struct node *p_fin = head;
		while (p_fin->next)      //蛇头下一个目标
		{
			p_fin = p_fin->next;
		}

		if (array[p_fin->y - 1][p_fin->x] == 0) //下一位置为空位
		{
			array[temp->y][temp->x] = 0;        //蛇尾为空（0）
			array[p_fin->y - 1][p_fin->x] = 1;  //蛇头更新（1）

			head = head->next;                  //链表右移一位
			insert(head, p_fin->x, p_fin->y - 1);   //链表添加新蛇头
		}
		else if (array[p_fin->y - 1][p_fin->x] == 2)//下一位置为食物
		{
			array[p_fin->y - 1][p_fin->x] = 1;      //蛇头更新（1）
			insert(head, p_fin->x, p_fin->y - 1);   //链表添加新蛇头

			//更新食物
			srand((unsigned)time(NULL));
			int food_x = (rand() % (WIDTH - 1 - 1)) + 1;
			int food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
			while (array[food_y][food_x] == 1)
			{
				printf("sdsafd");
				food_x = (rand() % (WIDTH - 1 - 1)) + 1;
				food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
			}
			array[food_y][food_x] = 2;
		}
		else                    //下一位置为撞墙或撞自身
		{
			printf("failed\n");
		}

		g_direc = up;   //更新方向
	}
}
//移动：向下
void move_down()
{
	if (g_direc != up)
	{
		struct node *temp = head;
		temp = temp->next;      //蛇尾
		struct node *p_fin = head;
		while (p_fin->next)      //蛇头下一个目标
		{
			p_fin = p_fin->next;
		}

		if (array[p_fin->y + 1][p_fin->x] == 0)   //空位
		{
			array[temp->y][temp->x] = 0;
			array[p_fin->y + 1][p_fin->x] = 1;

			head = head->next;
			insert(head, p_fin->x, p_fin->y + 1);
		}
		else if (array[p_fin->y + 1][p_fin->x] == 2)//食物
		{
			array[p_fin->y + 1][p_fin->x] = 1;
			insert(head, p_fin->x, p_fin->y + 1);

			//更新食物
			srand((unsigned)time(NULL));
			int food_x = (rand() % (WIDTH - 1 - 1)) + 1;
			int food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
			while (array[food_y][food_x] == 1)
			{
				printf("sdsafd");
				food_x = (rand() % (WIDTH - 1 - 1)) + 1;
				food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
			}
			array[food_y][food_x] = 2;
		}
		else                    //撞墙或撞自身
		{
			printf("failed\n");
		}

		g_direc = down;
	}
}
//移动：向右
void move_right()
{
	if (g_direc != left)
	{
		struct node *temp = head;
		temp = temp->next;      //蛇尾
		struct node *p_fin = head;
		while (p_fin->next)      //蛇头下一个目标
		{
			p_fin = p_fin->next;
		}

		if (array[p_fin->y][p_fin->x + 1] == 0)   //空位
		{
			array[temp->y][temp->x] = 0;
			array[p_fin->y][p_fin->x + 1] = 1;

			head = head->next;
			insert(head, p_fin->x + 1, p_fin->y);
		}
		else if (array[p_fin->y][p_fin->x + 1] == 2)//食物
		{
			array[p_fin->y][p_fin->x + 1] = 1;
			insert(head, p_fin->x + 1, p_fin->y);

			//更新食物
			srand((unsigned)time(NULL));
			int food_x = (rand() % (WIDTH - 1 - 1)) + 1;
			int food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
			while (array[food_y][food_x] == 1)
			{
				printf("sdsafd");
				food_x = (rand() % (WIDTH - 1 - 1)) + 1;
				food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
			}
			array[food_y][food_x] = 2;
		}
		else                    //撞墙或撞自身
		{
			printf("failed\n");
		}

		g_direc = right;
	}
}
//移动：向左
void move_left()
{
	if (g_direc != right)
	{
		struct node *temp = head;
		temp = temp->next;      //蛇尾
		struct node *p_fin = head;
		while (p_fin->next)      //蛇头下一个目标
		{
			p_fin = p_fin->next;
		}

		if (array[p_fin->y][p_fin->x - 1] == 0)   //空位
		{
			array[temp->y][temp->x] = 0;
			array[p_fin->y][p_fin->x - 1] = 1;

			head = head->next;
			insert(head, p_fin->x - 1, p_fin->y);
		}
		else if (array[p_fin->y][p_fin->x - 1] == 2)//食物
		{
			array[p_fin->y][p_fin->x - 1] = 1;
			insert(head, p_fin->x - 1, p_fin->y);

			//更新食物
			srand((unsigned)time(NULL));
			int food_x = (rand() % (WIDTH - 1 - 1)) + 1;
			int food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
			while (array[food_y][food_x] == 1)
			{
				printf("sdsafd");
				food_x = (rand() % (WIDTH - 1 - 1)) + 1;
				food_y = (rand() % (HEIGHT - 1 - 1)) + 1;
			}
			array[food_y][food_x] = 2;
		}
		else                    //撞墙或撞自身
		{
			printf("failed\n");
		}

		g_direc = left;
	}
}
//交互操作
void get_key()
{
	char key = 0;
	while (1)
	{
		key = getch();  //获取键值（无需回车即可输入）
		switch (key)
		{
		case 'w': move_up();    update(); break;
		case 'a': move_left();  update(); break;
		case 's': move_down();  update(); break;
		case 'd': move_right(); update(); break;
		}
	}
}
int main()
{
	init();     //初始化
	get_key();  //获取按键值

	return 0;
}
#endif