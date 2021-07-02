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



WORK_DIR=$(mktemp -d -t book-XXXXXXXXXX)
echo "Working directory is $WORK_DIR"

# Generate markdown single file from tex
MAINMD="$WORK_DIR/main.md"
pandoc -f latex  --mathjax  -s --toc $SOURCE_ROOT/main.tex -o $MAINMD

TOCMD="$WORK_DIR/toc.md"
grep -P "^-\s*\[(.+)\]\((.+)\)" -o $MAINMD | sed 's/\[/\]/g' | cut -d ']' -f 2 > $TOCMD

CHAPTERDIR=$WORK_DIR/chapters
mkdir $CHAPTERDIR

set -u

echo "Copyright 2016–2021 Davide Spataro" > $CHAPTERDIR/_copyright

echo "% Coding interview Essentials" > $CHAPTERDIR/index.md
# Create MD chapters
idx=1 
cat "$TOCMD" | while read line 
do
   FILENAME=$CHAPTERDIR/$idx.$(echo $line | sed 's/ /_/g').md;
   touch $FILENAME
   echo $FILENAME
   echo "% $idx. $line" > $FILENAME

   sed -n '/^12$/,/^15$/p' $MAINMD | sed '1d;$d'

   echo "from $line to next chapter"
   echo "sed -n -E -e '/^# $line/,/^# /p' $MAINMD"

   cat $MAINMD | sed -n -E -e "/^# $line/,/^# /p"  >> $FILENAME
   let "idx+=1" 

done



CURRDIR=$(pwd)
cd $CHAPTERDIR

/home/dspataro/git/rippledoc/rippledoc.py
sort -n -t= $CHAPTERDIR/toc.conf -o $CHAPTERDIR/toc.conf
/home/dspataro/git/rippledoc/rippledoc.py

cd $CURRDIR
ls -lah $CHAPTERDIR

google-chrome-stable $CHAPTERDIR/index.html
#sed -n -E -e '/^# Power set/,/^# /p' ./main.md


# ^-\s*\[(.+)\]\((.+)\) 