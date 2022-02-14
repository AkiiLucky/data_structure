#include <stdio.h>

#define MaxVertexNum 100                          //顶点数目的最大值 
#define VertexType int


/* 邻接矩阵存储 */
typedef struct {
	VertexType Vex[MaxVertexNum];				//顶点表 
	int Edge[MaxVertexNum][MaxVertexNum];		//邻接矩阵，边表 
	int vexnum, arcnum;						    //图的当前顶点数和边数/弧数 
}MGraph;




/* 邻接表存储 */
typedef struct ArcNode {						//边表结点 
	int adjvex;									//该弧指向的顶点的位置 
	struct ArcNode *next;						//指向下一条弧的指针 
	//InfoNode info;							//网的边权值 
}ArcNode;

typedef struct VNode {							//顶点表结点 
	VertexType data;							//顶点信息 
	ArcNode *first;								//指向第一条依附该顶点的弧的指针 
}VNode, AdjList[MaxVertexNum]; 

typedef struct {
	AdjList vertices;							//邻接表 
	int vexnum, arcnum;							//图的当前顶点数和边数/弧数 
} ALGraph;										//ALGraph 是以邻接表存储的图类型
 
 


int main()
{
	MGraph MG;
	ALGraph ALG;
	
	return 0;
}
