#!/bin/bash

file_wordcnt() {
    files=$(ls *.txt)
    for file in $files; do
        result=$(wc -w $file | awk '{print $1}')
        echo "$file 파일의 단어는 $result 개 입니다."
    done
}

# file_wordcnt

SHCNT=$(find . -name "*.sh" | wc -l)
echo "$SHCNT"