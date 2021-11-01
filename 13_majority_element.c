/**
 * 已知一个整数序列A(a0,a1,...,a(n-1))
 * 其中0 <= ai < n(0 <= i<n)。
 * 若存在
 * ap1 = ap2 = ... = apm
 * 且 m>n/2(0 <= pk < n,1 < k <= m)，
 * 则称x为A的主元素。
 * 例如A= (0，5，5，3，5，7，5，5)，
 * 侧为A为主元素；
 * 又如A=(0，5，5，3，5，1，5，7)，
 * 则 A中没有主元素。
 * 假设A中的n个元素保存在一个一维数组中，
 * 请设计一个尽可能高效的算法，
 * 找出A的主元素。
 * 若存在主元素，
 * 则输出该元素；否则输出-1。
 *
 * reference:https://leetcode.com/problems/majority-element/discuss/51613/O(n)-time-O(1)-space-fastest-solution
 */
#include <stdio.h>

#define NOT_FOUND -1

/**
 * 寻找主元,-1(#NOT_FOUND) 表示主元
 * @param  nums   数组
 * @param  length 数组长
 * @return        主元
 */
int get_major(int *nums, int length) {
  int major = nums[0];
  int margin = 1;  // 第一个元素领先一票

  for (int i = 1; i < length; ++i) {
    if (nums[i] == major) {
      ++margin;
    } else {
      --margin;
      if (margin < 0) {  // 当前非主元与主元相同
        major = nums[i];
        margin = 0;
      }
    }
  }

  if (margin <= 0) {
    return NOT_FOUND;  // -1 表示无主元
  }
  return major;
}

int main() {
  printf("test1:\n\tinput:\t0,5,5,3,5,7,5,5\n");
  printf("\texpect:\t5\n");
  int test1[8] = {0, 5, 5, 3, 5, 7, 5, 5};
  printf("\toutput:\t%d\n", get_major(test1, 8));
  /** output
   * test1:
   *     input:  0,5,5,3,5,7,5,5
   *     expect: 5
   *     output: 5
   */

  printf("test2:\n\tinput:\t0,5,5,3,5,1,5,7\n");
  printf("\texpect:\t-1\n");
  int test2[8] = {0, 5, 5, 3, 5, 1, 5, 7};
  printf("\toutput:\t%d\n", get_major(test2, 8));
  /** output
   * test2:
   *     input:  0,5,5,3,5,1,5,7
   *     expect: -1
   *     output: -1
   */

  printf("test2:\n\tinput:\t1,3,1,1,4,1,1,5,1,1,6,2,2\n");
  printf("\texpect:\t1\n");
  int test3[13] = {1, 3, 1, 1, 4, 1, 1, 5, 1, 1, 6, 2, 2};
  printf("\toutput:\t%d\n", get_major(test3, 13));
}
