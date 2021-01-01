
#ifndef OPENGUI_FUNC_H
#define OPENGUI_FUNC_H
#include <vector>
template <typename T>
class LinkedLists {
private:
    std::vector<T> list;
    public:
    bool add(T t){
        list.push_back(t);
        return true;
    }
    bool remove(int i){
        std::vector<T>::iterator It;
        It = list.begin();
        for(int j=0;j<list.size();j++,It++)
        {
            if(j==i){
                list.erase(It);
                return true;
            }
        }
        return false;
    }
    bool remove(T t){
        std::vector<T>::iterator it;
        it= find(list.begin(),list.end(),t);
        if(it!=list.end()){
            list.erase(it);
            return true;
        }
        return false;
    }
    T get(int i){
        return list[i];
    }
    bool set(int i,T t){
        if(i>=list.size()){
            return false;
        }else{
            list[i]=t;
            return true;
        }
    }
};






#endif //OPENGUI_FUNC_H