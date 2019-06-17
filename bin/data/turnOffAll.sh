#!/bin/bash
#net rpc shutdown -I IPADDRESS -U USERNAME%PASSWORD
# set machine on the same network


command1() {
## Víztorony 
# 1. emelet
IPADDRESS=192.168.137.111
USERNAME=s1
PASSWORD=sajt123
RESTART="-r -t 0"

if [ $(net rpc shutdown  -v ${RESTART} -I ${IPADDRESS} -U "${USERNAME}%${PASSWORD}" 2>/dev/null & ) ]; then
    echo -ne "\r1.emelet lekapcsolva!\n"
else
    echo -ne "\r1.emelet sikertelen lekapcsolás\n"
fi    
}


command2() {
# 2. emelet
IPADDRESS=192.168.137.112
USERNAME=s2
PASSWORD=sajt123
RESTART="-r -t 0"

if [ $(sudo net rpc shutdown  -v ${RESTART} -I ${IPADDRESS} -U "${USERNAME}%${PASSWORD}" 2>/dev/null & ) ]; then
    echo -ne "\r2.emelet lekapcsolva!\n"
else
    echo -ne "\r2.emelet sikertelen lekapcsolás\n"
fi  

#now
#sudo shutdown 2>&1 &
#    echo "A server lekapcsol!"

#sleep 1

#sudo shutdown -c

}

command3() {

    if $(zenity --question --text="Hoolulu" --default-cancel) ; then
    command1 &
    command2 &
    command4 &
    echo
    else command3
    fi
}

command4() {
    TIME=$(err=$(shutdown 2>&1) && echo $err | sed  's/.*\(-[0-9][0-9] \)//; s/CEST.*//' && sudo shutdown -c)
    H=${TIME%%:*}
    M=${TIME%:*}
    M=${M##*:}
    S=${TIME##*:}
    midnight=$(date -d 'today 00:00:00' '+%s')
    SHUTDOWN_TIME_IN_SEC=$((3600*$H+60*$M+$S))
    CURR_TIME_IN_SEC=$(( now - midnight ))
    echo
    while [[ $(($SHUTDOWN_TIME_IN_SEC - $CURR_TIME_IN_SEC)) > 0 ]]
        do
            now=$(date '+%s')
            CURR_TIME_IN_SEC=$(( now - midnight ))
            echo -ne "\r$(($SHUTDOWN_TIME_IN_SEC - $CURR_TIME_IN_SEC))"
        done
}

command3
exit