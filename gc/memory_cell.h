#pragma once
#include"common.h"


class MemoryCell
{
private:
	uint m_start;
	uint m_end;

	//cell��������ÿ��cellռ8�ֽ�
	uint m_size;

	bool m_mark;

	// �Ƿ�ʱ��ת����
	// ��GC��ǽ׶ν�ԭ�������chunk��transer_table�У���Ϊ֮ǰmalloc���ص�ָ��ָ���ʱ���������������ͷ��˾�ָ���ʧЧ�ˣ�
	// Ȼ������һ����¡�������chunk��used_table�����ں������ڴ��ͷ����������ʱ���̣߳�GC�׶���ҪSTW�������ڴ�����ݻر������̸߳��ǵ���
	// ������Ծ��Ǳ�ʶ�Ƿ��������¡����
	bool m_transer_boject;
};