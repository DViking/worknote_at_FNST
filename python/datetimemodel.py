#!/usr/bin/env python
# -*- coding: utf-8 -*-
# File Name : datetimemodel.py
# Author: Ding Weiqin
# Mail : D_VIKING@163.COM
# Created Time: 9/4/17 1:33 PM

__author__ = 'Ding Weiqin'

import re
from datetime import datetime, timezone, timedelta

def to_timestamp(dt_str, tz_str):
    dt = datetime.strptime(dt_str, '%Y-%m-%d %H:%M:%S')

    now_time = dt.utcnow().astimezone(
        timezone(
            timedelta(
                hours=
                (int(str.split('UTC')[1].split(':00')[0])
))))

