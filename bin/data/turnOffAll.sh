#!/bin/bash
#net rpc shutdown -I IPADDRESS -U USERNAME%PASSWORD

IPADDRESS=192.168.0.59
USERNAME=highd
PASSWORD=ZZSJR5qWs
RESTART="-r -t 0"
net rpc shutdown  ${RESTART} -I ${IPADDRESS} -U "${USERNAME}%${PASSWORD}"
# sudo shutdown now