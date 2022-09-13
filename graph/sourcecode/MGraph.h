//
// Created by yu on 2022-9-10.
//

#ifndef DATA_STRUCT_MGRAPH_H
#define DATA_STRUCT_MGRAPH_H
#define MAX_VERTEX_NUM 100

#endif //DATA_STRUCT_MGRAPH_H


typedef int VertexType;
typedef int EdgeType;
typedef int Adjvex;

/**
 * 图的邻接矩阵表示
 *
 */
typedef struct {
    VertexType vex[MAX_VERTEX_NUM];
    EdgeType edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    //当前顶点数和弧数
    int vexnum, arcnum;
}MGraph;

//访问标记数组
bool visited[MAX_VERTEX_NUM];


/**
 * 创建
 *
 * @param graph
 * @return
 */
MGraph * createGraph(MGraph * graph){
    graph->vexnum = 0;
    return graph;
}

/**
 * 定位顶点
 *
 * @param graph
 * @param vp
 * @return
 */
int locateVex(MGraph *graph, VertexType * vp){

    for (int i = 0; i < graph->vexnum; ++i) {
        if (graph->vex[i] == *vp){
            return i;
        }
    }
    //无此顶点
    return -1;
}

/**
 * 增加顶点
 *
 * @param graph
 * @param vp
 * @return
 */
int addVertex(MGraph *graph, VertexType * vp){

    if(graph->vexnum >= MAX_VERTEX_NUM){
        //超出
        return -1;
    }
    if(locateVex(graph, vp) != -1){
        //已经存在
        return -1;
    }
    int k = graph->vexnum;
    //添加节点
    graph->vex[graph->vexnum ++] = *vp;
    //添加默认边
    for (int i = 0; i < graph->vexnum; ++i) {
        graph->edge[i][k] = 0;
        graph->edge[k][i] = 0;
    }
}


int addEdge(MGraph *graph, int i, int j, Adjvex arcValType){

    //无向
    graph->edge[j][i] = arcValType;
    graph->edge[i][j] = arcValType;
}

