#!/bin/bash

CONF=$@

TEST_IP=`grep test_ip $CONF | awk -F '"' '{print $4}'`
BROWSER=`grep "browser" $CONF | awk -F '"' '{print $4}'`
LANGUAGE=`grep  language $CONF | awk -F '"' '{print $4}'`


echo  $TEST_IP $BROWSER $LANGUAGE
