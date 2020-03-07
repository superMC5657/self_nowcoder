/* -*- coding: utf-8 -*-
  !@time: 2020/3/7 1:50
  !@author: superMC @email: 18758266469@163.com
  !@fileName: the_first_unique_character_in_the_character_stream.cpp
 */
#include <environment.h>

class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        vec.push_back(ch);
        mapdata[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        vector<int>::iterator it;
        for(it=vec.begin();it!=vec.end();it++)
        {
            if(mapdata[*it]==1)
                return *it;
        }
        return '#';
    }
    map<char,int> mapdata;
    vector<int> vec;
};

int fun() {
    return 0;
}