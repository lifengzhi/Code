#include<iostream>
#include <fstream.h>

#define MIN_SUM -99999
#define max(a, b) (a>b?a:b)

class NumTrigon
{
public:
	NumTrigon(const char* filename)
	{
		m_triSize = 0;
		m_pTrigon = NULL;
		m_MaxSum = 0;
		GetDateFromFile(filename);
		InitMemo();
	}
	void GetDateFromFile(const char* datefile)
	//���ļ��ж�ȡ���ݵ�m_pTrigon
	{
		ifstream readfile(datefile);
		readfile>>m_triSize;
		m_pTrigon = new int*[m_triSize];
		for(int i=0; i<m_triSize; i++)
			m_pTrigon[i] = new int[m_triSize];

		for(i=0; i<m_triSize; i++)
			for (int j=0; j<=i; j++)
				readfile>>m_pTrigon[j][i];
		readfile.close();

	}
	void InitMemo()
	//����m_triSize��ֵ���䲢��ʼ��MemoΪ��С
	{
		m_pMemo = new int*[m_triSize];
		for(int i=0; i<m_triSize; i++)
			m_pMemo[i] = new int[m_triSize];
		for(i=0; i<m_triSize; i++)
			for(int j=0; j<m_triSize; j++)
				m_pMemo[i][j] = MIN_SUM;
	}
	int GetMaxSum(int i, int j)
	{
		//�ж��������Ž�ļ�¼
		if(m_pMemo[i][j] != MIN_SUM)
			return m_pMemo[i][j];
		
		int n = m_pTrigon[i][j];
		//�ݹ���ֹ���� �������������
		if(j == m_triSize-1)
		{
			m_pMemo[i][j] = n;
			return n;
		}

		//�ݹ���� ���ڷ���ʱ��¼���Ž�
		m_pMemo[i][j] = max(n+GetMaxSum(i, j+1), n+GetMaxSum(i+1, j+1));
		return m_pMemo[i][j];
	}
	void CalcuMaxSum()
	{
		m_MaxSum = GetMaxSum(0,0);
	}
	void CalcuMaxSum_Loop()
	//������
	{
		//��ʼ����ײ�������Memo
		for(int i=0; i<m_triSize; i++)
			m_pMemo[i][m_triSize-1] = m_pTrigon[i][m_triSize-1];

		//����������
		for(int j=m_triSize-2; j>=0; j--)
			for (int i=0; i<=j; i++)
				m_pMemo[i][j] = m_pTrigon[i][j] + max(m_pMemo[i][j+1], m_pMemo[i+1][j+1]);

		m_MaxSum = m_pMemo[0][0];
	}

	void WriteSumToFile(const char* aimfile)
	{
		ofstream writefile(aimfile);
		writefile<<m_MaxSum;
		writefile.close();
	}

	~NumTrigon()
	{
		for(int i=0; i<m_triSize; i++)
		{
			delete m_pTrigon[i];
			delete m_pMemo[i];
		}
		delete m_pTrigon;
		delete m_pMemo;
		
	}
private:
	int m_triSize;
	int** m_pTrigon;
	int m_MaxSum;
	int** m_pMemo;
};

int main()
{
	NumTrigon test("input.txt");
	test.CalcuMaxSum_Loop();
	test.WriteSumToFile("output.txt");
	return 0;
}