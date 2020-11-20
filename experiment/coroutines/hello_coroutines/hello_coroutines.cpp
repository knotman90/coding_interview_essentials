#include<iostream>
#include <experimental/coroutine>

void f(){
    std::cout<<"start"<<std::endl;
    co_await std::experimental::suspend_always();
    std::cout<<"end"<<std::endl;
}

int main(){

    f();
    return 0;
}