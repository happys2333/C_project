using LinearAlgebra#dot to get the answer
#Julia core using BigFloat
# begin at 1

path=pwd()
fname = "results.txt"
fout=open(fname,"w")
function readfile(filename)
    fread=open(filename,"r")
    for line in eachline(f)
	    print(line, "\n")
	end
end
function printtofile(result)#file output
    println(fout,result)
end
function commandMode()
        println("您正在使用的是 命令行 模式，请输入您的向量的维度")
        dim = readline()

        println("请输入您的向量个数")
        n = readline()

        for i = 1:n

        end

end
function fileMode()




end
print("Julia核心已经初始化完成，正在进入主程序")
print("欢迎继续使用本程序，输入-q退出程序，输入-f使用文件读取模式，输入-c进入命令行读取模式")
cmd = readline()
while cmd!="-q"
    if cmd[0]!='-'
        print("wrong command, please try again")
    end
elseif cmd[1]=='f'
    fileMode()
end
elseif cmd[1]=='c'
    commandMode()
end
else
    print("wrong command, please try again")
end
end
