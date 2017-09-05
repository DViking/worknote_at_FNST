#!/usr/bin/env python
# -*- coding: utf-8 -*-
# File Name : contextlib.py
# Author: Ding Weiqin
# Mail : D_VIKING@163.COM
# Created Time: 9/5/17 9:41 AM

__author__ = 'Ding Weiqin'
#
# class Query(object):
#
#     def __init__(self, name):
#         self.name = name
#
#     def __enter__(self):
#         print('Begin')
#         return self
#
#     def __exit__(self, exc_type, exc_val, exc_tb):
#         if exc_type:
#             print('Error')
#         else:
#             print('End')
#
#     def query(self):
#         print('Query info about %s...' % self.name)
#
#
# with Query('Bob') as q:
#     q.query()

from contextlib import contextmanager

class Query(object):
    def __init__(self, name):
        self.name = name

    def query(self):
        print('Query info about %s...' % self.name)

@contextmanager
def create_query(name):
    print('Begin')
    q = Query(name)
    yield q
    print('End')

