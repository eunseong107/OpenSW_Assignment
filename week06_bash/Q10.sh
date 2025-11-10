#!/bin/bash

MYNAME="Eunseong Son"

print_param() {
    echo "Script name: $0"
    echo "first param: $1"
    echo "second param: $2"
    echo "all params: $1 $2 $3"
    echo "the number of params: $#"
}

# print_param "Hello" "World" "!"

echo $MYNAME > file3.txt