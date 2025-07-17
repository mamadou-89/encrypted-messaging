#!/bin/bash

ko='\e[00;31m';
wipe='\e[00m';
ok='\e[01;32m';

BASE=./
TEST=./tests
RET=
clef=ab5

function test_cipher_xor {
	echo "cryptage"
    RET=0

    if [ -x $BASE/dh_crypt ]
    then

    	rm -rf $TEST/crypted/
   		mkdir $TEST/crypted/

	while read i
	do
 	    $BASE/dh_crypt -i $TEST/ref/$i  -o $TEST/crypted/xor_${i} -k $clef -m xor > /dev/null
	    diff $TEST/ref_crypted/xor_$i  $TEST/crypted/xor_${i}  &>/dev/null
	    RET=$?
	    [ $RET -eq 0 ] && printf "\t%-12s [${ok}OK${wipe}]\n" "$i"
	    [ $RET -ne 0 ] && printf "\t%-12s [${ko}KO${wipe}]\n" "$i" 

	done <./$TEST/file_list.txt 
    fi
}

function test_decipher_xor {
	echo "décryptage"
    RET=0
    rm -rf $TEST/decrypted/
    mkdir $TEST/decrypted/

    if [ -x $BASE/dh_crypt ]
    then
	    while read i
	    do
 		$BASE/dh_crypt -o $TEST/decrypted/xor_$i  -i $TEST/crypted/xor_${i} -k $clef -m xor &> /dev/null
		diff $TEST/ref/$i $TEST/decrypted/xor_${i}  &>/dev/null
		RET=$?
		[ $RET -eq 0 ] && printf "\t%-12s [${ok}OK${wipe}]\n" "$i"
		[ $RET -ne 0 ] && printf "\t%-12s [${ko}KO${wipe}]\n" "$i"
	    done < ./$TEST/file_list.txt

    fi
}
echo "la clef utilisé est $clef"
test_cipher_xor;
test_decipher_xor;

exit 0
