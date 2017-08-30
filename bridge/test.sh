#########################################################################
# File Name: test.sh
# Author: Ding Weiqin
# mail: D_viking@163.com
# Created Time: Fri 14 Jul 2017 03:54:58 PM CST
#########################################################################
#!/bin/bash
echo "this is a test shell script"
time 
ip netns del ns1 >/dev/null 2>&1
ip netns del ns2 >/dev/null 2>&1
ip link del br_ns1_ns2 > /dev/null 2>&1
ip link del ns1_veth0 > /dev/null 2>&1
ip link del ns2_veth0 > /dev/null 2>&1
ip link del ns1_veth0_br > /dev/null 2>&1
ip link del ns2_veth0_br > /dev/null 2>&1
ip netns add ns1 > /dev/null 2>&1
ip netns add ns2 > /dev/null 2>&1
ip link add br_ns1_ns2 type bridge > /dev/null 2>&1
ip link add ns1_veth0 type veth peer name ns1_veth0_br > /dev/null 2>&1
ip link add ns2_veth0 type veth peer name ns2_veth0_br > /dev/null 2>&1
ip link set ns1_veth0_br master br_ns1_ns2  > /dev/null 2>&1
ip link set ns2_veth0_br master br_ns1_ns2  > /dev/null 2>&1
ip link set ns1_veth0 netns ns1  > /dev/null 2>&1
ip link set ns2_veth0 netns ns2  > /dev/null 2>&1
ip link set br_ns2_ns2 up  > /dev/null 2>&1
ip link set ns1_veth0_br up > /dev/null 2>&1
ip link set ns2_veth0_br up > /dev/null 2>&1
ip netns exec ns1 lo up > /dev/null 2>&1
ip netns exec ns1 ns1_veth0 up > /dev/null 2>&1
ip netns exec ns2 lo up > /dev/null 2>&1
ip netns exec ns2 ns2_veth0 up > /dev/null 2>&1
ip add add 192.168.100.200 dev br_ns1_ns2 > /dev/null 2>&1
ip netns exec ns1 ip add add 192.168.100.2 dev ns1_veth0 >/dev/null 2>&1
ip netns exec ns2 ip add add 192.168.100.3 dev ns2_veth0 >/dev/null 2>&1


while true; do /root/test.sh ;done &
while true; do /root/test.sh; done &
while true; do /root/test.sh; done &


