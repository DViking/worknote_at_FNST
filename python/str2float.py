#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: str2float.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Wed 30 Aug 2017 10:21:13 AM CST
#########################################################################

from functools import reduce

def char2num(s):
    return {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}[s]

def fa(x,y):
    return x * 10 + y

def fb(x):
    while x > 1.0:
        x = x * 0.1
    return x

def str2float(s):
    split = s.find('.')
    a = s[:split]
    b = s[split + 1:]

    a = reduce(fa,map(char2num, a))
    b = reduce(fa,map(char2num, b))
    b = fb(b)
    return a + b

