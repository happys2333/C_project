
#ifndef OPENGUI_FUNC_HPP
#define OPENGUI_FUNC_HPP
#include <vector>
#include <stdexcept>
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
        if (i < 0 || static_cast<size_t>(i) >= list.size()) return false;
        list.erase(list.begin() + i);
        return true;
    }
    bool remove(T t){
        typename std::vector<T>::iterator it;
        it= find(list.begin(),list.end(),t);
        if(it!=list.end()){
            list.erase(it);
            return true;
        }
        return false;
    }
    T& get(int i){
        if (i < 0 || static_cast<size_t>(i) >= list.size())
            throw std::out_of_range("LinkedLists::get index out of range");
        return list[i];
    }
    bool set(int i,T t){
        if(i < 0 || static_cast<size_t>(i) >= list.size()){
            return false;
        }else{
            list[i]=t;
            return true;
        }
    }
    void free(){
        list.clear();
        std::vector<T>().swap(list);
    }
    int size(){
        return static_cast<int>(list.size());
    }

};


#endif //OPENGUI_FUNC_HPP
