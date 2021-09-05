#!/bin/zsh

FQBN=arduino:avr:uno
PORT=/dev/cu.usbmodem11401

arduino-cli compile --warnings string -b $FQBN
arduino-cli upload -b $FQBN -p $PORT