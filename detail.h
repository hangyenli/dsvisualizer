//
// Created by 鸿昊李 on 2019-04-29.
//

#ifndef DSVISUALIZER_DETAIL_H
#define DSVISUALIZER_DETAIL_H


class detail {
public:
    //constructor
    detail();

    //accessor
    int get_compare();
    int get_access();

    //modifier
    bool set_compare(unsigned int i);
    bool set_access(unsigned int i);
    void increment_compare();
    void increment_access();

private:
    int compare;
    int access;

};


#endif //DSVISUALIZER_DETAIL_H
