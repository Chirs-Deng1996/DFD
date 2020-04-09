// Luogu algorithm exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define N 110 
using namespace std;
int m, n, count1;//矩阵行数 列数 static

//int static N = 10005;
//int used[][110] ;
int sample [110][110] ;
void initial()//初始化获得输入
{

	cin >> m >> n;
	count1 = 0;
	//used = new int[m+2,n+2];
	//sample = new int[m + 2, n + 2];

	for (int i = 0; i <= m-1; i++)
	{
		/*cout << endl;*/
		for (int j = 0; j <= n-1; j++)
		{
			scanf("%1d", &sample[i+1][j+1]);
			/*cout << sample[i + 1][j + 1];*/

		}
	}

}
void search1(int x, int y, int num)//每到达一个数字细胞就进行搜索
{


	sample[x][y] = 0;//清除已经到达的点
	if (sample[x][y + 1] != 0)//在此点上对4个方向分别进行深搜（如果符合条件）
	{

		search1(x, y + 1, num + 1);
	}
	if (sample[x + 1][y] != 0)
	{

		search1(x + 1, y, num + 1);
	}
	if (sample[x][y - 1] != 0)
	{

		search1(x, y - 1, num + 1);
	}

	if (sample[x - 1][y] != 0)
	{

		search1(x - 1, y, num + 1);
	}
	if (num == 1)
	{
		++count1;
		/*for (int i = 1; i <= m+1; i++)
		{
			cout << endl;
		    for (int j = 1; j <= n+1; j++)
		    {



		           cout<<sample[i,j];





		    }

		}
		cout<<endl;*/

	}

}
void dfs(int x, int y, int num)//初始化时给not传1
{
	//if (sample[x, y] != 0)
	//{
	//    search1(x, y, num);
	//}
	//else
	//{
	for (int i = x; i <= m; i++)
	{

		for (int j = y; j <= n; j++)
		{

			if (sample[i][j] != 0)
			{
				/*cout << sample[i][j];*/
				search1(i, j, num);
				
			}


		}

	}
	//}

}

int  main()
{
	
	initial();
	dfs(1, 1, 1);
	cout << count1;
	return 0;
}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
