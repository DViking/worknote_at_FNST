#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: xiaoming.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Mon 28 Aug 2017 02:32:45 PM CST
#########################################################################

high = 1.75
heavy = 80.5

BMI = heavy /( high * high)

if BMI < 18.5:
    print('Too light')
elif BMI < 25:
    print('Normal')
elif BMI < 28:
    print('Heavy')
elif BMI < 32:
    print('Fat')
else:
    print('Too Fat')
