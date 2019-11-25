/* -*- coding: utf-8 -*-
  !@time: 2019/11/21 20:12
  !@author: superMC @email: 18758266469@163.com
  !@fileName: InfoH.h
 */
#ifndef INFOH_H
#define INFOH_H

#define INFI  ((unsigned int)-1)

struct InfoH {
    int pos;
    bool newline;

    InfoH() : pos(INFI), newline(false) {}

    int add_pos(int add) {
        pos += add;
        return pos;
    }
};


#endif