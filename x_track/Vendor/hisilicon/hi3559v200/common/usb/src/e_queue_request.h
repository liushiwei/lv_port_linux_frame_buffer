
#ifndef _E_QUEUE_REQUEST_H__
#define _E_QUEUE_REQUEST_H__

#include <assert.h>
#include <stdlib.h>
#include <pthread.h>

#include "e_queue_tpl.h"

#ifdef __cplusplus
extern "C" {
#endif


#define E_MAX_REQUEST_IN_QUEUE 32

typedef struct {
  char data[1024];
} e_request;

pthread_mutex_t g_e_queue_request_mutex;

E_QUEUE_DECLARE(request, e_request*, E_MAX_REQUEST_IN_QUEUE);

static void e_request_init(e_queue_request *qr) {
  assert(qr != NULL);
  pthread_mutex_init(&g_e_queue_request_mutex, NULL);
  e_queue_request_init(qr);
}

static int e_request_add(e_queue_request *qr, e_request *r) {
  pthread_mutex_lock(&g_e_queue_request_mutex);
  assert(qr != NULL && r != NULL);
  if (e_queue_request_is_full(qr)) {
    e_request *req = NULL;
    e_queue_request_pop(qr, &req);
    if (req != NULL) {
    fprintf(stderr, "WARN request queue is full, drop request ==> %s\n", req->data);
      free(req);
    }
  }
  int ret = e_queue_request_push(qr, &r);
  pthread_mutex_unlock(&g_e_queue_request_mutex);
  return ret;
}

static int e_request_get(e_queue_request *qr, e_request **r) {
  pthread_mutex_lock(&g_e_queue_request_mutex);
  assert(qr != NULL);
  int ret = e_queue_request_pop(qr, r);
  pthread_mutex_unlock(&g_e_queue_request_mutex);
  return ret;
}


#ifdef __cplusplus
}
#endif

#endif /* _E_QUEUE_REQUEST_H__ */
