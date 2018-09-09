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
// DFS function using recurion**********************************************************************************************************************
//************************************************
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
//************************************************************************************************************************************************

// BFS funtion using Queue***********************************************************************************************************************
//*********************************************************************************************************************************************

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
//******************************************************************************************************************************************
