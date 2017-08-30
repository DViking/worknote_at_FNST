#########################################################################
# File Name: bridge.sh
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Mon 17 Jul 2017 04:14:35 PM CST
# Details: This script is for build a bridge.
#########################################################################
#!/bin/bash

#Program:
#	This program is for build a bridge by create 2 couples of netcard and a net bridge.
ip link add tap11 type veth peer name tap22

ip link add tap33 type veth peer name tap44

echo creat 2 couples of netcard success

ip netns add net1

ip netns add net3

echo creat 2 netns success

ip link set tap11 netns net1

ip link set tap33 netns net3

echo set netcard into netns success

ip netns exec net1 ifconfig tap11 172.16.11.11/24 up

ip netns exec net1 ifconfig lo up

ip netns exec net3 ifconfig tap33 172.16.11.33/24 up

ip netns exec net3 ifconfig lo up

echo set ip addr in netns success

brctl addbr br0

echo build bridge success

brctl addif br0 tap22

brctl addif br0 tap44

echo add netcard to bridge success

ifconfig tap22 up

ifconfig tap44 up

echo set ip addr at home success

ifconfig br0 up
echo set bridge ip and up it success

brctl stp br0 off

echo "The bridge is build up."


#########################################################################
#LastChange: 07/18/17 16:18:44 by @Ding Weiqin
#Status: Trying
#########################################################################
