#!/bin/bash
killall Xephyr
export DISPLAY=:0
export ANTICO_DEBUG=1
Xephyr :2 -host-cursor -screen 800x480x16 -dpi 96 -ac &
export DISPLAY=:2
gdb qde
