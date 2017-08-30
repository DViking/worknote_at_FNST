#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: calc.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Mon 28 Aug 2017 04:53:13 PM CST
#########################################################################

def calc(*numbers):
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum
