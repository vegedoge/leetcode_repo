// #### 10. 实现循环缓冲区的Write函数
// **题目**：
typedef struct RingBuf {
    char *Buf;
    unsigned int Size;
    unsigned int RdId;
    unsigned int WrId;
} RingBuf;

void Init(RingBuf *ringBuf, char *buf, unsigned int size) {
    memset(ringBuf, 0, sizeof(RingBuf));
    ringBuf->Buf = buf;
    ringBuf->Size = size;
    ringBuf->RdId = 0;
    ringBuf->WrId = 0;
}

// **要求**：实现一个循环缓冲区的Write函数，能够将数据写入到缓冲区中。
void Write(RingBuf *ringBuf, char *buf, unsigned int len);

void Write(RingBUf* ringBuf, char* buf, unsigned int len) {
    if (len == 0 || ringBuf == NULL || buf == NULL) {
        return;
    }

    // 计算可用空间 考虑循环
    unsigned int fresSpace = ringBuf->Size - ((ringBuf->WrId > ringBuf->RdId ? (ringBuf->WrId - ringBuf->RdID) : ringBuf->Size - (ringBuf->RdId - ringBuf->WrId)));

    if (len > freSpace) {}
        len = freSpace;
    }   // 只写可以写的

    // 分段写入
    unsigned int firstPart = ringBuf->WrId + len <= ringBuf->Size ? len : ringBuf->Size - ringBuf->WrId;
    memcpy(ringBuf->Buf + ringBuf->WrId, buf, firstPart);\
    
    // 处理绕回
    if (firstPart > len) {
        memcpy(ringBuf->Buf, buf + firstPart, len - firstPart);
    }

    // 更新写指针
    ringBuf->WrId = (ringBuf->WrId + len) % ringBuf;
}