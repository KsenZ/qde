#!/bin/bash
killall Xephyr
export DISPLAY=:0
Xephyr :2 -host-cursor -screen 800x480x16 -dpi 96 -ac &
export DISPLAY=:2
qde
