#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: pord.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Wed 30 Aug 2017 10:10:19 AM CST
#########################################################################
from functools import reduce
def pord(L):
    return reduce(X,L)

def X(a,b):
    return a * b
