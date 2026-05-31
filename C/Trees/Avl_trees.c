// #here we go 350 lines of code


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

// Creates a fresh leaf node
Node* newNode(int key)
{
    Node* node   = (Node*)malloc(sizeof(Node));
    node->key    = key;
    node->height = 1;      // every new node starts as a leaf, height = 1
    node->left   = NULL;
    node->right  = NULL;
    return node;
}

// Returns height of a node — returns 0 if NULL so we never crash
int getHeight(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// Balance factor = left height minus right height
// Positive  →  left-heavy
// Negative  →  right-heavy
// Zero      →  perfectly balanced
int getBalance(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

int maxInt(int a, int b)
{
    return (a > b) ? a : b;
}

Node* rightRotate(Node* x)
{
    Node* y  = x->left;    // y will become the new subtree root
    Node* T2 = y->right;   // T2 is the piece that gets rehomed

    // --- do the rotation ---
    y->right = x;          // x drops down to become y's right child
    x->left  = T2;         // T2 fills the empty spot on x's left

    // update heights — ALWAYS update x first because x is now lower
    x->height = 1 + maxInt(getHeight(x->left), getHeight(x->right));
    y->height = 1 + maxInt(getHeight(y->left), getHeight(y->right));

    return y;              // y is now the root of this subtree
}

Node* leftRotate(Node* x)
{
    Node* y  = x->right;   // y will become the new subtree root
    Node* T2 = y->left;    // T2 is the piece that gets rehomed

    // --- do the rotation ---
    y->left  = x;          // x drops down to become y's left child
    x->right = T2;         // T2 fills the empty spot on x's right

    // update heights — x first because x is now lower
    x->height = 1 + maxInt(getHeight(x->left), getHeight(x->right));
    y->height = 1 + maxInt(getHeight(y->left), getHeight(y->right));

    return y;              // y is now the root of this subtree
}

Node* insert(Node* node, int key)
{
    // ── STEP 1: Standard BST insert ───────────────────────────────────
    // Walk left or right until we hit NULL, place new node there.

    if (node == NULL)
    {
        return newNode(key);        // base case: empty spot found
    }

    if (key < node->key)
    {
        node->left  = insert(node->left,  key);   // go left
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);   // go right
    }
    else
    {
        return node;    // duplicate key — AVL trees don't allow duplicates
    }

    // ── STEP 2: Update height of THIS node ────────────────────────────
    // After recursion unwinds, every ancestor recalculates its height.
    // Height = 1 (for self) + taller of the two children.

    node->height = 1 + maxInt(getHeight(node->left),
                               getHeight(node->right));

    // ── STEP 3: Check balance ──────────────────────────────────────────
    // If |balance| <= 1, this node is fine. If > 1, we must fix it.

    int balance = getBalance(node);

    // ── STEP 4: Fix imbalance — exactly one of 4 cases applies ────────

    // ── Case 1: Left Left ──────────────────────────────────────────────
    // New key went into the LEFT child's LEFT subtree.
    // One right rotation fixes it.
    //
    //       30  ← balance = +2 (left-heavy)
    //      /
    //     20
    //    /
    //   10  ← inserted here

    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // ── Case 2: Right Right ────────────────────────────────────────────
    // New key went into the RIGHT child's RIGHT subtree.
    // One left rotation fixes it.
    //
    //   10  ← balance = -2 (right-heavy)
    //     \
    //      20
    //        \
    //         30  ← inserted here

    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // ── Case 3: Left Right ─────────────────────────────────────────────
    // New key went into the LEFT child's RIGHT subtree.
    // Two rotations: left-rotate the child first, then right-rotate root.
    //
    //       30  ← balance = +2
    //      /
    //     10
    //       \
    //        20  ← inserted here

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);   // step 1: straighten child
        return rightRotate(node);              // step 2: fix root
    }

    // ── Case 4: Right Left ─────────────────────────────────────────────
    // New key went into the RIGHT child's LEFT subtree.
    // Two rotations: right-rotate the child first, then left-rotate root.
    //
    //   10  ← balance = -2
    //     \
    //      30
    //     /
    //    20  ← inserted here

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);  // step 1: straighten child
        return leftRotate(node);                 // step 2: fix root
    }

    // ── No imbalance — return node unchanged ──────────────────────────
    return node;
}
// Inorder always prints a BST in sorted order — good sanity check
void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}
// Returns the node with the smallest key in a subtree
// Always go left until you can't — that's the minimum
Node* minValueNode(Node* node)
{
    Node* current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* node, int key)
{
    // ── STEP 1: Standard BST delete ───────────────────────────────────

    if (node == NULL)
    {
        return node;    // key not found, nothing to do
    }

    if (key < node->key)
    {
        // key is in the left subtree
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key)
    {
        // key is in the right subtree
        node->right = deleteNode(node->right, key);
    }
    else
    {
        // ── Found the node to delete — 3 sub-cases ────────────────────

        // Sub-case A: node has only right child OR no children
        if (node->left == NULL)
        {
            Node* temp = node->right;  // could be NULL (no children)
            free(node);
            return temp;               // temp takes node's place
        }

        // Sub-case B: node has only left child
        else if (node->right == NULL)
        {
            Node* temp = node->left;
            free(node);
            return temp;               // temp takes node's place
        }

        // Sub-case C: node has TWO children
        // Strategy: find inorder successor (smallest in right subtree),
        // copy its key into this node, then delete the successor below.
        else
        {
            Node* temp = minValueNode(node->right);  // inorder successor

            node->key = temp->key;   // overwrite current key with successor's key

            // now delete the successor from the right subtree
            node->right = deleteNode(node->right, temp->key);
        }
    }

    // ── STEP 2: Update height ──────────────────────────────────────────
    node->height = 1 + maxInt(getHeight(node->left),
                               getHeight(node->right));

    // ── STEP 3: Check balance ──────────────────────────────────────────
    int balance = getBalance(node);

    // ── STEP 4: Fix imbalance — same 4 cases as insertion ─────────────

    // ── Case 1: Left Left ──────────────────────────────────────────────
    // Left subtree is too tall AND left child is left-heavy or balanced

    if (balance > 1 && getBalance(node->left) >= 0)
    {
        return rightRotate(node);
    }

    // ── Case 2: Left Right ─────────────────────────────────────────────
    // Left subtree is too tall BUT left child is right-heavy

    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left = leftRotate(node->left);   // straighten child first
        return rightRotate(node);
    }

    // ── Case 3: Right Right ────────────────────────────────────────────
    // Right subtree is too tall AND right child is right-heavy or balanced

    if (balance < -1 && getBalance(node->right) <= 0)
    {
        return leftRotate(node);
    }

    // ── Case 4: Right Left ─────────────────────────────────────────────
    // Right subtree is too tall BUT right child is left-heavy

    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);  // straighten child first
        return leftRotate(node);
    }

    return node;    // no imbalance, return unchanged
}

int main()
{
    Node* root = NULL;

    // build the tree
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 35);
    root = insert(root, 50);

    printf("Before deletion: ");
    inorder(root);                      // 10 20 25 30 35 40 50
    printf("\n");

    // ── delete a leaf ─────────────────────────────────────
    root = deleteNode(root, 10);
    printf("After deleting 10 (leaf):          ");
    inorder(root);                      // 20 25 30 35 40 50
    printf("\n");

    // ── delete a node with one child ──────────────────────
    root = deleteNode(root, 20);
    printf("After deleting 20 (one child):     ");
    inorder(root);                      // 25 30 35 40 50
    printf("\n");

    // ── delete a node with two children ───────────────────
    root = deleteNode(root, 40);
    printf("After deleting 40 (two children):  ");
    inorder(root);                      // 25 30 35 50
    printf("\n");

    printf("Root key: %d\n", root->key);

    return 0;
}

