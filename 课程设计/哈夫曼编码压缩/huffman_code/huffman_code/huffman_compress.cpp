#include<iostream>
#include "HuffmanTree.h"

using namespace std;

//字符缓存器
struct BufferType
{
	char ch;					//字符
	unsigned int bits;			//实际比特数
};


class HuffmanCompress
{
protected:
	HuffmanTree<char, unsigned long>* pHuffmanTree;
	FILE* infp, * outfp;								//输入输出文件
	BufferType buf;										//字符缓存

	void Write(unsigned int bit);						//向目标文件中写入一个比特
	void WriteToOutfp();								//强行将字符缓存写入目标文件

public:
	HuffmanCompress() {};
	~HuffmanCompress() {};
	void Compress();									//压缩算法
	void DeCompress();									//解压缩算法
	//HuffmanCompress(const HuffmanCompress& copy);		//复制构造函数
	//HuffmanCompress& operator = (const HuffmanCompress& copy);	//重载赋值运算符

};


void HuffmanCompress::Write(unsigned int bit)			
{
	buf.bits++;
	buf.ch = (buf.ch << 1) | bit;						//将 bit 加入到缓存字符中
	if (buf.bits == 8)									//缓存区已满，写入目标文件
	{
		fputc(buf.ch, outfp);
		buf.bits = 0;
		buf.ch = 0;
	}
}

void HuffmanCompress::WriteToOutfp()
{
	unsigned int len = buf.bits;
	if (len > 0)	//缓存非空，将缓存的比特数增加到 8，自动写入目标文件
	{
		for (unsigned int i = 0; i < 8 - len; i++) Write(0);
	}
}


void HuffmanCompress::Compress()
{
	char infName[256], outfName[256];

	cout << "请输入源文件名（文件小于 4GB）：";
	cin >> infName;
	if ((fopen_s(&infp, infName, "r")) != 0)
	{
		cerr << "打开源文件失败！" << endl;
		exit(1);
	}

	fgetc(infp);
	if (feof(infp))
	{
		cerr << "空源文件！" << endl;
		exit(2);
	}

	cout << "请输入目标文件名：";
	cin >> outfName;
	if ((fopen_s(&outfp,outfName, "w")) != 0)
	{
		cerr << "打开目标文件失败！" << endl;
		exit(3);
	}

	cout << "正在处理，请稍后..." << endl;

	const unsigned long n = 256;				//字符个数
	char ch[256];								//字符数组
	unsigned long w[256];						//字符出现频度（权）
	unsigned long i, size = 0;
	char cha;

	for (i = 0; i < n; i++)
	{
		ch[i] = (char)i;					//初始化 ch[]
		w[i] = 0;							//初始化 w[]
	}


	rewind(infp);
	cha = fgetc(infp);
	while (!feof(infp))						//统计字符出现频度
	{	
		w[(unsigned char)cha]++;
		size++;
		cha = fgetc(infp);
	}

	if (pHuffmanTree != NULL) delete[]pHuffmanTree;
	pHuffmanTree = new HuffmanTree<char, unsigned long>(ch, w, n);		//生成哈夫曼树
	rewind(outfp);
	fwrite(&size, sizeof(unsigned long), 1, outfp);		//向目标文件写入源文件大小
	for (i = 0; i < n; i++)								//向目标文件写入每个字符出现的频度
	{
		fwrite(&w[i], sizeof(unsigned long), 1, outfp);
	}

	buf.bits = 0;				//初始化 bits
	buf.ch = 0;					//初始化  ch
	rewind(infp);
	cha = fgetc(infp);
	String strTmp;
	while (!feof(infp))			//对源文件字符编码，并将编码写入目标文件
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
	cout << "处理结束!" << endl;
}


void HuffmanCompress::DeCompress()
{
	char infName[256], outfName[256];

	cout << "请输入压缩文件名：";
	cin >> infName;
	if ((fopen_s(&infp, infName, "r")) != 0)
	{
		cerr << "打开压缩文件失败" << endl;
		exit(4);
	}

	fgetc(infp);
	if (feof(infp))
	{
		cerr << "压缩文件为空！" << endl;
		exit(5);
	}

	cout << "请输入目标文件名：";
	cin >> outfName;
	if ((fopen_s(&outfp, outfName, "w")) != 0)
	{
		cerr << "打开目标文件失败！" << endl;
		exit(6);
	}
	
	cout << "正在处理，请稍后..." << endl;

	const unsigned long n = 256;		//字符个数
	char ch[n];							//字符数组
	unsigned long w[n];					//权
	unsigned long i, size = 0;
	char cha;

	rewind(infp);
	fread(&size, sizeof(unsigned long), 1, infp);		//读取压缩文件大小
	for (i = 0; i < n; i++)
	{
		ch[i] = (char)i;								//初始化 ch[]
		fread(&w[i], sizeof(unsigned int), 1, infp);	//读取字符频度
	}
	if (pHuffmanTree != NULL) delete []pHuffmanTree;	//释放空间
	pHuffmanTree = new HuffmanTree<char, unsigned long>(ch, w, n);		//生成哈夫曼树


	unsigned long len = 0;								//解压的字符个数
	cha = fgetc(infp);									//取出源文件第一个字符
	String strTmp;
	while (!feof(infp))									//对压缩字符进行解码，并将解码的字符写入目标文件
	{
		unsigned char c = (unsigned char)cha;
		for (i = 0; i < 8; i++)							//将 c 转换为二进制串
		{
			if (c < 128) Concat(strTmp, "0");
			else Concat(strTmp, "1");
			c = c << 1;
		}
		cha = fgetc(infp);
	}

	DbLinkList<char> lst = pHuffmanTree->DeCode(strTmp);	//译码
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
	cout << "处理结束！" << endl;
}




int main()
{
	HuffmanCompress Huff_1;		
	Huff_1.Compress();			//编码
	HuffmanCompress Huff_2;
	Huff_2.DeCompress();		//解码
	return 0;

}