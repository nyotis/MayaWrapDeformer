#!/bin/bash

DIST=fedora13

PROJECT_NAME=PFWrapDeformer
VERSION=1.0.0
SOURCES=(
    PFWrapDeformer.cpp
)
CFLAGS=(-Wno-deprecated -fPIC -g -Wall) 
TYPE=library
APPLICATION=maya
APPLICATION_VERSION=2011sp1
OPTIONS=no_prefix

source install_project

