/**
 * 已知由n(n>=2)个正整数构成的集合
 * A={ak|0<=k<n}，将其划分为两个不相交的子集A1和A2，
 * 元素个数分别是n1和n2，A1和A4中元素之和分别为S1和S2。
 * 设计一个可尽能高效的划分算法，
 * 满足|n1-n2|最小且|S1-S2|最大
 */

#include <stdio.h>
#include <stdlib.h>

void exchange(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * 使数组nums[left..right]有序，
 * @param  nums  数组
 * @param  left  左边的下标
 * @param  right 右边界下标
 * @return       枢纽的位置
 */
int parition(int *nums, int left, int right) {
  int right_value = nums[right];
  int less = left - 1;
  for (int i = left; i < right; ++i) {
    if (nums[i] <= right_value) {
      ++less;
      exchange(&nums[less], &nums[i]);
    }
  }
  exchange(&nums[less], &nums[right]);
  return less + 1;
}

/**
 * 部分快速排序,只对当前元素大的部分做快速排序
 * @param  nums   数组
 * @param  midd   数组中间的位置
 * @param  left   最左边的下标
 * @param  right  最右边的下标
 */
void partly_quick_sort(int *nums, int mid, int left, int right) {
  int pivot = parition(nums, left, right);
  if (pivot > mid) {
    partly_quick_sort(nums, mid, left, pivot - 1);
  } else if (pivot < mid) {
    partly_quick_sort(nums, mid, pivot + 1, right);
  }
}

/**
 * 返回划分后S2开始的位置
 * @param  nums   数组
 * @param  length 数组长度
 * @return        划分之后后半部分起点位置
 */
int divide_with_maximum_sum_difference(int *nums, int length) {
  int mid = length / 2;
  partly_quick_sort(nums, mid, 0, length - 1);
  return mid;
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

  int test3[5] = {0,1,4,3,2};
  printf("input:[0,1,4,3,2]\n");
  printf("expect:2\n");
  printf("output:%d\n", divide_with_maximum_sum_difference(test3, 5));
  /**
   * input:[0,1,4,3,2]
   * expect:2
   * output:2
   */
}
