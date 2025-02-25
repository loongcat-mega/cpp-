
STL 提供了一套全面的容器类型，包括顺序容器、关联容器和容器适配器。以下是简要的概述:

- 顺序容器：
顺序容器提供了一个接口，其中元素按顺序排列。虽然可以按顺序使用元素，但其中一些容器 使用连续存储，而其他容器则不使用。STL 包含以下顺序容器:

array 是固定大小的序列，在连续存储器中保存特定数量的元素，分配之后就不能改变大小。 这是最简单和访问速度最快的连续存储容器。 
vector 就像数组，可以缩小和扩大。其元素是连续存储的，因此改变大小可能涉及分配内存和 移动数据的开销。vector 可以保留额外的空间来降低操作成本。在 vector 容器后面以外的任何 位置插入和删除元素将触发元素的重新排列，以保持内存的连续存储。
list 是双链表结构，允许在常量 (O(1)) 时间内插入和删除元素。遍历列表的时间为线性 O(n)。 单链表的变体是 forward_list，只能向前迭代。forward_list 会使用更少的空间，并且比双链表 更高效，但缺少一些功能。 
deque(通常发音为 deck) 是双端队列，是连续的容器，可以在两端展开或收缩。deque 允许随 机访问它的元素，很像 vector，但不保证存储的连续性。

- 关联容器

关联容器将一个键与每个元素关联起来。元素是通过键来引用的，而不是其在容器中的位置。 STL 关联容器包括以下容器:

set 是一个关联容器，每个元素也是自己的键，元素通常按某种二叉树方式排序。set 中的元素 不可变，不能修改，但是可以插入和移除。set 中的元素是唯一的，不允许重复。set 可以根据 排序操作符按顺序进行迭代。 
multiset 就像一个具有非唯一键的集合，允许重复。 
unordered_set 就像一个不按顺序迭代的集合。元素不按特定顺序排序，而是根据哈希值进行 组织，以便快速访问。
unordered_multiset 类似于 unordered_set，允许重复。
map 是键-值对的关联容器，其中每个键都映射到特定的值 (或有效负载)。键和值的类型可能 不同；键是唯一的，但值不是。map 根据其排序操作符，按键的顺序进行迭代。
ultimap 类似于具有非唯一键的映射，允许重复键。 
unordered_map 就像一个没有按顺序迭代的 map。
unordered_multimap 类似于 unordered_map，允许重复。

# 使用参数函数从容器中删除项

# 常量时间从未排序的向量中删除项

# 安全访问vector元素

# 保持vector元素的顺序

# 高效地将元素插入到map中

# 高效地修改map项的键值

# 自定义键值的unordered_map


# 使用set对输入进行排序和筛选

# 简单的RPN计算机去deque

# 使用map的词频计数器

# 找出含有相应长句的vector


# 使用multimap制作待办事项列表


