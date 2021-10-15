/**
 * 假定采用带头结点的单链表保存单词,
 * 当两个单词有相同的后缀时,
 * 则可共享相同的后缀存储空间,
 * 例如,
 * “loading”和“being”的存储映像如下所示.
 * str1
 *  ↓
 * head → l → o → a → d   p
 *                    ↓ ↙
 *                    i → n → g
 *                    ↑
 *         head → b → e
 *          ↑
 *         str2
 *
 * 设 str1 和 str2 分别指向两个单词所在单链表的头结点,
 * 链表结点结构为 ,
 * 请设计一个时间上尽可能高效的算法,
 * 找出由 str1 和 str2 所指向两个链表共同后缀的起始位置
 * (如图中字符 i 所在结 点的位置 p)
 *
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  char data;
  struct ListNode* next;
};

/**
 * 由字符串生成一个链表
 * @param  string 原始字符串
 * @param  length 长度
 * @param  end    尾部链接的节点
 * @return        头节点(该头节点无数据)
 */
struct ListNode* generate_linked_list(char* string, int length,
                                      struct ListNode* end) {
  struct ListNode* head = (struct ListNode*)calloc(1, sizeof(struct ListNode));

  struct ListNode* cur = NULL;
  struct ListNode* pre = head;
  for (int i = 0; i < length; ++i) {
    cur = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    pre->next = cur;
    cur->data = string[i];
    pre = cur;
  }
  cur->next = end;
  return head;
}

/**
 * 打印链表
 * @param data_node 链表的第一个带数据的结点
 */
void print_linked_list(struct ListNode* data_node) {
  while (data_node) {
    putchar(data_node->data);
    data_node = data_node->next;
  }
  putchar('\n');
}

/**
 * 获得链表的长度(含头指针)
 * @param  head 头结点
 * @return      链表的长度
 */
int len(struct ListNode* head) {
  int length = 0;
  while (head) {
    ++length;
    head = head->next;
  }
  return length;
}

/**
 * 获得公共后缀的第一个结点位置
 * @param  str1 表示第一个字符串的 head 结点
 * @param  str2 表示第二个字符串的 head 结点
 * @return      公共前缀的起始结点
 */
struct ListNode* common_suffix_loc(struct ListNode* str1,
                                   struct ListNode* str2) {
  int str1_length = len(str1), str2_length = len(str2);

  // 移动头指针使得两链表等长
  while (str1_length > str2_length) {
    str1 = str1->next;
    --str1_length;
  }
  while (str2_length > str1_length) {
    str2 = str2->next;
    --str2_length;
  }

  // 同步移动指针直到两者相同
  while (str1 != str2) {
    str1 = str1->next;
    str2 = str2->next;
  }
  return str1;
}

int main() {
  // test 1
  struct ListNode* suffix = generate_linked_list("ng", 2, NULL);
  suffix->data = 'i';
  struct ListNode* str1 = generate_linked_list("load", 4, suffix);
  struct ListNode* str2 = generate_linked_list("be", 2, suffix);
  printf("input:\n");
  printf("  str1:\t\t\t");
  print_linked_list(str1->next);
  printf("  str2:\t\t\t");
  print_linked_list(str2->next);
  printf("expect:\n");
  printf("  the common suffix:\t");
  print_linked_list(suffix);

  printf("output:\n");
  printf("  the common suffix:\t");
  struct ListNode* common_suffix_head = common_suffix_loc(str1, str2);
  print_linked_list(common_suffix_head);
}
/**
 * input:
 *   str1:                 loading
 *   str2:                 being
 * expect:
 *   the common suffix:    ing
 * output:
 *   the common suffix:    ing
 */
