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
#include <math.h>
#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * 获得两个升序数列的中位数
 * @param  nums_a 数组A
 * @param  nums_b 数组B
 * @param  length 他们的长度
 * @return        中位数
 */
int get_median(int* nums_a, int* nums_b, int length) {
  int left_a = 0, left_b = 0;
  while (length > 1) {
    int new_length = ceil(length / 2);
    int eat = length - new_length;
    length = new_length;

    int middle_a_loc = left_a + new_length - 1;
    int middle_b_loc = left_b + new_length - 1;

    if (nums_a[middle_a_loc] < nums_b[middle_b_loc]) {
      left_a += eat;
    } else {
      left_b += eat;
    }
  }
  return min(nums_a[left_a], nums_b[left_b]);
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
  int nums_31[1] = {5};
  int nums_32[1] = {8};
  printf("%d\n", get_median(nums_31, nums_32, 1));
  // output: 5

  int nums_41[4] = {1, 3, 5, 7};
  int nums_42[4] = {2, 4, 6, 8};
  printf("%d\n", get_median(nums_41, nums_42, 4));
  // output: 4
}
