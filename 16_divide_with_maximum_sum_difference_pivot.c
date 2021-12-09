/**
 * 已知由n(n>=2)个正整数构成的集合
 * A={ak|0<=k<n}，将其划分为两个不相交的子集A1和A2，
 * 元素个数分别是n1和n2，A1和A4中元素之和分别为S1和S2。
 * 设计一个可尽能高效的划分算法，
 * 满足|n1-n2|最小且|S1-S2|最大
 */

#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

/**
 * 返回划分后S2开始的位置
 * @param  nums   数组
 * @param  length 数组长度
 * @return        划分之后后半部分起点位置
 */
int divide_with_maximum_sum_difference(int *nums, int length) {
  qsort(nums, sizeof(int), length, comp);
  return length / 2;
}

int main() {
  int test1[1] = {1};
  printf("input:1\n");
  printf("expect:0\n");
  printf("output:%d\n\n", divide_with_maximum_sum_difference(test1, 1));
  /**
   * input:1
   * expect:0
   * output:0
   */

  int test2[6] = {1, 2, 3, 4, 5, 6};
  printf("input:[1,2,3,4,5,6]\n");
  printf("expect:3\n");
  printf("output:%d\n", divide_with_maximum_sum_difference(test2, 6));
  /**
   * input: [1,2,3,4,5,6]
   * expect:3
   * output:3
   */
}
