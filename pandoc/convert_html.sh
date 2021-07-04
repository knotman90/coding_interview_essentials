#!/bin/bash

set -u 
ROOT="/home/dspataro/git/algorithm_articles/"
WORK_DIR=$(mktemp -d -t book-XXXXXXXXXX)

cp -r $ROOT/* $WORK_DIR
ROOT="$WORK_DIR"
SOURCE_ROOT=$ROOT/sources

cd $ROOT

for texfile in $(find $ROOT -iname "*.tex" )
do
    echo "$texfile"
    sed -i 's#sources/#'"$SOURCE_ROOT"'/#g' $texfile
done



for pdfimage in $(find $SOURCE_ROOT -iname "*.pdf" | grep images)
do
    
    DIR=$(dirname $pdfimage)
    FILENAME=$(basename $pdfimage .pdf)

    convert -density 96 -quality 85 "$pdfimage" "$DIR/$FILENAME.jpg"

    mv $pdfimage $pdfimage.bak

    echo "$DIR/$FILENAME.jpg"
done



echo "Working directory is $WORK_DIR"

# Generate markdown single file from tex
MAINMD="$WORK_DIR/main.md"
MAINTEX="$WORK_DIR/main_pandoc.tex"
cp $SOURCE_ROOT/main_pandoc.tex  $MAINTEX

pandoc -f latex  --mathjax    -s --toc $MAINTEX -o $MAINMD

#exit 0
#set -x 
set -u
#set -e
# fix code blocks
grep -e "\`\`\` {" $MAINMD  | while read -r line ; do
    LABEL=$(echo $line | cut -d'{' -f2- | cut -d' ' -f1)
    LABEL_LST=$(echo $LABEL |  sed 's/#list/#lst/g')
    LANG=$(echo $line | cut -d'{' -f2- | cut -d' ' -f2)
    CAPTION=$(echo $line | cut -d'{' -f2- | cut -d' ' -f4- | sed -n -e 's/^\(.*\)\(label=\)\(.*\)$/\1/p')
    
    LANGESC=$(echo $LANG | sed 's/+/p/g')
    CAPTION_DOUBLE_QUOTES_REMOVED=$(echo $CAPTION | sed 's/\\"//g');
    SUB="~~~{$LABEL_LST $LANGESC $CAPTION_DOUBLE_QUOTES_REMOVED}"

    SUB_ESCAPED=$(echo $SUB | sed 's_/_\\/_g')
    sed -i '0,/``` {#.*language.*caption.*/{s/``` {#.*language.*caption.*/'"$SUB_ESCAPED"'/}'  $MAINMD
    
done

sed -i 's/```/~~~/g' $MAINMD

#cat $MAINMD  | grep "\`\`\`"

#exit 0

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
   FILENAME=$CHAPTERDIR/$idx.$(echo $line | sed 's/ /_/g' | sed 's/,/_/g'| sed -r 's/[\^{}\$]//g').md;
   touch $FILENAME
   echo $FILENAME
   echo "% $idx. $line" > $FILENAME

   sed -n '/^12$/,/^15$/p' $MAINMD | sed '1d;$d'

   echo "from $line to next chapter"
   LINE_ESCAPED=$(echo $line | sed -r 's/\^/\\^/g' | sed -r 's/\$/\\$/g')
   echo "sed -n '/^# $LINE_ESCAPED/,/^# /p' $MAINMD"

   cat $MAINMD | sed -n  "/^# $LINE_ESCAPED/,/^# /p"  | head -n -1 >> $FILENAME
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