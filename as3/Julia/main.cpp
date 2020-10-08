#include <julia.h>
#include <zconf.h>
#include <string>
using namespace std;
JULIA_DEFINE_FAST_TLS()
string path;
void setpathofjulia(){
    path ="include(\"";
    char *buffer;
    if((buffer = getcwd(NULL, 0)) == NULL)
    {
        perror("getcwd error");
    }
    else
    {
        path+=buffer;
        free(buffer);
    }
    path= path.substr(0,path.find("as3/"));
    path += "as3/Julia/Juliacore.jl\")";
}
int main(int argc, char *argv[])
{

    setpathofjulia();
    printf("");
    jl_init();
    jl_eval_string(path.c_str());
    jl_atexit_hook(0);
    return 0;
}