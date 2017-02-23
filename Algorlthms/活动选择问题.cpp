/*
    DJ.W 2012.8.3
	��������: ���㷨���ۡ�P223
*/
#include<iostream>
using namespace std;

#define N 14
#define M 11

typedef struct tagActiv
{
	int start;
	int end;
} Activ, *PActiv;

//=====================================��̬�滮���ݹ��============================================================================//
/*
   ע�����ͨ��������������������  ���������ڻ��ֹʱ������ ����ò���i j����С�ݹ���ҷ�Χ ���Ч�� �������� ��Ӧ�д˲���
   ��θ���������·�� ���ڶ�̬�滮����������ص��� ������Ž���ٱ����ܹ������������������ ���ﰴ��k̽����˳�������ٻ���
*/
/*
int count;
int Dynamic_Select(int start, int end, PActiv pActiv, int i, int j, int memo[N+1][N+1], int res[N+1][N+1])
{
	count++;
	if(memo[start][end] != -1)
		return memo[start][end];

	int temp, temp_k=-1;
	int numAct = 0;
	//ע����ʱֵ�ĳ�ʼ�� ��Ϊ�п�����i!=j�������û�л������������ѭ���ڲ�����ִ�� ����Щ��ʱֵ��ѭ���ⲿ�õ���
    while(pActiv[j].end>end)
		j--;
	//ȥ������Ҫ��̽��(��Ϊ���ֹʱ������)
	for(int k=i; k<=j; k++)
	{
		if(pActiv[k].start>=start)
		//��ͬ�ھ�����˵�̽�� �����i!=jҲ����ʹ�ݹ���ֹ
		{
			temp = 1 + Dynamic_Select(start, pActiv[k].start, pActiv, i, k-1, memo, res)
				+ Dynamic_Select(pActiv[k].end, end, pActiv, k+1, j, memo, res);

			if(temp > numAct)
			{
				numAct = temp;
				temp_k = k;
			}
		}
	}
	memo[start][end] = numAct;
	res[start][end] = temp_k;
	return numAct;
}

void Display(int res[N+1][N+1], int i, int j, PActiv pAc)
{
	int k = res[i][j];
	if(k == -1)
		return;
	Display(res, i, pAc[k].start, pAc);
	cout<<"A"<<k<<" ";
	Display(res, pAc[k].end, j, pAc);
}
void Dynamic_Select_memo(int start, int end, PActiv pActiv, int first_activ, int last_activ)
{
	int memo[N+1][N+1];
	int res[N+1][N+1];
	//��ʼ��res��Ϊ�˷���Display�еĵݹ���ֹ ��Ϊ�ڸ������� i!=jҲ����ʹ�ݹ���ֹ ��˿�������ֵ�����

	for(int i=0; i<N+1; i++)
		for(int j=0; j<N+1; j++)
		{
			memo[i][j] = -1;
			res[i][j] = -1;
		}
	

	cout<<"�����ݻ��ĿΪ:"<<Dynamic_Select(start, end, pActiv, first_activ, last_activ, memo, res)<<endl;
	cout<<"ѡ�еĻ�����:"<<endl;
	Display(res, 0, N, pActiv);
}
*/

//======================================��̬�滮��������============================================================================//
//���㷨������������Ч
/*
    ���ͨ������������չ ���������ӽṹ ���𲽻���Ϊ����������Ĺ����� �;���������� ���memo�ļ�¼��ʽ 
	    ���ó�������չ�ķ�ʽ����չ������
	�ڶ�memo���м���ʱ Ҫ��֤��ÿһ��������memo����һ��ȷ����ֵ 
	    ������ �������i jû���ʺϵĻ ��ômemo����ͨ��temp��ֵ ��������Ĭ��ֵ ���memoĬ��ֵΪ-1������ֵ ����Ҫ��temp�жϲ����¸�ֵ
	�ڵݹ�תΪ����ʱ ��ø��ݵݹ��memo��ʽ��������ķֽ���ʽ���趨Ƕ��ѭ��
*/
/*
void Display(int res[N+1][N+1], int i, int j, PActiv pAc)
{
	int k = res[i][j];
	if(k == -1)
		return;
	Display(res, i, pAc[k].start, pAc);
	cout<<"A"<<k<<" ";
	Display(res, pAc[k].end, j, pAc);
}

void Dynamic_Select_memo(int start, int end, PActiv pActiv, int first_activ, int last_activ)
{
	int memo[N+1][N+1];
	int res[N+1][N+1];
	for(int i=0; i<N+1; i++)
		for(int j=0; j<N+1; j++)
		{
				memo[i][j] = 0;
			    res[i][j] = -1;
		}
	int j, temp = 0;
	for(int len=1; len<=end-start; len++)
		for(int i=start; i<end-len+1; i++)
		{
			j = i+len;
			for(int k=first_activ; k<=last_activ; k++)
			//���ڴ�������ѭ��֮�� ��������ݽ���ʱ������Ļ���н��������� ��˲��ñ���
			{
				if(pActiv[k].start>=i && pActiv[k].end<=j)
				{
					temp = 1+memo[i][pActiv[k].start]+memo[pActiv[k].end][j];
					if(temp>memo[i][j])
					{
						memo[i][j] = temp;
						res[i][j] = k;
					}
				}
			}
		}
	cout<<"numAct = "<<memo[0][N]<<endl;
	Display(res, 0, N, pActiv);
	cout<<endl;
}
*/
//===============================================̰���㷨���ݹ��===================================================================//
/*
void Greedy_Select(int start, int end, PActiv pAc, int f_ac, int e_ac)
{
	while( (pAc[f_ac].start<start || pAc[f_ac].end>end) && f_ac<=e_ac)
		f_ac++;
	if(f_ac <= e_ac)
	{
		cout<<"A"<<f_ac<<" ";
		Greedy_Select(pAc[f_ac].end, end, pAc, f_ac, e_ac);
	}
}
*/
//===============================================̰���㷨��������===================================================================//
/*
void Greedy_Select(int start, int end, PActiv pAc, int f_ac, int e_ac)
{
	for(int i=f_ac; i<=e_ac; i++)
	{
		if(pAc[i].start>=start && pAc[i].end<=end)
		{
			start = pAc[i].end;
			cout<<"A"<<i<<" ";
		}
	}
}
*/
int main()
{
	Activ ac[M] = {{1,4}, {3,5}, {0,6}, {5,7}, {3,8}, {5,9}, {6,10}, {8,11}, {8,12}, {2,13}, {12,N}};
	//Dynamic_Select_memo(0, N, ac, 0, 10);
	Greedy_Select(0, N, ac, 0, 10);
	return 0;
}