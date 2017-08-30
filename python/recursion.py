#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: recursion.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Tue 29 Aug 2017 10:20:13 AM CST
#########################################################################

def fact(n):
    return fact_iter(n, 1)

def fact_iter(num, product):
    if num == 1:
        return product
    return fact_iter(num -1, num * product)


