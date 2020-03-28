# cs122
软件工程：C编码实战篇

## 打包&解包
```bash
tar -zcvf name.tar.gz path_and_files	# 打包
tar -zxvf name.tar.gz					# 解包
```

## GDB
```
gcc -g menu.c -o demo
```

## vim 操作
| :bn  | 当前打开的下一个文件 	  |
| ---- | -------------------- |
|      |                      |
|      |                      |
|      |                      |

---

## 代码风格
- 缩进：4个空格（严格执行）
- 行宽：<100个字符
- 负责表达式中用`()`清晰表达逻辑优先级
- 严格执行`{}`独占一行且成对出现

## 命名
- 类型的成员变量通常用`m_`或`_`来做前缀
- 一般变量使用`lowCamel`风格，第一个单词一般用来表示变量类型，eg. int型变量`iCounter`
- 类型/类/函数名一般都用`Pascal`风格，即所有单词首字母大写
- 类型/类/变量一般用名词或组合名词, eg. `Member`
- 函数名一般用动词或动宾短语，eg. `get/set`,`RenderPage`

## 注释
- 使用英文，保持源代码为ASCII字符格式文件
- 不要解释程序是如何工作的

## "开-闭"原则
> 对于扩展开放，对于修改封闭

## 如何复用？
> 模块复用&系统复用 </b>
> 业务逻辑逻辑层 & 数据存储层

## 将系统模块放在不同的源文件中


---

## 代码设计规范
### 通用原则
	- KISS （ keep it simple & stupid)
		- 一个函数，只做一件事
		- 不要有多份代码做同一件事
	- using design to frame the code (设计与实际保持一致)
		- including pseuducode
	- 不要和陌生人说话
	- 合理利用Control Structures、Data Structures来简化代码
		- 使用数据结构来简化代码
		eg. 累计税收计算
| Bracket | Base  | Percent |
| :-----: | :---: | :-----: |
|    0    |   0   |   10    |
|  10000  | 1000  |   12    |
|  20000  | 2200  |   15    |
|  30000  | 3700  |   18    |
|  40000  | 55000 |   20    |

```cpp
for(int i = 1, level = 0; i < 5; i++)
{
	if(taxable_income > bracket[i])
    level = level + 1;
}
tax = base[level] + percent[level] * (taxable_income - bracket[level]);
```

	- 一定要错误处理 （代码健壮性）
		- Debug版本中所有的参数都要验证是否正确
		- Release版本中从外部传递进来的参数要验证正确性

### 异常处理
	- 断言 (用在肯定的情况)
	`assert(p != NULL);`
	- 错误处理
	```cpp
	p = AllocateNewSpace(); // could be fail
	if(p == NULL)
	{	// error handing.
	}
	else
	{	//use p to do something
	}
	```



