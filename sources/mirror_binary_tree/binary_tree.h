#ifndef TEST_MIRROR_BINARY_TREE_BINARY_TREE
#define TEST_MIRROR_BINARY_TREE_BINARY_TREE

template<typename T>
struct Node{
    Node() = default;
    Node(const T& val ): payload(val), left(nullptr), right(nullptr){};
    Node* left = nullptr, *right = nullptr;
    T payload{};
};

#endif /* TEST_MIRROR_BINARY_TREE_BINARY_TREE */
