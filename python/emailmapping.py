#!/usr/bin/env python
# -*- coding: utf-8 -*-
# File Name : emailmapping.py
# Author: Ding Weiqin
# Mail : D_VIKING@163.COM
# Created Time: 9/4/17 11:30 AM

__author__ = 'Ding Weiqin'

import re


def checkthemail(mail):
    #将正则表达式直接编译，因为后面可能会大量使用到，节省后面编译的时间：
    mapping = r'([a-zA-Z0-9._-]+)@([a-zA-Z0-9_-]+)(.[a-zA-Z0-9]+)'
    re_mapmail = re.compile(mapping)

    #使用编译好的正则表达式来匹配mail：
    m = re_mapmail.match(mapping, mail)
    if m:
        print('<', m.group(1).upper(), '>: ', mail)
    else:
        print('NOT A MAIL ADDRESS!')

if __name__ == '__main__':

    print('This program is from Mr. %s \n' % __author__)

    test = ['bill.gates@microsoft.com','someone@gmail.com','tom@voyager.org']

    for i in range(len(test)):
        checkthemail(test[i])



