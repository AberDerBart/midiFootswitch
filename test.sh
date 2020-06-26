#!/bin/bash

#get device number
CLIENT_NUMBER=$(aconnect -i|grep SparkFun|grep ^client|cut -d ' ' -f2|cut -d ':' -f1)

#dump midi messages
aseqdump -p $CLIENT_NUMBER
