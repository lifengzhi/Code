/*
	DJ.W 2012.7.28
	�������������㷨���ۡ�P212
		����������� �������Ų��Ҷ������м�ֵ����������ֽ�� ���Ժ�����Ū��
	��ʵ�����ֻ��һ�ֳ�ν ���Խ��俴����ͨҶ�ӽ��������  ����ڵݹ��Ͷ���
	������Output_tree��ʱ�����i i-1 ��Ϊ��ֹ���� �����ڼ�ֵ������ȥ�� Ϊʲô
	����i==j���ؼ�ֵ���� ��ʵ��ֵ�����Ѿ���w[i][j]ͳ����:
	         w[i][i] = 2 * (pNode[i-1] + pNode[i]) + pKey[i];

    �ڵݹ���� Ҳ���Բ���ʼ��memo ֱ������ֹ�������������memo��ֵ

    
*/
#include<iostream>
using namespace std;

#define N 5
#define MAX_EP 123456789.0f

//===================================================������========================================================================//
/*
void Output_tree(int root[N+1][N+1], int i, int j)
{
	if(i-1 == j)
	{
		cout<<"d"<<j<<endl;
		return;
	}
	if(i == j)
		cout<<"k"<<i<<endl;
	else cout<<"k"<<root[i][j]<<endl;

	cout<<"k"<<root[i][j]<<"������Ϊ:";
	Output_tree(root, i, root[i][j]-1);
	
	cout<<"k"<<root[i][j]<<"���Һ���Ϊ:";
	Output_tree(root, root[i][j]+1, j);

}
//����Ҫ�õ�e[i][i-1]������Ҷ�ӽڵ� ��˽���Ч�ļ�ֵ����pKey[1...N]
void optimal_tree(float pKey[N+1], float pNode[N+1])
{
	float e[N+2][N+1];
	float w[N+2][N+1];
	int root[N+1][N+1];
	for(int i=1; i<N+2; i++)
	{
		//��ʼ��memo
		e[i][i-1] = pNode[i-1];
		w[i][i-1] = pNode[i-1];
	}

	for(i=0; i<N+1; i++)
		for(int j=0; j<N+1; j++)
			root[i][j] = -1;

	int j;
	float temp;
	for(int len=1; len<=N; len++)//���ȹ�ģ
		for(int i=1; i<N-len+2; i++)//��ʼ��
		{
			j = i+len-1;//������
			e[i][j] = MAX_EP;
			w[i][j] = w[i][j-1]+pKey[j]+pNode[j];
			for(int k=i; k<=j; k++)
			{
				temp = e[i][k-1] + e[k+1][j] + w[i][j];
				if(temp < e[i][j])
				{
					e[i][j] = temp;
					root[i][j] = k;
				}
			}
		}
	cout<<"���Ŷ���������ֵ: "<<e[1][N]<<endl;
	Output_tree(root, 1, N);
}
*/
//=============================================�ݹ��===============================================================================//

int count;
float optimal_tree_memo(float pKey[N+1], float pNode[N+1], int i, int j, 
						float memo[N+1][N+1], float w[N+2][N+1], int root[N+1][N+1])
{
	count++;
	//�˴�memo�б������͵ݹ���ֹ�������� ��Ϊmemo[i][i-1]�г�ֵ i i-1��Ϊ�����������
	if(memo[i][j] != MAX_EP)
		return memo[i][j];

	float temp;
	for(int k=i; k<=j; k++)
	{
		temp = optimal_tree_memo(pKey, pNode, i, k-1, memo, w, root)
			+ optimal_tree_memo(pKey, pNode, k+1, j, memo, w, root) + w[i][j];
		if(temp < memo[i][j])
		{
			root[i][j] = k;
			memo[i][j] = temp;
		}
	}
	return memo[i][j];
}

void Output_tree(int root[N+1][N+1], int i, int j)
{
	if(i-1 == j)
	{
		cout<<"d"<<j<<endl;
		return;
	}
	if(i == j)
		cout<<"k"<<i<<endl;
	else cout<<"k"<<root[i][j]<<endl;

	cout<<"k"<<root[i][j]<<"������Ϊ:";
	Output_tree(root, i, root[i][j]-1);
	
	cout<<"k"<<root[i][j]<<"���Һ���Ϊ:";
	Output_tree(root, root[i][j]+1, j);

}

void optimal_tree(float pKey[N+1], float pNode[N+1])
{
	float memo[N+1][N+1];
	float w[N+2][N+1];
	int root[N+1][N+1];

	for(int i=0; i<N+1; i++)
		for(int j=0; j<N+1; j++)
			memo[i][j] = MAX_EP;

	for(i=1; i<N+2; i++)
	{
		w[i][i-1] = pNode[i-1];
		memo[i][i-1] = pNode[i-1];
	}

    //ע��j��i��ʼ ����w[i][i-1]��������
	for(i=0; i<N+2; i++)
		for(int j=i; j<N+1; j++)
			w[i][j] = w[i][j-1] + pNode[j] + pKey[j];

	optimal_tree_memo(pKey, pNode, 1, N, memo, w, root);

	cout<<"���Ŷ���������ֵ:"<<memo[1][N]<<endl;
	cout<<"���ô���: "<<count<<endl;
	cout<<"����������: "<<endl;
	Output_tree(root, 1, N);
}


/*
int count;
float optimal_tree_o(float pKey[N+1], float pNode[N+1], int i, int j, float w[N+2][N+1])
{
    count++;
    if(i-1 == j)
		return pNode[i-1];

    float temp;
	float ep = MAX_EP;
	for(int k=i; k<=j; k++)
	{
		temp = optimal_tree_o(pKey, pNode, i, k-1, w) + optimal_tree_o(pKey, pNode, k+1, j, w) + w[i][j];
		if(temp < ep)
			ep = temp;
	}
	return ep;
}

void optimal_tree(float pKey[N+1], float pNode[N+1])
{

	float w[N+2][N+1];

    for(int i=1; i<N+2; i++)
	{
		w[i][i-1] = pNode[i-1];
	}


	for(i=0; i<N+2; i++)
		for(int j=i; j<N+1; j++)
			w[i][j] = w[i][j-1] + pNode[j] + pKey[j];

	
    cout<<"���Ŷ���������ֵ:"<<optimal_tree_o(pKey, pNode, 1, N, w)<<endl;
	cout<<"���ô���: "<<count<<endl;
}
*/

int main()
{
	float pKey[N+1] = {0.0f, 0.15f, 0.10f, 0.05f, 0.10f, 0.20f};
	float pNode[N+1] = {0.05f, 0.10f, 0.05f, 0.05f, 0.05f, 0.10f};
	optimal_tree(pKey, pNode);
	return 0;
}

