// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
 public:
  Node *intersect(Node *quadTree1, Node *quadTree2) {
    if (quadTree1->isLeaf && quadTree2->isLeaf) {
      return new Node(quadTree1->val || quadTree2->val, true);
    }
    bool flag1 = false, flag2 = false;
    if (quadTree1->isLeaf) {
      flag1 = true;
      quadTree1 = new Node(quadTree1->val, quadTree1->isLeaf, quadTree1, quadTree1, quadTree1, quadTree1);
    }
    if (quadTree2->isLeaf) {
      flag2 = true;
      quadTree2 = new Node(quadTree2->val, quadTree2->isLeaf, quadTree2, quadTree2, quadTree2, quadTree2);
    }
    auto res = new Node(false,
                        false,
                        intersect(quadTree1->topLeft, quadTree2->topLeft),
                        intersect(quadTree1->topRight, quadTree2->topRight),
                        intersect(quadTree1->bottomLeft, quadTree2->bottomLeft),
                        intersect(quadTree1->bottomRight, quadTree2->bottomRight));
    if (res->topLeft->isLeaf && res->topRight->isLeaf && res->bottomLeft->isLeaf && res->bottomRight->isLeaf) {
      if (res->topLeft->val == res->topRight->val && res->topLeft->val == res->bottomLeft->val
          && res->topLeft->val == res->bottomRight->val) {
        res->isLeaf = true;
        res->val = res->topLeft->val;
        res->topLeft = nullptr;
        res->topRight = nullptr;
        res->bottomLeft = nullptr;
        res->bottomRight = nullptr;
      }
    }

    if (flag1) delete quadTree1;
    if (flag2) delete quadTree2;
    return res;
  }
};