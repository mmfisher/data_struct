//
// Created by yu on 2022-9-12.
//

#ifndef DATA_STRUCT_DIJKSTRA_H
#define DATA_STRUCT_DIJKSTRA_H

#endif //DATA_STRUCT_DIJKSTRA_H
#define MAX_VEX 100
#define INFINITE 100

#include "AlGraph.h"


bool final[MAX_VEX];
int dist[MAX_VEX];
bool path[MAX_VEX];

void Dijkstra_path (AlGraph *graph, int v){

    //初始化
    int vexNum = graph->vexnumber;
    for (int j = 0; j < vexNum; ++j) {
        final[j] = false;
        dist[j] = INFINITE;
        path[j] = -1;
    }

    final[v] = true;
    dist[v] = 0;





    for (LinkNode * p = graph->adjList[v].firstarc; p->adjvex >= 0; p = p->nextarc) {

        int vex = p->adjvex;

    }
}
