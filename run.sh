#!/bin/bash
[ -d app ] || mkdir app
if [ ! -x app/app ]; then
    echo "app not found, starting compilation"
    bash scripts/build.sh
fi
./app/app # to function