#!/bin/bash

rm -rf Difficulty/Easy/*
rm -rf Difficulty/Medium/*
rm -rf Difficulty/Hard/*

for i in $(ls All)
do
    Difficulty=$(tail -n 1 All/$i | awk '{print $3}')
    if [[ $Difficulty == "EASY" ]];then
        ln -s ./All/$i ./Difficulty/Easy/$i
    elif [[ $Difficulty == "MEDIUM" ]];then
        ln -s ./All/$i ./Difficulty/Medium/$i
    else [[ $Difficulty == "HARD" ]]
        ln -s ./All/$i ./Difficulty/Hard/$i
    fi
done

echo "Soft link regenerate finished."