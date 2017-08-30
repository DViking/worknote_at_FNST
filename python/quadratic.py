#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: quadratic.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Mon 28 Aug 2017 03:04:20 PM CST
#########################################################################

import math

def quadratic(a,b,c):
    derta = math.sqrt((b * b) - (4 * a * c))
    print(derta)
    x = (-b + derta) / (2 * a)
    y = (-b - derta) / (2 * a)
    return x, y
