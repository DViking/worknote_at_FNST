#!/usr/bin/env python
# -*- coding: utf-8 -*-
# File Name : urllib.py
# Author: Ding Weiqin
# Mail : D_VIKING@163.COM
# Created Time: 9/5/17 10:29 AM

__author__ = 'Ding Weiqin'

from urllib import request

with request.urlopen('https://api.douban.com/v2/book/2129650') as f:
    data = f.read()
    print('Status:', f.status, f.reason)
    for k, v in f.getheaders():
        print('%s: %s' % (k, v))
    print('Data:', data.decode('utf-8'))