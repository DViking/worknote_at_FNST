#!/usr/bin/env python3
# -*- coding; utf-8 -*-
#########################################################################
# File Name: keyword.py
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Tue 29 Aug 2017 10:01:07 AM CST
#########################################################################

# 命名关键字必须传入参数名，这和位置参数不同，如果没有传入参数名，将汇报错
# 传入的参数会组成dict
def person(name, age, **kw):

    if 'city' in kw:
        # 有city参数
        pass

    if 'job' in kw:
        # 有job参数
        pass

    print('name:', name, 'age:', age, 'others:', kw)

