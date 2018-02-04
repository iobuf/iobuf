typedef struct {
  int *buf;    /* Buffer array */
  int n;       /* Maximum number of slots */
  int front;   /* buf[(front+1)%n] is first item */
  int rear;    /* buf[rear%n] is last item */
  sem_t mutex; /* Protects accesses to buf */
  sem_t slots; /* Counts available slots */
  sem_t items; /* Counts available items */
} sbuf_t;

#define P(mu) sem_wait(mu)
#define V(mu) sem_post(mu)

/* Create an empty, bounded, shared FIFO buffer with n slots */
void sbuf_init(sbuf_t *sp, int n)
{
  sp->buf   = calloc(n, sizeof(int));
  sp->n     = n;              /* Buffer holds max of n items */
  sp->front = sp->rear = 0;   /* Empty buffer if front == rear */
  sem_init(&sp->mutex, 0, 1); /* Binary semaphore for locking */
  sem_init(&sp->slots, 0, 1); /* Initially, buf has n empty slots */
  sem_init(&sp->items, 0, 1); /* Initially, buf has zero data items */
}

/* Clean up buffer sp */
void sbuf_deinit(sbuf_t *sp)
{
  free(sp->buf);
}

/* Insert items onto the rear of shared buffer sp */
void sbuf_insert(sbuf_t *sp, int items)
{
  P(&sp->slots);                        /* Wait for available slot */
  P(&sp->mutex);                        /* Lock the buffer */
  sp->buf[(++sp->rear)%(sp->n)] = item; /* Insert the item */
  V(&sp->mutex);                        /* Unlock the buffer */
  V(&sp->slots);                        /* Announce the available item */
}

/* Remove and return the first item from buffer sp */
int sbuf_remove(sbuf_t *sp)
{
  int item;
  P(&sp->items);                         /* Wait for available item */
  P(&sp->mutex);                         /* Lock the buffer */
  item = sp->buf[(++sp->front)%(sp->n)]; /* Remove the item */
  V(&sp->mutex);                         /* Unlock the buffer */
  V(&sp->slots);                         /* Announce available slot */
  return item;
}
