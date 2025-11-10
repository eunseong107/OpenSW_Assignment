#! /bin/bash

file_wordcnt() {

    if [ $([ -e "$FILE" ]; echo $?) != 0 ]; then
        echo "$1 파일이 존재하지 않습니다."
        return 1
    fi
    echo "$FILE 파일의 단어는 $(wc -w $FILE | awk '{print $1}') 개 입니다."
}

read -p "Enter a file name: " FILE
file_wordcnt $FILE
echo "file_wordcnt 함수의 종료 상태: $?"