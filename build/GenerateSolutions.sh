#!/bin/sh

SHELL_FOLDER=$(dirname $(readlink -f "$0"))
dir=linux-VK
mkdir -p "${SHELL_FOLDER}/${dir}"
pushd $dir>/dev/null
cmake ../.. -DGFX_API=VK
popd>/dev/null
