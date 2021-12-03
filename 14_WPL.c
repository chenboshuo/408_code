/**
 * 二叉树的带权路径长度(WPL)
 * 是二叉树中所有叶结点的带权路径长度之和。
 * 给定一棵二叉树 T，
 * 采用二叉链表存储，结点结构为：
 * left|weight|right
 * 其中叶结点的 weight 域保存该结点的非负权值。
 * 设 root 为指向 T 的根结点的指针，
 * 请设计求 T 的 WPL 的算法，要求：
 * 1）给出算法的基本设计思想；
 * 2）使用 C 或 C++语言，给出二叉树结点的数据类型定义；
 * 3）根据设计思想，采用 C 或 C++语言描述算法，关键之处给出注释。
 *
 * 例如(https://blog.csdn.net/weixin_41546300/article/details/102879137)
 *           *
 *         /   \
 *        *     *
 *      /  \   / \
 *     7   5  2  4
 * WPL = (7+5+2+4)*2 = 36
 */
#include <stdio.h>
struct WeightedBinTree {
  int weight;
  struct WeightedBinTree *left, *right;
};

/**
 * 递归计算WPL的函数
 * @param  node       当前的节点
 * @param  depth      结点深度
 * @return            截止到该结点的WPL值
 */
int _calculate_WPL(struct WeightedBinTree* node, int depth) {
  if (!node->left && !node->right) {
    return node->weight * depth;
  }
  return (_calculate_WPL(node->left, depth + 1) +
          _calculate_WPL(node->right, depth + 1));
}

/**
 * 计算给定二叉树的WPL
 * @param  root 根结点
 * @return      最终WPL的值
 */
int get_WPL(struct WeightedBinTree* root) {
  return _calculate_WPL(root, 0);  // 计算左右空结点时实际上计算了两边
}

int main() {
  // test 1
  struct WeightedBinTree case_1[7];
  // case_1[0].left = case_1[1];
  // case_1[1].right = case_1[1];
  for (int i = 0; i <= 2; ++i) {
    case_1[i].left = &case_1[2 * i + 1];
    case_1[i].right = &case_1[2 * i + 2];
  }
  int weights[4] = {7, 5, 2, 4};
  for (int i = 3; i <= 6; ++i) {
    case_1[i].weight = weights[i - 3];
    case_1[i].left = NULL;
    case_1[i].right = NULL;
  }
  printf("WPL=%d\n", get_WPL(case_1));
  /// output: WPL=36

  return 0;
}
