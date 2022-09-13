//
// Created by yu on 2022-9-11.
//

#ifndef DATA_STRUCT_ALGRAPH_H
#define DATA_STRUCT_ALGRAPH_H

#endif //DATA_STRUCT_ALGRAPH_H
#define MAX_VERTEX_NUM 100

typedef int VertexType;
typedef int Adjvex;
typedef int InfoType;


typedef struct LinkNode{
    //邻接点
    Adjvex adjvex;
    //下一个节点
    struct LinkNode *nextarc;
    // 权值
    InfoType info;
}LinkNode;

typedef struct {
    //顶点信息
    VertexType vertexType;
    //第一个节点
    LinkNode *firstarc;
}VexNode;


typedef struct {
    int vexnumber;
    VexNode adjList[MAX_VERTEX_NUM];

}AlGraph;


/**
 * 创建
 *
 * @param graph
 * @return
 */
AlGraph * createGraph(AlGraph * graph){
    graph->vexnumber = 0;
    return graph;
}


/**
 * 定位顶点
 *
 * @param graph
 * @param vp
 * @return
 */
int locateVex(AlGraph *graph, VertexType * vp){

    for (int i = 0; i < graph->vexnumber; ++i) {
        if (graph->adjList[i].vertexType == *vp){
            return i;
        }
    }
    //无此顶点
    return -1;
}

void visit(int i){

}

/**
 * 深度优先遍历
 */
void DFS(AlGraph *graph, int v, bool visited[]){

    visited[v] = true;
    visit(v);
    LinkNode * p = graph->adjList[v].firstarc;
    while (p != NULL){
        if (!visited[p->adjvex]){
            DFS(graph, p->adjvex, visited);
            p = p->nextarc;
        }
    }
}

/**
 * 深度优先遍历
 */
void DFSTraverse(AlGraph *graph){

    bool visited[graph->vexnumber];
    //初始化visited
    for (int i = 0; i < graph->vexnumber; ++i) {
        visited[i] = false;
    }
    for (int j = 0; j < graph->vexnumber; ++j) {
        if (!visited[j]){
            DFS(graph, j, visited);
        }
    }
}


/**** 广度优先遍历 ******/

void BFS(AlGraph *graph, int v, bool visited[]){

    Queue *queue;
    visited[v] = true;
    enque(queue, v);

    for (    LinkNode * p = graph->adjList[v].firstarc; p->adjvex >= 0; p = p->nextarc) {
        if(!visited[p->adjvex]){
            visited[p->adjvex] = true;
            enque(queue, v);
        }     
    }

}

/**
 * 广度优先遍历
 *
 * @param graph
 */
void BFSTraverse(AlGraph * graph){
    bool visited[graph->vexnumber];
    //初始化visited
    for (int i = 0; i < graph->vexnumber; ++i) {
        visited[i] = false;
    }

    for (int j = 0; j < graph->vexnumber; ++j) {
        if (!visited[j]){
            DFS(graph, j, visited);
        }
    }
}

