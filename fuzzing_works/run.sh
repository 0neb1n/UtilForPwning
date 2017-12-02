#!/bin/sh

	while true; do
		radamsa -o fuzzed/fuzz-%n -n 100 samples/*
	done;

