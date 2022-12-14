
> <a name="kfSiH"></a>
### 遍历二叉树的非递归算法


## 中序遍历非递归算法
关键点：在中序遍历过某个节点的整个左子树后，如何找到该节点的根以及右子树
基本思想：
1. 建立一个栈
2. 根节点进栈，遍历左子树
3. 根节点出栈，输出根节点，遍历右子树
（遇见根节点先不访问，将其入栈，继续访问左子树，左子树为空时，访问根
节点出栈，再遍历右子树
创建一个函数，将树的根节点传入，在函数中创建一个空栈，指针变量p指向
根节点，如果p存在且栈不为空，执行if，将当前指向的根节点入栈，不输出
，继续让当前p指向的节点的左孩子赋值给p，即p=p->lchild，访问左子树，
如果存在，则重复以上操作，如果p为空，但栈不为空，则执行else，弹出当
前栈顶元素，令q指向当前访问的根节点，输出其的数值，根输出完，应当遍
历右子树，令p=q->rchild，再次执行时如果p不为空，则执行if，根节点入
栈，不输出，p指向左孩子，重复操作。
















