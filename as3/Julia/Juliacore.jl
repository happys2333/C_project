print("Julia核心已经初始化完成，正在进入主程序")
print("欢迎继续使用本程序，输入-q退出程序，输入-f使用文件读取模式，输入-c进入命令行读取模式")
cmd = readline()
while cmd!="-q"
     if cmd[0]!='-'
         print("wrong command, please try again")
     end
end