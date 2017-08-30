#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: yanghuiTriangle.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Tue 29 Aug 2017 02:07:28 PM CST
#########################################################################

def triangles(max):
    
    i, l = 0, [1]
    while i < max:
        yield l
        l = [l[a - 1] + l[a] for a in range(len(l)) if a > 0]
        #print(l)
        l.append(1)
        #print(l)
        l.insert(0,1)
        #print(l)
        i = i + 1

    return 'done'
    
