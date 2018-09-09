// DFS graph formation using recursion *************

#include <stdlib.h>

struct arr_node{
  char c;
  struct vertex * list_head;
};

struct vertex{
  char c;
  struct vertex * next;
};

int time_ = 0;

void Adjacency_list(char c1, char c2 , struct arr_node* arr){
  struct vertex *  new =(struct vertex * )malloc(sizeof(struct vertex));
  new->c = c2;
  new->next = NULL;
  struct vertex *  temp  = arr[c1-'a'].list_head;
  arr[c1-'a'].list_head  = new;
  new->next = temp;
}

void DFS_visit(struct arr_node * arr,int i,int size , char* color , int* d,int *f , struct arr_node ** predecessor){
  color[i] = 'g';
  time_++;
  d[i] = time_;
  struct vertex * temp  = arr[i].list_head;
  while(temp!=NULL){
    if(color[temp->c-'a'] == 'w'){
      predecessor[temp->c-'a']=&arr[i];
      DFS_visit(arr,temp->c-'a',size , color, d,f,predecessor);
    }
    temp = temp->next;
  }
  color[i] = 'b';
  time_++;
  f[i] = time_;
}

void DFS(struct arr_node * arr,int size , char* color , int* d,int *f , struct arr_node ** predecessor){
  int i;
  for(i=0 ; i< size; i++){
    color[i] ='w';
  }

  for(i=0 ; i< size; i++){
    if(color[i]=='w'){
      DFS_visit(arr,i,size,color,d,f,predecessor);
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

  printf("\n%c , %c ",arr[0].list_head->c,arr[1].list_head->c);

  char color[vertex_count] ;
  int d[vertex_count] , f[vertex_count] ;

  DFS(arr,vertex_count,color,d,f,predecessor);

  printf("\n%d %d %d %d %d" , d[0], f[0] ,d[1] ,f[1] ,d[2]);

}
