# 1-生成并构建一个xmake项目

## 在终端操作

- 创建项目: shell中输入

```bash
xmake create -l c++ -P <project_name>
```

会生成名为`project_name`的项目, 目录结构如下所示

```
hello
├── src
│   └── main.cpp
└── xmake.lua

2 directories, 2 files
```

- 构建项目:

```bash
xmake build <project_name>
```

会生成build目录, 可执行文件和其他构建产生的文件输出到这个目录.

- 运行项目:

```bash
xmake run <project_name>
```

## vscode配置
