#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTATIONS 100



typedef struct EdgeNode//边表结点
{
    int adjvex;//邻接点域用于存储该顶点对应的下标
    char name[50];//站名
    double distance;//边的权值
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode//顶点表结点
{
    char name[50];//站名
    int line;//站点所属线路号
    EdgeNode *firstedge;
}VertexNode;//顶点表结点

typedef struct
{
    VertexNode station[MAXSTATIONS];//存放所有顶点
}Graph;

typedef struct stop
{
    int line;
    char name[50];
    double distance;
}stop;


int CreateVertex(int length,Graph* G,stop stations[])//创建表头结点
{
    stations++;
    int reallength=0;//除去重名站点后的长度
    for(int i=0;i<length;i++)
    {
        int k=0;
        for(;k<i;k++)//检查此站名是否有出现过
        {
            if(!(strcmp(G->station[k].name,stations[i].name)))//之前存放的表头结点中有相同名字的,即为换乘点
            {
                reallength--;
                break;
            }
        }
        if(k==i||i==0)//循环找完后确实没有重名过
        {
            strcpy(G->station[reallength].name,stations[i].name);//获取站点名并将其放在顶点表中
            G->station[reallength].line=stations[i].line;//获取站点所属线路号并将其放在顶点表中
        }
        reallength++;
    }
    return reallength;
}

void CreateEdge(int length,int reallength,Graph* G,stop stations[])//创建边表结点
{
    for(int i=0;i<reallength;i++)//一一获取所有站(不重名的)
    {
        EdgeNode* temp = (EdgeNode*)malloc(sizeof(EdgeNode));
        temp->next=NULL;
        EdgeNode* first = G->station[i].firstedge;

        strcpy(temp->name,G->station[i].name);
        for(int j=0;j<length;j++)//逐一对比所有的站点,确定此站的位置
        {
            if(!(strcmp(temp->name,stations[j].name)))//找到该站位置
            {
                if(j==0)//此站为第一站
                {
                    if(stations[j+1].line==stations[j].line)//和后一站位于同一条线
                    {
                        temp->distance=stations[j+1].distance;
                        strcpy(temp->name,stations[j+1].name);
                        first->next=temp;
                        first=first->next;
                    }
                }
                else if(j==length-1)//此站为最后一站
                {
                    if(stations[j-1].line==stations[j].line) //和前一站位于同一条线
                    {
                        temp->distance=stations[j-1].distance;
                        strcpy(temp->name,stations[j-1].name);
                        first->next=temp;
                        first=first->next;
                    }
                }
                else
                {
                    if(stations[j-1].line==stations[j].line)//和前一站位于同一条线
                    {
                        temp->distance=stations[j-1].distance;
                        strcpy(temp->name,stations[j-1].name);
                        first->next=temp;
                        first=first->next;

                        if(stations[j+1].line==stations[j].line)//和后一站也位于同一条线
                        {
                            EdgeNode* temp = (EdgeNode*)malloc(sizeof(EdgeNode));
                            temp->next=NULL;
                            temp->distance=stations[j+1].distance;
                            strcpy(temp->name,stations[j+1].name);
                            first->next=temp;
                            first=first->next;
                        }

                    }
                    else if(stations[j+1].line==stations[j].line)//和后一站位于同一条线(进入这一判断说明已经不和前一站同一条线了,故不再需要判断)
                    {
                        temp->distance=stations[j+1].distance;
                        strcpy(temp->name,stations[j+1].name);
                        first->next=temp;
                        first=first->next;
                    }
                }
            }
        }

    }
}

void show(Graph* G,int reallength)
{

    for(int i=0;i<reallength;i++)
    {
        printf(" %s %.2lf",G->station[i].firstedge->next->name,G->station[i].firstedge->distance);
    }
}

int main()
{
    int n;//线路总条数n
    printf("输入线路的条数\n");
    scanf("%d",&n);
    Graph G;
    stop stations[MAXSTATIONS];
    int length=0;
    for(int i=0;i<n;i++)//读入站名距离等信息至一结构数组
    {
        int line;
        scanf("%d",&line);

        do
        {
            stations[length].line=line;
            scanf("%s %lf",stations[length].name,&stations[length].distance);
            length++;
        } while (stations[length-1].distance!=0);//因为length++了
    }
    int reallength=0;
    reallength=CreateVertex(length,&G,stations);
    CreateEdge(length,reallength,&G,stations);
    show(&G,reallength);

    system("pause");
    return 0;
}

/*
测试输入：
4 1 liuduqiao 5.00 xunlimen 4.00 dazhilu 4.00 sanyanglu 5.00 huangpulu 0 2 hankouhuochezhan 10.00 fanhu 2.00 wangjiadundong 2.00 qingnianlu 4.00 zhongshangongyuan 2.00 xunlimen 2.00 jianghanlu 5.00 jiyuqiao 0 6 sanyanqiao 3.00 xiangganglu 2.00 miaolilu 2.00 dazhilu 5.00 jianghanlu 1.00 hanzhengjie 0 7 wuhanshangwuqu 1.00 wangjiadundong 2.00 qushuilou 2.00 xiangganglu 6.00 sanyanglu 9.00 xujiapeng 3.00 sanjiaolu 3.00 sancenglou 3.00 jiyuqiao 0
预期输出：
1 六渡桥 5.00 循礼门 4.00 大智路 4.00 三阳路 5.00 黄浦路
2 汉口火车站 10.00 范湖 2.00 王家墩东 2.00 青年路 4.00 中山公园 2.00 循礼门 2.00 江汉路 5.00 积玉桥
6 三眼桥 3.00 香港路 2.00 苗栗路 2.00 大智路 5.00 江汉路 1.00 汉正街
7 武汉商务区 1.00 王家墩东 2.00 取水楼 2.00 香港路 6.00 三阳路 9.00 徐家棚 3.00 三角路 3.00 三层楼 3.00 积玉桥
*/
