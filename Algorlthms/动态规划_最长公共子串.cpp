/*
    DJ.W 2012.7.25
	���빦��:
	  ���������ַ���str1, str2 �ҳ����ǵ���󹫹��Ӵ�
	��ע:
	     �����������memo��·������ʱ,��ҪŪ���ά������Ҫ�����ά��
		 �ڱ�������memo��lcs�������˱��ַ������ȶ�һ��ά�� ������Ϊmemo��lcs��¼���ǵ�ǰ����������
		 �˴���Ϊ�ɺ���ǰ���������ַ���ʱ �����ַ����ĳ��� ���ַ������Ⱥ��ַ����±����������
		 �����֮�������ַ�����Ҫ��һ

         ���о������ͨ��lcs��¼����������ַ��� ���ڶ���ÿ��������������i��j�Ĵ�С ��˷���һ����ά����lcs[N1+1][N2+1]
		 ���޿ɺ�ǵ� ��Щ��ͬ�ڱ���������� �����ÿ��������������������� �����������ÿ����Ʒֻ��װ�Ͳ�װ�������
		 ��˺������ҵ�����·�� ����������������� ���ǿ���֪�� ֻ����str1[i]==str2[j]ʱ ����һ�����
		 �����������������·�߸��ٿ��ñ��ʵ�� �������'-' '\\' '|' �������� ��Ӧ������ѡ��ı���·�� ���ͨ��Display���

         ��ʵҲ���Բ�ͨ��lcs�������Ӵ� ֱ����β��ͷ�Ƚ�str1, str2 ������ ��� ������� ȥmemo[i-1][j] memo[i][j-1]
		 �г���һ������������  ��ҪO(N1+N2)ʱ��
*/
#include<iostream>
using namespace std;

#define N1 7
#define N2 6

#define max(a, b) (a>b?a:b)


int count;
/*int Find(char* str1, int n1, char* str2, int n2)
{
    count++;

	int res1, res2;
	if(n1==0 || n2 ==0)
		return 0;

	if(str1[n1-1] == str2[n2-1])
	{
		return 1 + Find(str1, n1-1, str2, n2-1);
	}
	else
	{
		res1 = Find(str1, n1, str2, n2-1);
		res2 = Find(str1, n1-1, str2, n2);
		if(res1>res2)
			return res1;
		else
			return res2;
	}
}
*/
//===============================================�ݹ��=============================================================================//
/*
int find_fast(char* str1, int i, char* str2, int j, int memo[N1+1][N2+1], char lcs[N1+1][N2+1])
{
    count++;

	if(memo[i][j] != -1)
		return memo[i][j];

	int res1, res2;
	if(i==0 || j ==0)
	{
		memo[i][j] = 0;
		return 0;
	}

	if(str1[i-1] == str2[j-1])
	{
		memo[i][j]  = 1 + find_fast(str1, i-1, str2, j-1, memo, lcs);
        lcs[i][j]   = '\\';
		return memo[i][j];
	}
	else
	{
		res1 = find_fast(str1, i, str2, j-1, memo, lcs);
		res2 = find_fast(str1, i-1, str2, j, memo, lcs);
		if(res1>res2)
		{
			memo[i][j] = res1;
			lcs[i][j] = '|';
			return res1;
		}
		else
		{
			memo[i][j] = res2;
			lcs[i][j] = '-';
			return res2;
		}
	}
}

void Display(char lcs[N1+1][N2+1], int i, int j, char* str1)
{
	if(i == 0 || j == 0)
		return;
	if(lcs[i][j] == '-')
		Display(lcs, i-1, j, str1);
	else if(lcs[i][j] == '|')
		Display(lcs, i, j-1, str1);
	else
	{
		Display(lcs, i-1, j-1, str1);
		cout<<str1[i-1];
    }
}

int Find(char* str1, int n1, char* str2, int n2)
{
	char lcs[N1+1][N2+1];
	int memo[N1+1][N2+1];
	for(int i=0; i<N1+1; i++)
		for(int j=0; j<N2+1; j++)
		{
			memo[i][j] = -1;
			lcs[i][j] = ' ';
		}
	for(i=1; i<N1+1; i++)
		lcs[i][0] = str1[i-1];
	for(int j=1; j<N2+1; j++)
		lcs[0][j] = str2[j-1];

	int len = find_fast(str1, n1, str2, n2, memo, lcs);

	for(i=0; i<N1+1; i++)
	{
		for(j=0; j<N2+1; j++)
		{
			cout<<lcs[i][j]<<" ";
		}
		cout<<endl;
	}

    
	Display(lcs, N1, N2, str1);
	cout<<endl;
    return len;
}
*/
//============================================================������================================================================//

void Display(char lcs[N1+1][N2+1], int i, int j, char* str1)
{
	if(i == 0 || j == 0)
		return;
	if(lcs[i][j] == '-')
		Display(lcs, i-1, j, str1);
	else if(lcs[i][j] == '|')
		Display(lcs, i, j-1, str1);
	else
	{
		Display(lcs, i-1, j-1, str1);
		cout<<str1[i-1];
    }
}

int Find(char* str1, int n1, char* str2, int n2)
{
	//Ϊ�˽ϺõĴ���߽����� ���ｫstr��memo�д�1��ʼ
    int memo[N1+1][N2+1];
	char lcs[N1+1][N2+1];
	for(int i=0; i<N1+1; i++)
		memo[i][0] = 0;
	for(int j=0; j<N2+1; j++)
		memo[0][j] = 0;

	for(i=1; i<N1+1; i++)
		for(int j=1; j<N2+1; j++)
		{
			if(str1[i-1] == str2[j-1])
			{
				memo[i][j] = 1 + memo[i-1][j-1];
				lcs[i][j] = '\\';
			}
			else if(memo[i-1][j]>memo[i][j-1])
			{
				memo[i][j] = memo[i-1][j];
				lcs[i][j] = '-';
			}
			else
			{
				memo[i][j] = memo[i][j-1];
				lcs[i][j] = '|';
			}
		}
		Display(lcs, N1, N2, str1);
		cout<<endl;
	return memo[N1][N2];
}
int main()
{
	char* str1 = "ABCBDAB";
	char* str2 = "BDCABA";
	cout<<"������Ӵ���: "<<Find(str1, N1, str2, N2)<<endl;
	cout<<"���ô���: "<<count<<endl;
	return 0;
}