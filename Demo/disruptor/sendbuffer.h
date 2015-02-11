#ifndef _SENDBUFFER_H_
#define _SENDBUFFER_H_

#include <atomic>

class SendBuffer
{
public:

    SendBuffer(size_t capacity = 65536);
    ~SendBuffer();

    // �򻺳���д������
    bool Push(const char* data, size_t len);

    // ���ػ�������������
    char* Peek(size_t& len);

    // ����ָ����������
    bool Pop(size_t len);

private:
    char* _buffer;
    size_t _capacity;
    size_t _capacity_mask;
    std::atomic_ullong _alloc_count;
    std::atomic_ullong _write_count;
    std::atomic_llong _idle_count;
    int64_t _read_count;
};

#endif