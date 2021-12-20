
#ifndef _E_QUEUE_TPL_H__
#define _E_QUEUE_TPL_H__

#ifdef __cplusplus
extern "C" {
#endif


#define E_QUEUE_DECLARE(name, item_type, max_items) \
\
typedef struct e_queue_##name { \
  volatile int head, tail; \
  item_type items[max_items]; \
} e_queue_##name; \
\
static inline void e_queue_##name##_init(e_queue_##name *q) { \
  q->head = q->tail = 0; \
} \
\
static inline int e_queue_##name##_is_empty(const e_queue_##name *q) { \
  return (q->head == q->tail); \
} \
\
static inline int e_queue_##name##_is_full(const e_queue_##name *q) { \
  return (q->head == (q->tail + 1) % (max_items)); \
} \
\
static inline int e_queue_##name##_length(const e_queue_##name *q) { \
  int nitems = q->tail - q->head; \
  return (nitems >= 0) ? nitems : (nitems + (max_items)); \
} \
\
static inline int e_queue_##name##_pop(e_queue_##name *q, item_type *item) { \
  if (e_queue_##name##_is_empty(q)) return -1; /* empty */ \
  __sync_synchronize(); /* full memory barrier */ \
  *item = q->items[q->head]; \
  __sync_synchronize(); /* full memory barrier */ \
  q->head = (q->head + 1) % (max_items); \
  return 0; \
} \
\
static inline int e_queue_##name##_push(e_queue_##name *q, item_type *item) { \
  if (e_queue_##name##_is_full(q)) return -1; /* full */ \
  __sync_synchronize(); /* full memory barrier */ \
  q->items[q->tail] = *item; \
  __sync_synchronize(); /* full memory barrier */ \
  q->tail = (q->tail + 1) % (max_items); \
  return 0; \
}


#ifdef __cplusplus
}
#endif

#endif /* _E_QUEUE_TPL_H__ */
