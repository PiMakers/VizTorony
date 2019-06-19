#!/bin/bash

##===================================================
## net rpc shutdown -I IPADDRESS -U USERNAME%PASSWORD
## set machine on the same network
## manage windowposition: sudo apt install wmctrl
## notification error:sudo apt-get install libnotify-cil-dev
##===================================================

## TurnOff blankScreen:
set s off
xset -dpms
xset s noblank

 ## Arg 1 - Pid of window to move.
 ## Arg 2 - X-Coord.
 ## Arg 3 - Y-Coord.
 ## E.g.  move_win $(pidof zenity) 0 0

function move_win() { 
 xdotool windowmove $(wmctrl -lp | grep ${1} | cut -d' ' -f1) ${2} ${3}
} 

command1() {
## Machines to shutdown 

PASSWORD=sajt123
RESTART="-r -t 0"


for ((i=1;i<3;i++))
    do
        IPADDRESS=192.168.137.11${i}
        USERNAME=s${i}


        if [ $(net rpc shutdown  -v ${RESTART} -I ${IPADDRESS} -U "${USERNAME}%${PASSWORD}" 2>/dev/null & ) ]; then
            c --text="${i}.emelet ( ${IPADDRESS} ) lekapcsolva!" --display=${DISPLAY} &
        else
            zenity --notification --text="${i}.emelet ( ${IPADDRESS} ) nem lett lekapcsolva!" --display=${DISPLAY} &
        fi
    done
}


command3() {

    if $(zenity --question --text="Kikapcsolod a rendszert?" --title="Kikapcs" --default-cancel) ; then
    command1 &
    shutdown &
    if 
        $((for ((i=0;i<100;i+=1))
            do 
                echo $i
                sleep 0.6
            done ) | \
                zenity --progress --auto-close --text="A rendszer lekapcsol..." --title="+36 30 944 6153"--time-remaining --title=Shutdown) --display=${DISPLAY}
        then echo "ok";
    else
        shutdown -c
        command3
    fi
    echo
    else command3
    fi
}

command3
exit