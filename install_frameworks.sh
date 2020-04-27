#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
LMAGENTA='\033[1;35m'
NORMAL='\033[0m'

unamestr=`uname`

if [[ "$unamestr" == 'Linux' ]]; then
   printf "${GREEN}Launching framework installer for linux...${NORMAL}\n"
   sleep 1s
   bash .linux_install_frameworks.sh
elif [[ "$unamestr" == 'Darwin' ]]; then
   printf "${CYAN}Launching framework installer for mac os...${NORMAL}\n"
   sleep 1s
   bash .mac_install_frameworks.sh
fi
