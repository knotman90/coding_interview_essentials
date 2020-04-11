#!/bin/bash

set -u
#set -x

die() { echo "$*" 1>&2 ; exit 1; }

SCRIPTNAME=`basename "$0"`

print_help() {
    cat << EOF
Usage: $SCRIPTNAME -f|--file filename -c|--command command -d|--directory directory (default is .)
Uses 'inotifywait' to execute a command when 'filename' has been modified.

EOF
}

# check dependencies
if ! type inotifywait &>/dev/null ; then
    echo "You are missing the inotifywait dependency. Install the package inotify-tools (apt-get install inotify-tools)"
    exit 1
fi


DIR="."
CMD=""
FILE=""

while getopts ":d:c:f:" o; do
    case "${o}" in
        d)
            DIR=${OPTARG}
            ;;
        f)
            FILE=${OPTARG}
            ;;
        c)
            CMD=${OPTARG}
            ;;
        *)
            usage
            ;;
    esac
done


[[ -z $CMD ]] && die "Invalid empty command"
[[ ! -d $DIR ]] && die "This directory $DIR does not exists!"

inotifywait -e close_write,moved_to,create -m $DIR |
while read -r directory events filename; do
    eval $CMD 
done