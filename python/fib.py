#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: fib.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Tue 29 Aug 2017 01:54:01 PM CST
#########################################################################

def fib(max):
    n, a, b = 0 ,0 ,1
    while n < max:
        yield b
        a, b = b, a + b
        n = n + 1
    return 'done'
