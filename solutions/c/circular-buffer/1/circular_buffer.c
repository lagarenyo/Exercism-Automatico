#include "circular_buffer.h"

circular_buffer_t *new_circular_buffer(size_t capacity) {
  circular_buffer_t *res;

  res = (circular_buffer_t *)malloc(sizeof(circular_buffer_t));
  res->capacity = capacity;
  res->top = capacity - 1;
  res->head = 0;
  res->tail = capacity;

  res->data = (buffer_value_t *)malloc(sizeof(buffer_value_t) * capacity);
  return res;
}

int write(circular_buffer_t *buffer, buffer_value_t w_values) {
  int res;

  res = (buffer->head == buffer->tail) ? 1 : 0;
  if (!res) {
    buffer->data[buffer->head] = w_values;
    if (buffer->tail == buffer->capacity)
      buffer->tail = buffer->head;
    buffer->head = (buffer->head != buffer->top) ? buffer->head + 1 : 0;
  }else {
  errno=ENOBUFS;
  }
  return res;
}

int overwrite(circular_buffer_t *buffer, buffer_value_t ow_value) {

  int aux;

  aux = buffer->head;
  buffer->data[buffer->head] = ow_value;
  buffer->head = (buffer->head != buffer->top) ? buffer->head + 1 : 0;
  if (buffer->tail == buffer->capacity)
    buffer->tail = aux;
  else if (buffer->tail == aux)
    buffer->tail = buffer->head;
  return 0;
}

int read(circular_buffer_t *buffer, buffer_value_t *r_value) {
  int res;

  res = (buffer->tail == buffer->capacity) ? 1 : 0;

  if (!res) {
    *r_value = buffer->data[buffer->tail];
    buffer->tail = (buffer->tail != buffer->top) ? buffer->tail + 1 : 0;
    if (buffer->tail == buffer->head)
      buffer->tail = buffer->capacity;
  } else
    errno = ENODATA;
  return res;
}

int delete_buffer(circular_buffer_t *buffer) {
  free(buffer->data);
  free(buffer);
  return 1;
}

int clear_buffer(circular_buffer_t *buffer) {
  buffer->head = 0;
  buffer->tail = buffer->capacity;
  return 1;
}