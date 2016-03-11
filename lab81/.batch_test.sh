#!/bin/bash

# Empty output directory
/bin/rm -f tact/*

# Create report for individual student
/bin/echo "************************" > log
/bin/echo "TEST REPORT" >> log
/bin/echo "************************" >> log

# compare the output
errnum=0
testnum=0
for currfile in `/bin/ls tinp/*` ; do
        testnum=`expr $testnum + 1`;
        filename=`echo $currfile | sed 's|tinp/||'`;
        (./$1 < $currfile > tact/$filename);
        (/usr/bin/diff -b tact/$filename texp/$filename) > /dev/null;
        if [ $? -ne 0 ] ; then
        	errnum=`expr $errnum + 1`;
                /bin/echo "" >> log;
                /bin/echo "************************" >> log;
                /bin/echo "**** Test Input:" >> log;
                /bin/cat $currfile >> log;
                /bin/echo "**** Expected Output:" >> log;
                /bin/cat texp/$filename >> log;
                /bin/echo "**** Actual Output:" >> log;
                /bin/cat tact/$filename >> log;
                /bin/echo "**** Differences (< = Expected, > = Actual):" >> log;
                (/usr/bin/diff -b texp/$filename tact/$filename) >> log;
                /bin/echo "************************" >> log;
        fi;
done
/bin/echo "" >> log
/bin/echo "**** LOG SUMMARY ****" >> log
/bin/echo "Number of Test Cases: $testnum" >> log
/bin/echo "Number of Test Failures: $errnum" >> log
/bin/echo "************************" >> log

if [ $errnum -gt 0 ] ; then
	/bin/more log
else
        /bin/echo " "
        /bin/echo "PASS"
        /bin/echo " "
fi

