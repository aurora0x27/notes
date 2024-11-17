# 2.基础知识

[TOC]

## 1.寄存器

***主要记忆以下寄存器作用:***

- `rip` 当前指令地址寄存器

- `rsp` 当前栈帧栈顶地址寄存器

- `rbp` 当前栈帧栈底地址寄存器

## 2.汇编指令(intel风格为例)

- `mov x, y`: 将y处的值放进x处

- `add x, y`: 相当于C语句`x += y;`

- `sub x, y`: 相当于C语句`x -= y;`

- `xor x, y`: x, y两数字做异或, 常用于使寄存器归零

- `lea x, y`: "Load Effective Address", 现在常用于计算.

```asm
lea rax, [rbp - 0x18] ; 等价于C代码 rax = rbp - 0x18;
```

- `call`: 调用函数

- `ret`: 返回调用地点

- `jmp x`: 跳转到地址x

- J开头指令(`jmp`除外): gcc特有指令

- `cmp x, y`: 和sub类似, 但是减法过后的结果不会赋值给x, 结果给下一条指令

```asm
cmp    al,0x61
jne    0x555555555277 <main+106> ; jne: 如果不等于零就跳转
; 如果al != 0x61, 就跳转到0x555555555277处执行
```

- `and x, y`: x, y做与运算, 运算结果给x

- `test x, y`: 相当于x和y做与运算, 但是运算结果不储存, 和cmp差不多

> Note
>
> 汇编中常见的取址长度
>
> `WORD`: 2字节
>
> `DWORD`: 4字节
>
> `QWORD`: 8字节

## 3.gcc重要选项

- `-no-pie` 不要生成动态链接的位置无关的可执行文件(内部全部是绝对地址)

- `-m32` 编译32位代码

- `-static` 静态链接

- `-fno-stack-protector` 关闭栈保护
