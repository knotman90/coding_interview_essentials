#!/bin/bash

set -u 
ROOT="/home/dspataro/git/algorithm_articles/"
SOURCE_ROOT=$ROOT/sources

for pdfimage in $(find $SOURCE_ROOT -iname "*.pdf" | grep images)
do
    
    DIR=$(dirname $pdfimage)
    FILENAME=$(basename $pdfimage .pdf)

    convert -density 96 -quality 85 "$pdfimage" "$DIR/$FILENAME.jpg"

    mv $pdfimage $pdfimage.bak

    echo "$DIR/$FILENAME.jpg"
done