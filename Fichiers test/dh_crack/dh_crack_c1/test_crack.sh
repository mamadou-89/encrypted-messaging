#!/bin/bash

ko='\e[00;31m';
wipe='\e[00m';
ok='\e[01;32m';

BASE=./
TEST=./tests
RET=
taille_clef=3
function test_crack_c1 {
# critère C1
    rm -rf $TEST/keys0
    mkdir $TEST/keys0

    if [ -x $BASE/dh_crack ]
    then
    while read i
    do
    $BASE/dh_crack -i $TEST/crypted_crack/123_${i} -m c1 -k ${taille_clef} > $TEST/keys0/${123}_${i}
    diff $TEST/keys0/${123}_${i} $TEST/keys0/${123}_${i} &>/dev/null
    RET=$?
    [ $RET -eq 0 ] && printf "\t%-12s [${ok}OK${wipe}]\n" "$i"
    [ $RET -ne 0 ] && printf "\t%-12s [${ko}KO${wipe}]\n" "$i" && return
    done < ./$TEST/file_list_crack.txt
    else
    RET=2
    fi

    }



test_crack_c1
    exit 0
