#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int array[100] = {0};
//使用数组的数组缺陷
	//1 数组是静态空间，一旦分配后，不可以动态扩展。一旦分配少了，可能不够用，如果分配多了，可能造成浪费
	//2 头插和头删效率很低 

//为了解决上述的缺陷，链表出现了

//一个链表是由节点组成
	//节点有两个部分组成，数据域和指针域


//链表的分类
	//方式一
		//静态链表（分配在栈上）
		//动态链表（分配在堆区）
	//方式二
		//单向链表
		//双向链表
		//单向（双向）循环链表 
			// 最后一个元素的指针域再指向第一个元素


//链表
//带头的节点 头结点，只维护指针域，不维护数据域。头结点永远固定保存位置