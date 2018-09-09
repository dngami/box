#include <stdio.h>
#include <stdlib.h>

struct arr_node{
  char c;
  struct vertex * list_head;
};

struct vertex{
  char c;
  struct vertex * next;
};

void Adjacency_list(char c1, char c2 , struct arr_node* arr){
  struct vertex *  new =(struct vertex * )malloc(sizeof(struct vertex));
  new->c = c2;
  new->next = NULL;
  struct vertex *  temp  = arr[c1-'a'].list_head;
  arr[c1-'a'].list_head  = new;
  new->next = temp;
}
// Queue formation *****************************************
      struct Q_node{
        char c;
        struct Q_node * next;
      };

      struct Queue{
          struct Q_node * rear , *front;
      };

      struct Queue * make_queue(){
        struct Queue * q = (struct Queue *)malloc(sizeof(struct Queue));
        q->rear = NULL;
        q->front = NULL;
        return q;
      }

      struct Q_node * new_Q_node(char c){
        struct Q_node * new = (struct Q_node *)malloc(sizeof(struct Q_node));
        new->c = c;
        new->next = NULL;
        return new;
      }

      void enQueue(struct Queue *q, char c)
      {
        struct Q_node *temp = new_Q_node(c);
        if (q->rear == NULL)
        {
           q->front = q->rear = temp;
           return;
        }
        q->rear->next = temp;
        q->rear = temp;
      }

    struct Q_node *deQueue(struct Queue *q)
    {
        if (q->front == NULL)
           return NULL;

        struct Q_node *temp = q->front;
        q->front = q->front->next;

        if (q->front == NULL)
           q->rear = NULL;
        return temp;
    }
//*********************************************************


void BFS(struct arr_node * arr , int size , char * color , int * d , struct arr_node ** predecessor){
  struct Queue * Q = make_queue();

  int i;
  for(i=0 ; i< size; i++){
    color[i] ='w';
  }
  enQueue(Q,arr[0].c);
  color[0] = 'g'; d[0]=0;

  while(Q->front!=NULL){
    struct Q_node *curr = deQueue(Q);
    int u = curr->c-'a';

    struct vertex * temp = arr[u].list_head;

    while(temp!=NULL){
      int v = temp->c-'a';
      if(color[v]=='w'){
        color[v]='g';
        d[v]=d[u]+1;
        predecessor[v] = &arr[u];
        enQueue(Q,temp->c);
        temp=temp->next;
      }
      color[u]='b';
    }

  }
}

int main(){
  int vertex_count , edge_count;
  printf("enter no vertex and edges:");
  scanf("%d,%d",&vertex_count , &edge_count);
  getchar();

  struct arr_node arr[vertex_count];
  struct arr_node *predecessor[vertex_count];

  int i;
  for(i=0;i<vertex_count;i++){
    arr[i].c = 'a'+i;
    arr[i].list_head = NULL;
    predecessor[i]=NULL;
  }

  char c1,c2;
  for(i=0;i<edge_count ; i++){
    scanf("%c,%c", &c1,&c2);
    getchar();
    Adjacency_list(c1,c2,arr);
  }

  char color[vertex_count] ;
  int d[vertex_count]  ;

  BFS(arr,vertex_count,color,d,predecessor);
  printf("%d %d %d %d \n",d[0],d[1],d[2],d[3] );
}
