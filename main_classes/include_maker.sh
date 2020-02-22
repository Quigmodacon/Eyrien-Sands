#!/bin/bash

HEADER=all_includes.hpp
echo "#ifndef __ALL_INCLUDES__" > $HEADER
echo "#define __ALL_INCLUDES__" >> $HEADER
for file in ../headers/*.hpp
do
    echo "#include \"$file\"" >> $HEADER
done
echo "#endif" >> $HEADER
