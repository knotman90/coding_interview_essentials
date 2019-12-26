#!/bin/bash

set -e
set -u 


function help()
{
	echo "USAGE:
	- $0 CHAPTER_NAME
	- Note that CHAPTER_NAME cannot exists as a folder in source or test (it means that chapter already exists.
	" 
    exit -1
}

NAME=$1
SOURCE_FOLDER="sources/$NAME"
TEST_FOLDER="test/$NAME"
TEX_FILE="$SOURCE_FOLDER/$NAME.tex"
TEST_FILE="$TEST_FOLDER/test_$NAME.cpp"
SOLUTION_FILE="${NAME}_solution"
CMAKE_FILE="${TEST_FOLDER}/CMakeLists.txt"

([ -d "$NAME" ] || [ -d "$TEST_FOLDER" ] || [ -d "$SOURCE_FOLDER" ] || [ -f "$TEX_FILE" ] || [ -f "$TEST_FILE" ]) && help

mkdir -p "$SOURCE_FOLDER"
touch "$TEX_FILE"

echo "%!TEX root = ../main.tex
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Links:
%
% Difficulty:
% Companies: 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
" >> $TEX_FILE

echo "\chapter{TITLE OF THE CHAPTER}
\label{ch:$NAME}
\section*{Introduction}
" >> $TEX_FILE


echo "\section{Problem statement}
\begin{exercise}

\end{exercise}


\begin{example}
	\hfill \\
	
\end{example}

\begin{example}
	\hfill \\
	
\end{example}

\section{Clarification Questions}

\begin{QandA}
	\item 
	\begin{answered}
		\textit{}
	\end{answered}
	
\end{QandA}
" >> $TEX_FILE

echo "\section{Discussion}
\label{$NAME:sec:discussion}


\subsection{Brute-force}
\label{$NAME:sec:bruteforce}

\lstinputlisting[language=c++, caption=Sample Caption,label=list:$NAME]{$SOURCE_FOLDER/${SOLUTION_FILE}1.cpp}
" >>  $TEX_FILE

####################################

mkdir -p "$TEST_FOLDER"


for i in `seq 1 4`
do
	touch "$SOURCE_FOLDER/${NAME}_solution$i.cpp"

done


cd $TEST_FOLDER
for i in ../../$SOURCE_FOLDER/*.cpp
do
	ln -s $i `basename $i`
done

cd ../../
touch "$TEST_FILE"

echo "#include <gtest/gtest.h>
#include <bits/stdc++.h>

#include \"${NAME}_solution1.cpp\"
#include \"${NAME}_solution2.cpp\"

using std::string;



TEST($NAME, test1)
{
	
	EXPECT_EQ(0,1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}
" >> $TEST_FILE


#########################################
touch $CMAKE_FILE

echo "cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_${NAME} `basename $TEST_FILE`)
target_link_libraries(test_${NAME} \${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(test_${NAME} PUBLIC \${GTEST_INCLUDE_DIRS})
" >> $CMAKE_FILE
