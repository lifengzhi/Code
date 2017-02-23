/*
    DJ.W 2012.7.22

*/

#include<iostream>
using namespace std;

#define N 6
#define MAX_INT 2147483647

//======================================================������====================================================================//
/*void Metric_chan_Order(int p[N+1], int memo[N][N], int s[N][N])
{
	//memo[i][j]���ڱ��� Ai--Aj��˵���С����
	//s[i][j]����Ai--Aj��С���۵Ļ��ֵ�
	for(int i=0; i<N; i++)
		memo[i][i] = 0;

	int j, temp;
	for(int len=2; len<=N; len++)
		for(i=0; i<N-len+1; i++)
		{
			//ע���±� m��s����0��ʼ ��A[i]��άΪP[i] P[i+1]
			j = i+len-1;
			memo[i][j] = MAX_INT;
			//k�ĵ����������i j������һ�����ܼ���len=2�����
            for(int k=i; k<j; k++)
			{
				temp = memo[i][k] + memo[k+1][j] + p[i]*p[k+1]*p[j+1];
				if(temp < memo[i][j])
				{
					memo[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
}

void Print(int s[N][N], int i, int j)
{
	if(i==j)
		cout<<"A"<<i;
	else 
	{
		cout<<"(";
		Print(s, i, s[i][j]);
		Print(s, s[i][j]+1, j);
		cout<<")";
	}
}

void Metric_chan(int p[N+1])
{
	int memo[N][N];
	int s[N][N];
	Metric_chan_Order(p, memo, s);
	cout<<"the least cost : "<<memo[0][N-1]<<endl;
	Print(s, 0, N-1);
}
*/

//=================================================�ݹ��========================================================================//

int count;
int Metric_chan_fast(int p[N+1], int i, int j, int memo[N][N], int s[N][N])
{
	if(memo[i][j] != MAX_INT)
	     return memo[i][j];
	
	count++;
	if(i == j)
	{
		memo[i][i] = 0;
		return 0;
	}

	int min_cost = MAX_INT;
	int temp, temp_k;
	for(int k=i; k<j; k++)
	{
		temp = (Metric_chan_fast(p, i, k, memo, s) + Metric_chan_fast(p, k+1, j, memo, s) + p[i]*p[k+1]*p[j+1]);
		if(temp < min_cost)
		{
            temp_k = k;
			min_cost = temp;
		}
	}
	s[i][j] = temp_k;
	memo[i][j] = min_cost;
	return min_cost;
}

void Print(int s[N][N], int i, int j)
{
	if(i==j)
		cout<<"A"<<i;
	else 
	{
		cout<<"(";
		Print(s, i, s[i][j]);
		Print(s, s[i][j]+1, j);
		cout<<")";
	}
}

void Metric_chan(int p[N+1])
{
	int memo[N][N];
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			memo[i][j] = MAX_INT;
	int s[N][N];
	cout<< "min_cost = " << Metric_chan_fast(p, 0, N-1, memo, s)<<endl;
	cout<< "count = "<<count<<endl;
	cout<< "the best scheme:";
	Print(s, 0, N-1);
	cout<<endl;
}

//--------------------------------------------------------------------------------------------------------------------------------//

int main()
{
	int p[N+1] = {5, 10, 3, 12, 5, 50, 6};
	Metric_chan(p);
	return 0;
}