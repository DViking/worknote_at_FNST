#!/usr/bin/env python
# -*- coding: utf-8 -*-
# File Name : collectionsmodel.py
# Author: Ding Weiqin
# Mail : D_VIKING@163.COM
# Created Time: 9/4/17 1:57 PM

__author__ = 'Ding Weiqin'

from collections import namedtuple
from collections import deque
from collections import defaultdict
from collections import OrderedDict

Point = namedtuple('Point', ['x', 'y'])

Circle = namedtuple('Circle', ['x', 'y', 'r'])

class LastUpdatedOrderedDict(OrderedDict):
    
    def __init__(self, capacity):
        super(LastUpdatedOrderedDict, self).__init__()
        self._capacity = capacity

    def __setitem__(self, key, value):
        containsKey = 1 if key in self else 0
        if len(self) - containsKey >= self._capacity:
            last = self.popitem(last=False)
            print('remove:', last)

        if containsKey:
            del self[key]
            print('set:', (key, value))

        else:
            print('add:', (key, value))

        OrderedDict.__setitem__(self, key, value)



