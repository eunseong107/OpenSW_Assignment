#! /bin/bash

echo -n "Enter your age: "
read AGE

# 25세 이상과 미만을 판별하시오.
if [ $AGE -ge 25 ]; then
    echo "당신은 25세 이상입니다."
else
    echo "당신은 25세 미만입니다."
fi