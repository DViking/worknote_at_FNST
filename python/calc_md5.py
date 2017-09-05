#!/usr/bin/env python
# -*- coding: utf-8 -*-
# File Name : calc_md5.py
# Author: Ding Weiqin
# Mail : D_VIKING@163.COM
# Created Time: 9/4/17 5:17 PM

__author__ = 'Ding Weiqin'

import hashlib

def calc_md5(password):
    md5 = hashlib.md5()
    md5.update(password.encode('utf-8'))
    return md5.hexdigest()

db = {
    'michael': 'e10adc3949ba59abbe56e057f20f883e',
    'bob': '878ef96e86145580c38c87f0410ad153',
    'alice': '99b1c2188db85afee403b1536010c2c9'
}

def login(user, password):
    if db[user] == calc_md5(password):
        return True
    else:
        return False

def register(user, password):
    db[user] = calc_md5(password + user + 'this-is-a-salt')


if __name__ == '__main__':
    user = input('please enter your user : ')
    password = input('please enter your password: ')

    for i in db:
        if i == user:
            if login(user, password) == True:
                print('Login Success, Welcome ', user.upper())
            else:
                print('Error user or password')

        else:
            pass

    check = input('the user is not exist, do you want to regist?[y/n]:')
    if check == 'y':
        register(user, password)
        print('regist success, Welcome ', user.upper())

    print(db)

