/**
 * 用单链表保存 m 个整数,
 * 结点的结构为:[data][link],
 * 且|data|≤n(n 为正整数) .
 * 现要求设计一个时间复杂度尽可能高效的算法,
 * 对于链表中 data 的绝对值相等的结点,
 * 仅保留第一次出现的结点而删除其余绝对值相等的结点.
 * 例如,若给定的单链表 head 如下:
 * head -> 21 -> -15 -> -15 -> -7-> 15
 * 则删除结点后的 head 为:
 * head -> 21 -> -15 -> -7
 * 1)给出算法的基本设计思想.
 * 2)使用 C 或 C++语言,给出单链表结点的数据类型定义.
 * 3)根据设计思想,采用 C 或 C++语言描述算法,关键之处给出注释.
 * 4)说明你所设计算法的时间复杂度和空间复杂度.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define abs(x) (((x) > 0) ? (x) : (-x))

struct LinkedList {
  int data;
  struct LinkedList* link;
};

void print_list(struct LinkedList* node) {
  node = node->link;
  printf("head");
  while (node) {
    printf("->(%d)", node->data);
    node = node->link;
  }
  printf("\n");
}

/**
 * 删除下一个结点
 * @param pre 要删除的结点的前一个结点的值
 * @return 删除后pre结点下一个结点的位置
 */
struct LinkedList* remove_next(struct LinkedList* pre) {
  struct LinkedList* to_delete = pre->link;
  struct LinkedList* next = to_delete->link;
  pre->link = next;
  free(to_delete);
  return next;
}

void purge_same_absolute_node(struct LinkedList* head, int upper_bound) {
  bool* has_discovered = (bool*)calloc(upper_bound + 1, sizeof(bool));
  struct LinkedList *pre = head, *cur = head->link;
  while (cur) {
    int abs_data = abs(cur->data);
    if (has_discovered[abs_data]) {
      // 表明该绝对值已经出现
      cur = remove_next(pre);
    } else {
      has_discovered[abs_data] = true;
      pre = cur;
      cur = cur->link;
    }
  }
  free(has_discovered);
}

int main() {
  int test_data[5] = {21, -15, -15, -7, 15};
  struct LinkedList *head =
                        (struct LinkedList*)malloc(sizeof(struct LinkedList)),
                    *pre = head;
  for (int i = 0; i < 5; ++i) {
    struct LinkedList* cur =
        (struct LinkedList*)malloc(sizeof(struct LinkedList));
    pre->link = cur;
    cur->data = test_data[i];
    pre = cur;
  }
  pre->link = NULL;

  printf("input:\t");
  print_list(head);
  purge_same_absolute_node(head, 21);
  printf("output:\t");
  print_list(head);
  /*
   *input:  head->(21)->(-15)->(-15)->(-7)->(15)
   *output: head->(21)->(-15)->(-7)
   */
}
