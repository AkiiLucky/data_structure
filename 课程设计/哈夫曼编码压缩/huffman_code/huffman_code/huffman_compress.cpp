#include<iostream>
#include "HuffmanTree.h"

using namespace std;

//�ַ�������
struct BufferType
{
	char ch;					//�ַ�
	unsigned int bits;			//ʵ�ʱ�����
};


class HuffmanCompress
{
protected:
	HuffmanTree<char, unsigned long>* pHuffmanTree;
	FILE* infp, * outfp;								//��������ļ�
	BufferType buf;										//�ַ�����

	void Write(unsigned int bit);						//��Ŀ���ļ���д��һ������
	void WriteToOutfp();								//ǿ�н��ַ�����д��Ŀ���ļ�

public:
	HuffmanCompress() {};
	~HuffmanCompress() {};
	void Compress();									//ѹ���㷨
	void DeCompress();									//��ѹ���㷨
	//HuffmanCompress(const HuffmanCompress& copy);		//���ƹ��캯��
	//HuffmanCompress& operator = (const HuffmanCompress& copy);	//���ظ�ֵ�����

};


void HuffmanCompress::Write(unsigned int bit)			
{
	buf.bits++;
	buf.ch = (buf.ch << 1) | bit;						//�� bit ���뵽�����ַ���
	if (buf.bits == 8)									//������������д��Ŀ���ļ�
	{
		fputc(buf.ch, outfp);
		buf.bits = 0;
		buf.ch = 0;
	}
}

void HuffmanCompress::WriteToOutfp()
{
	unsigned int len = buf.bits;
	if (len > 0)	//����ǿգ�������ı��������ӵ� 8���Զ�д��Ŀ���ļ�
	{
		for (unsigned int i = 0; i < 8 - len; i++) Write(0);
	}
}


void HuffmanCompress::Compress()
{
	char infName[256], outfName[256];

	cout << "������Դ�ļ������ļ�С�� 4GB����";
	cin >> infName;
	if ((fopen_s(&infp, infName, "r")) != 0)
	{
		cerr << "��Դ�ļ�ʧ�ܣ�" << endl;
		exit(1);
	}

	fgetc(infp);
	if (feof(infp))
	{
		cerr << "��Դ�ļ���" << endl;
		exit(2);
	}

	cout << "������Ŀ���ļ�����";
	cin >> outfName;
	if ((fopen_s(&outfp,outfName, "w")) != 0)
	{
		cerr << "��Ŀ���ļ�ʧ�ܣ�" << endl;
		exit(3);
	}

	cout << "���ڴ������Ժ�..." << endl;

	const unsigned long n = 256;				//�ַ�����
	char ch[256];								//�ַ�����
	unsigned long w[256];						//�ַ�����Ƶ�ȣ�Ȩ��
	unsigned long i, size = 0;
	char cha;

	for (i = 0; i < n; i++)
	{
		ch[i] = (char)i;					//��ʼ�� ch[]
		w[i] = 0;							//��ʼ�� w[]
	}


	rewind(infp);
	cha = fgetc(infp);
	while (!feof(infp))						//ͳ���ַ�����Ƶ��
	{	
		w[(unsigned char)cha]++;
		size++;
		cha = fgetc(infp);
	}

	if (pHuffmanTree != NULL) delete[]pHuffmanTree;
	pHuffmanTree = new HuffmanTree<char, unsigned long>(ch, w, n);		//���ɹ�������
	rewind(outfp);
	fwrite(&size, sizeof(unsigned long), 1, outfp);		//��Ŀ���ļ�д��Դ�ļ���С
	for (i = 0; i < n; i++)								//��Ŀ���ļ�д��ÿ���ַ����ֵ�Ƶ��
	{
		fwrite(&w[i], sizeof(unsigned long), 1, outfp);
	}

	buf.bits = 0;				//��ʼ�� bits
	buf.ch = 0;					//��ʼ��  ch
	rewind(infp);
	cha = fgetc(infp);
	String strTmp;
	while (!feof(infp))			//��Դ�ļ��ַ����룬��������д��Ŀ���ļ�
	{
		strTmp = pHuffmanTree->EnCode(cha);
		for (i = 0; i < strTmp.Length(); i++)
		{
			if (strTmp.CStr()[i] == '0') Write(0);
			else Write(1);
		}
		cha = fgetc(infp);
	}
	WriteToOutfp();

	fclose(infp);
	fclose(outfp);
	cout << "�������!" << endl;
}


void HuffmanCompress::DeCompress()
{
	char infName[256], outfName[256];

	cout << "������ѹ���ļ�����";
	cin >> infName;
	if ((fopen_s(&infp, infName, "r")) != 0)
	{
		cerr << "��ѹ���ļ�ʧ��" << endl;
		exit(4);
	}

	fgetc(infp);
	if (feof(infp))
	{
		cerr << "ѹ���ļ�Ϊ�գ�" << endl;
		exit(5);
	}

	cout << "������Ŀ���ļ�����";
	cin >> outfName;
	if ((fopen_s(&outfp, outfName, "w")) != 0)
	{
		cerr << "��Ŀ���ļ�ʧ�ܣ�" << endl;
		exit(6);
	}
	
	cout << "���ڴ������Ժ�..." << endl;

	const unsigned long n = 256;		//�ַ�����
	char ch[n];							//�ַ�����
	unsigned long w[n];					//Ȩ
	unsigned long i, size = 0;
	char cha;

	rewind(infp);
	fread(&size, sizeof(unsigned long), 1, infp);		//��ȡѹ���ļ���С
	for (i = 0; i < n; i++)
	{
		ch[i] = (char)i;								//��ʼ�� ch[]
		fread(&w[i], sizeof(unsigned int), 1, infp);	//��ȡ�ַ�Ƶ��
	}
	if (pHuffmanTree != NULL) delete []pHuffmanTree;	//�ͷſռ�
	pHuffmanTree = new HuffmanTree<char, unsigned long>(ch, w, n);		//���ɹ�������


	unsigned long len = 0;								//��ѹ���ַ�����
	cha = fgetc(infp);									//ȡ��Դ�ļ���һ���ַ�
	String strTmp;
	while (!feof(infp))									//��ѹ���ַ����н��룬����������ַ�д��Ŀ���ļ�
	{
		unsigned char c = (unsigned char)cha;
		for (i = 0; i < 8; i++)							//�� c ת��Ϊ�����ƴ�
		{
			if (c < 128) Concat(strTmp, "0");
			else Concat(strTmp, "1");
			c = c << 1;
		}
		cha = fgetc(infp);
	}

	DbLinkList<char> lst = pHuffmanTree->DeCode(strTmp);	//����
	char chTemp;
	for (int j = 1; j <= lst.Length(); j++)
	{
		lst.GetElem(j, chTemp);
		fputc(chTemp, outfp);
		len++;
		if (len == size) break;
	}

	fclose(infp);
	fclose(outfp);
	cout << "���������" << endl;
}




int main()
{
	HuffmanCompress Huff_1;		
	Huff_1.Compress();			//����
	HuffmanCompress Huff_2;
	Huff_2.DeCompress();		//����
	return 0;

}