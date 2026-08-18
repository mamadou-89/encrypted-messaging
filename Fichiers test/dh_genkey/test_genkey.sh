#!/bin/bash

ko='\e[00;31m';
wipe='\e[00m';
ok='\e[01;32m';

BASE=./
test_genkey()
{
    if [ -x $BASE/test_genkey ]
	then
	    echo "Patientez l'éxécution prends un peu de temps à cause des arrêts présents dans le programme"
 	    $BASE/test_genkey > /dev/null
	    RET=$?
	    [ $RET -eq 0 ] && printf "\t%-12s [${ok}OK${wipe}]\n" "test_genkey" 
		[ $RET -ne 0 ] && printf "\t%-12s [${ko}KO${wipe}]\n" "test_genkey"
	fi 
}

test_genkey;

exit 0
