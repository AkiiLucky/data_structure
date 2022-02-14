#include <stdio.h>

#define MaxVertexNum 100                          //������Ŀ�����ֵ 
#define VertexType int


/* �ڽӾ���洢 */
typedef struct {
	VertexType Vex[MaxVertexNum];				//����� 
	int Edge[MaxVertexNum][MaxVertexNum];		//�ڽӾ��󣬱߱� 
	int vexnum, arcnum;						    //ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;




/* �ڽӱ�洢 */
typedef struct ArcNode {						//�߱��� 
	int adjvex;									//�û�ָ��Ķ����λ�� 
	struct ArcNode *next;						//ָ����һ������ָ�� 
	//InfoNode info;							//���ı�Ȩֵ 
}ArcNode;

typedef struct VNode {							//������� 
	VertexType data;							//������Ϣ 
	ArcNode *first;								//ָ���һ�������ö���Ļ���ָ�� 
}VNode, AdjList[MaxVertexNum]; 

typedef struct {
	AdjList vertices;							//�ڽӱ� 
	int vexnum, arcnum;							//ͼ�ĵ�ǰ�������ͱ���/���� 
} ALGraph;										//ALGraph �����ڽӱ�洢��ͼ����
 
 


int main()
{
	MGraph MG;
	ALGraph ALG;
	
	return 0;
}
