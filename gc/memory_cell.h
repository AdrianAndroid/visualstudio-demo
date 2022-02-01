#pragma once
#include"common.h"


class MemoryCell
{
private:
	uint m_start;
	uint m_end;

	//cell的数量，每个cell占8字节
	uint m_size;

	bool m_mark;

	// 是否时中转对象
	// 在GC标记阶段将原对象放入chunk的transer_table中（因为之前malloc返回的指针指向的时这个对象，这个对象释放了旧指针就失效了）
	// 然后生成一个克隆对象放入chunk的used_table中用于后续的内存释放与整理（如果时多线程，GC阶段需要STW，否则内存的数据回被其他线程覆盖掉）
	// 这个属性就是标识是否是这个克隆对象
	bool m_transer_boject;
};