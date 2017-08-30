#!/bin/bash

num_processes=${1:-"5"}
num_iterations=${2:-"1000"}

#set -x
# clean env

build_netns(){
local ns1=$1
local ns2=$2
local br_if="br_$1_$2"
local ns1_veth0=$ns1"_veth0"
local ns2_veth0=$ns2"_veth0"
local ns1_veth0_br=$ns1"_veth0_br"
local ns2_veth0_br=$ns2"_veth0_br"
local nets="$ns1 $ns2"

for net in $nets; do
        ip netns del $net
done
[ "`ip link | grep $br_if`" ] && ip link del $br_if &> /dev/null
[ "`ip link | grep $ns1_veth0`" ] && ip link del $ns1_veth0 &> /dev/null
[ "`ip link | grep $ns2_veth0`" ] && ip link del $ns2_veth0 &> /dev/null
[ "`ip link | grep $ns1_veth0_br`" ] && ip link del $ns1_veth0_br &> /dev/null
[ "`ip link | grep $ns2_veth0_br`" ] && ip link del $ns2_veth0_br &> /dev/null

# start setup
for net in $nets; do
        ip netns add $net
done

ip link add $br_if type bridge || brctl addbr $br_if
ip link add $ns1_veth0 type veth peer name $ns1_veth0_br
ip link add $ns2_veth0 type veth peer name $ns2_veth0_br

ip link set $ns1_veth0_br master $br_if || brctl addif $br_if $ns1_veth0_br
ip link set $ns2_veth0_br master $br_if || brctl addif $br_if $ns2_veth0_br

ip link set $ns1_veth0 netns $ns1
ip link set $ns2_veth0 netns $ns2
HA="ip netns exec $ns1"
HB="ip netns exec $ns2"

out_ifaces="$br_if $ns1_veth0_br $ns2_veth0_br"
for iface in $out_ifaces; do
        ip link set $iface up
done
$HA ip link set lo up
$HA ip link set $ns1_veth0 up
$HB ip link set lo up
$HB ip link set $ns2_veth0 up

# MTU testing
#$HB ip link set $ns2_veth0 mtu 1300

# setup ipv4 addr
ip addr add 192.168.0.254/24 dev $br_if
$HA ip addr add 192.168.0.1/24 dev $ns1_veth0
$HB ip addr add 192.168.0.2/24 dev $ns2_veth0
#$HA ip route add default via 192.168.0.254 dev $ns1_veth0
#$HB ip route add default via 192.168.0.254 dev $ns2_veth0

# setup ipv6 addr
ip addr add 2000::254/64 dev $br_if
$HA ip addr add 2000::1/64 dev $ns1_veth0
$HB ip addr add 2000::2/64 dev $ns2_veth0
}

build_netns_looply()
{
for i in `seq $num_iterations`; do
build_netns $1 $2
done
}

itan=1

for i in `seq $num_processes`; do
build_netns_looply "ns$itan" "ns$(($itan+1))" && itan=$(($itan+2))
done


