//
// Created by 鸿昊李 on 2019-04-29.
//

#include "detail.h"
#include <iostream>

//constructor
detail::detail() {
    compare=0;
    access=0;
}

//accessor
int detail::get_compare(){
    return compare;
}
int detail::get_access(){
    return access;
}

//modifier
bool detail::set_compare(unsigned int i){
    compare=i;
    return true;
}
bool detail::set_access(unsigned int i){
    access=i;
    return true;
}
void detail::increment_compare(){
    compare++;
}
void detail::increment_access(){
    access++;
}

