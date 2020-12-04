#!/bin/sh
dir1=$1
while inotifywait -qqre modify "$dir1"; do
    make pdf tests
done