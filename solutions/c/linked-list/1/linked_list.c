#include "linked_list.h"

struct list_node
{
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list
{
   struct list_node *first, *last;
};

static struct list_node *create_node(ll_data_t val)
{
   struct list_node *res;

   res = malloc(sizeof(struct list_node));
   res->data = val;
   res->next = NULL;
   res->prev = NULL;
   return res;
}

static void destroy_node(struct list_node *node)
{
   free(node);
}

struct list *list_create(void)
{
   struct list *res;

   res = malloc(sizeof(struct list));
   res->first = NULL;
   res->last = NULL;
   return res;
}

size_t list_count(const struct list *list)
{
   size_t res;
   struct list_node *iter;

   iter = list->first;
   res = 0;
   while (iter != NULL)
   {
      res++;
      iter = iter->next;
   }
   return res;
}

void list_push(struct list *list, ll_data_t item_data)
{
   struct list_node *new_node;

   new_node = create_node(item_data);
   if (!list->last)
   {
      list->first = new_node;
      list->last = new_node;
   }
   else
   {
      list->last->next = new_node;
      new_node->prev = list->last;
      list->last = new_node;
   }
}

ll_data_t list_pop(struct list *list)
{
   ll_data_t res;
   struct list_node *aux;

   res = 0;
   aux = list->last;
   if (aux)
   {
      res = aux->data;
      list->last = aux->prev;
      if (list->last != NULL)
         list->last->next = NULL;
      else
         list->first = NULL;
      destroy_node(aux);
   }
   return res;
}

void list_unshift(struct list *list, ll_data_t item_data)
{
   struct list_node *new_node;

   new_node = create_node(item_data);
   if (!list->first)
   {
      list->first = new_node;
      list->last = new_node;
   }
   else
   {
      list->first->prev = new_node;
      new_node->next = list->first;
      list->first = new_node;
   }
}

ll_data_t list_shift(struct list *list)
{
   ll_data_t res;
   struct list_node *aux;

   res = 0;
   aux = list->first;
   if (aux)
   {
      res = aux->data;
      list->first = aux->next;
      if (list->first != NULL)
         list->first->prev = NULL;
      else
         list->last = NULL;
      destroy_node(aux);
   }
   return res;
}

void list_delete(struct list *list, ll_data_t data)
{
   struct list_node *aux;

   aux = list->first;
   while ((aux != NULL) && (aux->data != data))
      aux = aux->next;
   if (aux != NULL)
   {
      if (aux->prev == NULL)
         list->first = aux->next;
      else
         aux->prev->next = aux->next;
      if (aux->next == NULL)
         list->last = aux->prev;
      else
         aux->next->prev = aux->prev;
   }
   destroy_node(aux);
}

void list_destroy(struct list *list)
{
   struct list_node *aux1;
   struct list_node *aux2;

   aux1 = list->first;
   while (aux1 != NULL)
   {
      aux2 = aux1;
      aux1 = aux1->next;
      destroy_node(aux2);
   }
   free(list);
}