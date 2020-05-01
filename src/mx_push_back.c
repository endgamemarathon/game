#include "../inc/header.h"

void mx_push_back(t_list **list, void *data) {
  t_list *point = *list;
  if (point == NULL) {
    point = mx_create_node(data);
  } else {
    while(point->next) {
      point = point->next;
    }
    point->next = mx_create_node(data);
  }
}
