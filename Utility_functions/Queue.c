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
