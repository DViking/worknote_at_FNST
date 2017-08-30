#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: hanotower.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Tue 29 Aug 2017 10:35:35 AM CST
#########################################################################


# 汉诺塔解决方案：

def move(n, a = 'A', b = 'B', c = 'C'):
    if n == 1:
        print(a, '--> ', c)
        return

    move(n - 1, a, c, b)
    
    print(a,'--> ',c)
    
    move(n - 1, b, a, c)
    return


