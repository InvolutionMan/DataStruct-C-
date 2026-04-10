#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    string data;   // 结点值
    int parent;    // 父节点下标，根结点为 -1
};

struct ParentTree {
    vector<TreeNode> nodes;
    int root;      // 根结点下标
};

ParentTree createTree() {
    ParentTree tree;
    tree.nodes.push_back({"A", -1}); // 0
    tree.nodes.push_back({"B", 0});  // 1
    tree.nodes.push_back({"C", 0});  // 2
    tree.nodes.push_back({"D", 1});  // 3
    tree.nodes.push_back({"E", 1});  // 4

    tree.root = 0;
    return tree;
}

void printTree(const ParentTree& tree) {
    cout << "下标\t数据\t父节点下标\n";
    for (int i = 0; i < tree.nodes.size(); i++) {
        cout << i << "\t" << tree.nodes[i].data << "\t" 
             << tree.nodes[i].parent << endl;
    }
}

void findChildren(const ParentTree& tree, int parentIndex) {
    cout << tree.nodes[parentIndex].data << " 的孩子有：";
    bool hasChild = false;

    for (int i = 0; i < tree.nodes.size(); i++) {
        if (tree.nodes[i].parent == parentIndex) {
            cout << tree.nodes[i].data << " ";
            hasChild = true;
        }
    }

    if (!hasChild) {
        cout << "无";
    }
    cout << endl;
}

int main() {
    ParentTree tree = createTree();

    printTree(tree);
    cout << endl;

    findChildren(tree, 0); // 找 A 的孩子
    findChildren(tree, 1); // 找 B 的孩子

    return 0;
}