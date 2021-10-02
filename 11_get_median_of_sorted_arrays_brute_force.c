/**
 * 一个长度为 L（L≥1）的升序序列 S，
 * 处在第 ceil(L / 2) 个位置的数称为 S 的中位数。
 * 例如，若序列 S1=（11,13,15,17,19），
 * 则 S1 的中位数是 15，
 * 两个序列的中位数是含它们所有元素的升序序列的中位数。
 * 例如，若 S2=（2,4,6,8,20），
 * 则 S1 和 S2 的中位数是 11。
 * 现在有两个等长升序序列 A 和 B，
 * 试设计一个在时间和空间两方面都尽可能高效的算法，
 * 找出两个序列 A 和 B 的中位数。
 */
#include <stdio.h>

/**
 * 获得两个升序数列的中位数
 * @param  nums_a 数组A
 * @param  nums_b 数组B
 * @param  length 他们的长度
 * @return        中位数
 */
int get_median(int* nums_a, int* nums_b, int length) {
  int i = 0, j = 0;  // 两个序列的位置
  int cur_median;    // 当前中位数的值
  for (int merged_loc = 0; merged_loc < length; ++merged_loc) {
    if (j >= length ||  // b 数组用完
        (i < length && nums_a[i] <= nums_b[j])) {
      cur_median = nums_a[i];
      ++i;
    } else {
      cur_median = nums_b[j];
      ++j;
    }
  }
  return cur_median;
}

int main() {
  // test 1
  int nums_a[5] = {11, 13, 15, 17, 19};
  int nums_b[5] = {2, 4, 6, 8, 20};
  printf("%d\n", get_median(nums_a, nums_b, 5));
  // output: 11

  // test 2
  int nums_21[5] = {1, 2, 3, 4, 5};
  int nums_22[5] = {6, 7, 8, 9, 10};
  printf("%d\n", get_median(nums_21, nums_22, 5));
  // output: 5

  // test 3
  int nums_31[1] = {0};
  int nums_32[1] = {1};
  printf("%d\n", get_median(nums_31, nums_32, 1));
  // output: 0
}
