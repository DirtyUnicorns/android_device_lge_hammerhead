#!/bin/sh

dir=`cd $(dirname $0) && pwd`
top=$dir/../../../..

echo ""
echo "************************"
echo "* some patches *"
echo "************************"
for patch in `ls $dir/*.patch` ; do
    echo ""
    echo "==> patch file: ${patch##*/}"
    patch -p1 -N -i $patch -r - -d $top
done

cd $top
echo ""
