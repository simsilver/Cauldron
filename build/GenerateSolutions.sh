#!/bin/sh

mkdir -p VK
cd VK
cmake ../.. -DGFX_API=VK
cd ..
