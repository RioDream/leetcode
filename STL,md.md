##Allocator

	http://cissco.iteye.com/blog/379093
	

##Vector

http://www.2cto.com/kf/201204/126704.html

	template<class _Ty, 
    class _Ax = allocator<_Ty> > 
    
	template<class _Ty,
	 class _Ax = allocator<_Ty> >第二个参数定义内存模型。我们一般采用默认的内存模型。

###Vector::内部数据结构

vector模塑出一个动态数组。vector将其元复制到内部的动态数组中。元素之间总是存在某种顺序，它是一种有序群集。支持随即存取。它的迭代器是随机存取迭代器，所以对任何一个STL算法都奏效。

向vector添加一个元素或者删除其中的一个元素，其后的所有元素都要移动位置，每一次移动都要调用赋值操作符。所以，在末端添加或删除元素，性能很好。但是在前段或者中部的话，性能较差。

vector优异性能的秘诀之一是它配置比其所容纳的元素所需更多的内存。我们需要了解大小和容量的关系。

函数size()可以返回vector的大小，即vector中实际元素的个数。

而capacity()返回容量，是当前的vector所实际能够容纳的元素的数量。它应该总是大于或者等于vector的大小。如果需要向vector中放置比capacity更多的元素，则需要重新配置内部存储器。vector的容量也会随之增长。

vector的容量十分重要，是因为：

1、一旦内存重新配置，与之相关的所有的reference、pointers、iterators都会失效。

2、内存配置很费时。

解决这个问题的方法有：

1、可以使用reserve()保留适当容量，减少重新配置内存的次数。示例代码：

	vector<string> sentence(1); 
	sentence.reserve(50); 
	vector<string> sentence(1);
	sentence.reserve(50);

2、在初始化期间向构造函数传递附加参数，构造出足够的空间。

	vector<T> v(5); 
	vector<T> v(5);
	
当然，这种元素的型别必须提供默认构造函数。但是如果元素的型别比较复杂，初始化操作也很耗时。如果只是为了保留足够的内存，使用方法1较好。


注意：reserve不能缩减vector的容量。由此，我们可以知道，即使删除元素，其reference、pointers、iterators也会继续有效，指向动作发生前的位置。

但是插入操作可能使reference、pointers、iterators失效（因为可能会导致重新配置空间）。

###Vector::重新分配内存

http://www.360doc.com/content/13/0917/13/6432946_315151308.shtml

http://www.cnblogs.com/zhengyuhong/archive/2013/12/13/3473809.html

http://blog.csdn.net/xiajun07061225/article/details/7438782

	#include <iostream>
	#include <vector>
	
	using namespace std;
	
	void print(vector<int> v){
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
	
	int main() {
		vector<int> v(1); //调用默认构造函数，创造一个元素
		cout<<v[0]<<endl;
		cout<<v.size()<<endl; //size是1
		cout<<v.capacity()<<endl;
	
		cout<<endl;
	
		v.reserve(5); //预留空间， 指定capacity为5， 有可能造成重新分配内存
		cout<<v.size()<<endl;
		cout<<v.capacity()<<endl;
	
		cout<<endl;
	
		v.resize(6,1); //对于vector还不存在的元素使用默认构造函数构造进去, 可能会造成内存重新分配
		print(v);
	
	
		// your code goes here
		return 0;
	} 



###Vector::时间

随机访问每个元素。 **O(1)**

**末尾** 增加或删除元素所需时间与元素数目无关。  **O(1)**

**中间或开头** 增加或删除元素所需时间随元素数目呈线性变化。 **O(n)**


###Vector::内存管理###

可动态增加或减少元素，内存管理自动完成。 

但程序员可以使用reserve()成员函数来管理内存。

vector的迭代器在内存重新分配时将失效（它所指向的元素在该操作的前后不再相同）, 那么什么时候会重新分配内存呢。当把超过 capacity()-size()个元素插入 vector中时，会超过capacity， 内存会重新分配，所有的迭代器都将失效；

否则，指向当前元素以后的任何元素的迭代器都将失效。

当删除元素时，指向被删除元素以后的任何 元素的迭代器都将失效。

另外要注意一点。对于deque和vector来说，尽量少用erase(pos)和erase(beg,end)。因为这在中间删除数据后会导致后面的数据向前移动，从而使效率低下


##Deque

	template<class _Ty, class _Ax = allocator<_Ty> >
	class deque;
	
###Deque::内部结构

deque是一种优化了的对序列两端元素进行添加和删除操作的基本序列容器。通常由一些独立的区块组成，第一区块朝某方向扩展，最后一个区块朝另一方向扩展。它允许较为快速地随机访问但它不像vector一样把所有对象保存在一个连续的内存块，而是多个连续的内存块。并且在一个映射结构中保存对这些块以及顺序的跟踪。

其内部结构如下图所示：

![](http://up.2cto.com/2012/0410/20120410092902676.jpg)

###Deque::特点


1、支持随机访问，即支持[]以及at()，但是性能没有vector好。

2、可以在内部进行插入和删除操作，但性能不及list。

###Deque::比较

deque和vector的不同之处：


1、两端都能够快速插入和删除元素。vector只能在尾端进行。

2、deque的元素存取和迭代器操作会稍微慢一些。因为deque的内部结构会多一个间接过程。

3、迭代器是特殊的智能指针，而不是一般指针。它需要在不同的区块之间跳转。

4、deque可以包含更多的元素，其max_size可能更大。因为不止使用一块内存。

5、不支持对容量和内存分配时机的控制。

注意：在除了首尾两端的其他地方插入和删除元素，都将会导致指向deque元素的任何pointers、references、iterators失效。不过，deque的内存重分配优于vector。因为其内部结构显示不需要复制所有元素。

6、deque的内存区块不再被使用时，会被释放。deque的内存大小是可缩减的。不过，是不是这么做以及怎么做由实作版本定义。

 

deque和vector相似的特性：

1、在中间部分插入和删除元素相对较慢，因为所有元素都要被移动。

2、迭代器属于随即存取迭代器。

 

最好采用deque的情形：

1、需要在两端插入和删除元素。

2、无需引用容器内的元素。

3、要求容器释放不再使用的元素。



