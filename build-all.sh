#!/bin/bash
set -e -u -x

for PLAT in `cat platforms_list.txt`
do
    echo "==== $PLAT ===="
    podman  run --rm -e PLAT=$PLAT --security-opt label=disable -v `pwd`:/io quay.io/pypa/$PLAT /io/build-wheels.sh
done
