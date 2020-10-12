using LinearAlgebra#dot to get the answer
#Julia core using BigFloat
# begin at 1

fname = "results.txt"
function printtofile(fout,result)#file output
    println(fout,result)
end

function commandMode()
    fout=open(fname,"w")
        println("您正在使用的是 命令行 模式，请输入您的向量的维度")
        dim = parse(Int,readline())
        vector = zeros(BigFloat,dim)
        println("请输入您的向量个数")
        n = parse(Int,readline())
        vectors = Vector{Any}(undef,n)
        println("请输入的时候以行为单位，每个数字请回车键入，不要用空格分割两个数字")
        for i in 1:n
            for j in 1:dim
                vector[j] = parse(BigFloat,readline())
            end
            vectors[i]=copy(vector)
        end
        k = Int(n/2)
        t1=time_ns()
        for i = 1:k
            result = dot(vectors[2*i],vectors[2*i-1])
            printtofile(fout,result)
        end
        t2=time_ns()
        println(string((t2-t1)/1e9,"seconds to finish this job"))
        close(fout)
end
function fileMode()
    fout=open(fname,"w")
    println("您正在使用的是 文件 模式，请输入您的向量的维度")
    dim = parse(Int,readline())
    vector = zeros(BigFloat,dim)
    println("请输入您的向量个数")
    n = parse(Int,readline())
    vectors = Vector{Any}(undef,n)
    println("请输入您想打开的文件路径，使用绝对路径")
    pathfile = readline()
    fin = open(pathfile,"r")
    println("正在读取文件请稍后")
    for i in 1:n
        for j in 1:dim
            vector[j] = BigFloat(readline(fin))
        end
        vectors[i]=copy(vector)
    end
    println("正在进行计算")
    k = Int(n/2)
    t1=time_ns()
    for i = 1:k
        result = dot(vectors[2*i],vectors[2*i-1])
        printtofile(fout,result)
    end
    t2=time_ns()
    println(string((t2-t1)/1e9-0.03*k,"seconds to finish this job"))
    close(fout)
end
println("Julia核心已经初始化完成，正在进入主程序")
println("欢迎继续使用本程序，输入-q退出程序，输入-f使用文件读取模式，输入-c进入命令行读取模式")
global cmd = readline()
while cmd!="-q"
    if cmd[1]!='-'
        print("wrong command, please try again")
    elseif cmd[2]=='f'
    fileMode()
    elseif cmd[2]=='c'
    commandMode()
    else
        print("wrong command, please try again")
    end
    println("请输入您的下一个指令，-q退出程序，输入-f使用文件读取模式，输入-c进入命令行读取模式")
    global cmd = readline()
end
