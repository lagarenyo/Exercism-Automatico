#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[]) {
  list_t *res =
      (list_t *)malloc(sizeof(list_t) + sizeof(list_element_t) * length);

  res->length = length;
  for (size_t i = 0; i < length; i++)
    res->elements[i] = elements[i];
  return res;
}

list_t *append_list(list_t *list1, list_t *list2) {
  list_element_t elements[list1->length + list2->length];

  for (size_t i = 0; i < list1->length; i++)
    elements[i] = list1->elements[i];
  for (size_t i = 0; i < list2->length; i++)
    elements[list1->length + i] = list2->elements[i];
  return new_list(list1->length + list2->length, elements);
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
  list_element_t elements[list->length];
  size_t iter;

  iter = 0;
  for (size_t i = 0; i < list->length; i++)
    if (filter(list->elements[i]))
      elements[iter++] = list->elements[i];
  return new_list(iter, elements);
}

size_t length_list(list_t *list) { return list->length; }

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
  list_element_t list_map[list->length];

  for (size_t i = 0; i < list->length; i++)
    list_map[i] = map(list->elements[i]);

  return new_list(list->length, list_map);
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
  for (size_t i = 0; i < list->length; i++)
    initial = foldl(list->elements[i], initial);
  return initial;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
  for (size_t i = list->length; i > 0; i--)
    initial = foldr(list->elements[i - 1], initial);
  return initial;
}

list_t *reverse_list(list_t *list) {
  list_element_t listaux[list->length];
  for (size_t i = list->length - 1, j = 0; j < list->length; i--, j++)
    listaux[j] = list->elements[i];
  return new_list(list->length, listaux);
}

void delete_list(list_t *list) { free(list); }