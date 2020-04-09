#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define N 110 
using namespace std;
int vita [30];//用于储存最多25种维生素各自所需要的数量
int feed[20][30];//用于记录每种饲料对应的储存的每种维生素的含量
int v, g,num,min=15;//v用于记录所需维生素的种类， g用于记录投入饲料的种数, num 用于记录一次搜索过程中的层数, min记录输出组合中最小的饲料种数，初始化为15
int rec[10000000];//用于记录一次搜索过程中到达过的节点
int bestans[20];//用于记录一次
int vitagood[30];
struct cows
{
	
	int good[15];//用于记录满足要求的组合
}cow[15];
void initial()
{
	for (int i = 0; i < 30; i++)
	{
		vitagood[i] = 0;
	}
	/*rec[1] = 1*/;//初始化搜索中队列
}
void read()//输入数据
{
	cin >> v;
	for (int i = 0; i <= v - 1; i++)
	{
		cin >> vita[i + 1];
	}
	cin >> g;
	for (int i = 0; i <= g - 1; i++)
	{
		for (int j = 0; j <= v - 1; j++)
		{
			cin >> feed[i + 1][j + 1];
		}
	}
	
}
bool judge(int num)//输入当前搜索层使用的饲料的个数
{
	
	for (int i = 1; i <= v ; i++)
	{
		
			vitagood[i] += feed[rec[num]][i];
			
		
		
	}
	for (int i = 1; i <= v; i++)
	{
		if (vitagood[i] < vita[i])
		{
			return false;
		}
	}
	return true;
	
}
void dfs(int x, int num)//x表示当前选择的是什么饲料，num表示选择多少饲料
{
	
	if (x <= g)
	{
		rec[num] = x;
		if (judge(num))//判断是否满足第一输出条件：各种维生素全部达标
		{

			
			if (num < min)
			{
				/*for (int i = 1; i <= num; i++)
				{
					cout << bestans[i] << " ";
				}
				cout << endl;*/
				min = num;//置换搜索过程中找到的最优解
				for (int i = 1; i <= num; i++)
				{
					bestans[i] = rec[i];//替换最佳组合，由于是饲料编号不断变大进行搜索，因此天然是字典序最小
				}
				for (int i = 1; i <= v; i++)//回溯Vitagood数组
				{
					vitagood[i] -= feed[x][i];
				}
				return;//直接跳出当前递归
			}


		}
		//记录使用的这种饲料的编号
		dfs(x + 1, num + 1);//进入下一层搜索（如果使用当前饲料）
		rec[num] = 0;//回溯
		for (int i = 1; i <= v; i++)//回溯Vitagood数组
		{
			vitagood[i] -= feed[x][i];
		}
		dfs(x + 1, num);//进入下一层搜索（如果不使用当前饲料）
	}
	else
	{
		return;
	}

	

}

void printout()//输出
{
	cout << g;
	for (int i = 0; i <= g - 1; i++)
	{
		cout << endl;
		for (int j = 0; j <= v - 1; j++)
		{
			cout << feed[i + 1][j + 1];
		}

	}
	cout << endl;
	cout << v;
	for (int i = 0; i <= v - 1; i++)
	{
		cout << vita[i + 1];
	}
}


int main()
{
	read();
	initial();
	dfs(1,1);
	cout << min <<" ";
	for (int i = 1; i <= min; i++)
	{
		cout << bestans[i] <<" ";
	}

	return 0;
}