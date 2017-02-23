/*
    DJ.W 2012.7.23
*/

/*����memo��ע������:
  һ�κ�������ֻ�ܵõ�һ��memo ��Ϊ���ڵ�ǰ����������Ӧ�����ֻ����һ�����Ż�ѡ��
  Ψһ��memo�����ڸú����ĸ������ش�

  �˴η���: ����һ��maxval���������� ������maxmemo[i-1][remain]��maxmemo[i-1][remain-weight[i]]
  ΪʲôӦ����i������i-1 i���Ǵ˴κ�����Ӧ�����Ž� iȡ���ڴ˴κ������� �����ǵõ�memo���õ��¼�����
  ͬ��remain-weight[i] ���¼��������Ӧ�����Ž� Ӧ�����¼������������Ӧ����Ŀ�ʼ�Ͷ�memo�����˼��

  ֮���Բ��ں����е�ÿһ������������ʱ��������memo���м�� ����Ϊһ�����������һ�����Ž� ��ÿ�����������ж�
  �������Ƿ��Ѿ��������һ���������ĵݹ�ģʽ ����ڵ����¼�������ÿһ�������м�� ��ʹ�����Ե�ӷ���Ѷ�

*/
#include<iostream>
using namespace std;

#define N 20
#define M 100
#define max(a, b) (a>b?a:b)

//============================================�ݹ��==============================================================================//
/*
int count = 0;
int fast_maxval(int weight[], int value[], int i, int remain, int maxmemo[N][M+1], int result[N][M+1])
{

	
    count++;

	if(maxmemo[i][remain] != -1)
		return maxmemo[i][remain];
    
	if(i==0)
	{
		if(weight[i] <= remain)
		{
			maxmemo[i][remain] = value[i];
			result[i][remain] = 1;
			return maxmemo[i][remain];
		}
		else
		{
			maxmemo[i][remain] = 0;
			result[i][remain] = 0;
			return 0;
		}
	}
	int with_i;

	int without_i = fast_maxval(weight, value, i-1, remain, maxmemo, result);
	if(weight[i] > remain)
	{
		maxmemo[i][remain] = without_i;
		result[i][remain] = 0;
		return without_i;
	}
	else
			with_i = value[i] + fast_maxval(weight, value, i-1, remain-weight[i], maxmemo, result);

	if(with_i > without_i)
	{
		maxmemo[i][remain] =  with_i;
		result[i][remain] = 1;
	}
	else
	{
		maxmemo[i][remain] =  without_i;
		result[i][remain] = 0;
	}
	return maxmemo[i][remain];
}

void Display(int result[N][M+1], int i, int remain, int weight[N])
{

	if(i>0)
	{
		Display(result, i-1, remain-result[i][remain]*weight[i], weight);
	}
	cout<<result[i][remain];
}


int maxval(int weight[], int value[], int i, int remain)
{
	//Ϊʲô��M+1����Ʒ�����ʣ��������Ϊ�������� Ϊ�˱������ ���˽�����������Ϊ��0��ʼ
	int maxmemo[N][M+1];
    int result[N][M+1];
	for(int a=0; a<N; a++)
		for(int b=0; b<M+1; b++)
			maxmemo[a][b] = -1;
	int maxvalue = fast_maxval(weight, value, i, remain, maxmemo, result);
	cout<<"ѡȡ����:";
	Display(result, N-1, M, weight);
	cout<<endl;
	return maxvalue;
}
*/

//============================================��ͨ��===============================================================================//
/*int count;

int maxval(int weight[], int value[], int i, int remain)
{
    count++;
	if(i==0)
	{
		if(weight[i] <= remain)
			return value[i];
		else
			return 0;
	}

	int without_i = maxval(weight, value, i-1, remain);
	
	int with_i;
	if(weight[i] > remain)
		return without_i;
	else
		with_i = value[i] + maxval(weight, value, i-1, remain-weight[i]);
	return with_i > without_i ? with_i:without_i;
}
*/

//==================================================������=========================================================================//
/*
	��������Ҫ���������������� ��α�֤һ����Ʒֻ��װ��һ�� ������������� ���ǽ�����Ʒ�ĵ������ڶ������ĵ��������
	���������� ����Ҫ�������Դ�С���� �������Ա���һ����Ʒ������������Ž��б�װ���Ժ� �����ϼ���������Ž��б�װ��
	�������γ��˵�����1

    ������2�͵�����1��Ҫ�����㲻ͬ: 
	1.�ڵ�����2�� j��û�е�������������� ������Ϊ������2��memo��һ����ά���� ��ͬʱ��¼�˵�ǰ����������Ʒ�� ÿװ��һ����Ʒʱ
		��ǰ��ֵ������memo[i-1][j-wei[i]]+value[i]���� ����Ʒi��������memo[i-1][]�г��� �Ӷ���֤����Ʒiֻ��װ��һ�� ��������ʹ��
		������2 ���Խ�����Ʒ�ĵ����ŵ���� ������ʹ�øô���ľֲ��Ա�úܲ� Ч�ʱ��

	2.������2�� ��Ʒiû��װ��ʱ ��ǰ��ֵ��memo[i][j] = memo[i-1][j] ���ڵ�����1�� û��memo[j] = memo[j-1] ������Ϊ�ڵ�����1��
	    û�м�¼��Ʒ��� ��ômemo[j]�����ڸ���i ������Ϊĳһ��iûװ ������ǰ���i�ҵ����Ž� Ҳ������ô�� ��Ʒiװ����ʱ memo[j]
		û�б仯 ��Ĭ��ʹ����ǰ��i�����������Ž� ��Ϊi����С�������
		���ڵ�����2 ����¼��i ������ǰ������ĸ�������ʽ �����Ʒiûװ memo[i][j]Ĭ���Զ�����memo[i-1][j]�� ����Ҫ��ʾ��ֵ

 
   
*/

void Display(int scheme[N][M+1], int i, int remain, int weight[N])
{

	if(i>0)
	{
		Display(scheme, i-1, remain-scheme[i][remain]*weight[i], weight);
	}
	cout<<scheme[i][remain];
}


int maxval(int wei[N], int val[N])
{
 //==========������1
 /*
	int memo[M+1];
	int scheme[N][M+1];

	for(int i=0; i<M+1; i++)
		memo[i] = 0;

	for(i=0; i<N; i++)
	{
		//����Ҫ�����Ƿ�װ���µ����� ��˽�ѭ����Ϊ����
		//��װ��
		for(int j=M; j>=wei[i]; j--)
		{
			if(memo[j-wei[i]]+val[i] > memo[j])
			{
				memo[j] = memo[j-wei[i]]+val[i];
				scheme[i][j] = 1;
			}
			else
				scheme[i][j] = 0;
		}
		//����װ��
		for(; j>0; j--)
			scheme[i][j] = 0;
	}
	int result = memo[M];

	Display(scheme, N-1, M, wei);
	cout<<endl;
	return result;

*/

//==========������2	

	int memo[N][M+1];
	int scheme[N][M+1];

    for(int i=0; i<N; i++)
		for(int j=0; j<M+1; j++)
			memo[i][j] = 0;
	
	//���ȴ���߽� ������memo[i-1]�ĵ��� ������i=0ʱ���õ�memo[-1][]
	for(int j=0; j<=M; j++)
	{
		if(j<wei[0])
			scheme[0][j] = 0;
		else
		{
			memo[0][j] = val[0];
			scheme[0][j] = 1;
		}
	}

	for(i=1; i<N; i++)
		for(int j=1; j<=M; j++)
		{
			if(j<wei[i])
			{
				memo[i][j] = memo[i-1][j];
				scheme[i][j] = 0;
				continue;
			}
			if(memo[i-1][j] >= memo[i-1][j-wei[i]]+val[i])
			{
				memo[i][j] = memo[i-1][j];
				scheme[i][j] = 0;
			}
			else
			{
				memo[i][j] = memo[i-1][j-wei[i]] + val[i];
				scheme[i][j] = 1;
			}
			
		}
	Display(scheme, N-1, M, wei);
	cout<<endl;
    return memo[N-1][M];

}


int main()
{
	int value[N] = {3, 15, 26, 14, 19, 44, 122, 60, 77, 21, 30, 11, 41, 32, 9, 12, 14, 54, 43, 22};
	int weight[N] = {1, 6, 13, 5, 9, 22, 50, 18, 33, 10, 12, 4, 19, 15, 3, 5, 5, 25, 20, 9};
	cout<<"���������װ��ֵ��: "<<maxval(weight, value)<<endl;
	cout<<"���ô���: "<<count<<endl;
	return 0;//267 211012 2223
	         //458
}