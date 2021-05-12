/**
 * 设将 n(n>1)个整数存放到一维数组 R 中。
 * 试设计一个在时间和空间两方面都尽可能高效的算法。
 * 将 R 中保存的序列循环左移 p(0<p<n)个位置,
 * 即将 R 中的数据由(X0, X1...Xn-1)变换为
 * (Xp,Xp+1 ...Xn-1, X0, X1...Xp-1)
 */

#include <stdio.h>

/**
 * 反转数组的一部分
 * @param nums  数组
 * @param left  最右边的数据的下标
 * @param right 最左边的数据的下标
 */
void reverse(int* nums, int left, int right) {
  while (left < right) {
    nums[left] ^= nums[right];
    nums[right] ^= nums[left];
    nums[left] ^= nums[right];
    ++left, --right;
  }
}

/**
 * 将数组循环左移动p位
 * @param nums   数组
 * @param length 数组长度
 * @param p      要左移的位数
 */
void left_cycle_shift(int* nums, int length, int p) {
  int end = length - 1;
  reverse(nums, 0, p - 1);  // 将前半部分反转
  reverse(nums, p, end);    // 将后半部分反转
  reverse(nums, 0, end);    // 让数组整体交换顺序
}

int main() {
  int nums[5] = {0, 1, 2, 3, 4};
  left_cycle_shift(nums, 5, 3);
  for (int i = 0; i < 5; ++i) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}
// output:
// 3 4 0 1 2
