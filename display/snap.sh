#!/bin/sh

imagesnap -q -w 1 images/snapshot.png
convert images/snapshot.png images/snapshot.xpm
mv images/snapshot.png ~/Desktop
