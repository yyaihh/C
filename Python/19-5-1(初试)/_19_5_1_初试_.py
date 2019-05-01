print("这是第一篇用Python写的代码")
print("Hello world必须有哈哈哈")
print("hi,小白,你好，欢迎学习Python")
s=input("刚看完复联四,请问您觉得美队需要挣钱吗？需要or不需要？")
if s=="需要":
	money=int(input("您觉得美国队长的月薪多少呢?"))
	if money<=500:
		print("欢迎美队进入史塔克穷人帮前三名")
		if 100<money<=500:
			print("请美队找弗瑞队长加薪")
		else:
			print("恭喜美队荣获“美元队长”称号！")
	elif 500<money<=1000:
		print("祝贺美队至少可以温饱了")
	elif money>1000:
		print("经济危机都难不倒美队！")
		if 1000<money<=20000:
			print("美队快比钢铁侠有钱了！")        
		else :
			print("美队是不是来自于瓦坎达国？")
elif s=="不需要":
    print("再见了您嘞")
else :
	print("乱输[○･｀Д´･ ○]")
