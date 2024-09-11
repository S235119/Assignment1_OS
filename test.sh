#!/bin/bash

# Simple test of the command interpreter

in="abbabaq"
out="0,3,5;"

[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"


#!/bin/bash

# Simple test of the command interpreter

in="aacbaaraab"
out="0,4,5;"

[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"



#!/bin/bash

# Simple test of the command interpreter

in="k"
out=";"

[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"