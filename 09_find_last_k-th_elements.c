#include <stdio.h>
#define NOT_FOUND 0  // 0 表示找不到

typedef int Data;  // 数据类型定义

// 链表定义
struct node {
  Data data;
  struct node* link;
};

/**
 * 寻找倒数第loc_r 个元素
 * @param  head 指向链表头结点的指针
 * @param  loc_r       要寻找的元素的位置(倒数)
 * @return             找到结点的data值(找不到返回0)
 */
Data find_least_k_element(struct node* head, int loc_r) {
  struct node *fast = head, *slow = head;  // 定义快慢指针
  // 快指针前进k次
  while (loc_r--) {
    if (!fast) {         // 快指针到达空结点说明找不到
      return NOT_FOUND;  // 由题意，找不到返回0
    }
    fast = fast->link;
  }
  while (fast) {  // 前进两个指针，直到快指针为空
    fast = fast->link;
    slow = slow->link;
  }
  return slow->data;  // 快指针为空时慢指针的值就是所要求的值
}

int main() {
  struct node head, node[5];
  head.link = &node[0];
  for (int i = 0; i < 4; ++i) {
    node[i].data = 5 - i;
    node[i].link = &node[i + 1];
  }
  node[4].data = 1;
  node[4].link = NULL;
  // for(int i=0;i<5;++i){
  //   printf("%d ",node[i].data);
  // }
  printf("%d\n", find_least_k_element(&head, 6));  // 0
  printf("%d\n", find_least_k_element(&head, 5));  // 5
  printf("%d\n", find_least_k_element(&head, 4));  // 4
  printf("%d\n", find_least_k_element(&head, 2));  // 2
}
